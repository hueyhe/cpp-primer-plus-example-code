// using the new operator

#include <iostream>

int main() {
  using namespace std;

  int nights = 1001;
  int* pt = new int;
  *pt = 1001;

  cout << "nights value = " << nights;
  cout << nights << ": location " << &nights << endl;
  cout << "int value = " << *pt << ": location" << pt << endl;

  double* pd = new double;
  *pd = 10000001.0;

  cout << "double value = " << *pd << ": location" << pd << endl;
  cout << "size of pt = " << sizeof(pt);
  cout << ": size of *pt = " << sizeof(*pt) << endl;
  cout << "size of pd = " << sizeof(pd);
  cout << ": size of *pd = " << sizeof(*pd) << endl;

  return 0;
}
