/*
输入两个非负10进制整数A和B(<=230-1)，输出A+B的D (1 < D <= 10)进制数。

输入格式：

输入在一行中依次给出3个整数A、B和D。

输出格式：

输出A+B的D进制数。

输入样例：
123 456 8
输出样例：
1103
*/
#include <iostream>
#include <vector>
using namespace std;

int m_n(int, int);
int main() {
    int A, B, D;
    vector<int> result;
    cin >> A >> B >> D;
    if (D <= 0 && D > 10) return -1;

    int plus(A + B);
    if (!plus) result.push_back(0);
    while (plus) {
       result.push_back(plus % D);
       plus /= D;
    }
    for (int i = result.size() - 1; i >= 0; --i)
        cout << result[i];
    cout << endl;
    return 0;
}

