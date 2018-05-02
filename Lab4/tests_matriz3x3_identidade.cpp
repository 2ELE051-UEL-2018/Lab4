#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
	void matriz3x3_identidade(double A[][3]);
}

TEST(tests_matriz3x3_identidade, Teste)
{
	double identidade[3][3] = {
		{ 1.0, 0.0, 0.0 },
		{ 0.0, 1.0, 0.0 },
		{ 0.0, 0.0, 1.0 }
	};
	double A[3][3];

	matriz3x3_identidade(A);

	MATRIX_3X3_DOUBLES_EQUAL(identidade, A, 1e-6);
}
