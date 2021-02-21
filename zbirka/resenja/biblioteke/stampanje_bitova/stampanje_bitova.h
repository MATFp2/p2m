/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jelena Graovac, Nina Radojicic,
*             Ana Spasic, Mirko Spasic, Andjelka Zecevic
******************************************************************/

#ifndef _STAMPANJE_BITOVA_H
#define _STAMPANJE_BITOVA_H

/* Funkcija prikazuje na standardni izlaz binarnu reprezentaciju
   celog broja u memoriji. Bitove koji predstavljaju binarnu
   reprezentaciju broja treba ispisati sa leva na desno, tj. od
   bita najvece tezine ka bitu najmanje tezine */
void stampaj_bitove(unsigned x);

/* Funkcija prikazuje na standardni izlaz binarnu reprezentaciju
   celog broja tipa 'short' u memoriji. */
void stampaj_bitove_short(short x);

/* Funkcija prikazuje na standardni izlaz binarnu reprezentaciju
   karaktera u memoriji. */
void stampaj_bitove_char(char x);

#endif
