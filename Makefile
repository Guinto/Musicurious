#Makefile - Trent Ellingsen
CC=g++
MARSYAS_INSTALL = lib
CFLAGS=-framework OpenGL -framework GLUT -framework CoreAudio -framework CoreMidi -framework CoreFoundation -framework AudioToolBox
LDFLAGS=
LIB_MARYAS=-I${MARSYAS_INSTALL}/marsyas -L${MARSYAS_INSTALL} -lmarsyas 

ALL=music

all: $(ALL)

music: Main.o Utilities.o Keyboard.o KeyboardState.o Mouse.o Window.o Camera.o Cube.o Object.o ObjectCollection.o Ground.o Scene.o Audio.o Model.o AudioPlayer.o
	$(CC) $(CFLAGS) ${LIB_MARYAS} -o $@ $^

Main.o: src/Main.cpp src/*.h
	$(CC) -c $^

Utilities.o: src/Utilities.cpp src/Utilities.h
	$(CC) -c $^

Keyboard.o: src/Keyboard.cpp src/Keyboard.h 
	$(CC) -c $^

KeyboardState.o: src/KeyboardState.cpp src/KeyboardState.h
	$(CC) -c $^

Mouse.o: src/Mouse.cpp src/Mouse.h
	$(CC) -c $^

Window.o: src/Window.cpp src/Window.h
	$(CC) -c $^

Camera.o: src/Camera.cpp src/Camera.h
	$(CC) -c $^

Cube.o: src/Cube.cpp src/Cube.h
	$(CC) -c $^

Object.o: src/Object.cpp src/Object.h
	$(CC) -c $^

ObjectCollection.o: src/ObjectCollection.cpp src/ObjectCollection.h
	$(CC) -c $^

Ground.o: src/Ground.cpp src/Ground.h
	$(CC) -c $^

Scene.o: src/Scene.cpp src/Scene.h
	$(CC) -c $^

Audio.o: src/Audio.cpp src/Audio.h
	$(CC) -c $^

AudioPlayer.o: src/AudioPlayer.cpp src/AudioPlayer.h
	$(CC) -c $^

Model.o: src/Model.cpp src/Model.h
	$(CC) -c $^

clean:
	rm -rf core* *.o *.gch src/*.gch $(ALL)

clena: clean
