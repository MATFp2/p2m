#include <stdio.h>

void selection_sort_int(int a[], int n){
  int i,j;

  // na poziciju i zelimo da dovedemo min element ostatka niza
  for(i=0; i<n-1; i++){       // i uzima vrednosti od 0 do n-1
    for(j=i+1; j<n; j++){   // j uzima vrednosti od i+1 do n-1
      if (a[j] < a[i]){
	// zamenimo elemente niza na poz i i j
	int tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
      }
    }
  }
}

/*
tri razlike:
- tip prvog argumenta fje
- tip pomocne promenljive
- operacija poredjenja

 */

void selection_sort_float(float a[], int n){
  int i,j;

  // na poziciju i zelimo da dovedemo min element ostatka niza
  for(i=0; i<n-1; i++){       // i uzima vrednosti od 0 do n-1
    for(j=i+1; j<n; j++){   // j uzima vrednosti od i+1 do n-1
      if (a[j] < a[i]){
	// zamenimo elemente niza na poz i i j
	float tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
      }
    }
  }
}

int main(){
  int a[] = {5, 8, 2, 4};
  int n = sizeof(a)/sizeof(int);

  float b[] = {5.2, 8.1, 2.5, 4.3};
  int m = sizeof(b)/sizeof(float);
  
  int i;
  
  selection_sort_int(a, n);

  selection_sort_float(b, m);
  
  for(i=0; i<n; i++)
    printf("%d ", a[i]);
  printf("\n");

  for(i=0; i<m; i++)
    printf("%.2f ", b[i]);
  printf("\n");

  return 0;
}
