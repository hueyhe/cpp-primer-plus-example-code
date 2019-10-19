// count as directed

#include <iostream>

int main() {
  using std::cout;
  using std::cin;
  using std::endl;

  int by;
  cout << "Enter an integer: ";
  cin >> by;
  cout << "Counting by " << by << "s:\n";
  for (int i = 0; i < 100; i += by) {
    cout << i << endl;
  }

  return 0;
}
