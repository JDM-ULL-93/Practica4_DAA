#ifndef MERGESORT_H
#define MERGESORT_H 1

#include "../Framework/Problema.h"
#include "../Framework/Solucion.h"

/*
namespace CHECK
{
  struct No {}; 
  template<typename T, typename Arg> No operator== (const T&, const Arg&);
 
  template<typename T, typename Arg = T>
  struct EqualExists
  {
    enum { value = !std::is_same<decltype(*(T*)(0) == *(Arg*)(0)), No>::value };
  };  
}

class IComparable{
public:
    IComparable(){};
    virtual ~IComparable(){}
};

template<class T>
class Comparable : public IComparable{
public:
    Comparable(T value) : _value(value) : IComparable(){
        if(!CHECK::EqualExists<T>::value) throw std::exception("La clase definida no tiene definida operador de igualdad(==)");
    }
protected:
    T _value;
};
*/
/// ^Lo dejamos para más tarde^, primero realizar lo que se nos pide:

class MergeSortP : public Problema{
public:
    MergeSortP(int* array, const uint32_t begin, const uint32_t end) : _array(array), _begin(begin), _end(end), Problema(){};
    virtual ~MergeSortP(){};

    bool isCasoMinimo() override;
    pair<Problema*,Problema*> descomponer() override;
    void solver(Solucion* s) override;  
private:
    int* _array;
    uint32_t _begin;
    uint32_t _end;
};

class MergeSortS: public Solucion{
public:
    MergeSortS(int* array) : _array(array){}
    virtual ~MergeSortS(){} 

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

#endif /*MERGESORT_H*/