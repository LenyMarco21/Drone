################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_95HF_wrapper.c \
../lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF.c \
../lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_AAR.c \
../lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_Email.c \
../lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_Geo.c \
../lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_MyApp.c \
../lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_SMS.c \
../lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_Text.c \
../lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_URI.c \
../lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_Vcard.c 

OBJS += \
./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_95HF_wrapper.o \
./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF.o \
./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_AAR.o \
./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_Email.o \
./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_Geo.o \
./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_MyApp.o \
./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_SMS.o \
./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_Text.o \
./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_URI.o \
./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_Vcard.o 

C_DEPS += \
./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_95HF_wrapper.d \
./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF.d \
./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_AAR.d \
./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_Email.d \
./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_Geo.d \
./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_MyApp.d \
./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_SMS.d \
./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_Text.d \
./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_URI.d \
./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_Vcard.d 


# Each subdirectory must supply rules for building sources it contributes
lib/bsp/NFC03A1/lib_nfc/lib_NDEF/%.o lib/bsp/NFC03A1/lib_nfc/lib_NDEF/%.su lib/bsp/NFC03A1/lib_nfc/lib_NDEF/%.cyclo: ../lib/bsp/NFC03A1/lib_nfc/lib_NDEF/%.c lib/bsp/NFC03A1/lib_nfc/lib_NDEF/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F1 -DNUCLEO_F103RB -DSTM32F103RBTx -DSTM32 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../lib/bsp -I../lib//middleware/MIDI/ -I../lib/bsp/VL53L0X -I../lib/bsp/MPU6050 -I../lib/bsp/iks01a1 -I../lib/bsp/iks01a1/Common -I../lib/bsp/iks01a1/hts221 -I../lib/bsp/iks01a1/lis3mdl -I../lib/bsp/iks01a1/lps22hb -I../lib/bsp/iks01a1/lps25hb -I../lib/bsp/iks01a1/lsm6ds0 -I../lib/bsp/iks01a1/lsm6ds3 -I../lib/bsp/tft_ili9341 -I../lib/bsp/tft_pcd8544 -I../lib/bsp/MCP23S17 -I../lib/hal/inc -I../lib/bsp/Common -I../lib/bsp/lcd2x16 -I../lib/bsp/MLX90614 -I../lib/bsp/MatrixKeyboard -I../lib/bsp/MatrixLed -I../lib/CMSIS/core -I../lib/CMSIS/device -I../lib/middleware/FatFs -I../lib/middleware/FatFs/src -I../lib/middleware/FatFs/src/drivers -I../appli -O0 -ffunction-sections -fdata-sections -Wall -Wextra -Wconversion -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"

clean: clean-lib-2f-bsp-2f-NFC03A1-2f-lib_nfc-2f-lib_NDEF

clean-lib-2f-bsp-2f-NFC03A1-2f-lib_nfc-2f-lib_NDEF:
	-$(RM) ./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_95HF_wrapper.cyclo ./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_95HF_wrapper.d ./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_95HF_wrapper.o ./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_95HF_wrapper.su ./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF.cyclo ./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF.d ./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF.o ./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF.su ./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_AAR.cyclo ./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_AAR.d ./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_AAR.o ./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_AAR.su ./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_Email.cyclo ./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_Email.d ./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_Email.o ./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_Email.su ./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_Geo.cyclo ./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_Geo.d ./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_Geo.o ./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_Geo.su ./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_MyApp.cyclo ./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_MyApp.d ./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_MyApp.o ./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_MyApp.su ./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_SMS.cyclo ./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_SMS.d ./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_SMS.o ./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_SMS.su ./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_Text.cyclo ./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_Text.d ./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_Text.o ./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_Text.su ./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_URI.cyclo ./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_URI.d ./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_URI.o ./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_URI.su ./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_Vcard.cyclo ./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_Vcard.d ./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_Vcard.o ./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_Vcard.su

.PHONY: clean-lib-2f-bsp-2f-NFC03A1-2f-lib_nfc-2f-lib_NDEF

