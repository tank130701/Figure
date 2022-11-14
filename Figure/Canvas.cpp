#include <iostream>
#include "Windows.h"
#include <vector>
#include "Canvas.h"
#include "Figure.h"
#include "Point.h"
#include "Line.h"
#include "ellipse.h"
#include "rectangle.h"
#include "polygon.h"


void Canvas::show()
{
	for (size_t i = 0; i < Figures.size(); i++)
		Figures[i]->show_figure(hdc);
}
void Canvas::add_figure(Figure* shape)
{
	Figures.push_back(shape);
}
void Canvas::remove_figure()
{
	int n;
	std::cout << "Choose point which you want to draw: \n";
	print_figures_list();
	if (Figures.size() == 0)
		return;
	std::cin >> n;
	system("cls");
	auto iter = Figures.cbegin();
	Figures.erase(iter + n);
}
void Canvas::print_figures_list()
{
	if (Figures.size() == 0)
	{
		system("cls");
		std::cout << "List is empty!\n\nPress Enter to Continue\n";
		_getch();
		return;
	}
	else
	{
		for (size_t i = 0; i < Figures.size(); i++)
		{	
			std::cout << i << ") ";
			Figures[i]->print_info();
		}
		_getch();
	}
}

void Canvas::remove_all_figures()
{
	Figures.clear();
}

Point Canvas::create_point()
{
	int X, Y;
	std::cout << "Enter X and Y: ";
	std::cin >> X;
	std::cin >> Y;
	Point newPoint = Point(X, Y);
	return newPoint;
}

void Canvas::append_point()
{
	int X, Y;
	std::cout << "Enter X and Y: ";
	std::cin >> X;
	std::cin >> Y;
	Point *newPoint = new Point(X, Y);
	add_figure(newPoint);
}

void Canvas::append_line()
{
	Point a = create_point();
	Point b = create_point();
	Line *newLine = new Line(a, b);
	add_figure(newLine);
}

void Canvas::append_ellipse()
{
	std::cout << "Enter coordinates of top left Point: \n";
	Point a = create_point();
	std::cout << "Enter coordinates of bottom right Point: \n";
	Point b = create_point();
	std::cout << "Enter 1 if you want the rectangle to be filled, 0 if not: ";
	bool painted;
	std::cin >> painted;
	ellipse* newEllips = new ellipse(a, b, painted);
	add_figure(newEllips);
}

void Canvas::append_rectangle()
{
	std::cout << "Enter coordinates of top left Point: \n";
	Point a = create_point();
	std::cout << "Enter coordinates of bottom right Point: \n";
	Point b = create_point();
	std::cout << "Enter 1 if you want the rectangle to be filled, 0 if not: ";
	bool painted;
	std::cin >> painted;
	rectangle *newRectangle = new rectangle(a, b, painted);
	add_figure(newRectangle);
}

void Canvas::append_polygon()
{
	int count;
	std::vector<Point> rec_points;
	std::cout << "How many points will your polygon contain: ";
	std::cin >> count;
	std::cout << "Enter 1 if you want the rectangle to be filled, 0 if not: ";
	bool painted;
	std::cin >> painted;
	POINT* arr = new POINT[count];
	for (int i = 0; i < count; i++)
	{
		int temp;
		std::cout << "Enter X: ";
		std::cin >> temp;
		arr[i].x = temp;
		std::cout << "Enter Y: ";
		std::cin >> temp;
		arr[i].y = temp;
	}
	polygon *pol = new polygon(count, arr, painted);
	add_figure(pol);
}

Canvas::Canvas()
{
	hWnd = GetConsoleWindow(); // ссылка на окно
	hdc = GetDC(hWnd);		// ссылка на контекст устройства графического 
}

Canvas::~Canvas()
{
	ReleaseDC(hWnd, hdc);		// освобождение контекста устройства 
}

