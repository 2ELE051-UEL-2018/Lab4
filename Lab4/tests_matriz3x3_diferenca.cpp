#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
	void matriz3x3_diferenca(double C[][3], double A[][3], double B[][3]);
}

TEST(tests_matriz3x3_diferenca, TesteIdentidadeNula)
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

	matriz3x3_diferenca(C, identidade, nula);

	MATRIX_3X3_DOUBLES_EQUAL(identidade, C, 1e-6);
}

TEST(tests_matriz3x3_diferenca, TesteNulaIdentidade)
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

	double negIdentidade[3][3] = {
		{ -1.0,  0.0,  0.0 },
		{  0.0, -1.0,  0.0 },
		{  0.0,  0.0, -1.0 }
	};

	double C[3][3];

	matriz3x3_diferenca(C, nula, identidade);

	MATRIX_3X3_DOUBLES_EQUAL(negIdentidade, C, 1e-6);
}

TEST(tests_matriz3x3_diferenca, TesteIdentidadeIdentidade)
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

	matriz3x3_diferenca(C, identidade, identidade);

	MATRIX_3X3_DOUBLES_EQUAL(nula, C, 1e-6);
}
