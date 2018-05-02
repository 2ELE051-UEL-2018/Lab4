#include "gtest/gtest.h"

extern "C"
{
	double vetor_produtoEscalar(double a[], double b[], int numElementos);
}

TEST(tests_vetor_produtoEscalar, Teste0)
{
	double a[] = { 0.0 };
	double b[] = { 0.0 };

	ASSERT_NEAR(0.0, vetor_produtoEscalar(a, b, 1), 1e-6);
}

TEST(tests_vetor_produtoEscalar, Teste11)
{
	double a[] = { 1.0 };
	double b[] = { 1.0 };

	ASSERT_NEAR(1.0, vetor_produtoEscalar(a, b, 1), 1e-6);
}

TEST(tests_vetor_produtoEscalar, Teste12)
{
	double a[] = { 1.0 };
	double b[] = { 2.0 };

	ASSERT_NEAR(2.0, vetor_produtoEscalar(a, b, 1), 1e-6);
}

TEST(tests_vetor_produtoEscalar, Teste1234)
{
	double a[] = { 1.0, 2.0 };
	double b[] = { 3.0, 4.0 };

	ASSERT_NEAR(11.0, vetor_produtoEscalar(a, b, 2), 1e-6);
}

TEST(tests_vetor_produtoEscalar, Teste1m234056078)
{
	double a[] = { 1.0, -2.0, 0.0, 6.0, 7.0 };
	double b[] = { 3.0,  4.0, 5.0, 0.0, 8.0 };

	ASSERT_NEAR(51.0, vetor_produtoEscalar(a, b, 5), 1e-6);
}