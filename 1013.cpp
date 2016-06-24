/*

1013. 数素数 (20)
时间限制
100 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
CHEN, Yue
令Pi表示第i个素数。现任给两个正整数M <= N <= 104，请输出PM到PN的所有素数。

输入格式：

输入在一行中给出M和N，其间以空格分隔。

输出格式：

输出从PM到PN的所有素数，每10个数字占1行，其间以空格分隔，但行末不得有多余空格。

输入样例：
5 27
输出样例：
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103

*/

#include<iostream>
using namespace std;
bool is_primer(size_t num)
{
    for (size_t i = 2; i * i <= num; ++i)
        if ( num % i == 0 ) return false;
    return true;
}
int main()
{
    size_t n, m;
    cin >> n >> m;
    for (size_t i = 2, cnt = 0, nextline = 0; cnt < m; ++i) {
        if (is_primer(i)) {
            ++cnt;
            if (cnt >= n) {
                cout << i;
                ++nextline;
                if (nextline != 10 && cnt < m)  cout << " ";
                else { cout << endl; nextline = 0;}
            }
        }
    }
    return 0;
}
