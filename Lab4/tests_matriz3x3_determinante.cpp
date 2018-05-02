#include "gtest/gtest.h"

extern "C"
{
	double matriz3x3_determinante(double A[][3]);
}

TEST(tests_matriz3x3_determinante, TesteNula)
{
	double nula[3][3] = {
		{ 0.0, 0.0, 0.0 },
		{ 0.0, 0.0, 0.0 },
		{ 0.0, 0.0, 0.0 }
	};

	ASSERT_NEAR(0.0, matriz3x3_determinante(nula), 1e-6);
}

TEST(tests_matriz3x3_determinante, TesteIdentidade)
{
	double identidade[3][3] = {
		{ 1.0, 0.0, 0.0 },
		{ 0.0, 1.0, 0.0 },
		{ 0.0, 0.0, 1.0 }
	};

	ASSERT_NEAR(1.0, matriz3x3_determinante(identidade), 1e-6);
}

TEST(tests_matriz3x3_determinante, Teste123456789)
{
	double A[3][3] = {
		{ 1.0, 2.0, 3.0 },
		{ 4.0, 5.0, 6.0 },
		{ 7.0, 8.0, 9.0 }
	};

	ASSERT_NEAR(0.0, matriz3x3_determinante(A), 1e-6);
}

TEST(tests_matriz3x3_determinante, TesteMagic3)
{
	double A[3][3] = {
		{ 8.0, 1.0, 6.0 },
		{ 3.0, 5.0, 7.0 },
		{ 4.0, 9.0, 2.0 }
	};

	ASSERT_NEAR(-360.0, matriz3x3_determinante(A), 1e-6);
}
