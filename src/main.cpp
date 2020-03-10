#include "./Fibonacci/FibonacciP.h"
#include "./MergeSort/MergeSort.h"
#include "./QuickSort/QuickSort.h"
#include "./Framework/Framework.h"

int main (int argc, char *argv[]) {     
    int a[14] = {23,35,65,1352,535,353,21,24,56,2,54,87,12,844};
    QuickSortP* problem = new QuickSortP(a,0,13);
    QuickSortS* solution = new QuickSortS(a);
    Framework resolver = Framework();
    resolver.divideyVenceras(problem,solution);
    printf("QuickSort : \n");
    solution->resolver();
    printf("\n");
    system("pause");
    return 0;
 }