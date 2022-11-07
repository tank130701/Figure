#pragma once
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
	void delete_all_points();
	void draw_point();
	void print_points_list();
	//Lines
	void append_line();
	void remove_line();
	void delete_all_lines();
	void draw_line();
	void print_lines_list();
	//Ellipses
	void append_ellipse();
	void remove_ellipse();
	void delete_all_elipses();
	void draw_ellipse();
	void print_ellipses_list();
	//Rectangles
	void append_rectangle();
	void remove_rectangle();
	void delete_all_rectangles();
	void draw_rectangle();
	void print_rectangles_list();
	//Polygons
	void append_polygon();
	void remove_polygon();
	void delete_all_polygons();
	void draw_polygon();
	void print_polygons_list();

};