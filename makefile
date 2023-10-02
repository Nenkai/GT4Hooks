EE_BIN = scripts/GT4Hook.elf
EE_OBJS = source\main.o \
source\ps2\Memory.o \
source\gt4\HostFs.o \
source\gt4\HOutput.o \
source\gt4\CameraSys.o \
source\gt4\Adhoc.o \
source\gt4\GameFunctions\IO.o \
source\gt4\GameFunctions\FileDevice.o \
source\gt4\GameFunctions\String.o \
source\gt4\GameFunctions\Adhoc.o \
source\gt4\Utils\String.o \
source\gt4\Adhoc\Decl.o \
source\gt4\Adhoc\MMyModule.o \

HOSTFS_PRINT = 1
PRINT_HOSTFS_READS = 0

NEWLIB_NANO = 1
KERNEL_NOPATCH = 1

BASE_ADDRESS = 0x80000
EE_LINKFILE = linkfile

EE_CFLAGS =  -fno-zero-initialized-in-bss -O0 -DHOSTFS_PRINT=${HOSTFS_PRINT} 
EE_LDFLAGS = -Wl,--entry=INVOKER -Wl,-Map,scripts/GT4Hook.map -Wl,'--defsym=BASE_ADDRESS=$(BASE_ADDRESS)' -ffunction-sections -Wl,--gc-sections -fdata-sections

all: $(EE_BIN)

PS2SDK = external/ps2sdk/ps2sdk
include $(PS2SDK)/samples/Makefile.pref
include eemakefile.eeglobal
