#include <iostream>

using namespace std;

namespace TemplateSpace
{
    template <typename T>
    class TemplateClass
    {
    private:
        T val;

    public:
        TemplateClass(T val) : val(val) {}
        T &getVal()
        {
            return this->val;
        }
        void setVal(T val)
        {
            this->val = val;
        }
    };

    class Father
    {
    private:
        int fVal;

    public:
        Father(int fVal) : fVal(fVal) {}
        int &getFVal()
        {
            return this->fVal;
        }
    };

    template <typename T>
    class TemplateFather
    {
    private:
        T fVal;

    public:
        TemplateFather(T fVal) : fVal(fVal) {}
        T &getFVal()
        {
            return this->fVal;
        }
    };

    // 父类不是模板类，子类是模板类
    template <typename T>
    class TemplateSon1 : public Father
    {
    private:
        T sVal;

    public:
        TemplateSon1(T sVal) : sVal(sVal), Father(100) {}
        T &getSVal()
        {
            return this->sVal;
        }
    };

    // 父类是模板类，子类不是模板类, 需指定父类模板类型
    class Son : public TemplateFather<double>
    {
    private:
        int sVal;

    public:
        Son(int sVal) : sVal(sVal), TemplateFather<double>(100) {}
        int &getSVal()
        {
            return this->sVal;
        }
    };

    //父类是模板类，子类是模板类 子类虚类型可以传递到父类中
    template <typename T>
    class TemplateSon2 : public TemplateFather<T>
    {
    private:
        T sVal;

    public:
        TemplateSon2(T sVal) : sVal(sVal) {}
        T &getSVal()
        {
            return this->sVal;
        }
    };
}