#include "Object.hpp"  
	
Object::Object(int vCount, Point3D mid) {
	middle = mid;
    vertices = new std::vector<Point3D>(vCount, {0,0,0});
}
	
Object::~Object() {
	delete vertices;
}

void Object::setMiddle(Point3D point) {
	middle = point;
}

Point3D Object::getMiddle() {
	return middle;
}

std::vector<Point3D> Object::getVertices() {
	return *vertices;
}