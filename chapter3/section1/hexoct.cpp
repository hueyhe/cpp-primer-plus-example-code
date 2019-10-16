#include <iostream>

int main() {
  using namespace std;

  int chest = 42;
  int waist = 0x42;
  int inseam = 042;

  cout << "Monsieur cuts a striking figure!\n";
  cout << "chest = " << chest << " (42 in decimal)\n";
  cout << "waist = " << waist << " (42 in hex)\n";
  cout << "inseam = " << inseam << " (42 in octal)\n";

  return 0;
}
