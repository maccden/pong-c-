COMPILE=g++
LIBS=-lraylib -lGL -lm -lpthread -ldl -lrt -lX11
FILES=src/main.cpp src/ball.cpp src/player.cpp

linux:
	${COMPILE} ${FILES} -o Pong ${LIBS}

windows:
	${COMPILE} ${FILES} -o Pong.exe ${LIBS}