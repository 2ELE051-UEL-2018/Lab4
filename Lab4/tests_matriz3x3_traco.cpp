#include "gtest/gtest.h"

extern "C"
{
	double matriz3x3_traco(double A[][3]);
}

TEST(tests_matriz3x3_traco, TesteNula)
{
	double nula[3][3] = {
		{ 0.0, 0.0, 0.0 },
		{ 0.0, 0.0, 0.0 },
		{ 0.0, 0.0, 0.0 }
	};

	ASSERT_NEAR(0.0, matriz3x3_traco(nula), 1e-6);
}

TEST(tests_matriz3x3_traco, TesteIdentidade)
{
	double identidade[3][3] = {
		{ 1.0, 0.0, 0.0 },
		{ 0.0, 1.0, 0.0 },
		{ 0.0, 0.0, 1.0 }
	};

	ASSERT_NEAR(3.0, matriz3x3_traco(identidade), 1e-6);
}

TEST(tests_matriz3x3_traco, Teste123456789)
{
	double A[3][3] = {
		{ 1.0, 2.0, 3.0 },
		{ 4.0, 5.0, 6.0 },
		{ 7.0, 8.0, 9.0 }
	};

	ASSERT_NEAR(15.0, matriz3x3_traco(A), 1e-6);
}