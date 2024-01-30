#include <iostream>

using namespace std;

namespace PolymorphicSpace
{
    class Shape
    {
    protected:
        int width;
        int length;
        int radius;

    public:
        Shape(int width = 0, int length = 0, int radius = 0)
            : width(width), length(length), radius(radius) {}
        virtual void printArea() = 0;
    };

    class Rectangle : public Shape
    {
    public:
        Rectangle(int width, int length) : Shape(width, length, 0) {}

        void printArea() override
        {
            cout << "Rectangle area = " << width * length << endl;
        }
    };

    class Circle : public Shape
    {
    public:
        Circle(int radius) : Shape(0, 0, radius) {}

        void printArea() override
        {
            cout << "Circle area = " << 3.14 * radius * radius << endl;
        }
    };
}