#ifndef AUX_TEST_FUNCTIONS_H
#define AUX_TEST_FUNCTIONS_H

void VECTOR_DOUBLES_EQUAL(double expected[], double actual[], double tolerance, int numElementos);
void MATRIX_3X3_DOUBLES_EQUAL(double expected[][3], double actual[][3], double tolerance);
void COLUMN_VECTOR_DOUBLES_EQUAL(double expected[][1], double actual[][1], double tolerance, int numElementos);

#endif // AUX_TEST_FUNCTIONS_H
