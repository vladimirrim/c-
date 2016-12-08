#include "figure.h"

void Figure::move(int new_x, int new_y) {

    x = new_x;
    y = new_y;

}

Figure::~Figure() {}

Figure::Figure(int new_id, int new_x, int new_y) {
    id = new_id;
    x = new_x;
    y = new_y;
}

int Figure::get_id() { return id; }
