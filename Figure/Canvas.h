#pragma once
#include "Windows.h"
#include <vector>
#include "Figure.h"
#include "Point.h"
#include "line.h"
#include "ellipse.h"
#include "rectangle.h"
#include "polygon.h"

class Canvas
{
	std::vector<Figure*> Figures;
	HWND hWnd;
	HDC hdc;
public:
	void show();
	void add_figure(Figure *shape);
	void remove_figure();
	void print_figures_list();
	void remove_all_figures();
	//Points
	Point create_point();
	void append_point();
	//Lines
	void append_line();
	//Ellipses
	void append_ellipse();
	//Rectangles
	void append_rectangle();
	//Polygons
	void append_polygon();
	Canvas();
	~Canvas();
};