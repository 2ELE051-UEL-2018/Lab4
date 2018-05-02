#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
	void array_inverte(double res[], double v[], int numElementos);
}

TEST(tests_array_inverte, Teste0)
{
	double v[] = { 0.0 };
	double vInvertido[] = { 0.0 };
	double res[1];

	array_inverte(res, v, 1);

	VECTOR_DOUBLES_EQUAL(vInvertido, res, 1e-6, 1);
}

TEST(tests_array_inverte, Teste12)
{
	double v[] = { 1.0, 2.0 };
	double vInvertido[] = { 2.0, 1.0 };
	double res[2];

	array_inverte(res, v, 2);

	VECTOR_DOUBLES_EQUAL(vInvertido, res, 1e-6, 2);
}

TEST(tests_array_inverte, Teste123)
{
	double v[] = { 1.0, 2.0, 3.0 };
	double vInvertido[] = { 3.0, 2.0, 1.0 };
	double res[3];

	array_inverte(res, v, 3);

	VECTOR_DOUBLES_EQUAL(vInvertido, res, 1e-6, 3);
}

TEST(tests_array_inverte, Teste1234)
{
	double v[] = { 1.0, 2.0, 3.0, 4.0 };
	double vInvertido[] = { 4.0, 3.0, 2.0, 1.0 };
	double res[4];

	array_inverte(res, v, 4);

	VECTOR_DOUBLES_EQUAL(vInvertido, res, 1e-6, 4);
}
