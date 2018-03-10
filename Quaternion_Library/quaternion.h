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

			quat(double a, double b, double c, double d)
			{
				this->a = a;
				this->b = b;
				this->c = c;
				this->d = d;
			}

			quat negate(void);

			quat conjugate(void);

			double norm(void);

	};

			quat operator+ (const quat &q1, const quat &q2);

			quat operator+ (const quat &q, double r);

			quat operator+ (double r, const quat &q);

			quat operator* (const quat &q1, const quat &q2);

			quat operator* (const quat &q, double r);

			quat operator* (double r, const quat &q);

			quat operator- (const quat &q1, const quat &q2);

			quat operator- (const quat &q, double r);

			quat operator- (double r, const quat &q);
}
