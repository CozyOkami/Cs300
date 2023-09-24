#ifndef _shape_h
#define _shape_h

#include "vector.h"
#include <string>
#include "gwindow.h"

class Shape{
    public:
        void setLocation (double x, double y);
        void move (double x, double y);
        void setColor (std::string color);
        virtual void draw(GWindow & gw) = 0;
    
    protected:
        Shape();
        std::string color;
        double x, y;
};

class Line : public Shape {
    public:
        Line(double x1, double y1, double x2, double y2);
        virtual void draw(GWindow & gw);
    private:
        double dx;
        double dy;
};
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
class ShapeList {
private:
    std::vector<Shape*> shapes;

public:
    Shape* getShapeAt(double x, double y) const {
        for (int i = shapes.size() - 1; i >= 0; --i) {
            if (shapes[i]->contains(x, y)) {
                return shapes[i];
            }
        }
        return nullptr;
    }
};