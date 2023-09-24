#ifndef _shape_h
#define _shape_h

#include <vector>
#include <string>
#include "gwindow.h"

class Shape {
public:
    virtual void setLocation(double x, double y) = 0;
    virtual void move(double dx, double dy) = 0;
    void setColor(std::string color);
    virtual void draw(GWindow & gw) = 0;

protected:
    Shape();
    std::string color;
    double x, y;
};

class Line : public Shape {
public:
    Line(double x1, double y1, double x2, double y2);
    virtual void setLocation(double x, double y) override;
    virtual void move(double dx, double dy) override;
    virtual void draw(GWindow & gw) override;

private:
    double x1, y1, x2, y2;
};

class Square : public Shape {
private:
    double size;

public:
    Square(double upperLeftX, double upperLeftY, double size);
    virtual void setLocation(double x, double y) override;
    virtual void move(double dx, double dy) override;
    virtual void draw(GWindow & gw) override;
    bool contains(double px, double py) const override;
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

#endif
