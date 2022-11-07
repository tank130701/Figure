#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <vector>
#include "polygon.h"
#include "Point.h"
#include "Figure.h"

void polygon::show_figure()
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

	for (int i = 0; i < n-1; i++)
	{
		MoveToEx(hdc, Points.at(i).getX(), Points.at(i).getY(), 0);
		LineTo(hdc, Points.at(i+1).getX(), Points.at(i+1).getY());
	}
	MoveToEx(hdc, Points.at(0).getX(), Points.at(0).getY(), 0);
	LineTo(hdc, Points.at(n-1).getX(), Points.at(n-1).getY());
	ReleaseDC(hWnd, hdc);		// ������������ ��������� ���������� ������

	_getch();
	system("cls");

}

void polygon::print_info()
{
	int i = 0;
	for (std::vector<Point>::iterator it = Points.begin(); it != Points.end(); ++it)
		std::cout << i++ << ") " << "(" << it->getX() << ";" << it->getY() << ")\n";
	std::cout << "Painted: " << bool(painted_over) <<"\n";
}



polygon::polygon(int n, std::vector<Point>* Points, bool painted)
{
	this->n = n;
	this->Points = (*Points);
	this->painted_over = painted;
}
