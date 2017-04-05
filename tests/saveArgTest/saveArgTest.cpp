#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "saveArg.hpp"

class SomeMock : public ISomeClass
{
public:
    MOCK_METHOD1(foo, void(SomeData*));
};

// SaveArgPointee(pointer) Save the value pointed to by the N-th (0-based) argument to *pointer.
TEST(TestSomeFoo, shallPassOne)
{
    SomeData actualData{}; //zapisujemy wartosc
    SomeMock aMock;
    EXPECT_CALL(aMock, foo(::testing::_)).WillOnce(::testing::SaveArgPointee<0>(&actualData));
    someFunction(aMock);
    ASSERT_EQ(1, actualData.a_);
}


// SaveArg(pointer) Save the N-th (0-based) argument to *pointer.
TEST(TestSomeFoo, shallPassOne_DanglingPointer)
{
    SomeData* actualData; //zapisujemy adres, wiec musi byc pointer
    SomeMock aMock;
    EXPECT_CALL(aMock, foo(::testing::_)).WillOnce(::testing::SaveArg<0>(&actualData));
    someFunction(aMock);
    ASSERT_EQ(1, actualData->a_);
}
