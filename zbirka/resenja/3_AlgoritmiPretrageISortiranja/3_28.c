/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jelena Graovac, Nina Radojicic,
*             Ana Spasic, Mirko Spasic, Andjelka Zecevic
******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "matrica.h"

/* Funkcija odredjuje zbir v-te vrste matrice a sa m kolona */
int zbir_vrste(int **a, int v, int m)
{
  int i, zbir = 0;

  for (i = 0; i < m; i++) {
    zbir += a[v][i];
  }
  return zbir;
}

/* Funkcija koja sortira vrste matrice (pokazivace na vrste) na
   osnovu zbira elemenata koriscenjem selection sort algoritma */
void sortiraj_vrste(int **a, int n, int m)
{
  int i, j, min;

  for (i = 0; i < n - 1; i++) {
    min = i;
    for (j = i + 1; j < n; j++) {
      if (zbir_vrste(a, j, m) < zbir_vrste(a, min, m)) {
        min = j;
      }
    }
    if (min != i) {
      int *tmp;
      tmp = a[i];
      a[i] = a[min];
      a[min] = tmp;
    }
  }
}

int main(int argc, char *argv[])
{
  int **a, n, m;

  /* Unos dimenzija matrice */
  printf("Unesite dimenzije matrice: ");
  scanf("%d %d", &n, &m);

  /* Alokacija memorije */
  a = alociraj_matricu(n, m);
  if (a == NULL) {
    fprintf(stderr, "Greska: Neuspesna alokacija matrice\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavaju se elementi matrice */
  printf("Unesite elemente matrice po vrstama:\n");
  ucitaj_matricu(a, n, m);

  /* Poziva se funkcija koja sortira vrste matrice prema zbiru */
  sortiraj_vrste(a, n, m);

  /* Ispisuje se rezultujuca matrica */
  printf("Sortirana matrica je:\n");
  ispisi_matricu(a, n, m);

  /* Oslobadja se memorija */
  a = dealociraj_matricu(a, n);

  exit(EXIT_SUCCESS);
}
