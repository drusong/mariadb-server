/* -*- mode: C; c-basic-offset: 4 -*- */
#ident "Copyright (c) 2007, 2008 Tokutek Inc.  All rights reserved."

#include "includes.h"

#define dname __FILE__ ".dir"
#define rmrf "rm -rf " dname "/"

// create and close, making sure that everything is deallocated properly.

int main (int argc __attribute__((__unused__)),
	  char *argv[] __attribute__((__unused__))) {
    int r;
    system(rmrf);
    r = toku_os_mkdir(dname, S_IRWXU);    assert(r==0);
    TOKULOGGER logger;
    r = toku_logger_create(&logger);
    assert(r == 0);
    r = toku_logger_close(&logger);
    assert(r == 0);
    return 0;
}
