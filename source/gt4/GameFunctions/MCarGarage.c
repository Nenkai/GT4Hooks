#include "MCarGarage.h"

float (*QUICK_MENU_GetGTPerformanceIndex)(CarGarage* car) = (void*)ADDR_QUICK_MENU_GetGTPerformanceIndex;
void (*MCarGarage_MCarGarage)() = (void*)ADDR_MCarGarage_MCarGarage;
void (*MCarGarage_dtor)(MCarGarage* mCar, int flag) = (void*)ADDR_MCarGarage_dtor;
CarGarage* (*mCarGarage_getCarGarage)(MCarGarage* mCar) = (void*)ADDR_mCarGarage_getCarGarage;