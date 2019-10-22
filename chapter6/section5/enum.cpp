// using enum

#include <iostream>

enum {red, orange, yellow, green, blue, violet, indigo};

int main() {
  using namespace std;

  cout << "Enter color code (0-6): ";
  int code;
  cin >> code;
  while (code >= red && code <= indigo) {
    switch (code) {
      case red:
        cout << "Her lips were red.\n";
        break;
      case orange:
        cout << "Her lips were orange.\n";
        break;
      case yellow:
        cout << "Her lips were yellow.\n";
        break;
      case green:
        cout << "Her lips were green.\n";
        break;
      case blue:
        cout << "Her lips were blue.\n";
        break;
      case violet:
        cout << "Her lips were violet.\n";
        break;
      case indigo:
        cout << "Her lips were indigo.\n";
        break;
    }
    cout << "Enter color code (0-6): ";
    cin >> code;
  }
  cout << "Bye!\n";

  return 0;
}
