#pragma once
// класс точка

class Point : public Figure {
	int x, y;
public:
	Point();
	Point(int x, int y) : x(x), y(y) {} // конструктор с инициализатором
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
	HWND hWnd = GetConsoleWindow(); // ссылка на окно
	HDC hdc = GetDC(hWnd);		// ссылка на контекст устройства графического вывода
	SelectObject(hdc, GetStockObject(DC_PEN)); // выбор стандартного пера
	SelectObject(hdc, GetStockObject(DC_BRUSH)); // выбор стандартной кисти

	SetDCPenColor(hdc, RGB(255, 0, 0)); // установка пера красного цвета
	SetDCBrushColor(hdc, RGB(0, 255, 0)); // установка кисти зеленого цвета
	SetPixel(hdc, x, y, 255);
	ReleaseDC(hWnd, hdc);		// освобождение контекста устройства вывода
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
