#include <Windows.h>
#include <conio.h>
#include <iostream>
#include "Point.h"
#include "Figure.h"

int Point::getX()
{
	return x;
}

int Point::getY()
{
	return y;
}

void Point::show_figure()
{
	HWND hWnd = GetConsoleWindow(); // ссылка на окно
	HDC hdc = GetDC(hWnd);		// ссылка на контекст устройства графического вывода
	SelectObject(hdc, GetStockObject(DC_PEN)); // выбор стандартного пера
	SelectObject(hdc, GetStockObject(DC_BRUSH)); // выбор стандартной кисти

	SetDCPenColor(hdc, RGB(255, 0, 0)); // установка пера красного цвета
	SetDCBrushColor(hdc, RGB(0, 255, 0)); // установка кисти зеленого цвета
	SetPixel(hdc, x, y, 255);
	ReleaseDC(hWnd, hdc);		// освобождение контекста устройства вывода
	_getch();
	system("cls");
}

void Point::print_info()
{
	std::cout << "(" << getX() << ";" << getY() << ")\n";
}



Point::Point()
{
	x = 0;
	y = 0;
}
