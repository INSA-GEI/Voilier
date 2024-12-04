################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/target/STM32TouchController.cpp \
../TouchGFX/target/TouchGFXGPIO.cpp \
../TouchGFX/target/TouchGFXHAL.cpp 

OBJS += \
./TouchGFX/target/STM32TouchController.o \
./TouchGFX/target/TouchGFXGPIO.o \
./TouchGFX/target/TouchGFXHAL.o 

CPP_DEPS += \
./TouchGFX/target/STM32TouchController.d \
./TouchGFX/target/TouchGFXGPIO.d \
./TouchGFX/target/TouchGFXHAL.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/target/STM32TouchController.o: ../TouchGFX/target/STM32TouchController.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DDEBUG -c -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I"/home/dimercur/Documents/Travail/git/voilier/code/Console-Pilotage/Drivers/INSA/drivers" -I"/home/dimercur/Documents/Travail/git/voilier/code/Console-Pilotage/Drivers/INSA/services" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../TouchGFX/target/generated -I../Drivers/CMSIS/Include -I../Core/Inc -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../TouchGFX/App -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../TouchGFX/target -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/gui/include -I"/home/dimercur/Documents/Travail/git/voilier/code/Console-Pilotage/Drivers/BSP" -I"/home/dimercur/Documents/Travail/git/voilier/code/Console-Pilotage/Drivers/Components/Common" -I"/home/dimercur/Documents/Travail/git/voilier/code/Console-Pilotage/Drivers/Components/ft5336" -I"/home/dimercur/Documents/Travail/git/voilier/code/Console-Pilotage/Drivers/Components/n25q128a" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"TouchGFX/target/STM32TouchController.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
TouchGFX/target/TouchGFXGPIO.o: ../TouchGFX/target/TouchGFXGPIO.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DDEBUG -c -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I"/home/dimercur/Documents/Travail/git/voilier/code/Console-Pilotage/Drivers/INSA/drivers" -I"/home/dimercur/Documents/Travail/git/voilier/code/Console-Pilotage/Drivers/INSA/services" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../TouchGFX/target/generated -I../Drivers/CMSIS/Include -I../Core/Inc -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../TouchGFX/App -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../TouchGFX/target -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/gui/include -I"/home/dimercur/Documents/Travail/git/voilier/code/Console-Pilotage/Drivers/BSP" -I"/home/dimercur/Documents/Travail/git/voilier/code/Console-Pilotage/Drivers/Components/Common" -I"/home/dimercur/Documents/Travail/git/voilier/code/Console-Pilotage/Drivers/Components/ft5336" -I"/home/dimercur/Documents/Travail/git/voilier/code/Console-Pilotage/Drivers/Components/n25q128a" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"TouchGFX/target/TouchGFXGPIO.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
TouchGFX/target/TouchGFXHAL.o: ../TouchGFX/target/TouchGFXHAL.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DDEBUG -c -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I"/home/dimercur/Documents/Travail/git/voilier/code/Console-Pilotage/Drivers/INSA/drivers" -I"/home/dimercur/Documents/Travail/git/voilier/code/Console-Pilotage/Drivers/INSA/services" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../TouchGFX/target/generated -I../Drivers/CMSIS/Include -I../Core/Inc -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../TouchGFX/App -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../TouchGFX/target -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/gui/include -I"/home/dimercur/Documents/Travail/git/voilier/code/Console-Pilotage/Drivers/BSP" -I"/home/dimercur/Documents/Travail/git/voilier/code/Console-Pilotage/Drivers/Components/Common" -I"/home/dimercur/Documents/Travail/git/voilier/code/Console-Pilotage/Drivers/Components/ft5336" -I"/home/dimercur/Documents/Travail/git/voilier/code/Console-Pilotage/Drivers/Components/n25q128a" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"TouchGFX/target/TouchGFXHAL.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

