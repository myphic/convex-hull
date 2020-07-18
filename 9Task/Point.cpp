#include "pch.h"
#include "Point.h"

Point::Point(double x, double y) {
	this->x = x;
	this->y = y;
}
Point Point::operator+(const Point& A) const {
	return Point(x + A.x, y + A.y);
}

Point Point::operator-(const Point& A) const {
	return Point(x - A.x, y - A.y);
}
bool Point::operator==(const Point& A) const {
	return x == A.x && y == A.y;
}
Point Point::operator*(const double value) {
	return Point(this->x * value, this->y * value);
}
bool Point::operator<(const Point& dot) {
	return x * dot.y - y * dot.x > 0;
}
std::ostream& operator<<(std::ostream& stream, Point dot) {
	stream << dot.x << " " << dot.y << std::endl;
	return stream;
}
