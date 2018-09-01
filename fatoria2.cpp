#include <cstdio>
int main(){

  int x,fatorial;
scanf("%d",&x);
fatorial=1;

  for(int i=1;i<=x;++i) {
  fatorial=fatorial*i;

 }
printf("%d\n",fatorial);

 return 0;
}
