// bank account class methods
#include <iostream>
#include "acctabc.h"

using std::cout;
using std::ios_base;
using std::endl;
using std::string;

AcctABC::AcctABC(const string & s, long an, double bal) {
  fullName = s;
  acctNum = an;
  balance = bal;
}

void AcctABC::deposit(double amt) {
  if (amt < 0) {
    cout << "Negative deposit not allowed; "
         << "deposit is cancelled.\n";
  } else {
    balance += amt;
  }
}

void AcctABC::withdraw(double amt) {
  balance -= amt;
}

AcctABC::Formatting AcctABC::setFormat() const {
  Formatting f;
  f.flag = cout.setf(ios_base::fixed, ios_base::floatfield);
  f.pr = cout.precision(2);
  return f;
}

void AcctABC::restore(Formatting & f) const {
  cout.setf(f.flag, ios_base::floatfield);
  cout.precision(f.pr);
}

void Brass::withdraw(double amt) {
  if (amt < 0) {
    cout << "Withdraw amount must be positive; "
         << "withdraw canceled.\n";
  } else if (amt <= getBalance()) {
    AcctABC::withdraw(amt);
  } else {
    cout << "Withdraw amount of $" << amt
         << " exceeds your balance.\n"
         << "Withdraw canceled.\n";
  }
}

void Brass::viewAcct() const {
  // set up ###.## format
  Formatting f = setFormat();
  cout << "Brass Client: " << getFullName() << endl;
  cout << "Account Number: " << getAcctNum() << endl;
  cout << "Balance: $" << getBalance() << endl;
  restore(f);
}

BrassPlus::BrassPlus(
  const std::string & s,
  long an,
  double bal,
  double ml,
  double r
): AcctABC(s, an, bal), maxLoan(ml), rate(r) {
  owesBank = 0.0;
}

BrassPlus::BrassPlus(
  const Brass & ba,
  double ml,
  double r
): AcctABC(ba), maxLoan(ml), rate(r) {
  owesBank = 0.0;
}

void BrassPlus::viewAcct() const {
  // set up ###.## format
  Formatting f = setFormat();

  cout << "BrassPlus Client: " << getFullName() << endl;
  cout << "Account Number: " << getAcctNum() << endl;
  cout << "Balance: $" << getBalance() << endl;
  cout << "Maximum Loan: $" << maxLoan << endl;
  cout << "Owed to Bank: $" << owesBank << endl;
  cout.precision(3);
  cout << "Loan Rate: " << 100 * rate << "%\n";
  restore(f);
}

void BrassPlus::withdraw(double amt) {
  // set up ###.## format
  Formatting f = setFormat();

  double bal = getBalance();
  if (amt <= bal) {
    AcctABC::withdraw(amt);
  } else if (amt <= bal + maxLoan - owesBank) {
    double advance = amt - bal;
    owesBank += advance * (1.0 + rate);
    cout << "Bank advance: $" << advance << endl;
    cout << "Finance charge: $" << advance * rate << endl;
    deposit(advance);
    AcctABC::withdraw(amt);
  } else {
    cout << "Credit limit exceeded. Transaction cancelled.\n";
  }
  restore(f);
}
