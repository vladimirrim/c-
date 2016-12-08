#include "circle.h"
#include <string.h>
#include <cstdio>

#define sqr(x) ((x)*(x))

Circle::Circle(int new_id, int new_x, int new_y,int r, const char *l):Figure(new_id,new_x,new_y) {
    label = new char[strlen(l) + 1];
    strcpy(label, l);
    radius = r;
}

Circle::~Circle() {
    delete[]label;

}

void Circle::print() const {
    printf("Circle %d: x = %d y = %d radius = %d label = %s\n", id, x, y, radius, label);

}

bool Circle::is_inside(int x1, int y1) const {
    if (sqr(x - x1) + sqr(y - y1) <= sqr(radius))
        return true;
    return false;


}

void Circle::zoom(int factor) {
    radius *= factor;

}
