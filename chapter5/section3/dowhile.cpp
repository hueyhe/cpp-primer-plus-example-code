// exit-condition-loop

#include <iostream>

int main() {
  using namespace std;

  int n;
  cout << "Enter numbers in the range 1-10 to find ";
  cout << "my favorite number\n";
  do {
    cin >> n;
  } while (n != 2);
  cout << "Yes, 2 is my favorite.\n";

  return 0;
}
