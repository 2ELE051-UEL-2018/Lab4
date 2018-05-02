#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
	void vetor_soma(double c[], double a[], double b[],	int numElementos);
}


TEST(tests_vetor_soma, Teste00)
{
	double a[] = { 0.0 };
	double b[] = { 0.0 };
	double c[1];
	double aMaisB[] = { 0.0 };

	vetor_soma(c, a, b, 1);

	VECTOR_DOUBLES_EQUAL(aMaisB, c, 1e-6, 1);
}

TEST(tests_vetor_soma, Teste12)
{
	double a[] = { 1.0 };
	double b[] = { 2.0 };
	double c[1];
	double aMaisB[] = { 3.0 };

	vetor_soma(c, a, b, 1);

	VECTOR_DOUBLES_EQUAL(aMaisB, c, 1e-6, 1);
}

TEST(tests_vetor_soma, Teste1234)
{
	double a[] = { 1.0, 2.0 };
	double b[] = { 3.0, 4.0 };
	double c[2];
	double aMaisB[] = { 4.0, 6.0 };

	vetor_soma(c, a, b, 2);

	VECTOR_DOUBLES_EQUAL(aMaisB, c, 1e-6, 2);
}

TEST(tests_vetor_soma, Teste12345m12m34m5)
{
	double a[] = {  1.0, 2.0,  3.0, 4.0,  5.0 };
	double b[] = { -1.0, 2.0, -3.0, 4.0, -5.0 };
	double c[5];
	double aMaisB[] = { 0.0, 4.0, 0.0, 8.0, 0.0 };

	vetor_soma(c, a, b, 5);

	VECTOR_DOUBLES_EQUAL(aMaisB, c, 1e-6, 5);
}
