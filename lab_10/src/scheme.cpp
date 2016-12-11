#include "scheme.h"

Scheme::Scheme(int capacity) {
    figures_ = new Figure *[capacity];
    size = 0;
}

Scheme::~Scheme() {
    for (int i = 0; i < size; i++)
        delete figures_[i];
    delete[] figures_;
}

void Scheme::push_back_figure(Figure *fg) {
    figures_[size] = fg;
    size++;
}

void Scheme::remove_figure(int id1) {
    int tmp = 0;
    for (int i = 0; i < size; i++) {
        if (figures_[i]->get_id() == id1) {
            delete figures_[i];
            tmp = i;
            break;
        }

    }

    for (int i = tmp; i < size - 1; i++)
        figures_[i] = figures_[i + 1];

    size--;
}

void Scheme::print_all_figures() {
    for (int i = 0; i < size; i++) {
        figures_[i]->print();
    }

}

void Scheme::zoom_figure(int id1, int factor) {
    for (int i = 0; i < size; i++)
        if (figures_[i]->get_id() == id1) {
            figures_[i]->zoom(factor);
            break;
        }
}

Figure *Scheme::is_inside_figure(int x, int y) {
    for (int i = 0; i < size; i++)
        if (figures_[i]->is_inside(x, y))
            return figures_[i];
    return 0;
}

void Scheme::move(int id1, int new_x, int new_y) {
    for (int i = 0; i < size; i++)
        if (figures_[i]->get_id() == id1) {
            figures_[i]->move(new_x, new_y);
            break;
        }

}
