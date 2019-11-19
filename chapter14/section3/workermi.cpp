// working class methods with MI
#include <iostream>
#include "workermi.h"

using std::cout;
using std::cin;
using std::endl;

Worker::~Worker() {}

void Worker::getData() const {
  cout << "Name: " << fullname << endl;
  cout << "Employee ID: " << id << endl;
}

void Worker::get() {
  getline(cin, fullname);
  cout << "Enter worker's ID: ";
  cin >> id;
  while (cin.get() != '\n') {
    continue;
  }
}

// Waiter methods
void Waiter::set() {
  cout << "Enter waiter's name: ";
  Worker::get();
  get();
}

void Waiter::show() const {
  cout << "Category waiter\n";
  Worker::getData();
  getData();
}

void Waiter::getData() const {
  cout << "Panache rating: " << panache << endl;
}

void Waiter::get() {
  cout << "Enter waiter's panache rating: ";
  cin >> panache;
  while (cin.get() != '\n') {
    continue;
  }
}

// Singer methods
char * Singer::pv[] = {
  "other", "alto", "contralto",
  "soprano", "brass", "baritone", "tenor"
};

void Singer::set() {
  cout << "Enter singer's name: ";
  Worker::get();
  get();
}

void Singer::show() const {
  cout << "Category singer\n";
  Worker::getData();
  getData();
}

void Singer::getData() const {
  cout << "Vocal range: " << pv[voice] << endl;
}

void Singer::get() {
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

// SingingWaiter methods
void SingingWaiter::getData() const {
  Singer::getData();
  Waiter::getData();
}

void SingingWaiter::get() {
  Waiter::get();
  Singer::get();
}

void SingingWaiter::set() {
  cout << "Enter singing waiter's name: ";
  Worker::get();
  get();
}

void SingingWaiter::show() const {
  cout << "Category singing waiter\n";
  Worker::getData();
  getData();
}
