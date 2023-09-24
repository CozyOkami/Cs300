#include <string>
#include <cmath>
#include "gwindow.h"
#include "shape.h"
#include <vector>
using namespace std;

int main() {
    GWindow gw;
    double width = gw.getWidth();
    double height = gw.getHeight();
    vector<Shape*> shapes;

    Square* rp = new Square(width / 4, height / 4, min(width, height) / 2);
    rp->setColor("Blue");
    shapes.push_back(rp);

    shapes.push_back(new Line(0, height / 2, width / 2, 0));
    shapes.push_back(new Line(width / 2, 0, width, height / 2));
    shapes.push_back(new Line(width, height / 2, width / 2, height));
    shapes.push_back(new Line(width / 2, height, 0, height / 2));

    for (Shape* sp : shapes) {
        sp->draw(gw);
    }

    for (Shape* sp : shapes) {
        delete sp;
    }

    shapes.clear();

    return 0;
}
