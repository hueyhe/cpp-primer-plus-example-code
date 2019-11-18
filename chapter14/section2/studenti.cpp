// Student class using containment
#include "studenti.h"

using std::ostream;
using std::endl;
using std::istream;
using std::string;

double Student::average() const {
  if (ArrayDb::size() > 0) {
    return ArrayDb::sum() / ArrayDb::size();
  } else {
    return 0;
  }
}

const string & Student::getName() const {
  return (const string &) *this;
}

double & Student::operator[](int i) {
  return ArrayDb::operator[](i);
}

double Student::operator[](int i) const {
  return ArrayDb::operator[](i);
}

ostream & Student::arr_out(ostream & os) const {
  int i;
  int lim = ArrayDb::size();
  if (lim > 0) {
    for (i = 0; i < lim; i++) {
      os << ArrayDb::operator[](i) << " ";
      if (i % 5 == 4) {
        os << endl;
      }
    }
    if (i % 5 != 0) {
      os << endl;
    }
  } else {
    os << " empty array ";
  }
  return os;
}

// friends
istream & operator>>(istream & is, Student & stu) {
  is >> (string &) stu;
  return is;
}

istream & getline(istream & is, Student & stu) {
  getline(is, (string &) stu);
  return is;
}

ostream & operator<<(ostream & os, const Student & stu) {
  os << "Scores for " << (const string &) stu << ":\n";
  stu.arr_out(os);
  return os;
}
