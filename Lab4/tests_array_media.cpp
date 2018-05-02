#include "gtest/gtest.h"

extern "C"
{
	double array_media(double v[], int numElementos);
}

TEST(tests_array_media, Teste0)
{
	double v[] = { 0.0 };

	ASSERT_NEAR(0.0, array_media(v, 1), 1e-6);
}

TEST(tests_array_media, Teste1)
{
	double v[] = { 1.0 };

	ASSERT_NEAR(1.0, array_media(v, 1), 1e-6);
}

TEST(tests_array_media, Teste13)
{
	double v[] = { 1.0, 3.0 };

	ASSERT_NEAR(2.0, array_media(v, 2), 1e-6);
}

TEST(tests_array_media, Teste1m22m1)
{
	double v[] = { 1.0, -2.0, 2.0, -1.0 };

	ASSERT_NEAR(0.0, array_media(v, 4), 1e-6);
}

TEST(tests_array_media, Teste1234567)
{
	double v[] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0 };

	ASSERT_NEAR(4.0, array_media(v, 7), 1e-6);
}