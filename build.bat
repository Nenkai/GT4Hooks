@echo off

del /s source\*.o

mkdir scripts
powershell external/ps2sdk/ee/bin/vsmake.ps1

if not exist BASE_SCUS_974.36 (
    print "BASE_SCUS_974.36 missing in directory, create it with PDTools.GT4ElfBuilderTool"
    exit /B 0
)

if exist ps2plugininjector.exe (
    ps2plugininjector.exe -i scripts/GT4Hook.elf -o SCUS_974.36.elf BASE_SCUS_974.36
) else (
    print "ps2plugininjector.exe missing in directory"
    exit /B 0
)

:: Print elf size for memory space reasons
set dec = 0
set hex = 0
call :filesize scripts/GT4Hook.elf
call :toHex dec hex
echo Elf Size is 0x%hex% bytes

del /s source\*.o

:: Set filesize of first argument in %dec% variable, and return
:filesize
  set dec=%~z1
  exit /b 0
  
:toHex dec hex -- convert a decimal number to hexadecimal, i.e. -20 to FFFFFFEC or 26 to 0000001A
::             -- dec [in]      - decimal number to convert
::             -- hex [out,opt] - variable to store the converted hexadecimal number in
::Thanks to 'dbenham' dostips forum users who inspired to improve this function
:$created 20091203 :$changed 20110330 :$categories Arithmetic,Encoding
:$source https://www.dostips.com
SETLOCAL ENABLEDELAYEDEXPANSION
set /a dec=%~1
set "hex="
set "map=0123456789ABCDEF"
for /L %%N in (1,1,8) do (
    set /a "d=dec&15,dec>>=4"
    for %%D in (!d!) do set "hex=!map:~%%D,1!!hex!"
)
rem !!!! REMOVE LEADING ZEROS by activating the next line, e.g. will return 1A instead of 0000001A
rem for /f "tokens=* delims=0" %%A in ("%hex%") do set "hex=%%A"&if not defined hex set "hex=0"
( ENDLOCAL & REM RETURN VALUES
    IF "%~2" NEQ "" (SET %~2=%hex%) ELSE ECHO.%hex%
)
EXIT /b
