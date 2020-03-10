#include "QuickSort.h"

bool QuickSortP::isCasoMinimo(){
    return (_begin >= _end);
}

pair<Problema*,Problema*> QuickSortP::descomponer(){
    int i = _begin, j = _end;
	int32_t piv = _array[(i+j)/2];
	while(i <= j){
		while(_array[i] < piv) i++; ///Parará cuando sec[i] >= piv
		while(_array[j] > piv) j--; ///Parará cuando sec[j] >= piv
		if(i <= j){ ///No interesa intercambiar si se han cruzado, estaremos tocando los ya ordenados
			int32_t aux = _array[i];
			_array[i] = _array[j];
			_array[j] = aux;
			i++,j--;
		}
	}
    pair<Problema*,Problema*> subProblemas;
    subProblemas.first = new QuickSortP(_array, i, _end);
	subProblemas.second =new QuickSortP(_array, _begin, j);
    return subProblemas;
}

void QuickSortP::solver(Solucion* s){
    ((QuickSortS*)s)->setBegin(_begin);
    ((QuickSortS*)s)->setEnd(_end);
}

/////////////////////////////////////////////////////////////////////////////////////

Solucion* QuickSortS::getInstance(){
    return new QuickSortS(this->_array);
}

void QuickSortS::mezcla(pair<Solucion*,Solucion*> soluciones){
    QuickSortS* first = ((QuickSortS*)soluciones.first);
    QuickSortS* second = ((QuickSortS*)soluciones.second);
    this->setBegin(first->getBegin());
    this->setEnd(second->getEnd());
    //Nada
}


void QuickSortS::resolver(){
    //printf("init = %d , end= %d", _begin, _end);
    //Cuando el algoritmo termine _end == 0 y _begin == end
    if(!compruebaOrdenado()) printf("Ha ocurrido un error, el array no esta ordenado");
    else for(int i = _end ; i <= _begin ; i++) printf("%d, ",_array[i]);
}

bool QuickSortS::compruebaOrdenado(){
    if(_begin < 1) return true;
    for(int i = 0, j = 1; j <= _begin; i++,j++)
        if(_array[i] > _array[j]) return false;
    return true;
}