EE_BIN = scripts/GT4Hook.elf
EE_OBJS = source\main.o \
source\ps2\Memory.o \
source\gt4\HostFs.o \

NEWLIB_NANO = 1
KERNEL_NOPATCH = 1

BASE_ADDRESS = 0x80000
EE_LINKFILE = linkfile

EE_CFLAGS =  -fno-zero-initialized-in-bss
EE_LDFLAGS = -Wl,--entry=INVOKER -Wl,-Map,scripts/GT4Hook.map -Wl,'--defsym=BASE_ADDRESS=$(BASE_ADDRESS)'

all: $(EE_BIN)

PS2SDK = external/ps2sdk/ps2sdk
include $(PS2SDK)/samples/Makefile.pref
include eemakefile.eeglobal
