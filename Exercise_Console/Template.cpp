#include "Template.h"

#include <iostream>

namespace test{

void Point::ShowPos()
{
	std::cout << "Point(" << x_ << "," << y_ <<")" << std::endl;
}

void Point::ShowPoint()
{
	std::cout << "Point(" << x_ << "," << y_ <<")" << std::endl;
}


void Line::ShowPos()
{
	std::cout << "Line: Begin_(" << begin_.x_ << "," << begin_.y_ << "), End_(";
	std::cout << end_.x_ << "," << end_.y_ << ")" << std::endl;
}

void Line::ShowLine()
{
	std::cout << "Line: Begin_(" << begin_.x_ << "," << begin_.y_ << "), End_(";
	std::cout << end_.x_ << "," << end_.y_ << ")" << std::endl;
}

} //namespace test