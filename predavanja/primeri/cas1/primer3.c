#include <stdio.h>

int g = 0;

int f(int x){
  int a = 0; // lokalna promenljiva za fju f

  for(int i=0; i<5; i++){

    int b = i+1; // lokalna za for petlju
    
    printf("%d\n", b);
    
    /*
    int a = i+1; // lokalna za for petlju
    // ovo a skriva prethodno a --- treba izbegavati
    
    printf("%d\n", a);
    */
  }

  // ponovno koriscenje promenljivih je dozvoljeno na naredni nacin
  for(int i=0; i<10; i++){
    int b;
    printf("%d\n", i);

  }
  
  return 0;
}

int main(){
  f(0);
  return 0;
}
