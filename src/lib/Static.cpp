#include <iostream>
#include "../include/Static.h"

int StaticNamespace::Person::age = 18;

void StaticNamespace::Person::printAge()
{
    cout << "person age = " << StaticNamespace::Person::age << endl;
}