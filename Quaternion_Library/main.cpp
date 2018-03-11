#include <iostream>

#include "quaternion.h"

using namespace std;

int main (void)
{
	cout << "Quaternion Test" << endl;
	Quaternion::quat q = Quaternion::quat(1,1,1,1);
	Quaternion::quat r = Quaternion::quat(1,2,3,4);
	Quaternion::quat s = Quaternion::quat(5,6,7,8);
	Quaternion::quat out;

	out = q;
	cout << "q: " << out.a << " " << out.b << " " << out.c << " " << out.d << endl;
	out = r;
	cout << "r: " << out.a << " " << out.b << " " << out.c << " " << out.d << endl;
	out = s;
	cout << "s: " << out.a << " " << out.b << " " << out.c << " " << out.d << endl;

	out = q + s;
	cout << "q+s: " << out.a << " " << out.b << " " << out.c << " " << out.d << endl;
	out = s - q;
	cout << "s-q: " << out.a << " " << out.b << " " << out.c << " " << out.d << endl;
	out = q * q;
	cout << "q*q: " << out.a << " " << out.b << " " << out.c << " " << out.d << endl;
	out = r * s;
	cout << "r*s: " << out.a << " " << out.b << " " << out.c << " " << out.d << endl;
	cout << "END TEST" << endl;
	return 0;
}
