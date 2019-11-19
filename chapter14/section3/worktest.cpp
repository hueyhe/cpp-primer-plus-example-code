// test worker class hierarchy
#include <iostream>
#include "worker0.h"

const int LIM = 4;

int main() {
  Waiter bob("Bob Apple", 314L, 5);
  Singer bev("Beverly Hills", 522L, 3);
  Waiter w_temp;
  Singer s_temp;

  Worker * pw[LIM] = {&bob, &bev, &w_temp, &s_temp};

  int i;
  for (i = 2; i < LIM; i++) {
    pw[i]->set();
  }
  for (i = 0; i < LIM; i++) {
    pw[i]->show();
    std::cout << std::endl;
  }

  return 0;
}
