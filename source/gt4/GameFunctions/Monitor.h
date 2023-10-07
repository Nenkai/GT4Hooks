#pragma once

#define ADDR_PDISTD_Monitor_lock 0x522E78
#define ADDR_PDISTD_Monitor_unlock 0x522EE8

extern int (*PDISTD_Monitor_lock)(void* monitor);
extern int (*PDISTD_Monitor_unlock)(void* monitor);