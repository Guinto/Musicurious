################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../lib/FMOD\ Programmers\ API/examples/effects/main.cpp 

C_SRCS += \
../lib/FMOD\ Programmers\ API/examples/effects/main.c 

OBJS += \
./lib/FMOD\ Programmers\ API/examples/effects/main.o 

C_DEPS += \
./lib/FMOD\ Programmers\ API/examples/effects/main.d 

CPP_DEPS += \
./lib/FMOD\ Programmers\ API/examples/effects/main.d 


# Each subdirectory must supply rules for building sources it contributes
lib/FMOD\ Programmers\ API/examples/effects/main.o: ../lib/FMOD\ Programmers\ API/examples/effects/main.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I/Developer/SDKs/MacOSX10.6.sdk/System/Library/Frameworks/OpenGL.framework/Versions/A/Headers -I"/Users/ellingsenp/Dropbox/Dev/Musicuriousv2/lib/FMOD Programmers API/api/inc" -I/Developer/SDKs/MacOSX10.6.sdk/System/Library/Frameworks/GLUT.framework/Versions/A/Headers -O0 -g3 -Wall -c -fmessage-length=0 -arch i686 -MMD -MP -MF"lib/FMOD Programmers API/examples/effects/main.d" -MT"lib/FMOD\ Programmers\ API/examples/effects/main.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

lib/FMOD\ Programmers\ API/examples/effects/main.o: ../lib/FMOD\ Programmers\ API/examples/effects/main.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/Developer/SDKs/MacOSX10.6.sdk/System/Library/Frameworks/OpenGL.framework/Versions/A/Headers -I"/Users/ellingsenp/Dropbox/Dev/Musicuriousv2/lib/FMOD Programmers API/api/inc" -I/Developer/SDKs/MacOSX10.6.sdk/System/Library/Frameworks/GLUT.framework/Versions/A/Headers -O0 -g3 -Wall -c -fmessage-length=0 -arch i686 -MMD -MP -MF"lib/FMOD Programmers API/examples/effects/main.d" -MT"lib/FMOD\ Programmers\ API/examples/effects/main.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


