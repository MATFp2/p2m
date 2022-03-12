#include <stdio.h>

// fje se podrazumevano vide u svim ostalim .c fajlovima
// eksterno linkovanje
int f(int x){
  int broj = 4;
  printf("%d\n", broj);
  return broj;
}

// fja koja je vidljiva samo u ovoj datoteci
static int g(int x){
  return 1;
}

// promenjive podrazumevano imaju unutrasnje linkovanje
int a;

// ako zelimo pristup iz drugih fajlova
extern int a;

/*

primer2.c    --> primer2.o
                                   --> jedan objedinjeni izvrsni fajl
biblioteka.c --> biblioteka.o

 */
