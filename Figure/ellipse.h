#pragma once
#include "Figure.h"
#include "line.h"

class ellipse : public Figure
{
	Point a, b;
	bool painted_over;
public:
	ellipse(Point a, Point b, bool painted);
	void show_figure() override;
	void print_info() override;
};


