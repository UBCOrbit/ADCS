#include <math.h>

#include "quaternion.h"

using namespace Quaternion;

quat operator+ (const quat &q1, const quat &q2)
{
	return quat(q1.a + q2.a, q1.b + q2.b, q1.c + q2.c, q1.d + q2.d);
}

quat operator+ (const quat &q, double r)
{
	return quat(q.a + r, q.b + r, q.c + r, q.d + r);
}

quat operator+ (double r, const quat &q)
{
	return quat(r + q.a, r + q.b, r + q.c, r + q.d);
}

quat operator- (const quat &q1, const quat &q2)
{
	return quat(q1.a - q2.a, q1.b - q2.b, q1.c - q2.c, q1.d - q2.d);
}

quat operator- (const quat &q, double r)
{
	return quat(q.a - r, q.b - r, q.c - r, q.d - r);
}

quat operator- (double r, const quat &q)
{
	return quat(r - q.a, r - q.b, r - q.c, r - q.d);
}

quat operator* (const quat &q1, const quat &q2)
{
	return quat(
		q1.a*q2.a - q1.b*q2.b - q1.c*q2.c - q1.d*q2.d,
		q1.a*q2.b + q1.b*q2.a + q1.c*q2.d - q1.d*q2.c,
		q1.a*q2.c - q1.b*q2.d + q1.c*q2.a + q1.d*q2.b,
		q1.a*q2.d + q1.b*q2.c - q1.c*q2.b + q1.d*q2.a
	);
}

quat operator* (const quat &q, double r)
{
	return quat(r*q.a, r*q.b, r*q.c, r*q.d);
}

quat operator* (double r, const quat &q)
{
	return quat(r*q.a, r*q.b, r*q.c, r*q.d);
}

quat quat::negate(void)
{
	return quat(-this->a, -this->b, -this->c, -this->d);
}

quat quat::conjugate(void)
{
	return quat(this->a, -this->b, -this->c, -this->d);
}

double quat::norm(void)
{
	return sqrt(
		this->a*this->a +
		this->b*this->b +
		this->c*this->c +
		this->d*this->d
	);
}
