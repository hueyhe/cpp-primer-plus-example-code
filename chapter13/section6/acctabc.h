// bank account classes
#ifndef ACCTABC_H_
#define ACCTABC_H_

#include <iostream>
#include <string>

class AcctABC {
  private:
    std::string fullName;
    long acctNum;
    double balance;

  protected:
    struct Formatting {
      std::ios_base::fmtflags flag;
      std::streamsize pr;
    };
    const std::string & getFullName() const { return fullName; }
    long getAcctNum() const { return acctNum; }
    Formatting setFormat() const;
    void restore(Formatting & f) const;

  public:
    AcctABC(
      const std::string & s = "Nullbody",
      long an = -1,
      double bal = 0.0
    );
    void deposit(double amt);
    virtual void withdraw(double amt) = 0; // pure virtual function
    double getBalance() const { return balance; }
    virtual void viewAcct() const = 0;
    virtual ~AcctABC() {};
};

class Brass: public AcctABC {
  public:
    Brass(
      const std::string & s = "Nullbody",
      long an = -1,
      double bal = 0.0
    ): AcctABC(s, an, bal) {}
    virtual void withdraw(double amt);
    virtual void viewAcct() const;
};

class BrassPlus: public AcctABC {
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
      double r = 0.10
    );
    BrassPlus(
      const Brass & ba,
      double ml = 500,
      double r = 0.10
    );
    virtual void withdraw(double amt);
    virtual void viewAcct() const;
    void resetMax(double m) { maxLoan = m; }
    void resetRate(double r) { rate = r; }
    void resetOwes() { owesBank = 0; }
};

#endif
