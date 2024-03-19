#include <iostream>
#include <vector>
#include <list>
#include <thread>
#include <mutex>

using namespace std;

namespace Cpp11Space
{
    void initVar()
    {
        int x1 = {1};
        int array1[]{1, 2, 3};
        int array2[5]{0}; // 以0初始化数组长度为5的数组
        int *p1 = new int[3]{1, 2, 3};
        int *p2 = new int[5]{0};
        // STL容器支持列表初始化是因为C++11新增了initializer_list容器
        vector<int> vec1 = {1, 2, 3};
        list<int> list1 = {1, 2, 3};
    }

    void autoTest()
    {
        // auto 修饰指针时， 加不加*效果一样
        // auto修饰变量必须初始化，因为要进行类型推导
        auto p1 = new int[3]{1, 2, 3};
        auto *p2 = new int(4);
        cout << "p1[1] = " << *(p1 + 1) << ", p2 = " << *p2 << endl;

        // auto修饰引用必须加&，否则会被当做普通变量
        auto &r1 = *p1;
        cout << "r1 = " << r1 << endl;

        // auto不能作为函数参数，不能直接用来声明数组
        // auto badArryay[]{1,2,3}; // 'auto' type cannot appear in top-level array typeC/C++(1589)
    }

    void nullptrTest()
    {
        cout << "sizeof(nullptr) = " << sizeof(nullptr) << ", sizeof((void *)0)=" << sizeof((void *)0) << endl;
    }

    class ExplicitTest
    {
    private:
        int a;

    public:
        explicit ExplicitTest(int a) : a(a) {}
    };

    void STLTest()
    {
        string s("1");
        int i1 = std::stoi(s);
        long l1 = std::stol(s);
        unsigned long ul1 = std::stoul(s);
        long long ll1 = std::stoll(s);
        float f1 = std::stof(s);
        double d1 = std::stod("1.2");
        cout << i1 << ", " << l1 << ", " << ul1 << ", " << ll1 << ", " << f1 << ", " << d1 << endl;
    }

    void threadTest()
    {
        // 默认无参的构造函数，啥也不做
        // thread t1;

        // thread t2([]
        //           { cout << "Hello thread 2" << endl; });
        // t1.join();
        // t2.join();

        // thread t3([](unsigned int threadId, int num)
        //           {
        //     for(int i=0; i<num; i++)
        //     {
        //         cout<<"thread "<<threadId<<": "<<i<<endl;
        //         // sleep(1);
        //     } },
        //           3, 10000);
        // thread t4([](unsigned int threadId, int num)
        //           {
        //     for(int i=0; i<num; i++)
        //     {
        //         cout<<"thread "<<threadId<<": "<<i<<endl;
        //         // sleep(1);
        //     } },
        //           4, 10000);

        // t3.join();
        // t4.join();

        int acc = {0};
        int cnt = 10000000;
        thread t5([&acc, cnt]
                  {
                      for (int i = 0; i < cnt; i++)
                      {
                          acc++;
                      } });
        thread t6([&acc, cnt]
                  {
                      for (int i = 0; i < cnt; i++)
                      {
                          acc++;
                      } });
        t5.join();
        t6.join();

        cout << "acc = " << acc << endl;

        // test thread joinable
        thread t7([]
                  {
                    cout << "thread 7" << endl;
                    this_thread::sleep_for(chrono::seconds(1)); });
        cout << "t7.joinable = " << t7.joinable() << endl;
        t7.join();
        cout << "t7.joinable = " << t7.joinable() << endl;
        cout << "-------------------------------------" << endl;

        // test thread detach
        thread t8([]
                  {
                    cout<<"t8 start"<<endl;
                    thread t81([]
                                {
                    cout<<"thread 81 started"<<endl;
                    this_thread::sleep_for(chrono::seconds(4));
                    cout<<"thread 81 end"<<endl; });

                    t81.detach(); 
                    // t81.join();
                    
                    this_thread::sleep_for(chrono::seconds(2));
                    cout<<"t8 end"<<endl; });

        t8.join();

        // get thread id
        thread t9([]{
            cout<<"thread 9 id = "<<this_thread::get_id()<<endl;
        });
        cout<<"thread 9 id = "<<t9.get_id()<<endl;
        t9.join();
    }

    void mutexTest()
    {
        cout << "start mutex test-------------------------------------" << endl;
        int acc = {0};
        int cnt = 10000000;

        mutex mtx;
        thread t1([&acc, cnt, &mtx]{
            for(int i = 0; i < cnt; i++)
            {
                mtx.lock();
                acc++;
                mtx.unlock();
            }
        });
        thread t2([&acc, cnt, &mtx]{
            for(int i = 0; i < cnt; i++)
            {
                mtx.lock();
                acc++;
                mtx.unlock();
            }
        });

        t1.join();
        t2.join();

        cout << "acc = " << acc << endl;
        cout << "end mutex test-------------------------------------" << endl;
    }

    std::mutex mtx;
    void uniqueLockTest()
    {
        cout << "start unique_lock test-------------------------------------" << endl;

        int acc = {0};
        int cnt = {10000000};
        
        thread t1([&acc, cnt, mtx]{
            for(int i=0; i<cnt; i++)
            {
                unique_lock<mutex> uLock(mtx);
                acc++;
            }
        });

        thread t2([&acc, cnt, mtx]{
            for(int i=0; i<cnt; i++)
            {
                unique_lock<mutex> uLock(mtx);
                acc++;
            }
        });

        t1.join();
        t2.join();

        cout << "acc = " << acc << endl;
        cout << "end unique_lock test-------------------------------------" << endl;
    }
}