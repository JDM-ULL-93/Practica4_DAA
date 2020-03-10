
#ifndef FIBONACCIS_H_
#define FIBONACCIS_H_

#include "../Framework/Solucion.h"

class FibonacciS: public Solucion {
public:
	FibonacciS();
	virtual ~FibonacciS();

	void resolver() override;
	void mezcla(pair<Solucion*,Solucion*>) override;
	Solucion* getInstance() override;

	void setValor(int);

private:
	int _n;

};

#endif /* FIBONACCIS_H_ */
