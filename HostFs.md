# Enabling HostFS

## QT PCSX2

1. Add search directory to the ELF file
2. Actually rename the elf file to have the elf extension to show up i.e SCUS_974.36.elf
3. Right click on the elf entry, properties
4. Summary -> Disc Path -> Browse -> Select ISO file
5. Emulation -> Tick "Enable Host Filesystem"

## Non-QT PCSX2

First select your ISO file
* CDVD -> ISO Selector -> ...

Then, boot through the ELF file (important!)
* System -> Run ELF... -> SCUS_974.36 (example)