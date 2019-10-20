// reading chars with cin.get()

#include <iostream>

int main(void) {
  using namespace std;

  int ch;
  int count = 0;
  while ((ch = cin.get()) != EOF) {
    cout.put(char(ch));
    count += 1;
  }
  cout << endl << count << " characters read\n";

  return 0;
}
