#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <dbi/dbi.h>

static void
assert_file_size (const char *fn, off_t expected_size)
{
  struct stat sb;

  assert (stat (fn, &sb) != -1);
  assert (sb.st_size == expected_size);
}

int
main (int argc, char *argv[])
{
  dbi_conn conn;
  char *tmpfn;
  FILE *f;

  if (argc < 2)
    {
      fprintf (stderr, "%s: Need a libdir as argument!\n", argv[0]);
      return 1;
    }

  dbi_initialize (argv[1]);

  conn = dbi_conn_new ("null");
  tmpfn = tempnam (NULL, "dbd-null.");
  f = fopen (tmpfn, "a");
  fclose (f);

  /*
   * Logging turned off
   */
  dbi_conn_connect (conn);

  assert_file_size (tmpfn, 0);

  f = fopen (tmpfn, "w");
  fclose (f);

  /*
   * Logging turned on
   */
  dbi_conn_set_option (conn, "null.log.filename", tmpfn);
  dbi_conn_connect (conn);
  dbi_conn_query (conn, "SELECT * FROM DUAL");
  dbi_conn_close (conn);

  assert_file_size (tmpfn, strlen ("CONNECT\n") +
                           strlen ("SELECT * FROM DUAL\n") +
                           strlen ("DISCONNECT\n"));

  /*
   * Cleanup
   */
  dbi_shutdown ();
  unlink (tmpfn);

  return 0;
}
