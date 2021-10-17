autonomous_taxi: autonomous_taxi.cpp entorno.cpp taxi.cpp
	g++ -std=c++14 -g -Wall -o taxi autonomous_taxi.cpp entorno.cpp taxi.cpp

entorno.o: entorno.cpp
	g++ -std=c++14 -g -Wall -o entorno entorno.cpp

taxi.o: taxi.cpp
	g++ -std=c++14 -g -Wall -o taxi taxi.cpp

clean:
	rm -f autonomous_taxi *.o