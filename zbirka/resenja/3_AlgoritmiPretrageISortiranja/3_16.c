/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jelena Graovac, Nina Radojicic,
*             Ana Spasic, Mirko Spasic, Andjelka Zecevic
******************************************************************/

#include <stdio.h>
#include "sort.h"

#define MAX_DIM 256

/* Funkcija za binarnu pretragu niza vraca 1 ako se element x
   nalazi u nizu, a 0 inace. Pretpostavlja se da je niz sortiran u
   rastucem poretku */
int binarna_pretraga(int a[], int n, int x)
{
  int levi = 0, desni = n - 1, srednji;

  while (levi <= desni) {
    srednji = (levi + desni) / 2;
    if (a[srednji] == x)
      return 1;
    else if (a[srednji] > x)
      desni = srednji - 1;
    else if (a[srednji] < x)
      levi = srednji + 1;
  }
  return 0;
}

int main()
{
  int a[MAX_DIM], n = 0, zbir, i;

  /* Ucitava se trazeni zbir */
  printf("Unesite trazeni zbir: ");
  scanf("%d", &zbir);

  /* Ucitavaju se elementi niza sve do kraja ulaza */
  i = 0;
  printf("Unesite elemente niza: ");
  while (scanf("%d", &a[i]) != EOF)
    i++;
  n = i;

  /* Za sortiranje niza moze se koristiti bilo koja od funkcija
     sortiranja iz sort.h. Ilustracije radi, u ovom zadatku koristi
     se quick sort. */
  quick_sort(a, 0, n - 1);

  for (i = 0; i < n; i++)
    /* Za i-ti element niza binarno se pretrazuje da li se u
       ostatku niza nalazi element koji sabran sa njim ima ucitanu
       vrednost zbira */
    if (binarna_pretraga(a + i + 1, n - i - 1, zbir - a[i])) {
      printf("da\n");
      return 0;
    }
  printf("ne\n");

  return 0;
}
