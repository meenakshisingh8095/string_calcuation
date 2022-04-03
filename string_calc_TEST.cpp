#include <gtest/gtest.h>
#include "string_calc.hpp"

TEST(return_int, Summation_by_comma)
{
    ASSERT_EQ(3, string_add("1,2"));
}

TEST(return_int, Multiplesummation_by_comma)
{
    ASSERT_NE(1, string_add("1,2,3,5"));
}

TEST(return_int, Summation_by_newline)
{
    ASSERT_EQ(6, string_add("1\n2\n3"));
}

TEST(return_0, Summation_by_emptystring)
{
    ASSERT_EQ(0, string_add(""));
}

TEST(return_num, Return_number)
{
    ASSERT_EQ(1, string_add("1"));
}

TEST(exception_Message, return_exception_onNegativeNumbers)
{
    try
    {
        string_add("-1,3,5\n4");
        // fail("negatives not allowed");
    }
    catch (runtime_error &e)
    {
        SUCCEED();
        return;
    }
    catch (runtime_error &e)
    {
        FAIL() << "negatives not allowed";
    }
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    // string_add("1,3,4\n555");
}
