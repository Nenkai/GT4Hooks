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

1. Get [GT4ElfBuilderTool](https://github.com/Nenkai/PDTools/releases/tag/elfbuilder-1.0.0)
2. `GT4ElfBuilderTool.exe CORE.GT4 BASE_SCUS_974.36` - You should have `BASE_SCUS_974.36` after this. Copy it to the main directory.
3. Get [ps2plugininjector](https://github.com/ermaccer/ps2plugininjector/releases/tag/1.0), copy `ps2plugininjector.exe` to the main directory. 
4. Clone [ps2sdk](//github.com/ThirteenAG/ps2sdk) into `external/` such that you have `external/ps2sdk/`
5. Create `scripts` folder
6. Run `build.bat`
7. You should have `SCUS_974.36.elf`, ready for use with PCSX2.
