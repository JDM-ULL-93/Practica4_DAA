
#ifndef FIBONACCIP_H_
#define FIBONACCIP_H_

#include "./../Framework/Problema.h"
#include "FibonacciS.h"

class FibonacciP: public Problema {
public:
	FibonacciP(int);
	virtual ~FibonacciP();

	bool isCasoMinimo() override;
	pair<Problema*,Problema*> descomponer() override;
	void solver(Solucion* s) override;

private:
	int _n;
};

#endif /* FIBONACCIP_H_ */
