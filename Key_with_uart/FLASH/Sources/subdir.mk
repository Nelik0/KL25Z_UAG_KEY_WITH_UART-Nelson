################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/cfgps2.c" \
"../Sources/decodificacion.c" \
"../Sources/decodificacion_mouse.c" \
"../Sources/funciones_teclas.c" \
"../Sources/lcd.c" \
"../Sources/main.c" \
"../Sources/mouse_init.c" \
"../Sources/sa_mtb.c" \

C_SRCS += \
../Sources/cfgps2.c \
../Sources/decodificacion.c \
../Sources/decodificacion_mouse.c \
../Sources/funciones_teclas.c \
../Sources/lcd.c \
../Sources/main.c \
../Sources/mouse_init.c \
../Sources/sa_mtb.c \

OBJS += \
./Sources/cfgps2.o \
./Sources/decodificacion.o \
./Sources/decodificacion_mouse.o \
./Sources/funciones_teclas.o \
./Sources/lcd.o \
./Sources/main.o \
./Sources/mouse_init.o \
./Sources/sa_mtb.o \

C_DEPS += \
./Sources/cfgps2.d \
./Sources/decodificacion.d \
./Sources/decodificacion_mouse.d \
./Sources/funciones_teclas.d \
./Sources/lcd.d \
./Sources/main.d \
./Sources/mouse_init.d \
./Sources/sa_mtb.d \

OBJS_QUOTED += \
"./Sources/cfgps2.o" \
"./Sources/decodificacion.o" \
"./Sources/decodificacion_mouse.o" \
"./Sources/funciones_teclas.o" \
"./Sources/lcd.o" \
"./Sources/main.o" \
"./Sources/mouse_init.o" \
"./Sources/sa_mtb.o" \

C_DEPS_QUOTED += \
"./Sources/cfgps2.d" \
"./Sources/decodificacion.d" \
"./Sources/decodificacion_mouse.d" \
"./Sources/funciones_teclas.d" \
"./Sources/lcd.d" \
"./Sources/main.d" \
"./Sources/mouse_init.d" \
"./Sources/sa_mtb.d" \

OBJS_OS_FORMAT += \
./Sources/cfgps2.o \
./Sources/decodificacion.o \
./Sources/decodificacion_mouse.o \
./Sources/funciones_teclas.o \
./Sources/lcd.o \
./Sources/main.o \
./Sources/mouse_init.o \
./Sources/sa_mtb.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/cfgps2.o: ../Sources/cfgps2.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/cfgps2.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/cfgps2.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/decodificacion.o: ../Sources/decodificacion.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/decodificacion.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/decodificacion.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/decodificacion_mouse.o: ../Sources/decodificacion_mouse.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/decodificacion_mouse.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/decodificacion_mouse.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/funciones_teclas.o: ../Sources/funciones_teclas.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/funciones_teclas.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/funciones_teclas.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/lcd.o: ../Sources/lcd.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/lcd.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/lcd.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/main.o: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/main.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/main.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/mouse_init.o: ../Sources/mouse_init.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/mouse_init.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/mouse_init.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/sa_mtb.o: ../Sources/sa_mtb.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/sa_mtb.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/sa_mtb.o"
	@echo 'Finished building: $<'
	@echo ' '


