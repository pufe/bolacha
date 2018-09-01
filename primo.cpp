#include <cstdio>
#include <cmath>

int main() {
  int num,a,b;
  scanf("%d",&num);
  b=0;
  for(int x=2; x*x <= num; ++x){ // O(sqrt(n))
    a=num%x;
    if (a==0) {
      b++; // divisor
      break;
    }
  }
  if(b==0){
    printf("sim\n");
  }
  else
    printf("nao\n");
  return 0;
}


/*

  estou testando se Y é primo

  se X divide Y

  então existe Z = Y/X

  Y/Z = X

  então Z divide Y também

 */
