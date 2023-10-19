################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Components/ft5336/ft5336.c 

OBJS += \
./Drivers/Components/ft5336/ft5336.o 

C_DEPS += \
./Drivers/Components/ft5336/ft5336.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Components/ft5336/ft5336.o: ../Drivers/Components/ft5336/ft5336.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DDEBUG -c -I../Middlewares/Third_Party/FreeRTOS/Source/include -I"/home/dimercur/Documents/Travail/git/voilier/code/Console-Pilotage/Drivers/INSA/drivers" -I"/home/dimercur/Documents/Travail/git/voilier/code/Console-Pilotage/Drivers/INSA/services" -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../TouchGFX/target/generated -I../Drivers/CMSIS/Include -I../Core/Inc -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../TouchGFX/App -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../TouchGFX/target -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/gui/include -I"/home/dimercur/Documents/Travail/git/voilier/code/Console-Pilotage/Drivers/BSP" -I"/home/dimercur/Documents/Travail/git/voilier/code/Console-Pilotage/Drivers/Components/Common" -I"/home/dimercur/Documents/Travail/git/voilier/code/Console-Pilotage/Drivers/Components/ft5336" -I"/home/dimercur/Documents/Travail/git/voilier/code/Console-Pilotage/Drivers/Components/n25q128a" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/Components/ft5336/ft5336.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

