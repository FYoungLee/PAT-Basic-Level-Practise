/*
给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：

A1 = 能被5整除的数字中所有偶数的和；
A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；
A3 = 被5除后余2的数字的个数；
A4 = 被5除后余3的数字的平均数，精确到小数点后1位；
A5 = 被5除后余4的数字中最大数字。
输入格式：

每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N，随后给出N个不超过1000的待分类的正整数。数字间以空格分隔。

输出格式：

对给定的N个正整数，按题目要求计算A1~A5并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。

若其中某一类数字不存在，则在相应位置输出“N”。

输入样例1：
13 1 2 3 4 5 6 7 8 9 10 20 16 18
输出样例1：
30 11 2 9.7 9
输入样例2：
8 1 2 4 5 6 7 9 16
输出样例2：
N 11 2 N 9
*/



#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int A1 = 0, a1n = 0, A2 = 0, a2n = 0, A3 = 0, A5 = 0, a2_ = 1, a4_ct = 0;
    double A4 = 0;
    int N;
    cin >> N;
    for (int n; N--;) {
        cin >> n;
        if (n % 5 == 0 && n % 2 == 0)
                A1 += n, ++a1n;
        else if (n % 5 == 1) {
            if (a2_) A2 += n, --a2_;
            else A2 -= n, ++a2_;
            ++a2n;
        }
        else if (n % 5 == 2)
            ++A3;
        else if (n % 5 == 3)
            A4 += n, ++a4_ct;
        else if (n % 5 == 4 && n > A5)
            A5 = n;
    }
    if (A4 != 0)
        A4 = A4 / (double)a4_ct;

    if (a1n)        cout << A1 << " ";
    else        cout << "N ";
    if (a2n)        cout << A2 << " ";
    else        cout << "N ";
    if (A3)        cout << A3 << " ";
    else        cout << "N ";
    if (A4 != 0)        cout << fixed << setprecision(1) << A4 << " ";
    else        cout << "N ";
    if (A5)        cout << A5 << "\n";
    else        cout << "N\n";
    return 0;
}
