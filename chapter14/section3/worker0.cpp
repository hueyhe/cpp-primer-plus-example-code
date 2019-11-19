// working class methods
#include <iostream>
#include "worker0.h"

using std::cout;
using std::cin;
using std::endl;

Worker::~Worker() {}

void Worker::set() {
  cout << "Enter worker's name: ";
  getline(cin, fullname);
  cout << "Enter worker's ID: ";
  cin >> id;
  while (cin.get() != '\n') {
    continue;
  }
}

void Worker::show() const {
  cout << "Name: " << fullname << endl;
  cout << "Employee ID: " << id << endl;
}

void Waiter::set() {
  Worker::set();
  cout << "Enter waiter's panache rating: ";
  cin >> panache;
  while (cin.get() != '\n') {
    continue;
  }
}

void Waiter::show() const {
  cout << "Category waiter\n";
  Worker::show();
  cout << "Panache rating: " << panache << endl;
}

char * Singer::pv[] = {
  "other", "alto", "contralto",
  "soprano", "brass", "baritone", "tenor"
};

void Singer::set() {
  Worker::set();
  cout << "Enter number of singer's vocal range:\n";
  int i;
  for (i = 0; i < Vtypes; i++) {
    cout << i << ": " << pv[i] << "   ";
    if (i % 4 == 3) {
      cout << endl;
    }
  }
  if (i % 4 != 0) {
    cout << endl;
  }
  while (cin >> voice && (voice < 0 || voice > Vtypes)) {
    cout << "Please enter a value >= 0 and < " << Vtypes << endl;
  }
  while (cin.get() != '\n') {
    continue;
  }
}

void Singer::show() const {
  cout << "Category singer\n";
  Worker::show();
  cout << "Vocal range: " << pv[voice] << endl;
}
