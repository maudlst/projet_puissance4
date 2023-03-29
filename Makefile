CC=clang++
FLAGS=-Wall -g -O0 -std=c++17 -D_GLIBCXX_DEBUG

PLAY : src/boardGame.cpp src/graphAI.cpp src/node.cpp src/game.cpp
		$(CC) $(FLAGS) -o $@ $^

learning : src/boardGame.cpp src/graphAI.cpp src/node.cpp src/learning.cpp
		$(CC) $(FLAGS) -o $@ $^

test : src/boardGame.cpp src/graphAI.cpp src/node.cpp src/testAI.cpp
		$(CC) $(FLAGS) -o $@ $^

clean : 
		rm -f src/*~ *~ test learning PLAY src/files/graphAI.txt
