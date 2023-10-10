################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/TIMER0/subdir.mk
-include MCAL/MUART/subdir.mk
-include MCAL/MTIMER1/subdir.mk
-include MCAL/MSPI/subdir.mk
-include MCAL/MI2C/subdir.mk
-include MCAL/MGIE/subdir.mk
-include MCAL/MEXIT/subdir.mk
-include MCAL/MDIO/subdir.mk
-include MCAL/MADC/subdir.mk
-include HAL/LED/subdir.mk
-include HAL/HULTRASONIC/subdir.mk
-include HAL/HSSD/subdir.mk
-include HAL/HRELAY/subdir.mk
-include HAL/HPB/subdir.mk
-include HAL/HLM35/subdir.mk
-include HAL/HLCD/subdir.mk
-include HAL/HKEY_PAD/subdir.mk
-include HAL/HEEPROM/subdir.mk
-include HAL/HDC_MOTOR/subdir.mk
-include HAL/HBUZ/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := Final_project_MC2
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Final_project_MC2.lss \

FLASH_IMAGE += \
Final_project_MC2.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: main-build

# Main-build Target
main-build: Final_project_MC2.elf secondary-outputs

# Tool invocations
Final_project_MC2.elf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Final_project_MC2.map -mmcu=atmega32 -o "Final_project_MC2.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Final_project_MC2.lss: Final_project_MC2.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Final_project_MC2.elf  >"Final_project_MC2.lss"
	@echo 'Finished building: $@'
	@echo ' '

Final_project_MC2.hex: Final_project_MC2.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Final_project_MC2.elf  "Final_project_MC2.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Final_project_MC2.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Final_project_MC2.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Final_project_MC2.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents main-build

-include ../makefile.targets
