#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
	int matriz3x3_simetrica(double A[][3]);
}

TEST(tests_matriz3x3_simetrica, TesteIdentidade)
{
	double identidade[3][3] = {
		{ 1.0, 0.0, 0.0 },
		{ 0.0, 1.0, 0.0 },
		{ 0.0, 0.0, 1.0 }
	};

	ASSERT_EQ(1, matriz3x3_simetrica(identidade));
}

TEST(tests_matriz3x3_simetrica, Teste123456789)
{
	double A[3][3] = {
		{ 1.0, 2.0, 3.0 },
		{ 4.0, 5.0, 6.0 },
		{ 7.0, 8.0, 9.0 }
	};

	ASSERT_EQ(0, matriz3x3_simetrica(A));
}

TEST(tests_matriz3x3_simetrica, TesteQuaseSimetrica)
{
	double A[3][3] = {
		{ 1.0, 2.0, 3.0 },
		{ 2.0, 4.0, 2.0 },
		{ 5.0, 2.0, 1.0 }
	};

	ASSERT_EQ(0, matriz3x3_simetrica(A));
}
