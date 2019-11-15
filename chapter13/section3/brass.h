// bank account classes
#ifndef BRASS_H_
#define BRASS_H_

#include <string>

class Brass {
  private:
    std::string fullName;
    long acctNum;
    double balance;

  public:
    Brass(
      const std::string & s = "Nullbody",
      long an = -1,
      double bal = 0.0
    );
    void deposit(double amt);
    virtual void withdraw(double amt);
    double Balance() const;
    virtual void viewAcct() const;
    virtual ~Brass() {}
};

class BrassPlus: public Brass {
  private:
    double maxLoan;
    double rate;
    double owesBank;

  public:
    BrassPlus(
      const std::string & s = "Nullbody",
      long an = -1,
      double bal = 0.0,
      double ml = 500,
      double r = 0.11125
    );
    BrassPlus(
      const Brass & ba,
      double ml = 500,
      double r = 0.11125
    );
    virtual void viewAcct() const;
    virtual void withdraw(double amt);
    void resetMax(double m) { maxLoan = m; }
    void resetRate(double r) { rate = r; }
    void resetOwes() { owesBank = 0; }
};

#endif
