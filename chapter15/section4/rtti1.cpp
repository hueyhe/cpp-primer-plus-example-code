// using the RTTI dynamic_cast operator
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;

class Grand {
  public:
    Grand(int h = 0): hold(h) {}
    virtual void speak() const { cout << "I am a grand class!\n"; }
    virtual int value() const { return hold; }
    virtual ~Grand() {}

  private:
    int hold;
};

class Superb: public Grand {
  public:
    Superb(int h = 0): Grand(h) {}
    void speak() const { cout << "I am a superb class!\n"; }
    virtual void say() const {
      cout << "I hold the superb value of " << value() << "!\n";
    }
    virtual ~Superb() {}
};

class Magnificent: public Superb {
  public:
    Magnificent(int h = 0, char c = 'A'): Superb(h), ch(c) {}
    void speak() const { cout << "I am a magnificent class!\n"; }
    void say() const {
      cout << "I hold the character " << ch
        << " and the integer " << value() << "!\n";
    }

  private:
    char ch;
};

Grand * getOne();

int main() {
  std::srand(std::time(0));
  Grand * pg;
  Superb * ps;
  for (int i = 0; i < 5; i++) {
    pg = getOne();
    pg->speak();
    ps = dynamic_cast<Superb *>(pg);
    if (ps != nullptr) {
      ps->say();
    }
  }

  return 0;
}

Grand * getOne() {
  Grand * p;
  switch (std::rand() % 3) {
    case 0:
      p = new Grand(std::rand() % 100);
      break;
    case 1:
      p = new Superb(std::rand() % 100);
      break;
    case 2:
      p = new Magnificent(
        std::rand() % 100,
        'A' + std::rand() % 26
      );
      break;
  }
  return p;
}
