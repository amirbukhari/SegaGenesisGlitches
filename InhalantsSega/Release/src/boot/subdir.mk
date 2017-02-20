################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/boot/rom_head.c 

OBJS += \
./src/boot/rom_head.o 

C_DEPS += \
./src/boot/rom_head.d 


# Each subdirectory must supply rules for building sources it contributes
src/boot/%.o: ../src/boot/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


