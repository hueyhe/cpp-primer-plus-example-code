// using the ctype.h library

#include <iostream>
#include <cctype>

int main() {
  using namespace std;

  cout << "Enter text for analysis, and type @"
          " to determine input.\n";
  char ch;
  int whitespace = 0;
  int digits = 0;
  int chars = 0;
  int punct = 0;
  int others = 0;

  cin.get(ch);
  while (ch != '@') {
    if (isalpha(ch)) {
      chars += 1;
    } else if (isspace(ch)) {
      whitespace += 1;
    } else if (isdigit(ch)) {
      digits += 1;
    } else if (ispunct(ch)) {
      punct += 1;
    } else {
      others += 1;
    }
    cin.get(ch);
  }
  cout << chars << " letters, "
       << whitespace << " whitespace, "
       << digits << " digits, "
       << punct << " punctuations, "
       << others << " others.\n";

  return 0;
}
