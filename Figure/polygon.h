#pragma once
#include "figure.h"
#include <Windows.h>
#include <conio.h>
#include <vector>
class polygon : public Figure
{
	std::vector<Point> Points;
	int n;
	bool painted_over;
public:
	polygon(int n, std::vector<Point> *Points, bool painted);
	void show_figure() override;
	void print_info() override;
};

inline void polygon::show_figure()
{
	for (int i = 0; i < n - 1; i++)
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
	
	
		MoveToEx(hdc, Points.at(n).getX(), Points.at(n).getY(), 0);
		LineTo(hdc, Points.at(n+1).getX(), Points.at(n+1).getY());
	

	ReleaseDC(hWnd, hdc);		// ������������ ��������� ���������� ������
	}
	_getch();
	system("cls");

}

inline void polygon::print_info()
{
	int i = 0;
	for (std::vector<Point>::iterator it = Points.begin(); it != Points.end(); ++it)
		std::cout << i++ << ") " << "(" << it->getX() << ";" << it->getY() << ")\n";
}



inline polygon::polygon(int n, std::vector<Point> *Points, bool painted)
{
	this->n = n;
	this->Points = (*Points);
	this->painted_over = painted;
}
