################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Core/Startup/startup_stm32f746nghx.s 

OBJS += \
./Core/Startup/startup_stm32f746nghx.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Startup/%.o: ../Core/Startup/%.s
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -c -I"/home/dimercur/Documents/Travail/git/voilier/code/Console-Pilotage/Drivers/BSP" -I"/home/dimercur/Documents/Travail/git/voilier/code/Console-Pilotage/Drivers/Components/Common" -I"/home/dimercur/Documents/Travail/git/voilier/code/Console-Pilotage/Drivers/Components/ft5336" -I"/home/dimercur/Documents/Travail/git/voilier/code/Console-Pilotage/Drivers/Components/n25q128a" -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/gui/include -x assembler-with-cpp --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

