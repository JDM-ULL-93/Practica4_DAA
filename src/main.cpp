#include "./Fibonacci/FibonacciP.h"
#include "./MergeSort/MergeSort.h"
#include "./QuickSort/QuickSort.h"
#include "./Framework/Framework.h"

int main (int argc, char *argv[]) {     
    Framework resolver = Framework();

    int a[35] = {23,35,65,1352,535,353,21,24,56,2,54,87,12,844,-23,
    3,-5,-4,3,-56,3,6,34,-6,-534,-234,-3,1,-10,56,32,14512,1256,143,2};
    QuickSortP* problem = new QuickSortP(a,0,34);
    QuickSortS* solution = new QuickSortS(a);
   
    resolver.divideyVenceras(problem,solution);
    printf("QuickSort : \n");
    solution->resolver();
    printf("\n");

    int b[35] = {23,35,65,1352,535,353,21,24,56,2,54,87,12,844,-23,
    3,-5,-4,3,-56,3,6,34,-6,-534,-234,-3,1,-10,56,32,14512,1256,143,2};
    MergeSortP* problem2 = new MergeSortP(b,0,34);
    MergeSortS* solution2 = new MergeSortS(b);
    printf("MergeSort : \n");
    resolver.divideyVenceras(problem2,solution2);
    solution2->resolver();
    printf("\n");
    system("pause");
    return 0;
 }