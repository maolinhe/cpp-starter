using namespace std;

namespace SingletonSpace
{
    class HungrySingleton
    {
    private:
        HungrySingleton()
        {
            cout << "Hungry singleton constructed" << endl;
        }
        HungrySingleton(const HungrySingleton &singleton) = delete;
        HungrySingleton &operator=(const HungrySingleton &) = delete;

        static HungrySingleton *singleton;

    public:
        static HungrySingleton *getInstance()
        {
            return singleton;
        }
    };
    HungrySingleton *HungrySingleton::singleton = new HungrySingleton();

    class LazySingleton
    {
    public:
        static LazySingleton *getInstance()
        {
            if (singleton == nullptr)
            {
                singleton = new LazySingleton();
            }
            return singleton;
        }

    private:
        LazySingleton()
        {
            cout << "Lazy singleton constructed" << endl;
        }
        LazySingleton(const LazySingleton &singleton) = delete;
        LazySingleton &operator=(const LazySingleton &) = delete;

        static LazySingleton *singleton;
    };
    LazySingleton *LazySingleton::singleton = nullptr;

    class SafeLazySingleton
    {
    public:
        SafeLazySingleton(const SafeLazySingleton &singleton) = delete;
        SafeLazySingleton &operator=(const SafeLazySingleton &) = delete;

        static SafeLazySingleton *getInstance()
        {
            // 静态局部变量实现线程安全的懒汉模式
            // C++11中静态局部变量是线程安全的
            static SafeLazySingleton singleton;
            return &singleton;
        }

    private:
        SafeLazySingleton()
        {
            cout << "Safe lazy singleton constructed" << endl;
        }
    };
}