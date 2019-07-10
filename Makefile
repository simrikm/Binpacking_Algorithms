OBJECTS=next_fit.o main.o best_fit.o first_fit.o first_fit_decreasing.o best_fit_decreasing.o  
bin_packing:$(OBJECTS)
	g++ -ggdb  $(OBJECTS) -o bin_packing
next_fit.o:next_fit.cpp project2.h
	g++ -c -std=c++11 -ggdb next_fit.cpp
best_fit.o:best_fit.cpp project2.h
	g++ -c  -std=c++11 -ggdb best_fit.cpp
first_fit.o:first_fit.cpp project2.h
	g++ -c -std=c++11 -ggdb first_fit.cpp
first_fit_decreasing.o:first_fit_decreasing.cpp project2.h
	g++ -c -std=c++11 -ggdb first_fit_decreasing.cpp
best_fit_decreasing.o:best_fit_decreasing.cpp project2.h
	g++ -c -std=c++11 -ggdb best_fit_decreasing.cpp
main.o:main.cpp project2.h
	g++ -c -std=c++11 -ggdb main.cpp

clean:
	/bin/rm -f $(OBJECTS)

