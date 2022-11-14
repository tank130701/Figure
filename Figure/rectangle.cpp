#include <conio.h> // ��� _getch
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
	//rectangle* rec = new rectangle(top_left, bottom_right); //������� ������ �������������
	//HWND hWnd = GetConsoleWindow(); // ������ �� ����
	//HDC hdc = GetDC(hWnd);		// ������ �� �������� ���������� ������������ ������
	SelectObject(hdc, GetStockObject(DC_PEN)); // ����� ������������ ����
	SelectObject(hdc, GetStockObject(DC_BRUSH)); // ����� ����������� �����

	SetDCPenColor(hdc, RGB(255, 0, 0)); // ��������� ���� �������� �����
	if (painted_over == true)
		SetDCBrushColor(hdc, RGB(0, 255, 0)); // ��������� ����� �������� �����
	else
		SetDCBrushColor(hdc, RGB(0, 0, 0));

	Rectangle(hdc, top_left.getX(), top_left.getY(), bottom_right.getX(), bottom_right.getY());	// ����� �������������� ������ ���� ������������ ������ �����
	SelectObject(hdc, GetStockObject(NULL_BRUSH)); // ���������� �������� ������

	//ReleaseDC(hWnd, hdc);		// ������������ ��������� ���������� ������
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


