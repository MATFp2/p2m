#include <stdio.h>

// rekurzivna fja koja racuna broj cifara

/*
 kada izdvajamo cifre broja
 poslednju cifru dobijamo - n%10
 rekurzivnom pozivu prosledjujemo n/10
 n = 123; 
 n = n/10 = 12;
 n = n/10 = 1;
 n = n/10 = 0; 

*/

// if (n<0) n=-n;

int br(int n){
  if (n == 0)
    return 0;
  else
    return 1 + br(n/10);
}

int main(int argc, char* argv[]){
  int x;
  scanf("%d", &x);
  printf("Broj cifara broja %d je %d.\n", x, br(x));
  return 0;
}

