autonomous_taxi: autonomous_taxi.cpp entorno.cpp taxi.cpp
	g++ -std=c++14 -g -Wall -o taxi autonomous_taxi.cpp entorno.cpp taxi.cpp cell.cpp

entorno.o: entorno.cpp
	g++ -std=c++14 -g -Wall -o entorno entorno.cpp

taxi.o: taxi.cpp
	g++ -std=c++14 -g -Wall -o taxi taxi.cpp

cell.o: cell.cpp
	g++ -std=c++14 -g -Wall -o cell cell.cpp

clean:
	rm -f autonomous_taxi *.o