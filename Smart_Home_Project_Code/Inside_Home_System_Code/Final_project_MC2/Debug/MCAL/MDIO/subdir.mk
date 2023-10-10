################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/MDIO/MDIO_prog.c 

OBJS += \
./MCAL/MDIO/MDIO_prog.o 

C_DEPS += \
./MCAL/MDIO/MDIO_prog.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/MDIO/%.o: ../MCAL/MDIO/%.c MCAL/MDIO/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"F:\All emportant studies\NTI-embedded\AVR\nti\workspace\Final_project_MC2\LIB" -I"F:\All emportant studies\NTI-embedded\AVR\nti\workspace\Final_project_MC2\MCAL\MUART" -I"F:\All emportant studies\NTI-embedded\AVR\nti\workspace\Final_project_MC2\HAL\HRELAY" -I"F:\All emportant studies\NTI-embedded\AVR\nti\workspace\Final_project_MC2\HAL\HDC_MOTOR" -I"F:\All emportant studies\NTI-embedded\AVR\nti\workspace\Final_project_MC2\HAL\HULTRASONIC" -I"F:\All emportant studies\NTI-embedded\AVR\nti\workspace\Final_project_MC2\MCAL\MI2C" -I"F:\All emportant studies\NTI-embedded\AVR\nti\workspace\Final_project_MC2\HAL\HEEPROM" -I"F:\All emportant studies\NTI-embedded\AVR\nti\workspace\Final_project_MC2\HAL\HLM35" -I"F:\All emportant studies\NTI-embedded\AVR\nti\workspace\Final_project_MC2\MCAL\MTIMER1" -I"F:\All emportant studies\NTI-embedded\AVR\nti\workspace\Final_project_MC2\MCAL\TIMER0" -I"F:\All emportant studies\NTI-embedded\AVR\nti\workspace\Final_project_MC2\HAL\HPB" -I"F:\All emportant studies\NTI-embedded\AVR\nti\workspace\Final_project_MC2\HAL\HBUZ" -I"F:\All emportant studies\NTI-embedded\AVR\nti\workspace\Final_project_MC2\MCAL\MEXIT" -I"F:\All emportant studies\NTI-embedded\AVR\nti\workspace\Final_project_MC2\MCAL\MGIE" -I"F:\All emportant studies\NTI-embedded\AVR\nti\workspace\Final_project_MC2\HAL\HLCD" -I"F:\All emportant studies\NTI-embedded\AVR\nti\workspace\Final_project_MC2\MCAL\MADC" -I"F:\All emportant studies\NTI-embedded\AVR\nti\workspace\Final_project_MC2\HAL\HKEY_PAD" -I"F:\All emportant studies\NTI-embedded\AVR\nti\workspace\Final_project_MC2\HAL\HBUZ" -I"F:\All emportant studies\NTI-embedded\AVR\nti\workspace\Final_project_MC2\HAL\HSSD" -I"F:\All emportant studies\NTI-embedded\AVR\nti\workspace\Final_project_MC2\HAL\LED" -I"F:\All emportant studies\NTI-embedded\AVR\nti\workspace\Final_project_MC2\MCAL\MDIO" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


