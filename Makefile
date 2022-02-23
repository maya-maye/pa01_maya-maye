all: game
	
# game: files1.cpp files1.hpp
# 	g++ files1.cpp files1.hpp -std=c++11 -o game.o
# 	./game.o a1.file a2.file a3.file b0.file b1.file b2.file b3.file

# utility.o:
# 	g++ -std=c++11 -c utility.cpp

# tests.o:
# 	g++ -std=c++11 -c tests.cpp

game: cards.o main.o utility.o
	g++ -std=c++11 -o game cards.o main.o utility.o
	./game a0.txt b0.txt

clean:
	rm -f *.o game tests
