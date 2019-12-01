// using format manipulators
#include <iostream>

int main() {
  using namespace std;

  cout << "Enter an integer: ";
  int n;
  cin >> n;

  cout << "n     n*n\n";
  cout << n << "     " << n * n << " (decimal)\n";

  // set to hex mode
  cout << hex;
  cout << n << "     " << n * n << " (hexadecimal)\n";

  // set to octal mode
  cout << oct;
  cout << n << "     " << n * n << " (octal)\n";

  dec(cout);
  cout << n << "     " << n * n << " (decimal)\n";

  return 0;
}
