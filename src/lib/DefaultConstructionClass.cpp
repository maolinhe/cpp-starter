#include <iostream>
#include "../include/DefaultConstructionClass.h"

using namespace std;

Dog::Dog()
{
    cout << "Dog construction" << endl;
}

Animal::Animal()
{
    cout << "Default animal construction" << endl;
}