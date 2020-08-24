################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Drivers/INSA/services/common/Message.cpp \
../Drivers/INSA/services/common/Service.cpp 

OBJS += \
./Drivers/INSA/services/common/Message.o \
./Drivers/INSA/services/common/Service.o 

CPP_DEPS += \
./Drivers/INSA/services/common/Message.d \
./Drivers/INSA/services/common/Service.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/INSA/services/common/Message.o: ../Drivers/INSA/services/common/Message.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DDEBUG -c -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I"/home/dimercur/Documents/Travail/git/voilier/code/Console-Pilotage/Drivers/INSA/drivers" -I"/home/dimercur/Documents/Travail/git/voilier/code/Console-Pilotage/Drivers/INSA/services" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../TouchGFX/target/generated -I../Drivers/CMSIS/Include -I../Core/Inc -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../TouchGFX/App -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../TouchGFX/target -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/gui/include -I"/home/dimercur/Documents/Travail/git/voilier/code/Console-Pilotage/Drivers/BSP" -I"/home/dimercur/Documents/Travail/git/voilier/code/Console-Pilotage/Drivers/Components/Common" -I"/home/dimercur/Documents/Travail/git/voilier/code/Console-Pilotage/Drivers/Components/ft5336" -I"/home/dimercur/Documents/Travail/git/voilier/code/Console-Pilotage/Drivers/Components/n25q128a" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"Drivers/INSA/services/common/Message.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/INSA/services/common/Service.o: ../Drivers/INSA/services/common/Service.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DDEBUG -c -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I"/home/dimercur/Documents/Travail/git/voilier/code/Console-Pilotage/Drivers/INSA/drivers" -I"/home/dimercur/Documents/Travail/git/voilier/code/Console-Pilotage/Drivers/INSA/services" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../TouchGFX/target/generated -I../Drivers/CMSIS/Include -I../Core/Inc -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../TouchGFX/App -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../TouchGFX/target -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/gui/include -I"/home/dimercur/Documents/Travail/git/voilier/code/Console-Pilotage/Drivers/BSP" -I"/home/dimercur/Documents/Travail/git/voilier/code/Console-Pilotage/Drivers/Components/Common" -I"/home/dimercur/Documents/Travail/git/voilier/code/Console-Pilotage/Drivers/Components/ft5336" -I"/home/dimercur/Documents/Travail/git/voilier/code/Console-Pilotage/Drivers/Components/n25q128a" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"Drivers/INSA/services/common/Service.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

