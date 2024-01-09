#include <iostream>
#include <fstream>

using namespace std;

namespace IOSpace
{
    void ofstreamTest()
    {
        ofstream ofs("../data/input.txt");
        if (ofs.is_open())
        {
            ofs << "Hello, cpp\n";
            ofs << "Hello world\n";
            ofs.close();
            clog << "Write ok!" << endl;
        }
        else
        {
            cerr << "File open failed" << endl;
        }
    }

    void ifstreamTest()
    {
        ifstream ifs("../data/input.txt");
        char buffer[1024];
        if (ifs.is_open())
        {
            while (!ifs.eof())
            {
                /* 第二个参数为最大读取长度 */
                ifs.getline(buffer, 100);
                cout << buffer << endl;
            }
        }
        else
        {
            cerr << "File open failed" << endl;
        }
    }

    void fstreamTest()
    {
        fstream ifs("../data/input.txt", ios::in | ios::binary);
        fstream ofs("../data/input.txt", ios::out | ios::binary);
        char buffer[1024];
        if (ifs.is_open() && ofs.is_open())
        {
            while (!ifs.eof())
            {
                ifs.getline(buffer, 100);
                cout << buffer << endl;
            }
            ifs.close();

            ofs << "Hello, fstream\n";
            ofs.sync(); // 同步缓存
            ofs.close();
        }
        else
        {
            cerr << "File open failed" << endl;
        }
    }

    long getBinarySize()
    {
        fstream ifs("../data/input.txt", ios::in | ios::binary);

        // 获取起始位置
        long start = ifs.tellg();
        // 将游标滑倒文件末尾位置
        ifs.seekg(0, ios::end);
        // 获取文件末尾位置
        long end = ifs.tellg();
        ifs.close();

        long size = end - start;
        cout << "File size is " << size << " bytes" << endl;
        return size;
    }

    void stringstreamTest()
    {
        int val = 10086;
        string str;

        // 将int转为string
        stringstream ss;
        ss << val;
        ss >> str;
        cout << str << endl;

        // 拼接字符串
        ss.clear(); // 不会清空流中内容，只是重置了流的状态标志
        ss.str(""); // 清除流中内容
        ss << "Hello"
           << ", "
           << "cpp" << endl;
        cout << ss.str();
    }
}