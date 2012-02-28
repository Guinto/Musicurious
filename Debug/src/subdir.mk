################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Audio.cpp \
../src/Camera.cpp \
../src/Cube.cpp \
../src/Ground.cpp \
../src/Keyboard.cpp \
../src/KeyboardState.cpp \
../src/Main.cpp \
../src/Model.cpp \
../src/Mouse.cpp \
../src/Object.cpp \
../src/ObjectCollection.cpp \
../src/Scene.cpp \
../src/Utilities.cpp \
../src/Window.cpp 

OBJS += \
./src/Audio.o \
./src/Camera.o \
./src/Cube.o \
./src/Ground.o \
./src/Keyboard.o \
./src/KeyboardState.o \
./src/Main.o \
./src/Model.o \
./src/Mouse.o \
./src/Object.o \
./src/ObjectCollection.o \
./src/Scene.o \
./src/Utilities.o \
./src/Window.o 

CPP_DEPS += \
./src/Audio.d \
./src/Camera.d \
./src/Cube.d \
./src/Ground.d \
./src/Keyboard.d \
./src/KeyboardState.d \
./src/Main.d \
./src/Model.d \
./src/Mouse.d \
./src/Object.d \
./src/ObjectCollection.d \
./src/Scene.d \
./src/Utilities.d \
./src/Window.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/Developer/SDKs/MacOSX10.6.sdk/System/Library/Frameworks/OpenGL.framework/Versions/A/Headers -I/Users/ellingsenp/Dropbox/Dev/Musicuriousv2/lib/marsyas -I"/Users/ellingsenp/Dropbox/Dev/Musicuriousv2/lib/FMOD Programmers API/api/inc" -I/Developer/SDKs/MacOSX10.6.sdk/System/Library/Frameworks/GLUT.framework/Versions/A/Headers -O0 -g3 -Wall -c -fmessage-length=0 -arch i686 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


