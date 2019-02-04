#include <boost/format.hpp>
#include <boost/math/constants/constants.hpp>
#include <boost/multiprecision/gmp.hpp>
#include <boost/multiprecision/mpc.hpp>
#include <boost/multiprecision/mpfr.hpp>
#include <iostream>
#include <string>

using namespace boost::multiprecision;

std::string get_str(mpfr_t x) {
	const int DISPLAY_DIGITS = 60;
	char str[std::max(DISPLAY_DIGITS + 2, 7)];
	mpfr_exp_t exp;

	mpfr_get_str(str, &exp, 10, DISPLAY_DIGITS, x, MPFR_RNDN);

	std::string s(str);

	return s.substr(0, exp) + "." + s.substr(exp, -1);
}

int main() {
	mpfr_float::default_precision(100);
	mpc_complex::default_precision(100);
	mpfr_float PI = boost::math::constants::pi<mpfr_float>();
	mpc_complex I = mpc_complex(0, 1);
	mpc_complex OMEGA = exp(2 * I * PI / 3);

	std::cout << "float precision: " << mpfr_float::default_precision() << std::endl;
	std::cout << "complex precision: " << mpc_complex::default_precision() << std::endl;

	std::cout << "---- Default behaviour ----" << std::endl;
	std::cout << "PI: " << PI << std::endl;
	std::cout << "I: " << I << std::endl;
	std::cout << "OMEGA: " << OMEGA << std::endl;

	std::cout << "---- C style routine with hardcoded displayed digits ----" << std::endl;
	std::cout << "PI: " << get_str(PI.backend().data()) << std::endl;

	std::cout << "---- Setting precision with C++ standard library (precision 50) ----" << std::endl;
	std::cout << std::scientific << std::fixed;
	std::cout << std::setprecision(std::numeric_limits<mpfr_float_50::value_type>::digits10);
	std::cout << "PI: " << PI << std::endl;
	std::cout << std::setprecision(std::numeric_limits<mpc_complex_50::value_type>::digits10);
	std::cout << "I: " << I << std::endl;
	std::cout << "OMEGA: " << OMEGA << std::endl;

	std::cout << "---- Setting precision with C++ standard library (precision 100) ----" << std::endl;
	std::cout << std::scientific << std::fixed;
	std::cout << std::setprecision(std::numeric_limits<mpfr_float_100::value_type>::digits10);
	std::cout << "PI: " << PI << std::endl;
	std::cout << std::setprecision(std::numeric_limits<mpc_complex_100::value_type>::digits10);
	std::cout << "I: " << I << std::endl;
	std::cout << "OMEGA: " << OMEGA << std::endl;

	return 0;
}