/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jelena Graovac, Nina Radojicic,
*             Ana Spasic, Mirko Spasic, Andjelka Zecevic
******************************************************************/

#include <stdio.h>

/* Funkcija broji koliko se puta dve uzastopne jedinice pojavljuju
   u binarnom zapisu celog neoznačenog broja x */
int broj_parova(unsigned int x)
{
  int broj_parova;
  unsigned int maska;

  /* Vrednost promenljive koja predstavlja broj parova se
     inicijalizuje na 0 */
  broj_parova = 0;

  /* Postavlja se maska tako da moze da procita da li su dva
     najmanja bita u zapisu broja x 11 */
  /* Binarna reprezentacija broja 3 je 000....00011 */
  maska = 3;

  while (x != 0) {
    /* Proverava se da li se na najmanjim pozicijama broja x nalazi
       par bitova 11 */
    if ((x & maska) == maska) {
      broj_parova++;
    }

    /* Pomera se broj u desnu stranu da bi se u narednoj iteraciji
       proveravao sledeci par bitova. Pomeranjem u desno bit
       najvece tezine se popunjava nulom jer je x neoznacen broj */
    x = x >> 1;
  }

  /* Vraca se izracunata vrednost */
  return broj_parova;
}

int main()
{
  unsigned int x;

  /* Ucitava se neoznacen broj */
  scanf("%u", &x);

  /* Ispisuje se rezultat */
  printf("%d\n", broj_parova(x));

  return 0;
}
