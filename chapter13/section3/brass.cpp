// bank account class methods
#include <iostream>
#include "brass.h"

using std::cout;
using std::endl;
using std::string;

typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);

Brass::Brass(
  const string & s,
  long an,
  double bal
): fullName(s), acctNum(an), balance(bal) {}

void Brass::deposit(double amt) {
  if (amt < 0) {
    cout << "Negative deposit not allowed; "
         << "deposit is cancelled.\n";
  } else {
    balance += amt;
  }
}

void Brass::withdraw(double amt) {
  // set up ###.## format
  format initialState = setFormat();
  precis prec = cout.precision(2);

  if (amt < 0) {
    cout << "Withdraw amount must be positive; "
         << "withdraw canceled.\n";
  } else if (amt <= balance) {
    balance -= amt;
  } else {
    cout << "Withdraw amount of $" << amt
         << " exceeds your balance.\n"
         << "Withdraw canceled.\n";
  }
  restore(initialState, prec);
}

double Brass::Balance() const {
  return balance;
}

void Brass::viewAcct() const {
  // set up ###.## format
  format initialState = setFormat();
  precis prec = cout.precision(2);
  cout << "Client: " << fullName << endl;
  cout << "Account Number: " << acctNum << endl;
  cout << "Balance: $" << balance << endl;
  restore(initialState, prec);
}


BrassPlus::BrassPlus(
  const std::string & s,
  long an,
  double bal,
  double ml,
  double r
): Brass(s, an, bal), maxLoan(ml), rate(r) {
  owesBank = 0.0;
}

BrassPlus::BrassPlus(
  const Brass & ba,
  double ml,
  double r
): Brass(ba), maxLoan(ml), rate(r) {
  owesBank = 0.0;
}

void BrassPlus::viewAcct() const {
  // set up ###.## format
  format initialState = setFormat();
  precis prec = cout.precision(2);

  Brass::viewAcct();
  cout << "Maximum Loan: $" << maxLoan << endl;
  cout << "Owed to Bank: $" << owesBank << endl;
  cout.precision(3);
  cout << "Loan Rate: " << 100 * rate << "%\n";
  restore(initialState, prec);
}

void BrassPlus::withdraw(double amt) {
  // set up ###.## format
  format initialState = setFormat();
  precis prec = cout.precision(2);

  double bal = Balance();
  if (amt < bal) {
    Brass::withdraw(amt);
  } else if (amt <= bal + maxLoan - owesBank) {
    double advance = amt - bal;
    owesBank += advance * (1.0 + rate);
    cout << "Bank advance: $" << advance << endl;
    cout << "Finance charge: $" << advance * rate << endl;
    deposit(advance);
    Brass::withdraw(amt);
  } else {
    cout << "Credit limit exceeded. Transaction cancelled.\n";
  }
  restore(initialState, prec);
}

format setFormat() {
  // set up ###.## format
  return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

void restore(format f, precis p) {
  cout.setf(f, std::ios_base::floatfield);
  cout.precision(p);
}
