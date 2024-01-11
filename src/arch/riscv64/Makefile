# Assembler section type character
#
ASM_TCHAR	:= @
ASM_TCHAR_OPS	:= @

# RISCV64-specific flags
#
CFLAGS		+= -mabi=lp64 -march=rv64imac_zicsr_zifencei -mcmodel=medany
CFLAGS		+= -fomit-frame-pointer
ASFLAGS		+= -mabi=lp64 -EL

# EFI requires -fshort-wchar, and nothing else currently uses wchar_t
#
CFLAGS		+= -fshort-wchar

# RISC-V-specific directories containing source files
SRCDIRS		+= arch/riscv64/core
SRCDIRS		+= arch/riscv64/interface/efi

# Include platform-specific Makefile
#
MAKEDEPS	+= arch/riscv64/Makefile.$(PLATFORM)
include arch/riscv64/Makefile.$(PLATFORM)
