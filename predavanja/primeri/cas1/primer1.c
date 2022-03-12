// primer1.c

#include <stdio.h>

// DOSEG PROMENLJIVIH
// deo koda u kome je promenljiva vidljiva

// globalna promenljiva --- doseg je cela datoteka
int globalna = 10;

// fja f ima globalni dosek
int f(){
  // lokalna promenljiva za fju f
  int broj = 3;

  globalna = globalna - 2;

  /* 
  int f1(){
    //...
  }
  */

  if (broj) {
    //doseg nivoa bloka -- ovih viticastih zagrada
    int i=0;
    i = i + broj + globalna;
  }

  // greska ako pokusamo da pristupimo promenljivoj "i"
  // van bloka u kome je uvedena
  // broj = broj + i;
  
  return broj;
}

// doseg nivoa prototipa fje
int min(int x, int y);

// doseg nivoa funkcije -- labele uz goto komandu

// ZIVOTNI VEK PROMENLJIVE

// staticki zivotni vek: vide se i postoje u toku celog izvrsavanja programa
// globalne promenljive

// automatski zivotni vek: promenljive koje su deklarisane u blokovima

int g(){

  //staticka promenljiva 
  static int broj_poziva = 0;
  
  broj_poziva++;
}

// dinamicki zivotni vek
int *p = (int *) malloc(10*sizeof());
//...
free(p);

int main(){
  // lokalna promenljiva za fju main
  int lokalna = 8;

  printf("%d\n", globalna);  
    
  globalna = globalna - 2;
  printf("%d\n", globalna);  

  printf("%d\n", f());
  printf("%d\n", globalna);  
  
  return 0;
}
