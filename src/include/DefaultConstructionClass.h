using namespace std;

class Dog
{
public:
    Dog();
};

class Animal
{
private:
    string name;
    Dog dog;

public:
    Animal();
    Animal(const string &name) : name(name) {
        cout << "Custom animal construction" << endl;
    }
};
