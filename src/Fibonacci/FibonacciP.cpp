
#include "FibonacciP.h"

FibonacciP::FibonacciP(int n) : Problema::Problema() {
	_n = n;
}

FibonacciP::~FibonacciP() {

}

bool FibonacciP::isCasoMinimo(){ //override from class Problem
	return (_n < 2);
}

pair<Problema*,Problema*> FibonacciP::descomponer(){ //override from class Problem
	pair<Problema*,Problema*> subProblemas;
	subProblemas.first = new FibonacciP(_n-1);
	subProblemas.second = new FibonacciP(_n-2);
	return subProblemas;
}

void FibonacciP::solver(Solucion* s){ //override from class Problem
	if (_n == 0){  // caso especial fibonacci(0) = 1
		_n = 1;
	}
	((FibonacciS*)s)->setValor(_n);
}
