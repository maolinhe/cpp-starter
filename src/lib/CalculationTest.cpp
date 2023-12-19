#include <vector>
#include <iostream>
#include "gtest/gtest.h"
#include "../include/Calculation.h"

using std::cout;
using std::endl;
using std::make_unique;
using std::unique_ptr;

TEST(addDouble, TestAdd)
{
    Calculation obj;
    EXPECT_EQ(5.5, obj.add(2.3, 3.2));
}

TEST(addInt, TestAdd)
{
    Calculation obj;
    EXPECT_EQ(5, obj.add(2, 3));
}

class CalculationTest : public ::testing::TestWithParam<int>
{
protected:
    CalculationTest()
    {
        cout << "CalculationTest constructed" << endl;
    }

    virtual ~CalculationTest()
    {
        cout << "CalculationTest destructed" << endl;
    }

    static void SetUpTestCase()
    {
        cout << "SetUpTestCase" << endl;
    }

    virtual void SetUp()
    {
        cout << "SetUp" << endl;
    }

    static void TearDownTestCase()
    {
        cout << "TearDownTestCase" << endl;
    }

    virtual void TearDown()
    {
        cout << "TearDown" << endl;
    }

    unique_ptr<Calculation> calculation = make_unique<Calculation>();
    Calculation c;
};

TEST_F(CalculationTest, TestDotSelf1)
{
    calculation.get()->baseNum = 2;
    c.baseNum = 2;
    EXPECT_EQ(4, calculation.get()->dotSelf(2));
}

TEST_F(CalculationTest, TestDotSelf2)
{
    // EXPECT_EQ(6, calculation.get()->dotSelf(3)); // expect 6 but actual 0
    EXPECT_EQ(6, c.dotSelf(3));
}

TEST_F(CalculationTest, TestIsEven1)
{
    EXPECT_EQ(true, c.isEven(2));
    EXPECT_EQ(false, c.isEven(3));
    EXPECT_EQ(true, c.isEven(4));
    EXPECT_EQ(false, c.isEven(5));
}

TEST_P(CalculationTest, TestIsEven2)
{
    int v = GetParam();
    EXPECT_TRUE(c.isEven(v));
}
INSTANTIATE_TEST_SUITE_P(EvenDatas, CalculationTest, testing::Values(2, 4, 6, 8));