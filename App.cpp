#include <iostream>
#include "PriorityQueue.h"
#include "ExtendedTest.h"
#include "ShortTest.h"
#include <crtdbg.h>
using namespace std;




int main() {
	testAll();
	testAllExtended();

	
	cout << "End" << endl;

	_CrtDumpMemoryLeaks();
	system("pause");

}
