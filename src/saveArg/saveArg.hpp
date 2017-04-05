struct SomeData {
    int a_;
};

class ISomeClass {
public:
    virtual ~ISomeClass() = default;
    virtual void foo(SomeData*) = 0;
};

void someFunction(ISomeClass& a) {
    SomeData b{1};
    a.foo(&b);
}
