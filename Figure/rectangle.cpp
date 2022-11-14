#include <conio.h> // для _getch
#include "Windows.h"
#include <iostream>
#include "Rectangle.h"
#include "Point.h"
#include "Figure.h"

rectangle::rectangle(Point a, Point b, bool painted)
{
	top_left = a;
	bottom_right = b;
	painted_over = painted;
}

void rectangle::show_figure(HDC hdc)
{
	//rectangle* rec = new rectangle(top_left, bottom_right); //создаем объект прямоугольник
	//HWND hWnd = GetConsoleWindow(); // ссылка на окно
	//HDC hdc = GetDC(hWnd);		// ссылка на контекст устройства графического вывода
	SelectObject(hdc, GetStockObject(DC_PEN)); // выбор стандартного пера
	SelectObject(hdc, GetStockObject(DC_BRUSH)); // выбор стандартной кисти

	SetDCPenColor(hdc, RGB(255, 0, 0)); // установка пера красного цвета
	if (painted_over == true)
		SetDCBrushColor(hdc, RGB(0, 255, 0)); // установка кисти зеленого цвета
	else
		SetDCBrushColor(hdc, RGB(0, 0, 0));

	Rectangle(hdc, top_left.getX(), top_left.getY(), bottom_right.getX(), bottom_right.getY());	// вывод прямоугольника цветом пера закрашенного цветом кисти
	SelectObject(hdc, GetStockObject(NULL_BRUSH)); // отключение закраски кистью

	//ReleaseDC(hWnd, hdc);		// освобождение контекста устройства вывода
	_getch();
	system("cls");
	//delete rec;
}

void rectangle::print_info()
{
	std::cout << "Rectangle\n";
	std::cout << "Top left point: ";
	top_left.print_info();
	std::cout << "Bottom right point: ";
	bottom_right.print_info();
	std::cout << "Painted: " << bool(painted_over) << "\n";
}


