#pragma once
#include "Figure.h"
#include "Windows.h"

// ����� �����
class Point : public Figure {
	int x, y;
public:
	Point();
	Point(int x, int y) : x(x), y(y) {} // ����������� � ���������������
	int getX();
	int getY();
	void show_figure(HDC hdc) override;
	void print_info() override;
};


