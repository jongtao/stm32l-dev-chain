
# Put your stlink folder here so make burn will work.
STLINK=/stlink.git

# Put your source files here (or *.c, etc)
SRCS=main.c system_stm32l1xx.c

# Binaries will be generated with this name (.elf, .bin, .hex, etc)
PROJ_NAME=blinky

# Put your STM32L1 library code directory here
STM_COMMON=../STM32L1xx_StdPeriph_Lib_V1.2.0

# Put your compiler directory here (can be blank if compiler is already in PATH)
TOOL=

# Normally you shouldn't need to change anything below this line!
#######################################################################################

CC=$(TOOL)arm-none-eabi-gcc
OBJCOPY=$(TOOL)arm-none-eabi-objcopy

CFLAGS  = -g -O2 -Wall -Tstm32_flash.ld 
CFLAGS += -mlittle-endian -mthumb -mcpu=cortex-m4 -mthumb-interwork
CFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16

CFLAGS += -I.

# Include files from STM libraries
CFLAGS += -I$(STM_COMMON)/Utilities/STM32_EVAL/STM32L152_EVAL
CFLAGS += -I$(STM_COMMON)/Libraries/CMSIS/Include
CFLAGS += -I$(STM_COMMON)/Libraries/CMSIS/Device/ST/STM32L1xx/Include
CFLAGS += -I$(STM_COMMON)/Libraries/STM32L1xx_StdPeriph_Driver/inc

CFLAGS += -I$(STM_COMMON)/Utilities/STM32_EVAL/Common

# add startup file to build
SRCS += $(STM_COMMON)/Libraries/CMSIS/Device/ST/STM32L1xx/Source/Templates/TrueSTUDIO/startup_stm32l1xx_md.s
OBJS = $(SRCS:.c=.o)


.PHONY: proj

all: proj

proj: $(PROJ_NAME).elf

$(PROJ_NAME).elf: $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@ 
	$(OBJCOPY) -O ihex $(PROJ_NAME).elf $(PROJ_NAME).hex
	$(OBJCOPY) -O binary $(PROJ_NAME).elf $(PROJ_NAME).bin

clean:
	rm -f *.o $(PROJ_NAME).elf $(PROJ_NAME).hex $(PROJ_NAME).bin

# Flash the STM32F4
burn: proj
	$(STLINK)/st-flash write $(PROJ_NAME).bin 0x8000000
