dbd-null
========

[![Build Status](https://secure.travis-ci.org/algernon/dbd-null.png?branch=master)](http://travis-ci.org/algernon/dbd-null)

This is a very primitive database driver for [libdbi][1], that does
pretty much nothing. It does just enough to make [syslog-ng][2] work
with it without throwing errors all over the place.

That's all there is to it, nothing more, nothing less, and it will
very likely stay that way. Except when it doesn't, and the driver gets
repurposed for another use-case: simulating slow databases.

The driver now accepts a set of options, which will make the driver
sleep for the set time (if the option is unset, no sleeping will
happen) when performing the appropriate function:

* null.sleep.connect
* null.sleep.disconnect
* null.sleep.list_dbs
* null.sleep.list_tables
* null.sleep.query
* null.sleep.query_null
* null.sleep.select_db
* null.sleep.ping

The driver also accepts the following other options:

* null.error.commit: When set to a non-zero value, and the driver
  receives a query starting with *COMMIT*, the query will fail instead
  of returning an empty result.
* null.error.query: Similarly to `null.error.commit`, when set to a
  non-zero value, **every** query the driver receives will fail
  instead of returning an empty result.
* null.error.query.nth: Similarly to `null.error.query`, when set to a
  non-zero value, every `nth` query the driver receives will fail
  instead of returning an empty result.
* null.geterror.errno: When `dbi_conn_get_error()` is called, this
  option is checked to see what errno to set. If unset, the driver
  uses 0.
* null.geterror.errmsg: When `dbi_conn_get_error()` is called, this
  option is checked to see what error message should be set. If unset,
  the driver sets the error message to NULL.
* null.log.filename: When set, most operations (connect, disconnect,
  and queries) will be logged to the given filename.

 [1]: http://libdbi.sourceforge.net/
 [2]: http://www.balabit.com/network-security/syslog-ng
