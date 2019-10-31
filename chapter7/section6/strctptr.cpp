// functions with pointer to structure arguments

#include <iostream>
#include <cmath>

struct polar {
  double distance;
  double angle;
};

struct rect {
  double x;
  double y;
};

void rect_to_polar(const rect* pxy, polar* pda);
void show_polar(const polar* pda);

int main() {
  using namespace std;

  rect rplace;
  polar pplace;

  cout << "Enter the x and y values: ";
  while (cin >> rplace.x >> rplace.y) {
    rect_to_polar(&rplace, &pplace);
    show_polar(&pplace);
    cout << "Next two numbers (q to quit): ";
  }
  cout << "Done.\n";

  return 0;
}

void rect_to_polar(const rect* pxy, polar* pda) {
  using namespace std;

  pda->distance = sqrt(pxy->x * pxy->x + pxy->y * pxy->y);
  pda->angle = atan2(pxy->y, pxy->x);
}

void show_polar(const polar* pda) {
  using namespace std;
  const double Rad_to_deg = 57.29577951;

  cout << "distance = " << pda->distance;
  cout << ", angle = " << pda->angle * Rad_to_deg;
  cout << " degrees\n";
}
