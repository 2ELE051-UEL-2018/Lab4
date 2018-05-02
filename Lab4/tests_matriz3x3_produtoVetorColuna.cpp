#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
	void matriz3x3_produtoVetorColuna(double C[][1], double A[][3], double B[][1]);
}

TEST(tests_matriz3x3_produtoVetorColuna, TesteIdentidade123)
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

	double C[3][1];

	matriz3x3_produtoVetorColuna(C, identidade, B);

	COLUMN_VECTOR_DOUBLES_EQUAL(B, C, 1e-6, 3);
}

TEST(tests_matriz3x3_produtoVetorColuna, TesteNula123)
{
	double identidade[3][3] = {
		{ 0.0, 0.0, 0.0 },
		{ 0.0, 0.0, 0.0 },
		{ 0.0, 0.0, 0.0 }
	};

	double B[3][1] = {
		{ 1.0 },
		{ 2.0 },
		{ 3.0 }
	};

	double esperado[3][1] = {
		{ 0.0 },
		{ 0.0 },
		{ 0.0 }
	};

	double C[3][1];

	matriz3x3_produtoVetorColuna(C, identidade, B);

	COLUMN_VECTOR_DOUBLES_EQUAL(esperado, C, 1e-6, 3);
}

TEST(tests_matriz3x3_produtoVetorColuna, TesteMagic3123)
{
	double A[3][3] = {
		{ 8.0, 1.0, 6.0 },
		{ 3.0, 5.0, 7.0 },
		{ 4.0, 9.0, 2.0 }
	};

	double B[3][1] = {
		{ 1.0 },
		{ 2.0 },
		{ 3.0 }
	};

	double esperado[3][1] = {
		{ 28.0 },
		{ 34.0 },
		{ 28.0 }
	};

	double C[3][1];

	matriz3x3_produtoVetorColuna(C, A, B);

	COLUMN_VECTOR_DOUBLES_EQUAL(esperado, C, 1e-6, 3);
}