#include "gtest/gtest.h"

extern "C"
{
	int matriz3x3_iguais(double A[][3], double B[][3]);
}

TEST(tests_matriz3x3_iguais, TesteIdentidadeIdentidade)
{
	double identidade[3][3] = {
		{ 1.0, 0.0, 0.0 },
		{ 0.0, 1.0, 0.0 },
		{ 0.0, 0.0, 1.0 }
	};

	double identidade2[3][3] = {
		{ 1.0, 0.0, 0.0 },
		{ 0.0, 1.0, 0.0 },
		{ 0.0, 0.0, 1.0 }
	};

	ASSERT_EQ(1, matriz3x3_iguais(identidade, identidade2));
}

TEST(tests_matriz3x3_iguais, TesteIdentidadeNula)
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

	ASSERT_EQ(0, matriz3x3_iguais(identidade, nula));
}

TEST(tests_matriz3x3_iguais, TesteTotalmenteDiferente)
{
	double A[3][3] = {
		{  1.0,  2.0,  3.0 },
		{  4.0,  5.0,  6.0 },
		{  7.0,  8.0,  9.0 }
	};

	double B[3][3] = {
		{ 10.0, 11.0, 12.0 },
		{ 13.0, 14.0, 15.0 },
		{ 16.0, 17.0, 18.0 }
	};

	ASSERT_EQ(0, matriz3x3_iguais(A, B));
}

TEST(tests_matriz3x3_iguais, TesteIgualDepoisUmElementoDiferente)
{
	double A[3][3] = {
		{ 1.0,  2.0,  3.0 },
		{ 4.0,  5.0,  6.0 },
		{ 7.0,  8.0,  9.0 }
	};

	double B[3][3];

	int i, j, k, l;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 3; k++)
				for (l = 0; l < 3; l++)
				{
					B[k][l] = A[k][l];
				}

			ASSERT_EQ(1, matriz3x3_iguais(A, B));

			B[i][j] = 0.0;

			ASSERT_EQ(0, matriz3x3_iguais(A, B));
		}
}