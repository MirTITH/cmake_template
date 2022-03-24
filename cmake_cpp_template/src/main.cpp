#include <iostream>
#include "main.hpp"
#include "version.h"

using namespace std;

int main(int, char**)
{
	cout << "Project: " << PROJECT_NAME << endl;
	cout << "Version: " << PROJECT_VER << endl;
    cout << "Hello, world!\n";
	return 0;
}
