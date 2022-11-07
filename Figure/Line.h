#pragma once
#include "point.h"
#include "Figure.h"


class Line : public Figure
{
	Point a, b;
public:
	Line(Point a, Point b);
	void show_figure() override;
	void print_info() override;
	double get_size();
};


