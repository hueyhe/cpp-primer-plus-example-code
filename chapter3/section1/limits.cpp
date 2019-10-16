// some integer limits

#include <iostream>
#include <climits>

int main() {
  using namespace std;

  int nInt = INT_MAX;
  short nShort = SHRT_MAX;
  long nLong = LONG_MAX;
  long long nLlong = LLONG_MAX;

  // sizeof operator yields size of type or of variable
  cout
    << "int is "
    << sizeof (int)
    << " bytes."
    << endl;

  cout
    << "short is "
    << sizeof nShort
    << " bytes."
    << endl;

  cout
    << "long is "
    << sizeof nLong
    << " bytes."
    << endl;

  cout
    << "long long is "
    << sizeof nLlong
    << " bytes."
    << endl;

  cout << endl;

  cout
    << "Maximum value:"
    << endl;
  cout
    << "int: "
    << nInt
    << endl;
  cout
    << "short: "
    << nShort
    << endl;
  cout
    << "long: "
    << nLong
    << endl;
  cout
    << "long long: "
    << nLlong
    << endl;

  cout
    << "Minimum int value = "
    << INT_MIN
    << endl;
  cout
    << "Bits per byte = "
    << CHAR_BIT
    << endl;

  return 0;
}
