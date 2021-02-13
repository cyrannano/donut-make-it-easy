#include "Square.hpp"  
#include <math.h>

Square::Square(int xx, int yy, int ssize) {
    x = xx;
    y = yy;
    size = ssize;

    vertices = new std::vector<Pos>(4);

    (*vertices)[0].x = x-size/2;
    (*vertices)[0].y = y+size/2;
    (*vertices)[1].x = x+size/2;
    (*vertices)[1].y = y+size/2;
    (*vertices)[3].x = x-size/2;
    (*vertices)[3].y = y-size/2;
    (*vertices)[2].x = x+size/2;
    (*vertices)[2].y = y-size/2;
    (*vertices).push_back({x,y});
}
	
Square::~Square() {
	
}

void Square::show() {
    for(int i = 0; i < (*vertices).size(); ++i) {
        printCharacter((*vertices)[i], "*");
    }
}

Pos Square::rotatePoint(Pos p, double angle) {
    double s = sin(angle);
    double c = cos(angle);
    
    p.x -= x;
    p.y -= y;

    double xn = p.x * c - p.y * s;
    double yn = p.x * s + p.y * c;

    p.x = xn + x;
    p.y = yn + y;

    return p;
}

void Square::rotate(int deg) {
    double rad = deg*(M_PI/180.0);

    for(int i = 0; i < (*vertices).size(); ++i) {
        (*vertices)[i] = rotatePoint((*vertices)[i], rad);
    }
    std::cout << x << " " << y << std::endl;
}

void Square::move(double _x, double _y) {
    x += _x;
    y += _y;
    for(int i = 0; i < (*vertices).size(); ++i) {
        (*vertices)[i].x += _x;
        (*vertices)[i].y += _y;
    }
}