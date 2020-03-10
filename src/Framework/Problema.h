
#ifndef PROBLEMA_H_
#define PROBLEMA_H_

#include <vector>
#include <utility>
#include <iostream>
#include "Solucion.h"
using namespace std;

class Problema {
public:
	Problema();
	virtual ~Problema();

	virtual bool isCasoMinimo() = 0;
	virtual pair<Problema*,Problema*> descomponer() = 0;
	virtual void solver(Solucion* s) = 0;
};

#endif /* PROBLEMA_H_ */
