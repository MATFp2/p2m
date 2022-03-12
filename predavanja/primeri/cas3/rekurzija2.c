#include <stdio.h>

// rekurzija koja racuna sumu elemenata niza a, duzine n

int suma_niza(int a[], unsigned n){
  if (n == 0)
    return 0;
  else {
    // izdvojimo poslednji element i rekurzivno pozovemo fju za ostatak niza
    // poslednji element je na poz [n-1]
    // ostatak niza je na pozicijama od 0 do n-2
    // ostaje nam niz duzine n-1
    return suma_niza(a, n-1) + a[n-1];
  } 
}

/*
  suma_niza(a, n) = suma_niza([1,2,3,4,5], 5)
  
 s[1,2,3,4,5] = s[1,2,3,4] + 5 
              = (s[1,2,3] + 4) + 5
              = ((s[1,2] + 3) + 4) + 5
	      = (((s[1] + 2) + 3) + 4) + 5
	      = ((((0 + 1) + 2) + 3) + 4) + 5
 */

/*

[1,2,3,4,5] = 1 + [2,3,4,5]
            = 1 + 2 + [3,4,5]
	    ...
 */

int suma_niza_poc(int a[], unsigned n){
  if (n == 0)
    return 0;
  else {
    return a[0] + suma_niza_poc(a + 1, n-1);
  } 
}

// alternativa sa pokazivacima
int suma_niza_poc_pok(int *pa, unsigned n){
  if (n == 0)
    return 0;
  else {
    return *pa + suma_niza_poc_pok(pa + 1, n-1);
  } 
}

int main(int argc, char* argv[]){
  int a[5] = {1,2,3,4,5};

  printf("prva fja: %d\n", suma_niza(a, sizeof(a)/sizeof(int)));
  printf("druga fja: %d\n", suma_niza_poc(a, sizeof(a)/sizeof(int)));
  printf("treca fja: %d\n", suma_niza_poc_pok(a, sizeof(a)/sizeof(int)));
  
  return 0;
}
