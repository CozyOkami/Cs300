#include <string>
#include <cmath>
#include "gwindow.h"
#include "shape.h"
#include "vector.h"
using namespace std;
Shape::Shape(){
    setColor("BLACK");
}

void Shape::setLocation(double x, double y){
    this ->x = x;
    this ->y = y;
}

void Shape::move(double dx, double dy){
    x += dx;
    y += dy;
}
void Shape::setColor(string color) {
    this ->color = color;
}


class Square : public Shape {
private:
    double size;

public:
    Square(double upperLeftX, double upperLeftY, double size)
        : size(size) {
        setLocation(upperLeftX, upperLeftY);
    }

    bool contains(double px, double py) const override {
        return (px >= x && px <= x + size && py >= y && py <= y + size);
    }
};

int main(){
    GWindow gw;
    double width = gw.getWidth();
    double height = gw.getHeight();
    Square *rp = new Square(width / 4, height /4, width / 2, height / 2);
    rp ->setColor("Blue");
    Shape.add(new Line(0, height / 2, width / 2, 0));
    Shape.add(new Line(width / 2, 0, width, height / 2));
    Shape.add(new Line(width, height / 2, width / 2, height));
    Shape.add(new Line(width / 2, height, 0, height / 2));
    Shape.add(rp);
    for (Shape *sp : shape){
        sp ->draw(gw);
    }
    for (Shape *sp : shape){
        delete sp;
    }
    shapes.clear();
    return 0;
}