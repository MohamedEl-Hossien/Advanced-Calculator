################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL_LAYER/DIO_DRIVER_ATMEGA32/DIO_prg.c 

OBJS += \
./MCAL_LAYER/DIO_DRIVER_ATMEGA32/DIO_prg.o 

C_DEPS += \
./MCAL_LAYER/DIO_DRIVER_ATMEGA32/DIO_prg.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL_LAYER/DIO_DRIVER_ATMEGA32/%.o: ../MCAL_LAYER/DIO_DRIVER_ATMEGA32/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\Engineering\Courses\IMT Embedded SYS\Days\ES\Advanced_Calculator\Application" -I"D:\Engineering\Courses\IMT Embedded SYS\Days\ES\Advanced_Calculator\HAL_LAYER" -I"D:\Engineering\Courses\IMT Embedded SYS\Days\ES\Advanced_Calculator\lib" -I"D:\Engineering\Courses\IMT Embedded SYS\Days\ES\Advanced_Calculator\MCAL_LAYER" -I"D:\Engineering\Courses\IMT Embedded SYS\Days\ES\Advanced_Calculator\HAL_LAYER\KPD_DRIVER" -I"D:\Engineering\Courses\IMT Embedded SYS\Days\ES\Advanced_Calculator\HAL_LAYER\LCD_DRIVER" -I"D:\Engineering\Courses\IMT Embedded SYS\Days\ES\Advanced_Calculator\MCAL_LAYER\DIO_DRIVER_ATMEGA32" -Wall -g2 -gstabs -O1 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


