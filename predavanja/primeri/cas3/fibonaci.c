#include <stdio.h>

/*

  prva dva elementa: 1 1 
  svaki sledeci je zbir prethodna dva: 

  1 1 2 3 5 8 13 21 ...     --- vrednosti fibonacijevog niza
  0 1 2 3 4 5 6  7 ...      --- pozicije u nizu
  ........4
 */

// rekurzivnu fju koja racuna n-ti fibonacijev broj

int fib(int n){
  if (n<=1)
    return 1;
  else
    // [n-2] [n-1] [n]
    return fib(n-2) + fib(n-1);
    
}

// za vezbu: iscrtati stek okvire za fib(4)

/*
        f(4)
      /      \
    f(2)      f(3)
   /    \      /  \
  f(0) f(1)  f(1) f(2)
  |     |     |   /   \
  1     1     1  f(0) f(1)
                 |     |
                 1     1


 */

// iterativna fja za racunanje fibonacijevog broja na poziciji n
int fib_it(int n){
  int prvi, drugi, tekuci;
  prvi = 1;
  drugi = 1;

  for(int i=1; i<n; i++){
    // tekuci je zbir prethodna dva elementa
    // prvi drugi tekuci ....
     tekuci = prvi + drugi;

    // ...  prvi  drugi
     prvi = drugi;
     drugi = tekuci;
  }
  return drugi;
}


int main(int argc, char* argv[]){
  int n;
  scanf("%d", &n);
  printf("Fib(%d) = %d\n", n, fib(n));
  printf("Fib(%d) = %d\n", n, fib_it(n));
  
  return 0;
}
