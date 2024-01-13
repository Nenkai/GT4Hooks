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
