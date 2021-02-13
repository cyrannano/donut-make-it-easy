#ifndef SQUARE_H
#define SQUARE_H
#pragma once

#include "Interface.hpp"
#include <vector>

class Square: public Interface {
	private:
		double x;
		double y;
		int size;
		std::vector<Pos>* vertices;
	public:

		Square(int,int,int);
		~Square();

		void show();
		Pos rotatePoint(Pos, double);
		void rotate(int);
		void move(double, double);
};
#endif