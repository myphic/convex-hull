#pragma once
#include <vector>
#include <stack>
#include <algorithm>
#include <optional>
#include <fstream>
class Point
{
public:
	double x;
	double y;
	Point(double x = 0.0, double y = 0.0);
	Point operator+(const Point& A) const;
	Point operator-(const Point& A) const;
	bool operator==(const Point& A) const;
	Point operator*(const double value);
	bool operator<(const Point& dot);
	friend std::ostream& operator<<(std::ostream& stream, Point dot);
};

