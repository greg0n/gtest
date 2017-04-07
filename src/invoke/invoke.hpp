#include <iostream>
#include <cstring>

class Foo {
public:
    virtual ~Foo() {}
    virtual char DoThis(int n) = 0;
    virtual void DoThat(const char* s, int* p) = 0;
};

class FakeFoo : public Foo {
public:
    virtual char DoThis(int n) override {
        return (n > 0) ? '+' :
            (n < 0) ? '-' : '0';
    }

    virtual void DoThat(const char* s, int* p) {
        *p = std::strlen(s);
    }
};
