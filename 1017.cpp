/*
本题要求计算A/B，其中A是不超过1000位的正整数，B是1位正整数。你需要输出商数Q和余数R，使得A = B * Q + R成立。

输入格式：

输入在1行中依次给出A和B，中间以1空格分隔。

输出格式：

在1行中依次输出Q和R，中间以1空格分隔。

输入样例：
123456789050987654321 7
输出样例：
17636684150141093474 3
*/

#include<vector>
#include<iostream>
using namespace std;
int main() {
    vector<int> vA, result;
    int B, Q = 0, t;
    for (char ch; (ch = getchar()) != ' ';)
        vA.push_back(ch - '0');
    cin >> B;

    for (size_t n = 0; n != vA.size(); ++n) {
        if (Q) t = (vA[n] + Q * 10) / B;
        else t = vA[n] / B;
        Q = (vA[n] + Q * 10) % B;
        if (result.size() == 0 && t == 0)
            continue;
        result.push_back(t);
    }
    if (result.size() == 0)
        cout << '0';
    else
        for (auto& itr : result)
            cout << itr;
    cout << ' ' << Q << '\n';
    return 0;
}
