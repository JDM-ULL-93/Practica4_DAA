#ifndef SOLUCION_H_
#define SOLUCION_H_

#include <vector>
#include <utility>
#include <iostream>
using namespace std;

class Solucion {
public:
	Solucion();
	virtual ~Solucion();

	virtual void resolver() = 0;
	virtual void mezcla(pair<Solucion*,Solucion*>) = 0;
	virtual Solucion* getInstance() = 0;
};

#endif /* SOLUCION_H_ */
