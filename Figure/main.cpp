#include <iostream>
#include <vector>
#include <Windows.h>
#include <conio.h>
#include "Figure.h"
#include "Point.h"
#include "Line.h"
#include "ellipse.h"
#include "rectangle.h"
#include "polygon.h"
#include "Canvas.h"


int menu() {
	std::cout << 
		"\n=====Points========\n\n"
		"1. Append point\n"
		"2. Remove point\n"
		"3. Delete all points\n"
		"4. Draw point\n\n"
		"======Lines========\n\n"
		"5. Append line\n"
		"6. Remove line\n"
		"7. Delete all lines\n"
		"8. Draw line\n\n"
		"====Rectangles=====\n\n"
		"9. Append rectangle\n"
		"10. Remove rectangle\n"
		"11. Delete all rectangles\n"
		"12. Draw rectangle\n\n"
		"======Ellipses=====\n\n"
		"13. Append ellipse\n"
		"14. Remove ellipse\n"
		"15. Delete all ellipses\n"
		"16. Draw ellipse\n\n"
		"======Polygons=====\n\n"
		"17. Append polygon\n"
		"18. Remove polygon\n"
		"19. Delete all polygons\n"
		"20. Draw polygon\n\n"
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
			canv.remove_point();
			break;
		case 3:
			system("cls");
			canv.delete_all_points();
			break;
		case 4:
			system("cls");
			canv.draw_point();
			break;
		case 5:
			system("cls");
			canv.append_line();
			break;
		case 6:
			system("cls");
			canv.remove_line();
			break;
		case 7:
			system("cls");
			canv.delete_all_lines();
			break;
		case 8:
			system("cls");
			canv.draw_line();
			break;
		case 9:
			system("cls");
			canv.append_rectangle();
			break;
		case 10:
			system("cls");
			canv.remove_rectangle();
			break;
		case 11:
			system("cls");
			canv.delete_all_rectangles();
			break;
		case 12:
			system("cls");
			canv.draw_rectangle();
			break;
		case 13:
			system("cls");
			canv.append_ellipse();
			break;
		case 14:
			system("cls");
			canv.remove_ellipse();
			break;
		case 15:
			system("cls");
			canv.delete_all_elipses();
			break;
		case 16:
			system("cls");
			canv.draw_ellipse();
			break;
		case 17:
			system("cls");
			canv.append_polygon();
			break;
		case 18:
			system("cls");
			canv.remove_polygon();
			break;
		case 19:
			system("cls");
			canv.delete_all_polygons();
			break;
		case 20:
			system("cls");
			canv.draw_polygon();
			break;
		};
		if (exit == true) break;

	}
	return 0;
}

