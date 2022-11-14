#pragma once
#include "Figure.h"
#include "Windows.h"
#include <conio.h>
#include <vector>
#include "Point.h"
class polygon : public Figure
{
	//std::vector<Point> Points;
	int n;
	POINT* arr;
	bool painted_over;
public:
	polygon(int n, POINT *arr, bool painted);
	void show_figure(HDC hdc) override;
	void print_info() override;
};

