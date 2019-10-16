// some C++ arithmetic

#include <iostream>

int main() {
  using namespace std;

  float hats, heads;
  cout.setf(ios_base::fixed, ios_base::floatfield);
  cout << "Enter a number: ";
  cin >> hats;
  cout << "Enter another number: ";
  cin >> heads;

  cout << "hats = " << hats << ", heads = " << heads << endl;
  // The result is very interesting.
  // @ref https://0.30000000000000004.com/
  cout << "hats + heads = " << hats + heads << endl;
  cout << "hats - heads = " << hats - heads << endl;
  cout << "hats * heads = " << hats * heads << endl;
  cout << "hats / heads = " << hats / heads << endl;

  return 0;
}
