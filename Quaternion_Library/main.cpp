#include <iostream>

#include "quaternion.h"

using namespace std;

int main (void)
{
	cout << "Quaternion Test" << endl;
	Quaternion::quat q = Quaternion::quat(1,1,1,1);
	cout << "END TEST" << endl;
	return 0;
}
