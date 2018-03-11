#ifndef __QUATERNION_H
#define __QUATERNION_H

namespace Quaternion
{
	/**
	 * Wrapper to perform operations using quaternions
	 */
	class quat
	{
		// A quaternions consists of {a, b*i, c*j, d*k}
		public:

			double a;
			double b;
			double c;
			double d;

			quat()
			{
				this->a = 0;
				this->b = 0;
				this->c = 0;
				this->d = 0;
			}

			quat(double a, double b, double c, double d)
			{
				this->a = a;
				this->b = b;
				this->c = c;
				this->d = d;
			}

			quat& operator= (const quat &q);

			quat& operator+= (const quat &q);

			quat& operator-= (const quat &q);

			quat& operator*= (const quat &q);

			bool operator== (const quat &q);

			const quat negate(void);

			const quat conjugate(void);

			double norm(void);

	};

	const quat operator+ (const quat &q1, const quat &q2);

	const quat operator+ (const quat &q, double r);

	const quat operator+ (double r, const quat &q);

	const quat operator* (const quat &q1, const quat &q2);

	const quat operator* (const quat &q, double r);

	const quat operator* (double r, const quat &q);

	const quat operator- (const quat &q1, const quat &q2);

	const quat operator- (const quat &q, double r);

	const quat operator- (double r, const quat &q);

}

#endif // __QUATERNION_H
