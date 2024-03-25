CC=g++
CC=g++
LIBS_L=-lraylib -lGL -lm -lpthread -ldl -lrt -lX11
LIBS_W=-lraylib -lopengl32 -lgdi32 -lwinmm

linux:
	${CC} ${FILES} -o Pong ${LIBS_L}
	./Pong

windows:
	${CC} ${FILES} -o Pong.exe ${LIBS_W}
	Pong.exe