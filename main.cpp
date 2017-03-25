#include <iostream>
#include <time.h>

#include "command_routing.h"

using namespace std;

int main() {
	cout << "Welcome to your DnD Assistant." << endl;

	srand(time(0));

	//main loop logic, routes user commands until quit
	routeCommand();

	return 0;
}
