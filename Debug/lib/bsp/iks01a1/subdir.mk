################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/bsp/iks01a1/x_nucleo_iks01a1.c \
../lib/bsp/iks01a1/x_nucleo_iks01a1_accelero.c \
../lib/bsp/iks01a1/x_nucleo_iks01a1_gyro.c \
../lib/bsp/iks01a1/x_nucleo_iks01a1_humidity.c \
../lib/bsp/iks01a1/x_nucleo_iks01a1_magneto.c \
../lib/bsp/iks01a1/x_nucleo_iks01a1_pressure.c \
../lib/bsp/iks01a1/x_nucleo_iks01a1_temperature.c 

OBJS += \
./lib/bsp/iks01a1/x_nucleo_iks01a1.o \
./lib/bsp/iks01a1/x_nucleo_iks01a1_accelero.o \
./lib/bsp/iks01a1/x_nucleo_iks01a1_gyro.o \
./lib/bsp/iks01a1/x_nucleo_iks01a1_humidity.o \
./lib/bsp/iks01a1/x_nucleo_iks01a1_magneto.o \
./lib/bsp/iks01a1/x_nucleo_iks01a1_pressure.o \
./lib/bsp/iks01a1/x_nucleo_iks01a1_temperature.o 

C_DEPS += \
./lib/bsp/iks01a1/x_nucleo_iks01a1.d \
./lib/bsp/iks01a1/x_nucleo_iks01a1_accelero.d \
./lib/bsp/iks01a1/x_nucleo_iks01a1_gyro.d \
./lib/bsp/iks01a1/x_nucleo_iks01a1_humidity.d \
./lib/bsp/iks01a1/x_nucleo_iks01a1_magneto.d \
./lib/bsp/iks01a1/x_nucleo_iks01a1_pressure.d \
./lib/bsp/iks01a1/x_nucleo_iks01a1_temperature.d 


# Each subdirectory must supply rules for building sources it contributes
lib/bsp/iks01a1/%.o lib/bsp/iks01a1/%.su lib/bsp/iks01a1/%.cyclo: ../lib/bsp/iks01a1/%.c lib/bsp/iks01a1/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F1 -DNUCLEO_F103RB -DSTM32F103RBTx -DSTM32 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../lib/bsp -I../lib//middleware/MIDI/ -I../lib/bsp/VL53L0X -I../lib/bsp/MPU6050 -I../lib/bsp/iks01a1 -I../lib/bsp/iks01a1/Common -I../lib/bsp/iks01a1/hts221 -I../lib/bsp/iks01a1/lis3mdl -I../lib/bsp/iks01a1/lps22hb -I../lib/bsp/iks01a1/lps25hb -I../lib/bsp/iks01a1/lsm6ds0 -I../lib/bsp/iks01a1/lsm6ds3 -I../lib/bsp/tft_ili9341 -I../lib/bsp/tft_pcd8544 -I../lib/bsp/MCP23S17 -I../lib/hal/inc -I../lib/bsp/Common -I../lib/bsp/lcd2x16 -I../lib/bsp/MLX90614 -I../lib/bsp/MatrixKeyboard -I../lib/bsp/MatrixLed -I../lib/CMSIS/core -I../lib/CMSIS/device -I../lib/middleware/FatFs -I../lib/middleware/FatFs/src -I../lib/middleware/FatFs/src/drivers -I../appli -O0 -ffunction-sections -fdata-sections -Wall -Wextra -Wconversion -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"

clean: clean-lib-2f-bsp-2f-iks01a1

clean-lib-2f-bsp-2f-iks01a1:
	-$(RM) ./lib/bsp/iks01a1/x_nucleo_iks01a1.cyclo ./lib/bsp/iks01a1/x_nucleo_iks01a1.d ./lib/bsp/iks01a1/x_nucleo_iks01a1.o ./lib/bsp/iks01a1/x_nucleo_iks01a1.su ./lib/bsp/iks01a1/x_nucleo_iks01a1_accelero.cyclo ./lib/bsp/iks01a1/x_nucleo_iks01a1_accelero.d ./lib/bsp/iks01a1/x_nucleo_iks01a1_accelero.o ./lib/bsp/iks01a1/x_nucleo_iks01a1_accelero.su ./lib/bsp/iks01a1/x_nucleo_iks01a1_gyro.cyclo ./lib/bsp/iks01a1/x_nucleo_iks01a1_gyro.d ./lib/bsp/iks01a1/x_nucleo_iks01a1_gyro.o ./lib/bsp/iks01a1/x_nucleo_iks01a1_gyro.su ./lib/bsp/iks01a1/x_nucleo_iks01a1_humidity.cyclo ./lib/bsp/iks01a1/x_nucleo_iks01a1_humidity.d ./lib/bsp/iks01a1/x_nucleo_iks01a1_humidity.o ./lib/bsp/iks01a1/x_nucleo_iks01a1_humidity.su ./lib/bsp/iks01a1/x_nucleo_iks01a1_magneto.cyclo ./lib/bsp/iks01a1/x_nucleo_iks01a1_magneto.d ./lib/bsp/iks01a1/x_nucleo_iks01a1_magneto.o ./lib/bsp/iks01a1/x_nucleo_iks01a1_magneto.su ./lib/bsp/iks01a1/x_nucleo_iks01a1_pressure.cyclo ./lib/bsp/iks01a1/x_nucleo_iks01a1_pressure.d ./lib/bsp/iks01a1/x_nucleo_iks01a1_pressure.o ./lib/bsp/iks01a1/x_nucleo_iks01a1_pressure.su ./lib/bsp/iks01a1/x_nucleo_iks01a1_temperature.cyclo ./lib/bsp/iks01a1/x_nucleo_iks01a1_temperature.d ./lib/bsp/iks01a1/x_nucleo_iks01a1_temperature.o ./lib/bsp/iks01a1/x_nucleo_iks01a1_temperature.su

.PHONY: clean-lib-2f-bsp-2f-iks01a1

