################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/TI/ccsv6/tools/compiler/arm_15.12.3.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./infrastructure.obj" \
"./main.obj" \
"./INS/INS.obj" \
"./INS/kalman_filter.obj" \
"./INS/matrix_manipulation.obj" \
"./Sensors/ADXL345.obj" \
"./Sensors/GPS.obj" \
"./Sensors/HMC5883.obj" \
"./Sensors/ITG3200.obj" \
"./Sensors/MPL115A2.obj" \
"./board/DS2401.obj" \
"./board/SD_card.obj" \
"./board/board.obj" \
"./board/pinmux.obj" \
"./common/button_if.obj" \
"./common/gpio_if.obj" \
"./common/i2c_if.obj" \
"./common/i2s_if.obj" \
"./common/network_common.obj" \
"./common/network_if.obj" \
"./common/startup_ccs.obj" \
"./common/timer_if.obj" \
"./common/uart_if.obj" \
"./common/utils_if.obj" \
"./common/wdt_if.obj" \
"./interfaces/diskio.obj" \
"./interfaces/local_i2c_if.obj" \
"./interfaces/local_uart_if.obj" \
"./interfaces/terninal.obj" \
"../cc3200v1p32.cmd" \
$(GEN_CMDS__FLAG) \
-llibc.a \
-l"C:/TI/CC3200SDK_1.2.0/cc3200-sdk/simplelink/ccs/NON_OS/simplelink.a" \
-l"C:/TI/CC3200SDK_1.2.0/cc3200-sdk/third_party/fatfs/ccs/Release/fatfs.a" \
-l"C:/TI/CC3200SDK_1.2.0/cc3200-sdk/netapps/json/ccs/Release/json.a" \
-l"C:/TI/CC3200SDK_1.2.0/cc3200-sdk/driverlib/ccs/Release/driverlib.a" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include INS/subdir_vars.mk
-include Sensors/subdir_vars.mk
-include board/subdir_vars.mk
-include common/subdir_vars.mk
-include interfaces/subdir_vars.mk
-include subdir_rules.mk
-include INS/subdir_rules.mk
-include Sensors/subdir_rules.mk
-include board/subdir_rules.mk
-include common/subdir_rules.mk
-include interfaces/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
GPS-INS-NAV.out \

EXE_OUTPUTS__QUOTED += \
"GPS-INS-NAV.out" \

BIN_OUTPUTS += \
GPS-INS-NAV.bin \

BIN_OUTPUTS__QUOTED += \
"GPS-INS-NAV.bin" \


# All Target
all: GPS-INS-NAV.out

# Tool invocations
GPS-INS-NAV.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: ARM Linker'
	"C:/TI/ccsv6/tools/compiler/arm_15.12.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=vfplib -me -g --define=cc3200 --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi -z -m"GPS-INS-NAV.map" --stack_size=0x512 --heap_size=0x8000 -i"C:/TI/ccsv6/tools/compiler/arm_15.12.3.LTS/lib" -i"C:/Project A/workspace/sdhost_fatfs" -i"C:/TI/ccsv6/tools/compiler/arm_15.12.3.LTS/include" --reread_libs --warn_sections --diag_wrap=off --display_error_number --xml_link_info="GPS-INS-NAV_linkInfo.xml" --rom_model -o "GPS-INS-NAV.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

GPS-INS-NAV.bin: $(EXE_OUTPUTS)
	@echo 'Invoking: ARM Hex Utility'
	"C:/TI/ccsv6/tools/compiler/arm_15.12.3.LTS/bin/armhex"  -o "GPS-INS-NAV.bin" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)$(BIN_OUTPUTS__QUOTED)
	-$(RM) "infrastructure.d" "main.d" "INS\INS.d" "INS\kalman_filter.d" "INS\matrix_manipulation.d" "Sensors\ADXL345.d" "Sensors\GPS.d" "Sensors\HMC5883.d" "Sensors\ITG3200.d" "Sensors\MPL115A2.d" "board\DS2401.d" "board\SD_card.d" "board\board.d" "board\pinmux.d" "common\button_if.d" "common\gpio_if.d" "common\i2c_if.d" "common\i2s_if.d" "common\network_common.d" "common\network_if.d" "common\startup_ccs.d" "common\timer_if.d" "common\uart_if.d" "common\utils_if.d" "common\wdt_if.d" "interfaces\diskio.d" "interfaces\local_i2c_if.d" "interfaces\local_uart_if.d" "interfaces\terninal.d" 
	-$(RM) "infrastructure.obj" "main.obj" "INS\INS.obj" "INS\kalman_filter.obj" "INS\matrix_manipulation.obj" "Sensors\ADXL345.obj" "Sensors\GPS.obj" "Sensors\HMC5883.obj" "Sensors\ITG3200.obj" "Sensors\MPL115A2.obj" "board\DS2401.obj" "board\SD_card.obj" "board\board.obj" "board\pinmux.obj" "common\button_if.obj" "common\gpio_if.obj" "common\i2c_if.obj" "common\i2s_if.obj" "common\network_common.obj" "common\network_if.obj" "common\startup_ccs.obj" "common\timer_if.obj" "common\uart_if.obj" "common\utils_if.obj" "common\wdt_if.obj" "interfaces\diskio.obj" "interfaces\local_i2c_if.obj" "interfaces\local_uart_if.obj" "interfaces\terninal.obj" 
	-@echo 'Finished clean'
	-@echo ' '

post-build:
	-"C:/TI/ccsv6/utils/tiobj2bin/tiobj2bin" "GPS-INS-NAV.out" "GPS-INS-NAV.bin" "C:/TI/ccsv6/tools/compiler/arm_15.12.3.LTS/bin/armofd" "C:/TI/ccsv6/tools/compiler/arm_15.12.3.LTS/bin/armhex" "C:/TI/ccsv6/utils/tiobj2bin/mkhex4bin"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets

