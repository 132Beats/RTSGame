#include "app.hpp"
#include <iostream>
#include <fstream>


int main(int argc, char** argv) {
	try {
		App app;
		return app.Start();
	}
	catch (...) {
		return 1;
	}
	

	return 1;

}


