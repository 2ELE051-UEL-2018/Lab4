#include "gtest/gtest.h"

void VECTOR_DOUBLES_EQUAL(double expected[], double actual[], double tolerance, int numElementos)
{
	int i;

	for (i = 0; i < numElementos; i++)
		ASSERT_NEAR(expected[i], actual[i], tolerance);
}

void MATRIX_3X3_DOUBLES_EQUAL(double expected[][3], double actual[][3], double tolerance)
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			ASSERT_NEAR(expected[i][j], actual[i][j], tolerance);
}

void COLUMN_VECTOR_DOUBLES_EQUAL(double expected[][1], double actual[][1], double tolerance, int numElementos)
{
	int i;

	for (i = 0; i < numElementos; i++)
		ASSERT_NEAR(expected[i][0], actual[i][0], tolerance);
}