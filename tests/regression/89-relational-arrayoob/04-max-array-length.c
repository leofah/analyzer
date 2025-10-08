// PARAM: --enable ana.arrayoob --enable ana.int.interval --set ana.activated[+] apron

// Array with max length

#include <stdlib.h>
#include <stdint.h>

int main() {

  int len = rand() % SIZE_MAX;
  int arr[len];

  for (int i = 0; i < len; ++i) {
    arr[i] = 1; // NOWARN
  }

  return 0;
}
