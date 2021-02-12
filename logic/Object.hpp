#ifndef OBJECT_H
#define OBJECT_H
#pragma once

#include "Interface.hpp"
#include <vector>

struct Point3D {
	int x;
	int y;
	int z;
};	


class Object: public Interface {
	private:
		Point3D middle;
		std::vector<Point3D>* vertices;
	public:
		Object(int, Point3D);
		~Object();

		virtual void calculatePoints() = 0;
		virtual void displayPoints() = 0;
		virtual void rotateX() = 0;
		virtual void rotateY() = 0;
		virtual void rotateZ() = 0;

		void setMiddle(Point3D);
		Point3D getMiddle();
		std::vector<Point3D> getVertices();
};

#endif