#include<stdio.h>
#include <stdlib.h>
#include <string.h>
/* Funkcija sortira niz elemenata proizvoljnog tipa koriscenjem
   selection-sort-a. Argumenti funkcije su :
   -adresa pocetka niza data kao void*,
   -broj elemenata niza,
   -velicina jednog elementa niza,
   -funkcija poredjenja dva elementa niza.
*/
void sort(void* a, int n, int size, int (*poredi)(void*,void*))
{
  int i, j;
  for (i = 0; i<n-1; i++)
    for (j = i+1; j<n; j++)
      {
	void* adresa_itog = (char*)a+i*size;
	void* adresa_jtog = (char*)a+j*size;
	if (poredi(adresa_itog, adresa_jtog))
	  {
	    void* tmp = malloc(size);
	    memcpy(tmp, adresa_itog, size);
	    memcpy(adresa_itog, adresa_jtog, size);
	    memcpy(adresa_jtog, tmp, size);
	    free(tmp);
	  }
      }
}

int poredi_br(void* a, void* b) {
  int br_a = *(int*)a;
  int br_b = *(int*)b;
  return br_a < br_b;
}
int poredi_float(void* a, void* b) {
  float br_a = *(float*)a;
  float br_b = *(float*)b;
  if (br_a > br_b) return 1;
  else if (br_a < br_b) return -1;
  else return 0;
}

int main() {
  int a[] = {8, 2, 1, 9, 3, 7, 6, 4, 5};
  float b[] = {0.3, 2, 5, 5.8, 8};
  
  int n = sizeof(a)/sizeof(int);
  int nf = sizeof(b)/sizeof(float);
  int i;
  /* Sortiranje niza celih brojeva */
  sort(a, n, sizeof(int), poredi_br);
  for (i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n");
  /* Sortiranje niza realnih brojeva */
  sort(b, nf, sizeof(float), poredi_float);
  for (i = 0; i < nf; i++)
    printf("%.2f ", b[i]);
  printf("\n");

  return 0;
}
