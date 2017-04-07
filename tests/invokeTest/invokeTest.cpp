/*
 * https://github.com/google/googletest/blob/master/googlemock/docs/CookBook.md#delegating-calls-to-a-fake
*/

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "invoke.hpp"

using ::testing::_;
using ::testing::Invoke;

class MockFoo : public Foo {
public:
    // Normal mock method definitions using Google Mock
    MOCK_METHOD1(DoThis, char(int n));
    MOCK_METHOD2(DoThat, void(const char* s, int* p));

    // Delegates the default actions of the methods to a FakeFoo object.
    // This must be called *before* the custom ON_CALL() statements.

    void DelegateToFake() {
        ON_CALL(*this, DoThis(_))
            .WillByDefault(Invoke(&fake_, &FakeFoo::DoThis));
        ON_CALL(*this, DoThat(_, _))
            .WillByDefault(Invoke(&fake_, &FakeFoo::DoThat));
    }

private:
    FakeFoo fake_; // Keeps an instance of the fake in the mock.
};

TEST(AbcTest, Xyz) {
    MockFoo foo;
    foo.DelegateToFake(); // Enables the fake for delegation

    // No action specified, meaning to use the dafault action.
    EXPECT_CALL(foo, DoThis(5));
    EXPECT_CALL(foo, DoThat(_, _));

    int n = 0;
    EXPECT_EQ('+', foo.DoThis(5)); // FakeFoo::DoThis() is invoked.
    foo.DoThat("Hi", &n);            // FakeFoo::DoThat() is invoked.
    EXPECT_EQ(2, n);
}
