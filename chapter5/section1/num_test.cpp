// use numeric test in for loop

#include <iostream>

int main() {
  using namespace std;

  cout << "Enter the starting countdown value: ";
  int limit;
  cin >> limit;
  int i;
  for (i = limit; i; i -= 1) {
    cout << "i = " << i << endl;
  }
  cout << "Done now that i = " << i << "\n";

  return 0;
}
