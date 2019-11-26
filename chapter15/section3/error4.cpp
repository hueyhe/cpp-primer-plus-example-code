// using exception classes
#include <iostream>
#include <cmath>
#include "exc_mean.h"

double hmean(double a, double b);
double gmean(double a, double b);

int main() {
  using std::cout;
  using std::cin;
  using std::endl;

  double x, y, z;

  cout << "Enter two numbers: ";
  while (std::cin >> x >> y) {
    try {
      z = hmean(x, y);
      std::cout << "Harmonic mean of " << x << " and " << y
        << " is " << z << std::endl;
      std::cout << "Geometric mean of " << x << " and " << y
        << " is " << gmean(x, y) << std::endl;
      std::cout << "Enter next set of numbers <q to quit>: ";
    } catch (bad_hmean & bh) {
      bh.mesg();
      cout << "Try again.\n";
      continue;
    } catch (bad_gmean & bg) {
      cout << bg.mesg();
      cout << "Values used: " << bg.v1 << ", "
           << bg.v2 << endl;
      cout << "Sorry, you don't get to play any more.\n";
      break;
    }
  }
  std::cout << "Bye!\n";

  return 0;
}

double hmean(double a, double b) {
  if (a == -b) {
    throw bad_hmean(a, b);
  }
  return 2.0 * a * b / (a + b);
}

double gmean(double a, double b) {
  if (a < 0 || b < 0) {
    throw bad_gmean(a, b);
  }
  return std::sqrt(a * b);
}
