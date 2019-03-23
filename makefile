testException:main.cpp exception.hpp exception.cpp myCodeError.hpp
	g++ main.cpp -c
	g++ exception.cpp -c
	g++ main.o exception.o -o testException
	rm main.o exception.o
