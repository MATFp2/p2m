/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jelena Graovac, Nina Radojicic,
*             Ana Spasic, Mirko Spasic, Andjelka Zecevic
******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  int i, j;

  /* Pokazivac na niz vrsta matrice realnih brojeva */
  double **A = NULL;

  /* Broj vrsta i broj kolona */
  int n = 0, m = 0;

  /* Trag matice */
  double trag = 0;

  printf("Unesite broj vrsta i broj kolona:\n ");
  scanf("%d%d", &n, &m);

  /* Dinamicki se rezervise prostor za niz vrsta matrice */
  A = (double **) malloc(sizeof(double *) * n);

  /* Proverava se da li je uspelo rezervisanje memorije */
  if (A == NULL) {
    fprintf(stderr, "Greska: Neupesna alokacija memorije.\n");
    exit(EXIT_FAILURE);
  }

  /* Dinamicki se rezervise prostor za elemente u vrstama */
  for (i = 0; i < n; i++) {
    A[i] = (double *) malloc(sizeof(double) * m);

    /* Ukoliko je alokacija neuspesna, pre zavrsetka programa
       potrebno je osloboditi svih i-1 prethodno alociranih vrsta,
       i alociran niz pokazivaca */
    if (A[i] == NULL) {
      for (j = 0; j < i; j++)
        free(A[j]);
      free(A);
      exit(EXIT_FAILURE);
    }
  }

  printf("Unesite elemente matrice po vrstama:\n");
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      scanf("%lf", &A[i][j]);

  /* Izracunava se trag matrice, odnosno suma elemenata na glavnoj
     dijagonali */
  trag = 0.0;

  for (i = 0; i < n; i++)
    trag += A[i][i];

  printf("Trag unete matrice je %.2f.\n", trag);

  /* Oslobadja se prostor rezervisan za svaku vrstu */
  for (j = 0; j < n; j++)
    free(A[j]);

  /* Oslobadja se memorija za niz pokazivaca na vrste */
  free(A);

  exit(EXIT_SUCCESS);
}
