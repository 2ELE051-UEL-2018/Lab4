#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
	void matriz3x3_produto(double C[][3], double A[][3], double B[][3]);
}

TEST(tests_matriz3x3_produto, TesteIdentidadeIdentidade)
{
	double identidade[3][3] = {
		{ 1.0, 0.0, 0.0 },
		{ 0.0, 1.0, 0.0 },
		{ 0.0, 0.0, 1.0 }
	};

	double C[3][3];

	matriz3x3_produto(C, identidade, identidade);

	MATRIX_3X3_DOUBLES_EQUAL(identidade, C, 1e-6);
}

TEST(tests_matriz3x3_produto, TesteNulaIdentidade)
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

	matriz3x3_produto(C, nula, identidade);

	MATRIX_3X3_DOUBLES_EQUAL(nula, C, 1e-6);
}

TEST(tests_matriz3x3_produto, TesteIdentidadeNula)
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

	matriz3x3_produto(C, identidade, nula);

	MATRIX_3X3_DOUBLES_EQUAL(nula, C, 1e-6);
}

TEST(tests_matriz3x3_produto, TesteMagic3Magic3)
{
	double A[3][3] = {
		{ 8.0, 1.0, 6.0 },
		{ 3.0, 5.0, 7.0 },
		{ 4.0, 9.0, 2.0 }
	};

	double esperado[3][3] = {
		{ 91.0, 67.0, 67.0 },
		{ 67.0, 91.0, 67.0 },
		{ 67.0, 67.0, 91.0 }
	};

	double C[3][3];

	matriz3x3_produto(C, A, A);

	MATRIX_3X3_DOUBLES_EQUAL(esperado, C, 1e-6);
}
