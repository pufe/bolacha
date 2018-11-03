#include <cstdio>

int main() {
  int n, quadrado;
  int levado[20];
  int tamanho;
  bool encontrei;

  while(true) {
    scanf(" %d", &n);
    if (n==0)
      break;
    encontrei=false;
    quadrado = n*n;
    tamanho=0;
    while(quadrado>0) {
      levado[tamanho]=quadrado%10;
      tamanho++;
      quadrado=quadrado/10;
    }
    for(int i=0; i<tamanho/2; ++i) {
      int tmp=levado[i];
      levado[i]=levado[tamanho-i-1];
      levado[tamanho-i-1]=tmp;
    }
    for(int corte=0; corte<tamanho+1; ++corte) { // onde cortar
      int b=0;
      for(int j=0; j<corte; ++j) {
        b=10*b+levado[j];
        //printf("B ");
      }

      int a=0;
      for(int j=corte; j<tamanho; ++j) {
        a=10*a+levado[j];
        //printf("A ");
      }
      //printf("\n");
      //for(int j=0; j<tamanho; ++j)
      //  printf("%d ", levado[j]);
      //printf("\na=%d, b=%d\n", a, b);
      if (a+b==n && a>0 && b>0)
        encontrei=true;
    }
    if (encontrei || n==1)
      printf("%d: S\n", n);
    else
      printf("%d: N\n", n);
  }
  return 0;
}
