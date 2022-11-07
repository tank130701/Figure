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
	HWND hWnd = GetConsoleWindow(); // ������ �� ����
	HDC hdc = GetDC(hWnd);		// ������ �� �������� ���������� ������������ ������
	SelectObject(hdc, GetStockObject(DC_PEN)); // ����� ������������ ����
	SelectObject(hdc, GetStockObject(DC_BRUSH)); // ����� ����������� �����

	SetDCPenColor(hdc, RGB(255, 0, 0)); // ��������� ���� �������� �����
	SetDCBrushColor(hdc, RGB(0, 255, 0)); // ��������� ����� �������� �����
	SetPixel(hdc, x, y, 255);
	ReleaseDC(hWnd, hdc);		// ������������ ��������� ���������� ������
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
