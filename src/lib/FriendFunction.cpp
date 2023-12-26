#include <iostream>
#include "../include/FriendFunction.h"

using namespace std;
namespace FriendSpace
{
    void Box::setWidth(int width)
    {
        this->width = width;
    }

    void Box::setHeight(int height)
    {
        this->height = height;
    }

    void printBox(Box &box)
    {
        cout << "Box width = " << box.width << ", height = " << box.height << endl;
    }
}
