#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <vector>
#include "polygon.h"
#include "Point.h"
#include "Figure.h"

void polygon::show_figure(HDC hdc)
{

	//HWND hWnd = GetConsoleWindow(); // ������ �� ����
	//HDC hdc = GetDC(hWnd);		// ������ �� �������� ���������� ������������ ������
	SelectObject(hdc, GetStockObject(DC_PEN)); // ����� ������������ ����
	SelectObject(hdc, GetStockObject(DC_BRUSH)); // ����� ����������� �����

	SetDCPenColor(hdc, RGB(255, 0, 0)); // ��������� ���� �������� �����
	if (painted_over == true)
		SetDCBrushColor(hdc, RGB(0, 255, 0)); // ��������� ����� �������� �����
	else
		SetDCBrushColor(hdc, RGB(0, 0, 0));

	/*for (int i = 0; i < n - 1; i++)
	{
		MoveToEx(hdc, Points.at(i).getX(), Points.at(i).getY(), 0);
		LineTo(hdc, Points.at(i + 1).getX(), Points.at(i + 1).getY());
		//MoveToEx(hdc, Points.at(i + 1).getX(), Points.at(i + 1).getY(), 0);
	}*/
	Polygon(hdc, arr, n);
	//ReleaseDC(hWnd, hdc);		// ������������ ��������� ���������� ������

	_getch();
	system("cls");

}

void polygon::print_info()
{
	std::cout << "Polygon\n";
	for (int i = 0; i < n; i++)
		std::cout << "Point: " << i << ") " << "(" << arr[i].x << ":" << arr[i].y << ")\n";
	std::cout << "Painted: " << bool(painted_over) <<"\n";
}



polygon::polygon(int n, POINT *arr, bool painted)
{
	this->n = n;
	this->arr = arr;
	this->painted_over = painted;
}
