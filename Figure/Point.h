#pragma once
#include "Figure.h"

// класс точка
class Point : public Figure {
	int x, y;
public:
	Point();
	Point(int x, int y) : x(x), y(y) {} // конструктор с инициализатором
	int getX();
	int getY();
	void show_figure() override;
	void print_info() override;
};


