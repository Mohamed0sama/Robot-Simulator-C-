#include "robot.hpp"
#include <iostream>
#include <string>
using namespace std;

int main(void) {
	robot r1{ 7,3,'N' };
	string s;
	getline(cin, s);
	r1.applySequence(s);
	return 0;
}