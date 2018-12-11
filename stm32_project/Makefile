# STM32F103 Makefile模板
# 参考来源：
# https://github.com/andytt/stm32_template
# https://github.com/latelee/Makefile_templet
# 使用：
# make         #默认编译：调试版本，不输出详细编译过程
# make debug=n # release版本，不输出详细编译过程 
# make V=1     # 调试版本，输出详细编译过程
# make debug=n V=1 # release版本，输出详细编译过程 
#
# 为加快编译，make可加“-j”选项。
# 可能需要修改的地方使用“!!!===”标示出来
# log:
# 2018.12.10: 首版完成
################################################

#!!!=== 交叉编译器
CROSS_COMPILE = arm-none-eabi-
CC  = $(CROSS_COMPILE)gcc
AS  = $(CROSS_COMPILE)gcc -x assembler-with-cpp
CP  = $(CROSS_COMPILE)objcopy
AR  = $(CROSS_COMPILE)ar
SZ  = $(CROSS_COMPILE)size
HEX = $(CP) -O ihex
BIN = $(CP) -O binary -S

MKDIR_P ?= mkdir -p

#!!!=== 目标文件名，注：下面会生成$(target).hex等文件
target = target

#!!!=== 是否调试版本，如是，设置为y，反之，为n
debug  = y

#!!!=== 编译目录
BUILD_DIR = build

#!!!=== 头文件目录，需要一个一个列出目录名称
INC = CORE FWLIB/inc HARDWARE SYSTEM USER
INCDIRS := $(addprefix -I, $(INC))

######################################
# C源码文件
#注：find会递归查找项目目录所有.c文件，如c文件不必要，则要删除，否则可能会编译出错
C_SOURCES =  $(shell find ./ -name '*.c')

#!!!=== 启动汇编文件
ASM_SOURCES = startup_stm32f103xb.s
# TODO：其它目录在此列出

# float-abi 如不支持，则不填写
FLOAT-ABI = 
FPU = 

# 目标芯片特有编译指令
MCU = -mcpu=cortex-m3 -mthumb $(FPU) $(FLOAT-ABI)

# c编译标志
CFLAGS = $(MCU) $(DEFS) $(INCDIRS) -Wall  -Wfatal-errors -MMD -fdata-sections -ffunction-sections
ASFLAGS = $(CFLAGS) $(AS_DEFS)

# debug或release版本选择
ifeq ($(debug), y)
    CFLAGS += -g -gdwarf-2
else
    CFLAGS += -O2 -s # 或者-Og
endif

# AS宏定义
AS_DEFS = 

#!!!=== C宏定义
DEFS_STR += STM32F103X_MD USE_STDPERIPH_DRIVER
DEFS     := $(addprefix -D, $(DEFS_STR))

#!!!=== 链接脚本文件
LDSCRIPT = STM32F103R8Tx_FLASH.ld

#!!!=== 静态库名称
LIBS = -lc -lm -lnosys 
# 其它库目录
LIBDIR = 
# 链接标志
LDFLAGS = $(MCU) -specs=nano.specs -T$(LDSCRIPT) $(LIBDIR) $(LIBS) \
          -Wl,-Map=$(BUILD_DIR)/$(target).map,--cref -Wl,--gc-sections

ifeq ($(V),1)
Q=
NQ=true
else
Q=@
NQ=echo
endif

# default action: build all
all: $(BUILD_DIR)/$(target).elf $(BUILD_DIR)/$(target).hex $(BUILD_DIR)/$(target).bin

#######################################
## 目标文件规则（由.c .s产生.o的规则）
OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(C_SOURCES:.c=.o)))
vpath %.c $(sort $(dir $(C_SOURCES)))
OBJECTS += $(addprefix $(BUILD_DIR)/,$(notdir $(ASM_SOURCES:.s=.o)))
vpath %.s $(sort $(dir $(ASM_SOURCES)))

DEPS := $(OBJECTS:.o=.d)

# 编译.c .s文件
$(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR)
	@$(NQ) "Compiling: " $(basename $(notdir $@)).c
	$(Q)$(CC) -c $(CFLAGS) -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.c=.lst)) $< -o $@

$(BUILD_DIR)/%.o: %.s Makefile | $(BUILD_DIR)
	@$(NQ) "Compiling: " $(basename $(notdir $@)).s
	$(Q)$(AS) -c $(CFLAGS) $< -o $@

# 生成elf hex bin文件
$(BUILD_DIR)/$(target).elf: $(OBJECTS) Makefile
	@$(NQ) "Generating elf file..." $(notdir $@)
	$(Q)$(CC) $(OBJECTS) $(LDFLAGS) -o $@
	$(SZ) $@

$(BUILD_DIR)/%.hex: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	@$(NQ) "Generating hex file..." $(notdir $@)
	$(Q)$(HEX) $< $@
	$(Q)mv $@ .
	
$(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	@$(NQ) "Generating bin file..." $(notdir $@)
	$(Q)$(BIN) $< $@	
	$(Q)mv $@ .

$(BUILD_DIR):
	mkdir $@		

## 清理文件
clean:
	-rm -fR .dep $(BUILD_DIR)
	@find . -iname '*.o' -o -iname '*.bak' -o -iname '*.d' | xargs rm -f

## 烧录命令
flash:
	st-flash write $(BUILD_DIR)/$(target).bin 0x8000000
## 擦除命令
erase:
	st-flash erase

.PHONY: all clean flash erase

## 依赖文件
-include $(DEPS)
