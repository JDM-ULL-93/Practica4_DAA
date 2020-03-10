#ifndef QUICKSORT_H
#define QUICKSORT_H 1

#include "../Framework/Problema.h"
#include "../Framework/Solucion.h"

class QuickSortP : public Problema{
public:
    QuickSortP(int* array, const uint32_t begin, const uint32_t end) : _array(array), _begin(begin), _end(end), Problema(){};
    virtual ~QuickSortP(){};

    bool isCasoMinimo() override;
    pair<Problema*,Problema*> descomponer() override;
    void solver(Solucion* s) override; 
private:
    int* _array;
    uint32_t _begin;
    uint32_t _end;

};

class QuickSortS : public Solucion{
public:
    QuickSortS(int* array) : _array(array){}
    virtual ~QuickSortS(){} 

    void resolver() override;
    void mezcla(pair<Solucion*,Solucion*>) override;
    Solucion* getInstance() override;

    void setBegin(const uint32_t begin){ _begin = begin;}
    const uint32_t getBegin(){return _begin;}

    void setEnd(const uint32_t end){ _end = end;}
    const uint32_t getEnd(){return _end;}

    void setArray(int* array){ _array = array;}
    int* getArray(){return _array;}
private:
    uint32_t _begin;
    uint32_t _end;
    int* _array;
};

#endif /*QUICKSORT_H*/