#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
	int resolveSistemaLinear(double x[][1], double A[][3], double B[][1]);
}

TEST(tests_resolveSistemaLinear, TesteIdentidade123)
{
	double identidade[3][3] = {
		{ 1.0, 0.0, 0.0 },
		{ 0.0, 1.0, 0.0 },
		{ 0.0, 0.0, 1.0 }
	};

	double B[3][1] = {
		{ 1.0 },
		{ 2.0 },
		{ 3.0 }
	};

	double x[3][1];

	ASSERT_EQ(1, resolveSistemaLinear(x, identidade, B));

	COLUMN_VECTOR_DOUBLES_EQUAL(B, x, 1e-6, 3);
}

TEST(tests_resolveSistemaLinear, Teste1m3521m63m21m14200)
{
	double A[3][3] = {
		{ 1.0, -3.0,  5.0 },
		{ 2.0,  1.0, -6.0 },
		{ 3.0, -2.0,  1.0 }
	};

	double B[3][1] = {
		{ -14.0 },
		{  20.0 },
		{   0.0 }
	};

	double esperado[3][1] = {
		{  1.0 },
		{  0.0 },
		{ -3.0 }
	};

	double x[3][1];

	ASSERT_EQ(1, resolveSistemaLinear(x, A, B));

	COLUMN_VECTOR_DOUBLES_EQUAL(esperado, x, 1e-6, 3);
}

TEST(tests_resolveSistemaLinear, Teste1m2m312m124m1123)
{
	double A[3][3] = {
		{ 1.0, -2.0, -3.0 },
		{ 1.0,  2.0, -1.0 },
		{ 2.0,  4.0, -1.0 }
	};

	double B[3][1] = {
		{ 1.0 },
		{ 2.0 },
		{ 3.0 }
	};

	double esperado[3][1] = {
		{ -0.5  },
		{  0.75 },
		{ -1.0  }
	};

	double x[3][1];

	ASSERT_EQ(1, resolveSistemaLinear(x, A, B));

	COLUMN_VECTOR_DOUBLES_EQUAL(esperado, x, 1e-6, 3);
}

TEST(tests_resolveSistemaLinear, TesteNula)
{
	double A[3][3] = {
		{ 0.0, 0.0, 0.0 },
		{ 0.0, 0.0, 0.0 },
		{ 0.0, 0.0, 0.0 }
	};

	double B[3][1];
	double x[3][1];

	ASSERT_EQ(0, resolveSistemaLinear(x, A, B));
}

TEST(tests_resolveSistemaLinear, Teste123456789)
{
	double A[3][3] = {
		{ 1.0, 2.0, 3.0 },
		{ 4.0, 5.0, 6.0 },
		{ 7.0, 8.0, 9.0 }
	};

	double B[3][1];
	double x[3][1];

	ASSERT_EQ(0, resolveSistemaLinear(x, A, B));
}
