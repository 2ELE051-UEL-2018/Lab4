#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
	void array_copia(double a[], double b[], int numElementos);
}

TEST(tests_array_copia, Teste0)
{
	double v[] = { 0.0 };
	double res[1];

	array_copia(res, v, 1);

	VECTOR_DOUBLES_EQUAL(v, res, 1e-6, 1);
}

TEST(tests_array_copia, Teste12)
{
	double v[] = { 1.0, 2.0 };
	double res[2];

	array_copia(res, v, 2);

	VECTOR_DOUBLES_EQUAL(v, res, 1e-6, 2);
}

TEST(tests_array_copia, Teste123456)
{
	double v[] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0 };
	double res[6];

	array_copia(res, v, 6);

	VECTOR_DOUBLES_EQUAL(v, res, 1e-6, 6);
}