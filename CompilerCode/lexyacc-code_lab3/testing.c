/* Type your code helongre, or load an example. */
#include <stdio.h>

int array[256];

int main() {
  int n = 1000001;
  int s = 100000000;
  int a = 0;
  int d = 0;
  int t = 0;
  while (n > 0) {
    if (t == 0) {
      d = n;
      t = 1;
    } else {
      d = -n;
      t = 0;
    }
    a = a + s / d;
    n = n - 2;
  }
  printf("%d\n", a / (s / 100000) * 4);
}