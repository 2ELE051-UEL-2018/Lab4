#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
	int matriz3x3_inversa(double B[][3], double A[][3]);
}

TEST(tests_matriz3x3_inversa, TesteIdentidade)
{
	double identidade[3][3] = {
		{ 1.0, 0.0, 0.0 },
		{ 0.0, 1.0, 0.0 },
		{ 0.0, 0.0, 1.0 }
	};

	double B[3][3];

	ASSERT_EQ(1, matriz3x3_inversa(B, identidade));

	MATRIX_3X3_DOUBLES_EQUAL(identidade, B, 1e-6);
}

TEST(tests_matriz3x3_inversa, Teste105216340)
{
	double A[3][3] = {
		{ 1.0, 0.0, 5.0 },
		{ 2.0, 1.0, 6.0 },
		{ 3.0, 4.0, 0.0 }
	};

	double esperado[3][3] = {
		{ -24.0,  20.0, -5.0 },
		{  18.0, -15.0,  4.0 },
		{   5.0,  -4.0,  1.0 }
	};

	double B[3][3];

	ASSERT_EQ(1, matriz3x3_inversa(B, A));

	MATRIX_3X3_DOUBLES_EQUAL(esperado, B, 1e-6);
}

TEST(tests_matriz3x3_inversa, Teste210200201)
{
	double A[3][3] = {
		{ 2.0, 1.0, 0.0 },
		{ 2.0, 0.0, 0.0 },
		{ 2.0, 0.0, 1.0 }
	};

	double esperado[3][3] = {
		{ 0.0,  0.5, 0.0 },
		{ 1.0, -1.0, 0.0 },
		{ 0.0, -1.0, 1.0 }
	};

	double B[3][3];

	ASSERT_EQ(1, matriz3x3_inversa(B, A));

	MATRIX_3X3_DOUBLES_EQUAL(esperado, B, 1e-6);
}

TEST(tests_matriz3x3_inversa, TesteNula)
{
	double A[3][3] = {
		{ 0.0, 0.0, 0.0 },
		{ 0.0, 0.0, 0.0 },
		{ 0.0, 0.0, 0.0 }
	};

	double B[3][3];

	ASSERT_EQ(0, matriz3x3_inversa(B, A));
}

TEST(tests_matriz3x3_inversa, Teste1234567890)
{
	double A[3][3] = {
		{ 1.0, 2.0, 3.0 },
		{ 4.0, 5.0, 6.0 },
		{ 7.0, 8.0, 9.0 }
	};

	double B[3][3];

	ASSERT_EQ(0, matriz3x3_inversa(B, A));
}