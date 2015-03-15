// Exercise_Console.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Template.h"
#include "EightQuee.h"

using namespace test;

void FuncTemplate();
void FuncEightQuee();

int _tmain(int argc, _TCHAR* argv[])
{
	//FuncTemplate();
	FuncEightQuee();

	return 0;
}

void FuncTemplate()
{
	int min_int = min(5, 6);
	double min_double = min(4.3, 3.2);

	double res = min(4, 3.2);

	OperateGraph<Line> og1(Line(Point(3, 4), Point(4, 5)));
	og1.ShowPos();

	OperateGraph<Point> og2(Point(7, 8));
	og2.ShowPos();
}

void FuncEightQuee()
{
	EightQuee();
}