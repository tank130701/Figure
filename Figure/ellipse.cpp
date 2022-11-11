#include <Windows.h>
#include <iostream>
#include <conio.h>
#include "ellipse.h"
#include "Figure.h"

ellipse::ellipse(Point a, Point b, bool painted)
{
	this->a = a;
	this->b = b;
	this->painted_over = painted;
}

void ellipse::show_figure()
{
	HWND hWnd = GetConsoleWindow(); // ������ �� ����
	HDC hdc = GetDC(hWnd);		// ������ �� �������� ���������� ������������ ������
	SelectObject(hdc, GetStockObject(DC_PEN)); // ����� ������������ ����
	SelectObject(hdc, GetStockObject(DC_BRUSH)); // ����� ����������� �����

	SetDCPenColor(hdc, RGB(255, 0, 0)); // ��������� ���� �������� �����
	if (painted_over == true)
		SetDCBrushColor(hdc, RGB(0, 255, 0)); // ��������� ����� �������� �����
	else
		SetDCBrushColor(hdc, RGB(0, 0, 0));

	Ellipse(hdc, a.getX(), a.getY(), b.getX(), b.getY());
	SelectObject(hdc, GetStockObject(NULL_BRUSH)); // ���������� �������� ������
	ReleaseDC(hWnd, hdc);		// ������������ ��������� ���������� ������
	_getch();
	system("cls");
}

void ellipse::print_info()
{
	std::cout << "Top left point: ";
	a.print_info();
	std::cout << "Bottom right point: ";
	b.print_info();
	std::cout << "Painted: " << bool(painted_over) << "\n";
}

