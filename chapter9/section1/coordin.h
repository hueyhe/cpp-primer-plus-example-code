// structure templates and function prototypes
#ifndef COORDIN_H_
#define COORDIN_H_

// structure templates
struct polar {
  double distance;
  double angle;
};

struct rect {
  double x;
  double y;
};

// prototypes
polar rect_to_polar(rect xypos);
void show_polar(polar dapos);

#endif
