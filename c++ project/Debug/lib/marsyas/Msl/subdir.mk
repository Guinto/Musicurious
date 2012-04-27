################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../lib/marsyas/Msl/MslModel.cpp 

OBJS += \
./lib/marsyas/Msl/MslModel.o 

CPP_DEPS += \
./lib/marsyas/Msl/MslModel.d 


# Each subdirectory must supply rules for building sources it contributes
lib/marsyas/Msl/%.o: ../lib/marsyas/Msl/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/Developer/SDKs/MacOSX10.6.sdk/System/Library/Frameworks/OpenGL.framework/Versions/A/Headers -I/Users/ellingsenp/Dropbox/Dev/Musicuriousv2/lib/marsyas -I"/Users/ellingsenp/Dropbox/Dev/Musicuriousv2/lib/FMOD Programmers API/api/inc" -I/Developer/SDKs/MacOSX10.6.sdk/System/Library/Frameworks/GLUT.framework/Versions/A/Headers -O0 -g3 -Wall -c -fmessage-length=0 -arch i686 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


