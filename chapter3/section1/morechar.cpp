// the char type and int contrasted

#include <iostream>

int main() {
  using namespace std;

  char ch = 'M';
  int i = ch;
  cout << "The ASCII code for " << ch << " is " << i << endl;

  cout << "Add one to the character code:" << endl;
  ch += 1;
  i = ch;
  cout << "The ASCII code for " << ch << " is " << i << endl;

  cout << "Displaying char ch using cout.put(ch): ";
  cout.put(ch);

  cout.put('!');
  cout << endl << "Done" << endl;

  return 0;
}
