#ifndef SQUARE_H
#define SQUARE_H
#pragma once

#include "Interface.hpp"
#include <vector>
#include <algorithm>

struct Segment {
	Pos p1;
	Pos p2;
};

class Square: public Interface {
	private:
		Pos position;
		int size;
		std::vector<Pos>* vertices;
		std::vector<Segment>* edges;
	public:

		Square(int,int,int);
		~Square();

		void show();
		Pos rotatePoint(Pos, double);
		void rotate(int);
		void move(double, double);
		Pos getPostion();
		int getSize();
		bool rayCasting(Pos);
		std::vector<Segment> getEdges();
};
#endif