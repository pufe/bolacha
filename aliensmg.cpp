#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int main() {
  set<string> s;
  int n;
  char dna[128];
  while(true) {
    s.clear();
    scanf(" %d", &n);
    if (n==0)
      break;
    for(int i=0; i<n; ++i) {
      scanf("%s", dna);
      sort(dna, dna+strlen(dna));
      s.insert(string(dna));
    }
    printf("%lu\n", s.size());
  }
  return 0;
}
