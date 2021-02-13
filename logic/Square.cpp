#include "Square.hpp"  
#include <math.h>

Square::Square(int xx, int yy, int ssize) {
    position.x = xx;
    position.y = yy;
    size = ssize;

    vertices = new std::vector<Pos>(4);
    edges = new std::vector<Segment>;
    (*vertices)[0].x = position.x-size/2;
    (*vertices)[0].y = position.y+size/2;
    (*vertices)[1].x = position.x+size/2;
    (*vertices)[1].y = position.y+size/2;
    (*vertices)[3].x = position.x-size/2;
    (*vertices)[3].y = position.y-size/2;
    (*vertices)[2].x = position.x+size/2;
    (*vertices)[2].y = position.y-size/2;

    for(int i = 0; i < 3; ++i) {
        (*edges).push_back({(*vertices)[i], (*vertices)[i+1]});
    }
}
	
Square::~Square() {
	delete vertices;
    delete edges;
}

void Square::show() {
    for(int i = 0; i < (*vertices).size(); ++i) {
        printCharacter((*vertices)[i], "#");
    }
}

Pos Square::rotatePoint(Pos p, double angle) {
    double s = sin(angle);
    double c = cos(angle);
    
    p.x -= position.x;
    p.y -= position.y;

    double xn = p.x * c - p.y * s;
    double yn = p.x * s + p.y * c;

    p.x = xn + position.x;
    p.y = yn + position.y;

    return p;
}

void Square::rotate(int deg) {
    double rad = deg*(M_PI/180.0);

    for(int i = 0; i < (*vertices).size(); ++i) {
        (*vertices)[i] = rotatePoint((*vertices)[i], rad);
    }
    std::cout << position.x << " " << position.y << std::endl;
}

void Square::move(double _x, double _y) {
    position.x += _x;
    position.y += _y;
    for(int i = 0; i < (*vertices).size(); ++i) {
        (*vertices)[i].x += _x;
        (*vertices)[i].y += _y;
    }
}

Pos Square::getPostion() {
    return position;
}

int Square::getSize() {
    return size;
}

std::vector<Segment> Square::getEdges(){
    return *edges;
}

Segment generateRay(Pos p) {
    Segment s;
    s.p1 = {0,0};
    s.p2 = p;
    return s;
}

bool Square::rayCasting(Pos point) {
    Segment ray = generateRay(point);
    int intersected = 0;
    for(auto i: *edges) {

        
    }
}