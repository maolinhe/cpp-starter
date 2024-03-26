#include <iostream>
#include <vector>
#include <list>
#include <thread>
#include <mutex>
#include <atomic>
#include <memory>

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
        thread t9([]
                  { cout << "thread 9 id = " << this_thread::get_id() << endl; });
        cout << "thread 9 id = " << t9.get_id() << endl;
        t9.join();
    }

    void mutexTest()
    {
        cout << "start mutex test-------------------------------------" << endl;
        int acc = {0};
        int cnt = 10000000;

        mutex mtx;
        thread t1([&acc, cnt, &mtx]
                  {
            for(int i = 0; i < cnt; i++)
            {
                mtx.lock();
                acc++;
                mtx.unlock();
            } });
        thread t2([&acc, cnt, &mtx]
                  {
            for(int i = 0; i < cnt; i++)
            {
                mtx.lock();
                acc++;
                mtx.unlock();
            } });

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

        thread t1([&acc, cnt, mtx]
                  {
            for(int i=0; i<cnt; i++)
            {
                unique_lock<mutex> uLock(mtx);
                acc++;
            } });

        thread t2([&acc, cnt, mtx]
                  {
            for(int i=0; i<cnt; i++)
            {
                unique_lock<mutex> uLock(mtx);
                acc++;
            } });

        t1.join();
        t2.join();

        cout << "acc = " << acc << endl;
        cout << "end unique_lock test-------------------------------------" << endl;
    }

    void atomicTest()
    {
        cout << "start atomic test-------------------------------------" << endl;
        atomic_int v1 = {0};
        atomic<int> v2 = {0};

        thread t1([&v1, &v2]
                  {
                      for (int i = 0; i < 1000000; i++)
                      {
                          v1++;
                          // featch_add 只有int才有
                          v2.fetch_add(1);
                      } });
        thread t2([&v1, &v2]
                  {
                      for (int i = 0; i < 1000000; i++)
                      {
                          v1 += 1;
                          v2.fetch_add(1);
                      } });

        t1.join();
        t2.join();

        cout << "v1 = " << v1 << endl;
        cout << "v2 = " << v2 << endl;
        cout << "end atomic test-------------------------------------" << endl;
    }

    void smartPointerTest()
    {
        cout << "Start to test smart pointer----------------------------" << endl;
        // auto_ptr(deprecated)
        int *v1 = new int(10);
        auto_ptr<int> ap1(v1);
        (*ap1)++;
        cout << "*ap1 = " << *ap1 << endl;
        auto_ptr<int> ap2(ap1); // ap1 will be released
        (*ap2)++;
        cout << "*ap2 = " << *ap2 << "; ap1 is nullptr?: " << (ap1.get()) << endl;

        auto_ptr<int> ap3 = ap2; // ap2 will be released
        (*ap3)++;
        cout << "*ap3 = " << *ap3 << "; ap2 is nullptr?: " << (ap2.get()) << endl;

        // unique_ptr
        int *v2 = new int(20);
        unique_ptr<int> up1(v2);
        (*up1)++;
        cout << "*up1 = " << *up1 << endl;
        // unique_ptr<int> up2(up1); //error: use of deleted function ‘std::unique_ptr
        // unique_ptr<int> up3 = up1; //error: use of deleted function ‘std::unique_ptr

        // shared_ptr
        int *v3 = new int(30);
        shared_ptr<int> sp1(v3);
        (*sp1)++;
        cout << "*sp1 = " << *sp1 << endl;
        shared_ptr<int> sp2(sp1);
        (*sp2)++;
        cout << "*sp2 = " << *sp2 << "; sp1 is nullptr?: " << (sp1.get()) << endl;
        shared_ptr<int> sp3(sp2);
        (*sp3)++;
        cout << "*sp3 = " << *sp3 << "; sp2 is nullptr?: " << (sp2.get()) << endl;
        cout << "shared pointer of *v3 usage count = " << sp3.use_count() << endl;

        //weak_ptr
        int *v4 = new int(40);
        shared_ptr<int> tmp_sp(v4);
        cout << "shared pointer of *v4 usage count = " << tmp_sp.use_count() << endl;
        weak_ptr<int> wp1(tmp_sp);
        (*wp1.lock())++;
        cout << "*wp1 = " << *wp1.lock() << endl;
        cout << "weak pointer of *v4 usage count = " << wp1.lock().use_count() << endl;

        cout << "End to test smart pointer----------------------------" << endl;
    }
}