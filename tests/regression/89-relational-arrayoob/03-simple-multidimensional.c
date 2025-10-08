// PARAM: --enable ana.arrayoob --enable ana.int.interval --set ana.activated[+] apron

// Multidimensional, only checking the length of the outer array
// current relational analysis does not check 2nd dimension

#include <stdlib.h>

int main() {

  int len = rand() % 10 + 1;
  int len2 = rand() % 10 + 1;
  int arr[len][len2];

  arr[0][0] = 10;       // NOWARN
  arr[len - 1][0] = 10; // NOWARN
  arr[-1][0] = -1;      // WARN
  arr[len][0] = 10;     // WARN

  arr[0][len2 - 1] = 10; // NOWARN , but not detected

  for (int i = 0; i < len; ++i) {
    arr[i - 1][0] = 1; // WARN
    arr[i][0] = 1;     // NOWARN
    arr[i + 1][0] = 1; // WARN
  }
  return 0;
}
