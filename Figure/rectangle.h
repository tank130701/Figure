#pragma once
#include "figure.h"
#include "Point.h"
#include <Windows.h>
#include <conio.h>
// ����� �������������, ������������ ����� �����
class rectangle : public Figure {
	Point top_left;
	Point bottom_right;
	bool painted_over;
public:
	// �����������
	rectangle(Point a, Point b, bool painted);
	rectangle(int x1, int y1, int x2, int y2) : top_left(x1, y1), bottom_right(x2, y2) {}
	void show_figure() override;
	void print_info() override;
};

inline rectangle::rectangle(Point a, Point b, bool painted)
{
	top_left = a;
	bottom_right = b;
	painted_over = painted;
}

inline void rectangle::show_figure()
{
	//rectangle* rec = new rectangle(top_left, bottom_right); //������� ������ �������������
	HWND hWnd = GetConsoleWindow(); // ������ �� ����
	HDC hdc = GetDC(hWnd);		// ������ �� �������� ���������� ������������ ������
	SelectObject(hdc, GetStockObject(DC_PEN)); // ����� ������������ ����
	SelectObject(hdc, GetStockObject(DC_BRUSH)); // ����� ����������� �����

	SetDCPenColor(hdc, RGB(255, 0, 0)); // ��������� ���� �������� �����
	if (painted_over == true)
		SetDCBrushColor(hdc, RGB(0, 255, 0)); // ��������� ����� �������� �����
	else 
		SetDCBrushColor(hdc, RGB(0, 0, 0));

	Rectangle(hdc, top_left.getX(), top_left.getY(), bottom_right.getX(), bottom_right.getY());	// ����� �������������� ������ ���� ������������ ������ �����
	SelectObject(hdc, GetStockObject(NULL_BRUSH)); // ���������� �������� ������

	ReleaseDC(hWnd, hdc);		// ������������ ��������� ���������� ������
	_getch();
	system("cls");
	//delete rec;
}

inline void rectangle::print_info()
{
	std::cout << "Top left point: ";
	top_left.print_info();
	std::cout << "Bottom right point: ";
	bottom_right.print_info();
}


