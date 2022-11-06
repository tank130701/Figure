#pragma once
// ����� �����

class Point : public Figure {
	int x, y;
public:
	Point();
	Point(int x, int y) : x(x), y(y) {} // ����������� � ���������������
	int getX();
	int getY();
	void show_figure() override;
	void print_info() override;
};

inline int Point::getX()
{
	return x;
}

inline int Point::getY()
{
	return y;
}

inline void Point::show_figure()
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

inline void Point::print_info()
{
	std::cout << "(" << getX() << ";" << getY() << ")\n";
}



inline Point::Point()
{
	x = 0;
	y = 0;
}
