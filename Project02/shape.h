#ifndef _shape_h
#define _shape_h

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