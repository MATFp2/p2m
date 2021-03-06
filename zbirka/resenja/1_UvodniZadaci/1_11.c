/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jelena Graovac, Nina Radojicic,
*             Ana Spasic, Mirko Spasic, Andjelka Zecevic
******************************************************************/

#include <stdio.h>

/* Funkcija vraca 1 ukoliko je u binarnoj reprezentaciji broja n
   broj jedinica veci od broja nula. U suprotnom funkcija vraca 0 */
int broj_01(unsigned int n)
{
  int broj_nula, broj_jedinica;
  unsigned int maska;

  broj_nula = 0;
  broj_jedinica = 0;

  /* Maska je inicijalizovana tako da moze da analizira bit najvece
     tezine */
  maska = 1 << (sizeof(unsigned int) * 8 - 1);

  /* Cilj je proci kroz sve bitove broja x, zato se maska u svakoj
     iteraciji pomera u desno pa ce jedini bit koji je postavljen
     na 1 biti na svim pozicijama u binarnoj reprezentaciji maske */
  while (maska != 0) {
    /* Proverava se da li se na poziciji koju odredjuje maska
       nalazi 0 ili 1 i uvecava se odgovarajuci brojac. */
    if (n & maska) {
      broj_jedinica++;
    } else {
      broj_nula++;
    }

    /* Pomera se maska u desnu stranu */
    maska = maska >> 1;
  }

  /* Ako je broj jedinica veci od broja nula funkcija vraca 1, u
     suprotnom vraca 0 */
  return (broj_jedinica > broj_nula) ? 1 : 0;
}

int main()
{
  unsigned int n;

  /* Ucitava se neoznacen broj */
  scanf("%u", &n);

  /* Ispisuje se rezultat */
  printf("%d\n", broj_01(n));

  return 0;
}
