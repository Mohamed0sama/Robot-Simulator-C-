#include "robot.hpp"
#include <iostream>
#include <algorithm>
using namespace std;

robot::robot() {
	x_axis = 0;
	y_axis = 0;
	dir = 'N';
}
robot::robot(int x, int y, char d) {
	x_axis = x;
	y_axis = y;
	dir = d;
}

void robot::move() {
	switch (dir) {
	case 'E': x_axis++; break;
	case 'N':y_axis++; break;
	case 'W':x_axis--; break;
	case 'S':y_axis--; break;
	}
}

void robot::change_direction(char Rotation) {
	if (Rotation == 'R') {
		switch (dir) {
		case'E':dir = 'S'; break;
		case'N':dir = 'E'; break;
		case'S':dir = 'W'; break;
		case'W':dir = 'N'; break;
		}
	}
	else if (Rotation == 'L') {
		switch (dir) {
		case'E':dir = 'N'; break;
		case'N':dir = 'W'; break;
		case'W':dir = 'S'; break;
		case'S':dir = 'E'; break;
		}
	}
}

void robot::applySequence(string s) {
	transform(s.begin(), s.end(), s.begin(), ::toupper);
	for (int i = 0; i < s.length(); i++) {
		switch (s.at(i)) {
		case 'L':
		case 'R':
			change_direction(s.at(i));
			showLocation();
			break;
		case 'A':
			move();
			showLocation();
			break;
		default:
			cout << s.at(i) << " Out of range" << endl;
			break;
		}
	}
}

void robot::showLocation() {
	cout << "Robot at point (" << x_axis << "," << y_axis << ")..Heading to location " << dir << endl;
}


