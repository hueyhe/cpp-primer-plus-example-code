// reading chars with a while loop

#include <iostream>

int main() {
  using namespace std;

  char ch;
  int count = 0;
  cout << "Enter characters; enter # to quit:\n";
  cin >> ch;
  while (ch != '#') {
    cout << ch;
    count += 1;
    cin >> ch;
  }
  cout << endl << count << " characters read\n";

  return 0;
}
