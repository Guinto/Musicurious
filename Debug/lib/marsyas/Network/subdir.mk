################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../lib/marsyas/Network/Messager.cpp \
../lib/marsyas/Network/NetworkSocket.cpp \
../lib/marsyas/Network/NetworkTCPSink.cpp \
../lib/marsyas/Network/NetworkTCPSource.cpp \
../lib/marsyas/Network/NetworkUDPSink.cpp \
../lib/marsyas/Network/NetworkUDPSource.cpp \
../lib/marsyas/Network/Server.cpp \
../lib/marsyas/Network/Socket.cpp 

OBJS += \
./lib/marsyas/Network/Messager.o \
./lib/marsyas/Network/NetworkSocket.o \
./lib/marsyas/Network/NetworkTCPSink.o \
./lib/marsyas/Network/NetworkTCPSource.o \
./lib/marsyas/Network/NetworkUDPSink.o \
./lib/marsyas/Network/NetworkUDPSource.o \
./lib/marsyas/Network/Server.o \
./lib/marsyas/Network/Socket.o 

CPP_DEPS += \
./lib/marsyas/Network/Messager.d \
./lib/marsyas/Network/NetworkSocket.d \
./lib/marsyas/Network/NetworkTCPSink.d \
./lib/marsyas/Network/NetworkTCPSource.d \
./lib/marsyas/Network/NetworkUDPSink.d \
./lib/marsyas/Network/NetworkUDPSource.d \
./lib/marsyas/Network/Server.d \
./lib/marsyas/Network/Socket.d 


# Each subdirectory must supply rules for building sources it contributes
lib/marsyas/Network/%.o: ../lib/marsyas/Network/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/Developer/SDKs/MacOSX10.6.sdk/System/Library/Frameworks/OpenGL.framework/Versions/A/Headers -I/Users/ellingsenp/Dropbox/Dev/Musicuriousv2/lib/marsyas -I"/Users/ellingsenp/Dropbox/Dev/Musicuriousv2/lib/FMOD Programmers API/api/inc" -I/Developer/SDKs/MacOSX10.6.sdk/System/Library/Frameworks/GLUT.framework/Versions/A/Headers -O0 -g3 -Wall -c -fmessage-length=0 -arch i686 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


