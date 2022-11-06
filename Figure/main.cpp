#include <conio.h> // для _getch
#include <windows.h>
#include <iostream>
#include <list>
#include <vector>

#include "Figure.h"
#include "Point.h"
#include "line.h"
#include "ellipse.h"
#include "rectangle.h"
#include "polygon.h"

class Canvas
{
	std::vector<Point> Points;
	std::vector<Line> Lines;
	std::vector<ellipse> Ellipses;
	std::vector<rectangle> Rectangles;
	std::vector<polygon> Polygons;
public:
	//Points
	Point create_point();
	void append_point();
	void remove_point();
	void draw_point();
	void print_points_list();
	//Lines
	void append_line();
	void remove_line();
	void draw_line();
	void print_lines_list();
	//Ellipses
	void append_ellipse();
	void remove_ellipse();
	void draw_ellipse();
	void print_ellipses_list();
	//Rectangles
	void append_rectangle();
	void remove_rectangle();
	void draw_rectangle();
	void print_rectangles_list();
	//Polygons
	void append_polygon();
	void remove_polygon();
	void draw_polygon();
	void print_polygons_list();

};

int menu() {
	std::cout << 
		"\n=====Points========\n\n"
		"1. Append a point\n"
		"2. Remove a point\n"
		"3. Delete all points\n"
		"4. Draw a point\n\n"
		"======Lines========\n\n"
		"3. Append a line\n"
		"4. Draw a line\n\n"
		"====Rectangles=====\n\n"
		"5. Append rectangle\n"
		"6. Draw a rectangle\n\n"
		"======Ellipses=====\n\n"
		"7. Append ellipse\n"
		"8. Draw ellipse\n\n"
		"======Polygons=====\n\n"
		"9. Append polygon\n"
		"10. Draw polygon\n\n"
		"0. Exit " << std::endl;
	int cmd;
	std::cout << "~$ ";
	std::cin >> cmd;
	return cmd;
};


int main()
{
	Canvas canv;
	while (true)
	{
		int cmd = menu();
		bool exit = false;
		switch (cmd) {
		case 0:
			exit = true;
			break;
		case 1:
			system("cls");
			canv.append_point();
			break;
		case 2:
			system("cls");
			canv.draw_point();
			break;
		case 3:
			system("cls");
			canv.append_line();
			break;
		case 4:
			system("cls");
			canv.draw_line();
			break;
		case 5:
			system("cls");
			canv.append_rectangle();
			break;
		case 6:
			system("cls");
			canv.draw_rectangle();
			break;
		case 7:
			system("cls");
			canv.append_ellipse();
			break;
		case 8:
			system("cls");
			canv.draw_ellipse();
			break;
		case 9:
			system("cls");
			canv.append_polygon();
			break;
		case 10:
			system("cls");
			canv.draw_polygon();
			break;
		};
		if (exit == true) break;

	}
	return 0;
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
	for (int i = 0; i < count; i++)
	{
		Point newPoint = create_point();
		rec_points.push_back(newPoint);
	}
	polygon pol = polygon(count, (&rec_points), painted);
	Polygons.push_back(pol);
}

void Canvas::remove_polygon()
{
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