#include <cmath>
#include <conio.h> // ��� _getch
#include "Windows.h"
#include <iostream>
#include "Line.h"
#include "Figure.h"

Line::Line(Point a, Point b)
{
	this->a = a;
	this->b = b;
}
void Line::print_info()
{
	std::cout << "Line\n";
	std::cout << "A (" << a.getX() << ";" << a.getY() << ")\n";
	std::cout << "B (" << b.getX() << ";" << b.getY() << ")\n";
}
void Line::show_figure(HDC hdc)
{
	//HWND hWnd = GetConsoleWindow(); // ������ �� ����
	//HDC hdc = GetDC(hWnd);		// ������ �� �������� ���������� ������������ ������
	SelectObject(hdc, GetStockObject(DC_PEN)); // ����� ������������ ����
	SelectObject(hdc, GetStockObject(DC_BRUSH)); // ����� ����������� �����

	SetDCPenColor(hdc, RGB(255, 0, 0)); // ��������� ���� �������� �����
	SetDCBrushColor(hdc, RGB(0, 255, 0)); // ��������� ����� �������� �����
	MoveToEx(hdc, a.getX(), a.getY(), 0);
	LineTo(hdc, b.getX(), b.getY());
	//ReleaseDC(hWnd, hdc);		// ������������ ��������� ���������� ������
	_getch();
	system("cls");
}


double Line::get_size()
{
	return sqrt((a.getX() - b.getY()) * (a.getX() - b.getY()) + (a.getY() - b.getY()) * (a.getY() - b.getY()));
}