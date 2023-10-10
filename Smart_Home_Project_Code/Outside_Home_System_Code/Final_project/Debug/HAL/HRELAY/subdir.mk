################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/HRELAY/HRELAY_prg.c 

OBJS += \
./HAL/HRELAY/HRELAY_prg.o 

C_DEPS += \
./HAL/HRELAY/HRELAY_prg.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/HRELAY/%.o: ../HAL/HRELAY/%.c HAL/HRELAY/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"F:\All emportant studies\NTI-embedded\AVR\nti\workspace\Final_project\LIB" -I"F:\All emportant studies\NTI-embedded\AVR\nti\workspace\Final_project\HAL\HRELAY" -I"F:\All emportant studies\NTI-embedded\AVR\nti\workspace\Final_project\HAL\HDC_MOTOR" -I"F:\All emportant studies\NTI-embedded\AVR\nti\workspace\Final_project\HAL\HULTRASONIC" -I"F:\All emportant studies\NTI-embedded\AVR\nti\workspace\Final_project\MCAL\MI2C" -I"F:\All emportant studies\NTI-embedded\AVR\nti\workspace\Final_project\MCAL\MUART" -I"F:\All emportant studies\NTI-embedded\AVR\nti\workspace\Final_project\HAL\HEEPROM" -I"F:\All emportant studies\NTI-embedded\AVR\nti\workspace\Final_project\HAL\HLM35" -I"F:\All emportant studies\NTI-embedded\AVR\nti\workspace\Final_project\MCAL\MTIMER1" -I"F:\All emportant studies\NTI-embedded\AVR\nti\workspace\Final_project\MCAL\TIMER0" -I"F:\All emportant studies\NTI-embedded\AVR\nti\workspace\Final_project\HAL\HPB" -I"F:\All emportant studies\NTI-embedded\AVR\nti\workspace\Final_project\HAL\HBUZ" -I"F:\All emportant studies\NTI-embedded\AVR\nti\workspace\Final_project\MCAL\MEXIT" -I"F:\All emportant studies\NTI-embedded\AVR\nti\workspace\Final_project\MCAL\MGIE" -I"F:\All emportant studies\NTI-embedded\AVR\nti\workspace\Final_project\HAL\HLCD" -I"F:\All emportant studies\NTI-embedded\AVR\nti\workspace\Final_project\MCAL\MADC" -I"F:\All emportant studies\NTI-embedded\AVR\nti\workspace\Final_project\HAL\HKEY_PAD" -I"F:\All emportant studies\NTI-embedded\AVR\nti\workspace\Final_project\HAL\HBUZ" -I"F:\All emportant studies\NTI-embedded\AVR\nti\workspace\Final_project\HAL\HSSD" -I"F:\All emportant studies\NTI-embedded\AVR\nti\workspace\Final_project\HAL\LED" -I"F:\All emportant studies\NTI-embedded\AVR\nti\workspace\Final_project\MCAL\MDIO" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


