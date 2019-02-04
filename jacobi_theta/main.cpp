#include <boost/math/constants/constants.hpp>
#include <iostream>

void Jacobian_Theta_Functions(double z, double q, double *theta_1,
                           double *theta_2, double *theta_3, double *theta_4 );

int main() {
	double theta1, theta2, theta3, theta4;
	double PI = boost::math::constants::pi<double>();

	Jacobian_Theta_Functions(PI * 0.4, 0.1, &theta1, &theta2, &theta3, &theta4);
	std::cout << theta3 << std::endl;

	return 0;
}