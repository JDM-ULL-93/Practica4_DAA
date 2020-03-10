#include "MergeSort.h"



pair<Problema*,Problema*> MergeSortP::descomponer(){ //override from class Problem
	pair<Problema*,Problema*> subProblemas;
    uint32_t mid = (_begin+_end)/2;
	subProblemas.first = new MergeSortP(_array, _begin, mid);
	subProblemas.second = new MergeSortP(_array, mid+1, _end);
	return subProblemas;
}

bool MergeSortP::isCasoMinimo(){
    return (_begin >= _end);
}

void MergeSortP::solver(Solucion* s){
    ((MergeSortS*)s)->setBegin(_begin);
    ((MergeSortS*)s)->setEnd(_end);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////

void MergeSortS::mezcla(pair<Solucion*,Solucion*> soluciones){
    MergeSortS* first = ((MergeSortS*)soluciones.first);
    MergeSortS* second = ((MergeSortS*)soluciones.second);
    int* vector = first->getArray();
    unsigned int size = second->getEnd()+1;
    int* aux = new int[size]();
    unsigned int i = first->getBegin(), k = first ->getBegin(), j = first->getEnd() + 1
        , cen = first->getEnd(),end = second->getEnd();
    
    while ((i <= cen) && (j <= end)) ///Comparamos y vamos añadiendo
    {
        if (vector[i] < vector[j]) aux[k++] = vector[i++] ;
        else aux[k++] = vector[j++];
    }
    ///Procesamos el restante que ha quedado tras la comparacion
    while (j <= end) aux[k++] = vector[j++];
    while (i <= cen) aux[k++] = vector[i++];
    ///Modificamos nuestro vector original para empezar a ordenarlo apartir de lo ordenado en aux
    for (unsigned int k = first->getBegin(); k <= end; k++) vector[k] = aux[k];
    this->setBegin(first->getBegin());
    this->setEnd(second->getEnd());
}

Solucion* MergeSortS::getInstance(){
    return new MergeSortS(this->_array);
}

void MergeSortS::resolver(){
    if(!compruebaOrdenado()) printf("Ha ocurrido un error, el array no esta ordenado");
    else for(int i = 0; i < this->_end+1; i++) printf("%d, ",_array[i]);
}

bool MergeSortS::compruebaOrdenado(){
    if(_begin < 1) return true;
    for(int i = 0, j = 1; j <= _begin; i++,j++)
        if(_array[i] > _array[j]) return false;
    return true;
}