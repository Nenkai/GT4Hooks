#pragma once

#include "..\GameStructs\Adhoc.h"

#define ADDR_QUICK_MENU_GetGTPerformanceIndex 0x10D598
#define ADDR_MCarGarage_MCarGarage 0x12A008
#define ADDR_MCarGarage_dtor 0x129FB0
#define ADDR_mCarGarage_getCarGarage 0x133F28

extern float (*QUICK_MENU_GetGTPerformanceIndex)(CarGarage* car);
extern void (*MCarGarage_MCarGarage)();
extern void (*MCarGarage_dtor)(MCarGarage* mCar, int flag);
extern CarGarage* (*mCarGarage_getCarGarage)(MCarGarage* mCar);