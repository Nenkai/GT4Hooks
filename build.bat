@echo off

del /s source\*.o
powershell external/ps2sdk/ee/bin/vsmake.ps1

if not exist BASE_SCUS_974.36 (
    print "BASE_SCUS_974.36 missing in directory, create it with PDTools.GT4ElfBuilderTool"
    exit 0
)

if exist ps2plugininjector.exe (
    ps2plugininjector.exe -i scripts/GT4Hook.elf -o SCUS_974.36.elf BASE_SCUS_974.36
) else (
    print "ps2plugininjector.exe missing in directory"
    exit 0
)

del /s source\*.o
