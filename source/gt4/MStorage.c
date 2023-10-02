#include <stdio.h>

#include "MStorage.h"
#include "..\ps2\Memory.h"
#include "Utils\String.h"

#include "GameFunctions\String.h"
#include "GameFunctions\MStorage.h"
#include "GameFunctions\IO.h"

/* Hook: MStorage
   Purpose: Allows reading files from memory card from adhoc.
   How: Fixes MStorageMC::getFileSize being unimplemented so that MStorage::read works (which uses it)
   Adhoc Usage:
     #define STORAGE_HD 0
     #define STORAGE_MC 1

     var storage = main::menu::MStorage::getStorage(STORAGE_MC);
     var str = storage.read("/BASCUS-97436GAMEDATA/file.txt");
     print "%{str}\n";
*/

void MStorage_InstallHooks()
{
    HOOK(ADDR_mStorageMC_getFileSize, &HOOK__mStorageMC_getFileSize);
}

int HOOK__mStorageMC_getFileSize(void* this, char* name)
{
    int cmd, result;

    char copy[128];
    __strcpy(copy, name);
    char* dir = _dirname(copy);

    char mcDir[128];
    _sprintf(mcDir, "%s/*", dir);

    sceMcTblGetDir table[10];
    sceMcGetDir(0, 0, mcDir, 0, 10, table);
    int res = sceMcSync(0, &cmd, &result);

    //_print("mStorageMC::getFileSize: sceMcSync name=%s, res=%d\n", name, result);

    if (res < 0)
        return -1;

    char* fileName = get_file_name(name);
    for (int i = 0; i < result; i++)
    {
        sceMcTblGetDir* entry = &table[i];
        //_print("name=%s, size=%x\n", entry->EntryName, entry->FileSizeByte);

        if (!__strcmp(entry->EntryName, fileName))
            return entry->FileSizeByte;
    }

    // Not found
    return -1;
}