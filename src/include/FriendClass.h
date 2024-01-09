#include <iostream>

using namespace std;

namespace FriendSpace
{
    class MyClass;
    class FriendBox
    {
    private:
        int height;
        int width;

    public:
        FriendBox(int height, int width) : height(height), width(width) {}
        friend class MyClass;
    };

    class MyClass
    {
    public:
        void printBox(FriendBox &box)
        {
            cout << "Box width = " << box.width << ", height = " << box.height << endl;
        }
    };
}