/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jelena Graovac, Nina Radojicic,
*             Ana Spasic, Mirko Spasic, Andjelka Zecevic
******************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX 256

int prvi_veci_od_nule(int niz[], int n)
{
  /* Granice pretrage */
  int l = 0, d = n - 1;
  int s;
  /* Sve dok je leva manja od desne granice */
  while (l <= d) {
    /* Racuna se sredisnja pozicija */
    s = (l + d) / 2;
    /* Ako je broj na toj poziciji veci od nule, a eventualni
       njegov prethodnik manji ili jednak nuli, pretraga je
       zavrsena */
    if (niz[s] > 0 && ((s > 0 && niz[s - 1] <= 0) || s == 0))
      return s;
    /* U slucaju broja manjeg ili jednakog nuli, pretrazuje se
       desna polovina niza */
    if (niz[s] <= 0)
      l = s + 1;
    /* A inace, leva polovina */
    else
      d = s - 1;
  }
  return -1;
}

int main()
{
  int niz[MAX];
  int n = 0;

  /* Unos niza */
  while (scanf("%d", &niz[n]) == 1)
    n++;

  /* Stampa se rezultat */
  printf("%d\n", prvi_veci_od_nule(niz, n));

  return 0;
}
