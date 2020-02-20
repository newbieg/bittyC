all:
	g++ -O3 -o bcc -I include/ src/bittyC.cpp src/utils.cpp src/error.cpp src/parse.cpp src/compile.cpp src/variables.cpp 

help:
	# "first run make to build ./bcc, then use ./bcc on a .cpp file. this will produce out.s."
	# "Next call gcc -C out.s"
	# "this should now have produced an a.out file that you can run."

