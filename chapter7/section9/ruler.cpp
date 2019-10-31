// using recursion to subdivide a ruler

#include <iostream>

const int Len = 66;
const int Divs = 6;

void subdivide(char ar[], int low, int high, int level);

int main() {
  char ruler[Len];
  int i;
  for (i = 1; i < Len - 2; i += 1) {
    ruler[i] = ' ';
  }
  ruler[Len - 1] = '\0';
  int max = Len - 2;
  int min = 0;
  ruler[min] = ruler[max] = '|';
  std::cout << ruler << std::endl;
  
  for (i = 1; i <= Divs; i += 1) {
    subdivide(ruler, min, max, i);
    std::cout << ruler << std::endl;
    for (int j = i; j < Len - 2; j += 1) {
      ruler[j] = ' ';
    }
  }

  return 0;
}

void subdivide(char ar[], int low, int high, int level) {
  if (level == 0) {
    return;
  }
  int mid = (high + low) / 2;
  ar[mid] = '|';
  subdivide(ar, low, mid, level - 1);
  subdivide(ar, mid, high, level - 1);
}
