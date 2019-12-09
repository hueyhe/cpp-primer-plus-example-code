// an otherwise useless class with move semantics
#include <iostream>

using namespace std;

class Useless {
  private:
    int n;
    char * pc;
    static int ct;
    void showObject() const;

  public:
    Useless();
    explicit Useless(int k);
    Useless(int k, char ch);
    Useless(const Useless & f);
    Useless(Useless && f);
    ~Useless();
    Useless operator+(const Useless & f) const;
    void showData() const;
};

int Useless::ct = 0;

Useless::Useless() {
  ++ct;
  n = 0;
  pc = nullptr;
  cout << "default constructor called; number of objects: " << ct << endl;
  showObject();
}

Useless::Useless(int k): n(k) {
  ++ct;
  cout << "int constructor called; number of objects: " << ct << endl;
  pc = new char[n];
  showObject();
}

Useless::Useless(int k, char ch): n(k) {
  ++ct;
  cout << "int, char constructor called; number of objects: " << ct << endl;
  pc = new char[n];
  for (int i = 0; i < n; i++) {
    pc[i] = ch;
  }
  showObject();
}

Useless::Useless(const Useless & f): n(f.n) {
  ++ct;
  cout << "copy constructor called; number of objects: " << ct << endl;
  pc = new char[n];
  for (int i = 0; i < n; i++) {
    pc[i] = f.pc[i];
  }
  showObject();
}

Useless::Useless(Useless && f): n(f.n) {
  ++ct;
  cout << "move constructor called; number of objects: " << ct << endl;
  pc = f.pc;
  f.pc = nullptr;
  f.n = 0;
  showObject();
}

Useless::~Useless() {
  cout << "destructor called; objects left: " << --ct << endl;
  cout << "deleted object:\n";
  showObject();
  delete [] pc;
}

Useless Useless::operator+(const Useless & f) const {
  cout << "Entering operator+()\n";
  Useless temp = Useless(n + f.n);
  for (int i = 0; i < n; i++) {
    temp.pc[i] = pc[i];
  }
  for (int i = n; i < temp.n; i++) {
    temp.pc[i] = f.pc[i - n];
  }
  cout << "temp object:\n";
  cout << "Leaving operator+()\n";
  return temp;
}

void Useless::showObject() const {
  cout << "Number of elements: " << n;
  cout << " Data address: " << (void *) pc << endl;
}

void Useless::showData() const {
  if (n == 0) {
    cout << "(object empty)";
  } else {
    for (int i = 0; i < n; i++) {
      cout << pc[i];
    }
  }
  cout << endl;
}

int main() {
  {
    Useless one(10, 'x');
    Useless two = one;
    Useless three(20, 'o');
    Useless four (one + three);
    cout << "object one: ";
    one.showData();
    cout << "object two: ";
    two.showData();
    cout << "object three: ";
    three.showData();
    cout << "object four: ";
    four.showData();
  }
  return 0;
}
