class Inline
{
private:
    int a;
    int b;

public:
    Inline(int a, int b) : a(a), b(b){};
    ~Inline();
    int max();
};
