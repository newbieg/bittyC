all:
	g++ -I include/ src/bittyC.cpp src/utils.cpp src/error.cpp src/parse.cpp src/compile.cpp
