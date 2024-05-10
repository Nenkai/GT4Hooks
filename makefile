EE_BIN = scripts/GT4Hook.elf
EE_OBJS = source\main.o \
source\ps2\Memory.o \
source\gt4\HostFs.o \
source\gt4\HOutput.o \
source\gt4\CameraSys.o \
source\gt4\Adhoc.o \
source\gt4\MStorage.o \
source\gt4\MCarGarage.o \
source\gt4\GameFunctions\IO.o \
source\gt4\GameFunctions\FileDevice.o \
source\gt4\GameFunctions\String.o \
source\gt4\GameFunctions\Adhoc.o \
source\gt4\GameFunctions\MStorage.o \
source\gt4\GameFunctions\MCarGarage.o \
source\gt4\GameFunctions\Monitor.o \
source\gt4\GameFunctions\PolyphonyGL.o \
source\gt4\Utils\String.o \
source\gt4\Adhoc\Decl.o \
source\gt4\Adhoc\MMyModule.o \

#####################################################
# GT4 Hooks Configuration
#####################################################

# Whether to print any host fs messages
HOSTFS_PRINT = 1

# Whether to print actual file reads. Otherwise just accesses.
PRINT_HOSTFS_READS = 0

USE_DEV_RAM = 0

# So, where do we put the new code?
# We need to our code in an area of memory that seems safe enough and won't be read from other places.

# Initially I wanted to put my code before 0x100000, which is the image base for GT4O.
# Setting it to 0x80000 crashes when the hook gets past 0x82000... 

# The game creates pool/generic allocator (func 0x5225B0) from 0x8D0FB0 (start of .bss), size 0x1FF8000 (32mb?) before 
# main is called. It'll be memset'd to 0 entirely
# We wipe the memset call just incase we ever need to put stuff in it. main.c should be doing this.
# They probably did this for hot-reloading, which is not supported here.

BASE_ADDRESS = 0x68A480
# ^^^^^^^^^^^^^^^^^^^^^^
# This is the static global for wnn_globals_init aka the fep/wnn system ('fep' game folder)
# (https://socialsolution.omron.com/software/en/products/product_text/iwnn/)
# Aka japanese wnn keyboard layout handling by omron? Appears completely unused. Proof:
# -> LoadFep @ 0x1058D0 <<<< No xrefs!
#   -> PDISTD::InitFep @ 0x45A0F8
#     -> InitWnn @ 0x56FBF0
#
# This is ok to override, this is not used in GT4O.
# Goes from 0x68A480 to 0x69A790. Plenty of space. (0x10310)

#####################################################

NEWLIB_NANO = 1
KERNEL_NOPATCH = 1

EE_LINKFILE = linkfile

EE_CFLAGS =  -fno-zero-initialized-in-bss -O0 -DHOSTFS_PRINT=${HOSTFS_PRINT} 
EE_LDFLAGS = -Wl,--entry=INVOKER -Wl,-Map,scripts/GT4Hook.map -Wl,'--defsym=BASE_ADDRESS=$(BASE_ADDRESS)' -ffunction-sections -Wl,--gc-sections -fdata-sections

all: $(EE_BIN)

PS2SDK = external/ps2sdk/ps2sdk
include $(PS2SDK)/samples/Makefile.pref
include eemakefile.eeglobal
