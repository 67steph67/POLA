/**
 * @file    WRAP.h
 * @author OBERLE Stephane
 */

#ifndef _WRAP_H
#define _WRAP_H

    #include "CONTINU.h"
    #include <syslog.h>

    static int (*next_open)(const char *pathname, int flags) = NULL;
    static int (*next_opendir)(const char *name) = NULL;
    int open(const char *pathname, int flags);
    int opendir(const char *pathname);

#endif