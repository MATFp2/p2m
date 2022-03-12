// suma brojeva od 1 do n

#include <stdio.h>

// za vezbu napisati iterativnu fju sa minimalnim brojem izracunavanja
// bez petlje

/* rekurzivna fja - ilustracija
   suma(5) = 5 + [4 + 3 + 2 + 1]
           = 5 + suma(4)
   suma(4) = 4 + 3 + 2 + 1 = 
           = 4 + suma(3)
   suma(3) = 3 + 2 + 1 
           = 3 + suma(2)
   suma(2) = 2 + 1
           = 2 + suma(1)
   suma(1) = 1    ----- izlaz iz rekurzije

 */

int suma(int n){
  if (n <=0)
    return 0;
  
  // bez prethodnog dela koda, radilo bi samo za brojeve >=1
  // vrednosti 0 i negativni brojevi bi pravili beskonacnu rekurziju

  if (n == 1)
    return 1;
  else
    return n + suma(n-1);
}

int main(int argc, char* argv[]){
  int x;
  scanf("%d", &x);
  printf("Suma brojeva od 1 do %d je %d.\n", x, suma(x));
  return 0;
}
