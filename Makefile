# 'Make' calls targets makeobjects and main
all: makeobjects main

# Creates a folder called 'bin'
makeobjects:
	mkdir -p bin

# Compiles all .cpp files and creates the executable file

# Creates the executable file
main: bin/music.o bin/node.o bin/linked_list.o bin/playlist.o bin/playlist_node.o bin/playlist_list.o bin/main.o
	g++ bin/main.o -std=c++11 -o main

#Compiles all .cpp files
bin/music.o: ./src/music.cpp
	g++ ./src/music.cpp -std=c++11 -c -o bin/music.o

bin/node.o: ./src/node.cpp bin/music.o
	g++ ./src/node.cpp -std=c++11 -c -o bin/node.o

bin/linked_list.o: ./src/linked_list.cpp bin/music.o bin/node.o
	g++ ./src/linked_list.cpp -std=c++11 -c -o bin/linked_list.o

bin/playlist.o: ./src/playlist.cpp bin/music.o bin/node.o bin/linked_list.o
	g++ ./src/playlist.cpp -std=c++11 -c -o bin/playlist.o

bin/playlist_node.o: ./src/playlist_node.cpp bin/music.o bin/node.o bin/linked_list.o bin/playlist.o
	g++ ./src/playlist_node.cpp -std=c++11 -c -o bin/playlist_node.o

bin/playlist_list.o: ./src/playlist_list.cpp bin/music.o bin/node.o bin/linked_list.o bin/playlist.o bin/playlist_node.o
	g++ ./src/playlist_list.cpp -std=c++11 -c -o bin/playlist_list.o

bin/main.o: ./src/main.cpp bin/music.o bin/node.o bin/linked_list.o bin/playlist.o bin/playlist_node.o
	g++ ./src/main.cpp -std=c++11 -c -o bin/main.o

# Removes 'bin' folder and the executable file
clean:
	rm -rf bin
	rm main