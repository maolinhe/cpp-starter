class Reference
{
private:
    /* data */
public:
    Reference(/* args */);
    ~Reference();

    void basicRef();
    void constRef();
    void paramRef(int &val);
    int &returnRef(int val);
    void testParamAndReturnRef();
    void referenceAndPointer();
};
