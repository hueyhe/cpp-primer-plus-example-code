// reading chars to end of file

#include <iostream>

int main() {
  using namespace std;

  char ch;
  int count = 0;
  cin.get(ch);
  while (cin.fail() == false) {
    cout << ch;
    count += 1;
    cin.get(ch);
  }
  cout << endl << count << " characters read\n";

  return 0;
}
