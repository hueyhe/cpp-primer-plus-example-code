// testing bank account classes
// compile with brass.cpp
#include <iostream>
#include "brass.h"

int main() {
  using std::cout;
  using std::endl;

  Brass Piggy("Porcelot Pigg", 381299, 4000.00);
  BrassPlus Hoggy("Horatio Hogg", 382288, 3000.00);
  Piggy.viewAcct();
  cout << endl;
  Hoggy.viewAcct();
  cout << endl;
  cout << "Depositing $1000 into the Hogg Accout:\n";
  Hoggy.deposit(1000.00);
  cout << "New balance: $" << Hoggy.Balance() << endl;
  cout << "Withdrawing $4200 from the Piggy Accout:\n";
  Piggy.withdraw(4200.00);
  cout << "Piggy account balance: $" << Piggy.Balance() << endl;
  cout << "Withdrawing $4200 from the Hogg Accout:\n";
  Hoggy.withdraw(4200.00);
  Hoggy.viewAcct();

  return 0;
}
