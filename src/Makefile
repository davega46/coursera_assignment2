#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Purpose: A Makefile that can natively and cross compile an application.
# 	   Supported platforms: HOST (Linux) and cross platform (ARM)
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <FILE>.i - Generates <FILE>.i preprocessed output files
#      <FILE>.asm - Generates <FILE>.asm assembly output files
#      <FILE>.o - Generates <FILE>.o object files
#      <FILE>.d - Generates <FILE>.d dependency files
#
#      compile-all - Compiles all object files. Does NOT link.
#      build - Compiles all object files and links into a final executable.
#      clean - Removes all compiled objects, preprocessed outputs, assembly outputs,
#      	       executable files and build output files.
#
# Platform Overrides:
#      CPU - ARM Cortex Architecture (cortex-m0plus, cortex-m4)
#      ARCH - ARM Architecture (arm, thumb)
#      SPECS - Specs file to give the linker (nosys.specs, nano.specs)
#
#------------------------------------------------------------------------------
include sources.mk

#Defining all variables
# Platform Overrides
PLATFORM = HOST

# Architectures Specific Flags
LINKER_FILE =../msp432p401r.lds
CPU = cortex-m4
ARCH = thumb
SPECS = nosys.specs
ARCHFLAGS = -mcpu=$(CPU) -m$(ARCH) -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=$(SPECS)
# Compiler Flags and Defines
CC = gcc
LD = ld
LDFLAGS = -Wl,-Map=$(TARGET).map
CFLAGS = -Wall -Werror -g -O0 -std=c99 -D$(PLATFORM)
# -D is used at command line to define stuff.
CPPFLAGS = -E
TARGET = c1m2

SIZE = size
OBJDUMP = objdump

ifeq ($(PLATFORM), MSP432)
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	CFLAGS = -Wall -Werror -g -O0 -std=c99 -D$(PLATFORM) $(ARCHFLAGS)
	LDFLAGS = -Wl,-Map=$(TARGET).map -T$(LINKER_FILE)

	SIZE = arm-none-eabi-size
	OBJDUMP = arm-none-eabi-objdump
endif

# Start of Target list

# Method of tracking generated object files. For every *.c file associate a *.o file with the same name.
# Goes through every word in SOURCES list and replaces any *.c ending with *.o ending.

PREPRC = $(SOURCES:.c=.i)
ASSY = $(SOURCES:.c=.asm)
OBJS = $(SOURCES:.c=.o)

DEPS = $(SOURCES:.c=.d)

# Pattern Matching - Matches target object rule with an associated source file
# $@ is target. $^ - All prerequisites. Are known as automatic variables that within the scope of recipe.
# $@ - The filename of target of rule. In this case, it is the name of whichever target casued the rule's recipe to run.
# $< - The name of the first prerequisite. If target got recipe from implicit rule, then this is the 1st prerequisite added by implicit rule# 

%.i: %.c
	$(CC) $(INCLUDES) $(CPPFLAGS) $< $(CFLAGS) -o $@

%.asm: %.c
	$(CC) $(INCLUDES) -S $< $(CFLAGS) -o $@

%.o: %.c
	$(CC) $(INCLUDES) -c $< $(CFLAGS) -o $@
	
%.d: %.c
	$(CC) $(INCLUDES) -M $< $(CFLAGS) -o $@


# Target required for assembly output of implementations files + final output executable
$(TARGET).asm: $(TARGET).out
	$(OBJDUMP) -d $(TARGET).out >> $@

# Target required for the .PHONY build target
# Also includes GNU size utility to display sizes of compiled sections inside of onject file and executable file outputs.
$(TARGET).out: $(OBJS) $(DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) $(LDFLAGS) -o $@ $(OBJS)
	$(SIZE) $(TARGET).out
	$(SIZE) -Atd $(TARGET).out


# .PHONY directives - For nonfile targets.
.PHONY: compile-all
compile-all: $(OBJS)
	$(CC) $(INCLUDES) $(OBJS) -c $(CLFAGS) - o $(TARGET).o

.PHONY: build
build: $(TARGET).out

.PHONY: clean
clean:
	rm -f *.asm *.out *.map *.i *.o *.d

# Clean command didn't work: rm -f $(TARGET).asm $(TARGET).out $(TARGET).map $(PREPRC) $(ASSY) $(OBJS) $(DEPS)
