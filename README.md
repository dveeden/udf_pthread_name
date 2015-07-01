Description
===========
An MySQL UDF to set the thread name on Linux. This is useful for identifying threads from the OS.

Bug #70858  Set thread name
https://bugs.mysql.com/bug.php?id=70858

This only works for the current thread currently.

Installation
============

    $ gcc -o udf_pthread_name.so udf_pthread_name.c `mysql_config --include` -shared -fPIC -lpthread

    mysql> CREATE FUNCTION pthread_name RETURNS INTEGER SONAME 'udf_pthread_name.so';

Example
=======

    mysql> SELECT set_pthread_name('foobarbaz');
    +-------------------------------+
    | set_pthread_name('foobarbaz') |
    +-------------------------------+
    |                             0 |
    +-------------------------------+
    1 row in set (0.00 sec)
    mysql> \! ps -eLo pid,tid,comm | grep $(pgrep -x mysqld)
    3880  3880 mysqld
    3880  3881 mysqld
    3880  3882 mysqld
    3880  3883 mysqld
    3880  3884 mysqld
    3880  3885 mysqld
    3880  3886 mysqld
    3880  3887 mysqld
    3880  3888 mysqld
    3880  3889 mysqld
    3880  3890 mysqld
    3880  3893 mysqld
    3880  3894 mysqld
    3880  3895 mysqld
    3880  3896 mysqld
    3880  3897 mysqld
    3880  3898 mysqld
    3880  3899 mysqld
    3880  3900 mysqld
    3880  3901 mysqld
    3880  3902 mysqld
    3880  3911 foobarbaz
