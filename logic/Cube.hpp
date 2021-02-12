#ifndef CUBE_H
#define CUBE_H
#pragma once

#include "Object.hpp"

class Cube: public Object {
	private:

	public:

		Cube(Point3D);
		~Cube();

		virtual void calculatePoints();
		virtual void displayPoints();
		virtual void rotateX();
		virtual void rotateY();
		virtual void rotateZ();

};
#endif