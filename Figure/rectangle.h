#pragma once
#include "Figure.h"
#include "Point.h"
#include "Windows.h"
#include <conio.h>
// класс прямоугольник, использующий класс точка
class rectangle : public Figure {
	Point top_left;
	Point bottom_right;
	bool painted_over;
public:
	// конструктор
	rectangle(Point a, Point b, bool painted);
	//rectangle(int x1, int y1, int x2, int y2) : top_left(x1, y1), bottom_right(x2, y2) {}
	void show_figure(HDC hdc) override;
	void print_info() override;
};

