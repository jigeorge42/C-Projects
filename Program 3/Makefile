all	:	Creatures

Creatures	:	Ceatures.o Functions.o
			g++ -o Program3.exe Creatures.o Functions.o
			
Creatures.o	:	Creatures.cpp
			g++ -I ./ -c Creatures.cpp
			
Functions.o	:	Functions.cpp
			g++ -I ./ -c Functions.cpp
			
clean	:	Program3.exe
		del *.o
		del Program3.exe