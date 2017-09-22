#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1234;
 
int b[N][N];
int a[N];
 
int main() {
  int n, tt;
  scanf("%d %d", &n, &tt);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", b[i] + j);
    }
  }
  a[0] = 0;
  for (int i = 1; i < n; i++) {
    a[i] = b[0][i];
    bool ok = true;
    for (int j = 0; j < i; j++)
      if (abs(a[i] - a[j]) != b[i][j]) {
        ok = false;
        break;
      }
    if (!ok)
      a[i] = -b[0][i];
  }

  for (int qq = 0; qq <= tt; qq++) {
    for (int i = n - 1; i >= 0; i--) {
      a[i] -= a[0];
    }
    for (int i = 1; i < n; i++) {
      if (a[i] == 0) {
        continue;
      }
      if (a[i] > 0) {
        for (int j = i; j < n; j++) {
          a[j] = -a[j];
        }
      }
      break;
    }
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        putchar(' ');
      }
      printf("%d", a[i]);
    }
    printf("\n");
    if (qq < tt) {
      int id;
      scanf("%d", &id);
      id--;
      for (int i = 0; i < n; i++) {
        int foo;
        scanf("%d", &foo);
        b[id][i] = b[i][id] = foo;
      }
      int other = (id + 1) % n;
      a[id] = a[other] + b[other][id];
      bool ok = true;
      for (int i = 0; i < n; i++) {
        if (abs(a[i] - a[id]) != b[id][i]) {
          ok = false;
          break;
        }
      }
      if (!ok) {
        a[id] = a[other] - b[other][id];
      }
    }
  }//end big for loop
  return 0;
}
