all:
	g++ -O3 -I include/ src/bittyC.cpp src/utils.cpp src/error.cpp src/parse.cpp src/compile.cpp
