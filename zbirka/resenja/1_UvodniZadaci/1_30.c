/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jelena Graovac, Nina Radojicic,
*             Ana Spasic, Mirko Spasic, Andjelka Zecevic
******************************************************************/

#include <stdio.h>

/* Rekurzivna funkcija za odredjivanje najvece oktalne cifre */
int maks_oktalna_cifra(unsigned x)
{
  /* Izlazak iz rekurzije: ako je vrednost broja 0, onda je i
     vrednost najvece oktalne cifre u broju 0 */
  if (x == 0)
    return 0;

  /* Odredjuje se poslednja oktalna cifra u broju */
  int poslednja_cifra = x & 7;

  /* Odredjuje se maksimalna oktalna cifra u broju kada se iz njega
     izbrise poslednja oktalna cifra */
  int maks_bez_poslednje_cifre = maks_oktalna_cifra(x >> 3);

  return poslednja_cifra >
      maks_bez_poslednje_cifre ? poslednja_cifra :
      maks_bez_poslednje_cifre;
}

int main()
{
  unsigned x;

  /* Ucitava se neoznacen ceo broj */
  scanf("%u", &x);

  /* Ispisuje se vrednost najvece oktalne cifre unetog broja */
  printf("%d\n", maks_oktalna_cifra(x));

  return 0;
}
