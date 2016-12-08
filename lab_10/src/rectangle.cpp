#include "rectangle.h"
#include <cstdio>

Rectangle::Rectangle(int new_id, int new_x, int new_y, int w, int h):Figure(new_id,new_x,new_y) {
    width = w;
    height = h;

}

void Rectangle::print() const {
    printf("Rectangle %d: x = %d y = %d width = %d height = %d\n", id, x, y, width, height);
}

bool Rectangle::is_inside(int x1, int y1) const {
    if (x1 >= x - width / 2 && x1 <= x + width / 2 && y1 >= y - height / 2 && y1 <= y + height / 2)
        return true;
    return false;
}

void Rectangle::zoom(int factor) {
    width *= factor;
    height *= factor;

}
