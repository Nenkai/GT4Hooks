#include "Monitor.h"

int (*PDISTD_Monitor_lock)(void* monitor) = (void*)ADDR_PDISTD_Monitor_lock;
int (*PDISTD_Monitor_unlock)(void* monitor) = (void*)ADDR_PDISTD_Monitor_unlock;