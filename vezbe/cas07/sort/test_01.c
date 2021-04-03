/* Program testira funkcije koje sortiraju niz celih brojeva */
#include <stdio.h>
#include "sort.h"

int main()
{
    int a[] = { 11,7,3,14,1,17,81,18,24,59,52,31,44,26,9,37 };
    int n = sizeof(a) / sizeof(int); 
    int i;

//     selectionSort(a,n);
    selectionSort_rec(a,n);
//     quickSort(a,0,n-1);
//     mergeSort(a,0,n-1);
    
    printf("\n----- Sortiran niz -----\n ");
    for( i =0; i<n ; i++ )
        printf(" %d ", a[i]);
        
    putchar('\n');

    return 0;
}
