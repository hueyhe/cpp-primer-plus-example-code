// equality vs assignment

#include <iostream>

int main() {
  using namespace std;

  int quizescores[10] =
    { 20, 20, 20, 20, 20, 19, 20, 18, 20, 20 };

  cout << "Doing it right: \n";
  int i;
  for (i = 0; quizescores[i] == 20; i += 1) {
    cout << "quiz " << i << " is a 20\n";
  }
  cout << "Doing it dangerously wrong: \n";
  // for (i = 0; quizescores[i] == 20; i += 1) {
  //   cout << "quiz " << i << " is a 20\n";
  // }

  return 0;
}
