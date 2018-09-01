#include <cstdio>

int main() {
  int notas_de_50;
  int notas_de_10;
  int notas_de_5;
  int notas_de_1;
  int num_teste=1;
  int valor_a_ser_pago;

  while(true) {
    scanf("%d", &valor_a_ser_pago);
    if (valor_a_ser_pago==0)
      break;

    printf("Teste %d\n", num_teste);
    num_teste++;
    //  x+=y -> x=x+y

    notas_de_50 = valor_a_ser_pago/50;
    valor_a_ser_pago %= 50;

    notas_de_10 = valor_a_ser_pago/10;
    valor_a_ser_pago -= 10*notas_de_10;

    notas_de_5 = valor_a_ser_pago/5;
    valor_a_ser_pago -= 5*notas_de_5;

    notas_de_1 = valor_a_ser_pago;

    printf("%d %d %d %d\n", notas_de_50,
           notas_de_10, notas_de_5, notas_de_1);
    printf("\n");
  }

  return 0;
}
