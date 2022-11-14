#pragma once
#include "Windows.h"
class Figure
{
public:
	virtual void show_figure(HDC hdc) = 0;
	virtual void print_info() = 0;
};