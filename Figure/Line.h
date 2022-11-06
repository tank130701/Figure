#pragma once
#include "point.h"
#include "figure.h"
#include <Windows.h>
#include <conio.h>
#include <cmath>

class Line : public Figure
{
	Point a, b;
public:
	Line();
	Line(Point a, Point b);
	void show_figure() override;
	void print_info() override;
	double get_size();
};

inline Line::Line()
{

}

inline Line::Line(Point a, Point b)
{
	this->a = a;
	this->b = b;
}
inline void Line::print_info()
{
	std::cout << "A (" << a.getX() << ";" << a.getY() << ")\n";
	std::cout << "B (" << b.getX() << ";" << b.getY() << ")\n";
}
inline void Line::show_figure()
{
	HWND hWnd = GetConsoleWindow(); // ссылка на окно
	HDC hdc = GetDC(hWnd);		// ссылка на контекст устройства графического вывода
	SelectObject(hdc, GetStockObject(DC_PEN)); // выбор стандартного пера
	SelectObject(hdc, GetStockObject(DC_BRUSH)); // выбор стандартной кисти

	SetDCPenColor(hdc, RGB(255, 0, 0)); // установка пера красного цвета
	SetDCBrushColor(hdc, RGB(0, 255, 0)); // установка кисти зеленого цвета
	MoveToEx(hdc, a.getX(), a.getY(), 0);
	LineTo(hdc, b.getX(), b.getY());
	ReleaseDC(hWnd, hdc);		// освобождение контекста устройства вывода
	_getch();
	system("cls");
}


inline double Line::get_size()
{
	return sqrt((a.getX() - b.getY()) * (a.getX() - b.getY()) + (a.getY() - b.getY()) * (a.getY() - b.getY()));
}