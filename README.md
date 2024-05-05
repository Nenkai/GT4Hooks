# GT4Hooks

Gran Turismo 4 Online (US) code hooks using [PS2 Plugin Injector](https://github.com/ermaccer/ps2plugininjector)

## Features

* HostFS - Loading files loose (except sound/movie files)
* Class `HOutput` (which is stripped in release builds) was reimplemented to print debug messages
* `CameraSys::CameraOnBoard::GetCameraMountIndex` edited to add three new cameras
* Implemented adhoc method `mStorageMC::getFileSize` to proper save/load files from adhoc from memory card
* Added new adhoc method `mCarGarage::getPerformanceIndex`  to get the performance index of a car

## Note

Game memsets 32mb of ram when starting, refer to `BASE_ADDRESS` comment in makefile & NOP in main

## Building

```
git clone https://github.com/Nenkai/GT4Hooks
cd GT4Hooks
mkdir external
cd external
git clone https://github.com/ThirteenAG/ps2sdk
cd ps2sdk
git checkout fcb813152116579e7a44e800d64e17185f4c27b5 .
cd ../..
```

Then:
1. Get [GT4ElfBuilderTool](https://github.com/Nenkai/PDTools/releases/tag/elfbuilder-1.0.0)
2. `GT4ElfBuilderTool.exe CORE.GT4 BASE_SCUS_974.36` - You should have `BASE_SCUS_974.36` after this. Copy it to the main directory.
3. Get [ps2plugininjector](https://github.com/ermaccer/ps2plugininjector/releases/tag/1.0), copy `ps2plugininjector.exe` to the main directory. 
4. `build`
5. You should have `SCUS_974.36.elf`, ready for use with PCSX2.

When using it with PCSX2, ensure to link the original iso to the executable (Properties -> Disc Path).

You may also need to re-enable HostFS in Emulation -> Enable Host Filesystem everytime you rebuild the elf (different hash).

NOTE: If you get `Unable to initialize device PRN` when building, make sure that `ps2plugininjector.exe` & `BASE_SCUS_974.36` are present. 