// more looping with for

#include <iostream>

const int ArSize = 16;

int main() {
  using namespace std;

  long long factorials[ArSize];
  factorials[1] = factorials[0] = 1LL;
  for (int i = 2; i < ArSize; i += 1) {
    factorials[i] = i * factorials[i - 1];
  }
  for (int i = 0; i < ArSize; i += 1) {
    std::cout << i << "! = " << factorials[i] << std::endl;
  }

  return 0;
}
