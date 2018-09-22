#include <math.h>

#include "quaternion.h"

using namespace Quaternion;

quat& quat::operator= (const quat &q)
{
	this->a = q.a;
	this->b = q.b;
	this->c = q.c;
	this->d = q.d;
	return *this;
}

quat& quat::operator+= (const quat &q)
{
	this->a += q.a;
	this->b += q.b;
	this->c += q.c;
	this->d += q.d;
	return *this;
}

quat& quat::operator-= (const quat &q)
{
	this->a -= q.a;
	this->b -= q.b;
	this->c -= q.c;
	this->d -= q.d;
	return *this;
}
quat& quat::operator*= (const quat &q)
{

	double a = this->a*q.a - this->b*q.b - this->c*q.c - this->d*q.d;
	double b = this->a*q.b + this->b*q.a + this->c*q.d - this->d*q.c;
	double c = this->a*q.c - this->b*q.d + this->c*q.a + this->d*q.b;
	double d = this->a*q.d + this->b*q.c - this->c*q.b + this->d*q.a;
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
	return *this;
}

bool quat::operator== (const quat &q)
{
	return (this->a == q.a && this->b == q.b && this->c == q.c && this->d == q.d);
}

const quat Quaternion::operator+ (const quat &q1, const quat &q2)
{
	return quat(q1.a + q2.a, q1.b + q2.b, q1.c + q2.c, q1.d + q2.d);
}

const quat Quaternion::operator+ (const quat &q, double r)
{
	return quat(q.a + r, q.b + r, q.c + r, q.d + r);
}

const quat Quaternion::operator+ (double r, const quat &q)
{
	return quat(r + q.a, r + q.b, r + q.c, r + q.d);
}

const quat Quaternion::operator- (const quat &q1, const quat &q2)
{
	return quat(q1.a - q2.a, q1.b - q2.b, q1.c - q2.c, q1.d - q2.d);
}

const quat Quaternion::operator- (const quat &q, double r)
{
	return quat(q.a - r, q.b - r, q.c - r, q.d - r);
}

const quat Quaternion::operator- (double r, const quat &q)
{
	return quat(r - q.a, r - q.b, r - q.c, r - q.d);
}

const quat Quaternion::operator* (const quat &q1, const quat &q2)
{
	return quat(
		q1.a*q2.a - q1.b*q2.b - q1.c*q2.c - q1.d*q2.d,
		q1.a*q2.b + q1.b*q2.a + q1.c*q2.d - q1.d*q2.c,
		q1.a*q2.c - q1.b*q2.d + q1.c*q2.a + q1.d*q2.b,
		q1.a*q2.d + q1.b*q2.c - q1.c*q2.b + q1.d*q2.a
	);
}

const quat Quaternion::operator* (const quat &q, double r)
{
	return quat(r*q.a, r*q.b, r*q.c, r*q.d);
}

const quat Quaternion::operator* (double r, const quat &q)
{
	return quat(r*q.a, r*q.b, r*q.c, r*q.d);
}

const quat quat::negate(void)
{
	return quat(-this->a, -this->b, -this->c, -this->d);
}

const quat quat::conjugate(void)
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
