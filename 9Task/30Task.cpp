#include "pch.h"
#include <iostream>
#include "Point.h"

using namespace std;

vector<Point> convex_hull(vector<Point> p) {
	vector<Point> result;
	auto it = min_element(begin(p),end(p), [](auto& a, auto& b) -> bool {return a.y < b.y; });
	iter_swap(it, begin(p));
	for (int i = 1; i < p.size(); ++i) {
		p[i] = p[i] - p[0];
	}
	sort(begin(p) + 1, end(p));
	stack<Point> s;
	s.push(Point());
	s.push(p[1]);
	for (int c = 2; c < p.size(); c++) {
		auto b = s.top();
		s.pop();
		if (b - s.top() < p[c] - b) {
			s.push(b);
			s.push(p[c]);
		}
		else {
			--c;
		}
	}
	while(s.size()) {
		result.push_back(s.top()+p[0]);
		s.pop();
	}
	return result;
}

bool is_equal(vector<Point>& t, vector<Point>& t1) {
	sort(t.begin(), t.end());
	sort(t1.begin(), t1.end());
	for (int i = 0; i < t.size(); i++) {
		if (t[i].x != t1[i].x) {
			return false;
		}
	}
	return true;
}
//Функция вернет 0 если многоугольник выпуклый, а если нет, то найдет вершины внутри выпуклой оболочки
optional<vector<Point>> convex_hull_task(vector<Point> p) {
	vector<Point> convex(p.size());
	convex = convex_hull(p);
	if (is_equal(p,convex)) {
		return nullopt;
	}
	else {
		for (int i = 0; i < convex.size(); i++) {
			auto it = find(begin(p), end(p), convex[i]);
			p.erase(it);
		}
	}
	return p;
}

int main()
{
	string path = "30TaskSecondTest.txt";
	vector<Point> tmp;
	ifstream fileIn;
	fileIn.open(path);
	if (!fileIn.is_open()) {
		cout << "Error. File wasn't opened. " << endl;
	}
	else {
		cout << "File is opened" << endl;
		double x, y;
		while (fileIn >> x >> y) {
			tmp.push_back(Point(x, y));
		}
	}
	fileIn.close();

	bool test = bool(convex_hull_task(tmp));
	if (test) {
		auto vertices_inside = convex_hull_task(tmp);
		for (auto i : *vertices_inside) {
			cout << i;
		}
	}
	if (!test)
	{
		cout << test;
	}

	return 0;
}
