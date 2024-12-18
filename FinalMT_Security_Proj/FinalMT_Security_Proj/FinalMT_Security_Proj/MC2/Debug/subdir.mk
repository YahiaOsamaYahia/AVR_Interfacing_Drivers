################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Buzzer.c \
../DC_motor.c \
../GPIO.c \
../PWM.c \
../TIMER1.c \
../external_eeprom.c \
../mc2.c \
../twi.c \
../uart.c 

OBJS += \
./Buzzer.o \
./DC_motor.o \
./GPIO.o \
./PWM.o \
./TIMER1.o \
./external_eeprom.o \
./mc2.o \
./twi.o \
./uart.o 

C_DEPS += \
./Buzzer.d \
./DC_motor.d \
./GPIO.d \
./PWM.d \
./TIMER1.d \
./external_eeprom.d \
./mc2.d \
./twi.d \
./uart.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


