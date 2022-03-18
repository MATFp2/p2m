#include <stdio.h>

int nzd(int a, int b){

  printf("nzd(%d, %d): \n", a, b);
  
  if (b == 0)
    return a;
  else
    return nzd(b, a%b);
}

/*
stek okviri rekurzivnih poziva:

nzd(3,0): a = 3, b = 0 ---> vraca 3
------------------------------------
nzd(6,3): a = 6, b = 3
return nzd(b, a%b);
------------------------------------
nzd(9,6): a = 9, b = 6
------------------------------------
nzd(15,9): a = 15, b = 9
------------------------------------
main 
 */

/*
nakon sto se primeti da je ovaj rekurzivni poziv u stvari 
repna rekurzija, stek okviri se nece praviti vec ce se sve 
izvrsavati u jednom okviru:

nzd(3,0) vraca 3
main
 */

/* 
Uzastopni rekurzivni pozivi:

  nzd(9,15)
  nzd(15,9)
  nzd(9,6)
  nzd(6,3)
  nzd(3,0)
 */

int nzd_it(int a, int b){
  // ovo se moze pretvoriti u petlju
  /*
  while(1){
    if (b == 0)
      return a;
    else {
      // moramo da vodimo racuna da kada promenljive zavise jedna od druge
      // treba da uvedemo privremenu promenljivu
      int p = a%b; // p = 6
      a = b;       // a = b = 9
      b = p;       // b = p = 6
    }
  */
  while (b!=0){
    int p = a%b;
    a = b;
    b = p;
  }

  return a;
}

int main(int argc, char* argv[]){
  int a, b;
  scanf("%d%d", &a, &b);
  printf("nzd(%d,%d)=%d\n", a, b, nzd(a,b));
  printf("nzd_it(%d,%d)=%d\n", a, b, nzd_it(a,b));
  return 0;
}


/*

- Direktna rekurzija
- Indirektna rekurzija, uzajamna rekurzija

A --> B
B --> A

definiciju aritmetickog izraza sa operatorima + i *:
- 9, 12, 8
- (5 * 3) + (4 * 2) + (11 * 4)
- (5 * 3) + (4 * 2) + (11 * ((_*_)))

IZRAZ = niz SABIRAKA razdvojeni operacijom + (ukljucujuci i jedan sabirak)
SABIRAK = niz CINILACA razdvojeni operatorom * (ukljucujuci i jedan cinilac)
CINILAC = PRIRODAN_BROJ ili (IZRAZ)



 */
