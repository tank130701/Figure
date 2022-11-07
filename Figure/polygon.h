#pragma once
#include "Figure.h"
#include <Windows.h>
#include <conio.h>
#include <vector>
#include "Point.h"
class polygon : public Figure
{
	std::vector<Point> Points;
	int n;
	bool painted_over;
public:
	polygon(int n, std::vector<Point> *Points, bool painted);
	void show_figure() override;
	void print_info() override;
};

