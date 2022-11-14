#include <iostream>
#include <vector>
#include "Canvas.h"
#include "Figure.h"
#include "Point.h"
#include "Line.h"
#include "ellipse.h"
#include "rectangle.h"
#include "polygon.h"
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
	Point newPoint = Point(X, Y);
	Points.push_back(newPoint);
}

void Canvas::remove_point()
{
	int n;
	std::cout << "Choose point which you want to draw: \n";
	print_points_list();
	std::cin >> n;
	system("cls");
	auto iter = Points.cbegin();
	Points.erase(iter + n);
}

void Canvas::delete_all_points()
{
	Points.clear();
}

void Canvas::draw_point()
{
	int n;
	std::cout << "Choose point which you want to draw: \n";
	print_points_list();
	std::cin >> n;
	system("cls");
	Points.at(n).show_figure();
}

void Canvas::print_points_list()
{
	int i = 0;
	for (std::vector<Point>::iterator it = Points.begin(); it != Points.end(); ++it)
		std::cout << i++ << ") " << "(" << it->getX() << ";" << it->getY() << ")\n";
}

void Canvas::append_line()
{
	Point a = create_point();
	Point b = create_point();
	Line newLine = Line(a, b);
	Lines.push_back(newLine);
}

void Canvas::remove_line()
{
	int n;
	std::cout << "Choose line which you want to draw: \n";
	print_lines_list();
	std::cin >> n;
	system("cls");
	auto iter = Lines.cbegin();
	Lines.erase(iter + n);
}

void Canvas::delete_all_lines()
{
	Lines.clear();
}

void Canvas::print_lines_list()
{
	int i = 0;
	for (std::vector<Line>::iterator it = Lines.begin(); it != Lines.end(); ++it)
	{
		std::cout << i++ << ")\n";
		it->print_info();
	}
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
	ellipse newEllips = ellipse(a, b, painted);
	Ellipses.push_back(newEllips);

}

void Canvas::remove_ellipse()
{
	int n;
	std::cout << "Choose ellipse which you want to draw: \n";
	print_ellipses_list();
	std::cin >> n;
	system("cls");
	auto iter = Ellipses.cbegin();
	Ellipses.erase(iter + n);
}

void Canvas::delete_all_elipses()
{
	Ellipses.clear();
}

void Canvas::draw_ellipse()
{
	int n;
	std::cout << "Choose ellipse which you want to draw: \n";
	print_ellipses_list();
	std::cin >> n;
	system("cls");
	Ellipses.at(n).show_figure();
}

void Canvas::print_ellipses_list()
{
	int i = 0;
	for (std::vector<ellipse>::iterator it = Ellipses.begin(); it != Ellipses.end(); ++it)
	{
		std::cout << i++ << ")\n";
		it->print_info();
	}
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
	rectangle newRectangle = rectangle(a, b, painted);
	Rectangles.push_back(newRectangle);
}

void Canvas::remove_rectangle()
{
	int n;
	std::cout << "Choose ellipse which you want to draw: \n";
	print_lines_list();
	std::cin >> n;
	system("cls");
	auto iter = Ellipses.cbegin();
	Ellipses.erase(iter + n);
}

void Canvas::delete_all_rectangles()
{
	Rectangles.clear();
}

void Canvas::draw_rectangle()
{
	int n;
	std::cout << "Choose rectangle which you want to draw: \n";
	print_rectangles_list();
	std::cin >> n;
	system("cls");
	Rectangles.at(n).show_figure();
}

void Canvas::print_rectangles_list()
{
	int i = 0;
	for (std::vector<rectangle>::iterator it = Rectangles.begin(); it != Rectangles.end(); ++it)
	{
		std::cout << i++ << ")\n";
		it->print_info();
	}
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
	polygon pol = polygon(count, arr, painted);
	Polygons.push_back(pol);
}

void Canvas::remove_polygon()
{
	int n;
	std::cout << "Choose ellipse which you want to draw: \n";
	print_polygons_list();
	std::cin >> n;
	system("cls");
	auto iter = Polygons.cbegin();
	Polygons.erase(iter + n);
}

void Canvas::delete_all_polygons()
{
	Polygons.clear();
}

void Canvas::draw_polygon()
{
	int n;
	std::cout << "Choose Polygon which you want to draw: \n";
	print_polygons_list();
	std::cin >> n;
	system("cls");
	Polygons.at(n).show_figure();
}

void Canvas::print_polygons_list()
{
	int i = 0;
	for (std::vector<polygon>::iterator it = Polygons.begin(); it != Polygons.end(); ++it)
	{
		std::cout << i++ << ") \n";
		it->print_info();
		std::cout << "\n";
	}

}


void Canvas::draw_line()
{
	int n;
	std::cout << "Choose line which you want to draw: \n";
	print_lines_list();
	std::cin >> n;
	system("cls");
	Lines.at(n).show_figure();
}