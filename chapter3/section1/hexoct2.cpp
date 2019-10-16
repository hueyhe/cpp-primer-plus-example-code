#include <iostream>

int main() {
  using namespace std;

  int chest = 42;
  int waist = 0x42;
  int inseam = 042;

  cout << "Monsieur cuts a striking figure!\n";
  cout << "chest = " << chest << " (42 in decimal)" << endl;
  cout << hex;
  cout << "waist = " << waist << " (42 in hex)" << endl;
  cout << oct;
  cout << "inseam = " << inseam << " (42 in octal)" << endl;

  return 0;
}
