/*
#include <vector>
#include <Windows.h>
#include <conio.h>
#include "Figure.h"
#include "Point.h"
#include "Line.h"
#include "ellipse.h"
#include "rectangle.h"
#include "polygon.h"*/
#include "Windows.h"
#include <iostream>
#include "Canvas.h"


int menu() {
	system("cls");
	std::cout << 
		"\n=====Points========\n\n"
		"1. Append point\n\n"
		"======Lines========\n\n"
		"2. Append line\n\n"
		"====Rectangles=====\n\n"
		"3. Append rectangle\n\n"
		"======Ellipses=====\n\n"
		"4. Append ellipse\n\n"
		"======Polygons=====\n\n"
		"5. Append polygon\n\n"
		"=====Interaction===\n\n"
		"6. Draw figures\n"
		"7. Print figures list\n"
		"8. Delete all figures\n"
		"9. Remove figure\n"
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
			canv.append_line();
			break;
		case 3:
			system("cls");
			canv.append_rectangle();
			break;
		case 4:
			system("cls");
			canv.append_ellipse();
			break;
		case 5:
			system("cls");
			canv.append_polygon();
			break;
		case 6:
			system("cls");
			canv.show();
			break;
		case 7:
			system("cls");
			canv.print_figures_list();
			break;
		case 8:
			system("cls");
			canv.remove_all_figures();
			break;
		case 9:
			system("cls");
			canv.remove_figure();
			break;
		};
		if (exit == true) break;

	}
	return 0;
}

