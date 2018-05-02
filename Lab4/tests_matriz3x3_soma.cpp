#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
	void matriz3x3_soma(double C[][3], double A[][3], double B[][3]);
}

TEST(tests_matriz3x3_soma, TesteIdentidadeNula)
{
	double identidade[3][3] = {
		{ 1.0, 0.0, 0.0 },
		{ 0.0, 1.0, 0.0 },
		{ 0.0, 0.0, 1.0 }
	};

	double nula[3][3] = {
		{ 0.0, 0.0, 0.0 },
		{ 0.0, 0.0, 0.0 },
		{ 0.0, 0.0, 0.0 }
	};

	double C[3][3];

	matriz3x3_soma(C, identidade, nula);

	MATRIX_3X3_DOUBLES_EQUAL(identidade, C, 1e-6);
}

TEST(tests_matriz3x3_soma, TesteNulaIdentidade)
{
	double identidade[3][3] = {
		{ 1.0, 0.0, 0.0 },
		{ 0.0, 1.0, 0.0 },
		{ 0.0, 0.0, 1.0 }
	};

	double nula[3][3] = {
		{ 0.0, 0.0, 0.0 },
		{ 0.0, 0.0, 0.0 },
		{ 0.0, 0.0, 0.0 }
	};

	double C[3][3];

	matriz3x3_soma(C, nula, identidade);

	MATRIX_3X3_DOUBLES_EQUAL(identidade, C, 1e-6);
}

TEST(tests_matriz3x3_soma, TesteIdentidadeIdentidade)
{
	double identidade[3][3] = {
		{ 1.0, 0.0, 0.0 },
		{ 0.0, 1.0, 0.0 },
		{ 0.0, 0.0, 1.0 }
	};

	double identidadeMaisIdentidade[3][3] = {
		{ 2.0, 0.0, 0.0 },
		{ 0.0, 2.0, 0.0 },
		{ 0.0, 0.0, 2.0 }
	};

	double C[3][3];

	matriz3x3_soma(C, identidade, identidade);

	MATRIX_3X3_DOUBLES_EQUAL(identidadeMaisIdentidade, C, 1e-6);
}

TEST(tests_matriz3x3_soma, TesteAMaisMenosA)
{
	double A[3][3] = {
		{ 1.0, 2.0, 3.0 },
		{ 4.0, 5.0, 6.0 },
		{ 7.0, 8.0, 9.0 }
	};

	double B[3][3] = {
		{ -1.0, -2.0, -3.0 },
		{ -4.0, -5.0, -6.0 },
		{ -7.0, -8.0, -9.0 }
	};

	double nula[3][3] = {
		{ 0.0, 0.0, 0.0 },
		{ 0.0, 0.0, 0.0 },
		{ 0.0, 0.0, 0.0 }
	};

	double C[3][3];

	matriz3x3_soma(C, A, B);

	MATRIX_3X3_DOUBLES_EQUAL(nula, C, 1e-6);
}