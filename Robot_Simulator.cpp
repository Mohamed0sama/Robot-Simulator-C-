#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

typedef enum direction {
	north, south, east, west
};
direction current_direction = north;

void turn_right() {
	if (current_direction == north) {
		current_direction = east;
	}
	else if (current_direction == east) {
		current_direction = south;
	}
	else if (current_direction == south) {
		current_direction = west;
	}
	else if (current_direction == west) {
		current_direction = north;
	}
	else {
	}
}
void turn_left() {
	if (current_direction == north) {
		current_direction = west;
	}
	else if (current_direction == west) {
		current_direction = south;
	}
	else if (current_direction == south) {
		current_direction = east;
	}
	else if (current_direction == east) {
		current_direction = north;
	}
	else {
	}
}
const char* getDir(direction current_direction) {
	switch (current_direction) {
	case north:
		return "north";
	case south:
		return "south";
	case east:
		return "east";
	case west:
		return "west";
	default:
		cout << current_direction;
	}
}
void robot_moving(char* instructions,int *x,int *y) {
	int i{ 0 };
	while (instructions[i] != '\0') {
		if (instructions[i] == 'R' || instructions[i] == 'r') {
			turn_right();
		}
		else if (instructions[i] == 'L' || instructions[i] == 'l') {
			turn_left();
		}
		else if (instructions[i] == 'A' || instructions[i] == 'a') {
			if (current_direction == east) {
				*x = *x + 1;
			}
			else if (current_direction == north) {
				*y = *y + 1;
			}
			else if (current_direction == west) {
				*x = *x - 1;
			}
			else if (current_direction == south) {
				*y=*y-1;
			}
		}
		cout << instructions[i] << "--->The Robot Coorrdinates = " << "{" << *x << "," << *y << "}" << " Heading to " << getDir(current_direction) << endl;
		i++;
	}
}

int main() {	
	
	int x{ 7 }, y{ 3 };
	char instructions[100];
	cout << "Please enter the Set of instructions\nL for Left\nR for Right\nA for Advance" << endl;
	cin >> instructions;
	
	robot_moving(instructions,&x,&y);

	return 0;
}