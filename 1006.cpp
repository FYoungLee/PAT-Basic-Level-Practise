/*
让我们用字母B来表示“百”、字母S表示“十”，用“12...n”来表示个位数字n（<10），换个格式来输出任一个不超过3位的正整数。
例如234应该被输出为BBSSS1234，因为它有2个“百”、3个“十”、以及个位的4。

输入格式：每个测试输入包含1个测试用例，给出正整数n（<1000）。

输出格式：每个测试用例的输出占一行，用规定的格式输出n。

输入样例1：
234
输出样例1：
BBSSS1234
输入样例2：
23
输出样例2：
SS123
*/

#include <iostream>
using namespace std;

int main() {
    int N, b = 0, s = 0, g = 0, t = 0;
    cin >> N;
    if (N > 999) return -1;
    g = N % 10;
    N /= 10;
    if (N) {
        s = N % 10;
        N /= 10;
        if (N) b = N % 10;
    }
    for (int n = 0; n < b; ++n)
        cout << 'B';
    for (int n = 0; n < s; ++n)
        cout << 'S';
    for (int n = 1; n <= g; ++n)
        cout << n;
    cout << endl;
}
