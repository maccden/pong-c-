COMPILE_L=g++
COMPILE_W=gcc
LIBS_L=-lraylib -lGL -lm -lpthread -ldl -lrt -lX11
LIBS_W=-lraylib -lopengl32 -lgdi32 -lwinmm
FILES=src/main.cpp src/ball.cpp src/player.cpp

linux:
	${COMPILE_L} ${FILES} -o Pong ${LIBS_L}

windows:
	${COMPILE_W} ${FILES} -o Pong.exe ${LIBS_W}