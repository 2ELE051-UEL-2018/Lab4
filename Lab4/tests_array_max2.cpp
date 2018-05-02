#include "gtest/gtest.h"

extern "C"
{
	double array_max2(double v[], int numElementos);
}

TEST(tests_array_max2, Teste12)
{
	double v[] = { 1.0, 2.0 };

	ASSERT_NEAR(1.0, array_max2(v, 2), 1e-6);
}

TEST(tests_array_max2, Testem1m2)
{
	double v[] = { -1.0, -2.0 };

	ASSERT_NEAR(-2.0, array_max2(v, 2), 1e-6);
}

TEST(tests_array_max2, Teste123)
{
	double v[] = { 1.0, 2.0, 3.0 };

	ASSERT_NEAR(2.0, array_max2(v, 3), 1e-6);
}

TEST(tests_array_max2, Teste132)
{
	double v[] = { 1.0, 3.0, 2.0 };

	ASSERT_NEAR(2.0, array_max2(v, 3), 1e-6);
}

TEST(tests_array_max2, Teste321)
{
	double v[] = { 3.0, 2.0, 1.0 };

	ASSERT_NEAR(2.0, array_max2(v, 3), 1e-6);
}


TEST(tests_array_max2, Teste0000)
{
	double v[] = { 0.0, 0.0, 0.0, 0.0 };

	ASSERT_NEAR(0.0, array_max2(v, 4), 1e-6);
}
