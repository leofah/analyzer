// PARAM: --enable ana.arrayoob --enable ana.int.interval --set ana.activated[+] apron --set ana.apron.domain polyhedra

// array is initialized with an expression. Polyhedra domain needed.
//
#include <stdlib.h>

int main() {

  int len = rand() % 10 + 1;
  int arr[2 * len];

  for (int i = 0; i < 2 * len; ++i) {
    arr[i] = 1; // NOWARN
  }
  return 0;
}
