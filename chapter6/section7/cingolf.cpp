// non-numeric input skipped

#include <iostream>

const int Max = 5;

int main() {
  using namespace std;

  int golf[Max];
  cout << "Please enter your golf socres.\n";
  cout << "You must enter " << Max << " rounds.\n";
  int i;
  for (i = 0; i < Max; i += 1) {
    cout << "round #" << i + 1 << ": ";
    while (!(cin >> golf[i])) {
      cin.clear();
      while (cin.get() != '\n') {
        continue;
      }
      cout << "Please enter a number: ";
    }
  }
  double total = 0.0;
  for (i = 0; i < Max; i += 1) {
    total += golf[i];
  }
  cout << total / Max << " = average score "
       << Max << " rounds\n";

  return 0;
}
