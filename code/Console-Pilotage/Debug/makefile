################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include TouchGFX/target/generated/subdir.mk
-include TouchGFX/target/subdir.mk
-include TouchGFX/gui/src/rotationvoilier_screen/subdir.mk
-include TouchGFX/gui/src/model/subdir.mk
-include TouchGFX/gui/src/messages_screen/subdir.mk
-include TouchGFX/gui/src/common/subdir.mk
-include TouchGFX/gui/src/choixcanal_screen/subdir.mk
-include TouchGFX/generated/texts/src/subdir.mk
-include TouchGFX/generated/images/src/subdir.mk
-include TouchGFX/generated/gui_generated/src/rotationvoilier_screen/subdir.mk
-include TouchGFX/generated/gui_generated/src/messages_screen/subdir.mk
-include TouchGFX/generated/gui_generated/src/common/subdir.mk
-include TouchGFX/generated/gui_generated/src/choixcanal_screen/subdir.mk
-include TouchGFX/generated/fonts/src/subdir.mk
-include TouchGFX/App/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/subdir.mk
-include Drivers/STM32F7xx_HAL_Driver/Src/subdir.mk
-include Drivers/INSA/services/common/subdir.mk
-include Drivers/INSA/services/subdir.mk
-include Drivers/INSA/drivers/subdir.mk
-include Drivers/Components/ft5336/subdir.mk
-include Drivers/BSP/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Console-Pilotage.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Console-Pilotage.list \

OBJCOPY_BIN += \
Console-Pilotage.bin \


# All Target
all: Console-Pilotage.elf secondary-outputs

# Tool invocations
Console-Pilotage.elf: $(OBJS) $(USER_OBJS) /home/dimercur/Documents/Travail/git/voilier/code/Console-Pilotage/STM32F746NGHX_FLASH.ld
	arm-none-eabi-g++ -o "Console-Pilotage.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m7 -T"/home/dimercur/Documents/Travail/git/voilier/code/Console-Pilotage/STM32F746NGHX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Console-Pilotage.map" -Wl,--gc-sections -static -L"/home/dimercur/Documents/Travail/git/voilier/code/Console-Pilotage/Middlewares/ST/touchgfx/lib/core/cortex_m7/gcc" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -lstdc++ -lsupc++ -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Console-Pilotage.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Console-Pilotage.list"
	@echo 'Finished building: $@'
	@echo ' '

Console-Pilotage.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Console-Pilotage.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
