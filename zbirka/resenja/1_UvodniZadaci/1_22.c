/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jelena Graovac, Nina Radojicic,
*             Ana Spasic, Mirko Spasic, Andjelka Zecevic
******************************************************************/

#include <stdio.h>

/* Funkcija odredjuje zbir cifara zadatog broja x */
int zbir_cifara(unsigned int x)
{
  /* Izlazak iz rekurzije: ako je broj jednocifren */
  if (x < 10)
    return x;

  /* Zbir cifara broja jednak je zbiru svih njegovih cifara osim
     poslednje cifre + poslednja cifra tog broja */
  return zbir_cifara(x / 10) + x % 10;
}

int main()
{
  unsigned int x;

  /* Ucitava se ceo broj */
  scanf("%u", &x);

  /* Ispisuje se zbir cifara ucitanog broja */
  printf("%d\n", zbir_cifara(x));

  return 0;
}
