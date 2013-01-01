all: finitefield 

finitefield: Integer.h Integer.cpp FiniteField.h FiniteFieldMain.cpp xgcd.h
	g++ -Wall Integer.cpp FiniteFieldMain.cpp -o finitefield_test

finitefieldd: Integer.h Integer.cpp FiniteField.h FiniteFieldMain.cpp xgcd.h
	g++ -Wall Integer.cpp FiniteFieldMain.cpp -o finitefield_test -O0 -ggdb3 
