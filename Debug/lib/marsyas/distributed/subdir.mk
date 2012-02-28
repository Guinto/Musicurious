################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../lib/marsyas/distributed/collector.cpp \
../lib/marsyas/distributed/dispatcher.cpp \
../lib/marsyas/distributed/recvFFT.cpp \
../lib/marsyas/distributed/recvTCP.cpp \
../lib/marsyas/distributed/recvUDP.cpp \
../lib/marsyas/distributed/sendFFT.cpp \
../lib/marsyas/distributed/sendTCP.cpp \
../lib/marsyas/distributed/sendUDP.cpp 

OBJS += \
./lib/marsyas/distributed/collector.o \
./lib/marsyas/distributed/dispatcher.o \
./lib/marsyas/distributed/recvFFT.o \
./lib/marsyas/distributed/recvTCP.o \
./lib/marsyas/distributed/recvUDP.o \
./lib/marsyas/distributed/sendFFT.o \
./lib/marsyas/distributed/sendTCP.o \
./lib/marsyas/distributed/sendUDP.o 

CPP_DEPS += \
./lib/marsyas/distributed/collector.d \
./lib/marsyas/distributed/dispatcher.d \
./lib/marsyas/distributed/recvFFT.d \
./lib/marsyas/distributed/recvTCP.d \
./lib/marsyas/distributed/recvUDP.d \
./lib/marsyas/distributed/sendFFT.d \
./lib/marsyas/distributed/sendTCP.d \
./lib/marsyas/distributed/sendUDP.d 


# Each subdirectory must supply rules for building sources it contributes
lib/marsyas/distributed/%.o: ../lib/marsyas/distributed/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/Developer/SDKs/MacOSX10.6.sdk/System/Library/Frameworks/OpenGL.framework/Versions/A/Headers -I/Users/ellingsenp/Dropbox/Dev/Musicuriousv2/lib/marsyas -I"/Users/ellingsenp/Dropbox/Dev/Musicuriousv2/lib/FMOD Programmers API/api/inc" -I/Developer/SDKs/MacOSX10.6.sdk/System/Library/Frameworks/GLUT.framework/Versions/A/Headers -O0 -g3 -Wall -c -fmessage-length=0 -arch i686 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


