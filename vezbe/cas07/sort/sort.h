#ifndef __SORT_H__
#define __SORT_H__ 1


/* Maksimalna duzina niza 
 * Ovde je deklarisana zbog pomocnog niza b u merge sort
 */
#define MAX 1000000

void swap( int a[], int i, int j);
void selectionSort(int a[], int n);
void selectionSort_rec(int a[], int n);
void mergeSort(int a[], int levi, int desni);
void quickSort(int a[],  int levi, int desni);

#endif
