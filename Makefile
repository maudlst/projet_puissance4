FLAGS=-Wall -g -std=c++17

PLAY : src/boardGame.cpp src/graphAI.cpp src/node.cpp src/main.cpp
		g++ $(FLAGS) -o $@ $^

learning : src/boardGame.cpp src/graphAI.cpp src/node.cpp src/learning.cpp
		g++ $(FLAGS) -o $@ $^

test : src/boardGame.cpp src/graphAI.cpp src/node.cpp src/testAI.cpp
		g++ $(FLAGS) -o $@ $^

clean : 
		rm -f src/*~ *~ test learning PLAY src/files/graphAI.txt
