All:
	g++ main.cpp src/board.cpp src/agent.cpp -I./include/ -o Suduko

run: All
	./Suduko

clean:
	rm -f ./a.out ./Suduko
