
#include <iostream>
#include "FibonacciS.h"

FibonacciS::FibonacciS() : Solucion::Solucion() {
}

FibonacciS::~FibonacciS() {
}


void FibonacciS::resolver() {  //override from class Solucion
	printf("%d\n",_n);
	//cout << _n << endl;
}

void FibonacciS::mezcla(pair<Solucion*,Solucion*> subSoluciones) { //override from class Solucion
	int n1 = ((FibonacciS*)subSoluciones.first)->_n;
	int n2 = ((FibonacciS*)subSoluciones.second)->_n;
	_n = n1+n2;
}

Solucion* FibonacciS::getInstance() { ///override from class Solucion
	return new FibonacciS();
}

void FibonacciS::setValor(int n) {
	_n = n;
}
