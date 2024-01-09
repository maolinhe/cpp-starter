#include <vector>

class Calculation
{
public:
    Calculation() = default;
    ~Calculation() = default;

    template <typename T>
    T add(T v1, T v2)
    {
        return v1 + v2;
    }

    double dotSelf(double p);
    double baseNum;
    bool isEven(int v);
};