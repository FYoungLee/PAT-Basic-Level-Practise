/*
本题要求你写个程序把给定的符号打印成沙漏的形状。例如给定17个“*”，要求按下列格式打印

*****
 ***
  *
 ***
*****
所谓“沙漏形状”，是指每行输出奇数个符号；各行符号中心对齐；相邻两行符号数差2；符号数先从大到小顺序递减到1，再从小到大顺序递增；首尾符号数相等。

给定任意N个符号，不一定能正好组成一个沙漏。要求打印出的沙漏能用掉尽可能多的符号。

输入格式：

输入在一行给出1个正整数N（<=1000）和一个符号，中间以空格分隔。

输出格式：

首先打印出由给定符号组成的最大的沙漏形状，最后在一行中输出剩下没用掉的符号数。

输入样例：
19 *
输出样例：
*****
 ***
  *
 ***
*****
2
*/

#include <iostream>
#include <iomanip>
using namespace std;
void Print(int, char);
int main()
{
    int n;
    char c;
    while (cin >> n >> c)
        Print(n, c);
    return 0;
}
void Print(int n, char c)
{
    if (n > 1000) {
        cerr << "Exceed Limit\n";
        return;
    }
    int remain(n - 1);
    int t(3);
    int counter = 0;
    while ((remain - t * 2) >= 0) {
        remain -= t * 2;
        t += 2;
        ++counter;
    }
    t -= 2;
    if (counter) {
        int wid = 1, n = counter;
        for (; n > 0; --n) {
            int i = t;
            t -= 2;
            cout << setw(wid);
            for (; i > 0; --i)
                cout << c;
            cout << endl;
            ++wid;
        }
        cout << setw(wid) << c << endl;
        n = 0, t = 3;
        for (; n < counter; ++n) {
            --wid;
            cout << setw(wid);
            for (int i = 0; i < t; ++i)
                cout << c;
            cout << endl;
            t += 2;
        }
        cout << remain << endl;
    } else
        cout << c << endl << remain << endl;
}
