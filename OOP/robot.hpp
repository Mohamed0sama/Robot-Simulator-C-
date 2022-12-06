#ifndef ROBOT_HPP
#define ROBOT_HPP


using namespace std;
#include <iostream>


class robot {
private:
	int x_axis;
	int y_axis;
	char dir;

	void move();
	void change_direction(char R);

public:
	robot();
	robot(int x, int y, char d);
	void applySequence(string s);
	void showLocation();
};

#endif

