#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
	void matriz3x3_transposta(double B[][3], double A[][3]);
}


TEST(tests_matriz3x3_transposta, TesteIdentidade)
{
	double identidade[3][3] = {
		{ 1.0, 0.0, 0.0 },
		{ 0.0, 1.0, 0.0 },
		{ 0.0, 0.0, 1.0 }
	};
	double B[3][3];

	matriz3x3_transposta(B, identidade);

	MATRIX_3X3_DOUBLES_EQUAL(identidade, B, 1e-6);
}

TEST(tests_matriz3x3_transposta, Teste123456789)
{
	double A[3][3] = {
		{ 1.0, 2.0, 3.0 },
		{ 4.0, 5.0, 6.0 },
		{ 7.0, 8.0, 9.0 }
	};

	double AT[3][3] = {
		{ 1.0, 4.0, 7.0 },
		{ 2.0, 5.0, 8.0 },
		{ 3.0, 6.0, 9.0 }
	};

	double B[3][3];

	matriz3x3_transposta(B, A);

	MATRIX_3X3_DOUBLES_EQUAL(AT, B, 1e-6);
}
