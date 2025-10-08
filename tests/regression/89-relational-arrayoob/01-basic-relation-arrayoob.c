// PARAM: --enable ana.arrayoob --enable ana.int.interval --set ana.activated[+] apron

// Basic relational array out of bounce check

#include <stdlib.h>

int main() {

  int len = rand() % 10 + 1;
  int arr[len];

  arr[0] = 0; // NOWARN
  arr[len - 1] = len; // NOWARN
  arr[-1] = -1; // WARN
  arr[len] = len; // WARN

  for (int i = 0; i < len; ++i) {
    arr[i - 1] = 1; // WARN
    arr[i] = 1; // NOWARN
    arr[i + 1] = 1; // WARN
  }
  return 0;
}
