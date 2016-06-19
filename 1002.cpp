//读入一个自然数n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

//输入格式：每个测试输入包含1个测试用例，即给出自然数n的值。这里保证n小于10100。

//输出格式：在一行内输出n的各位数字之和的每一位，拼音数字间有1 空格，但一行中最后一个拼音数字后没有空格。

//输入样例：
//1234567890987654321123456789
//输出样例：
//yi san wu

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string num;
    cin >> num;
    if (num.size() > 100) return -1;
    string numPY[] {
        "ling", "yi", "er", "san", "si",
        "wu", "liu", "qi", "ba", "jiu"
    };
    int result(0);
    for (size_t sz = 0; sz < num.size(); ++sz)
        result += num[sz] - '0';
    vector<int> vo;
    while (result > 0) {
        vo.push_back(result % 10);
        result /= 10;
    }
    for (size_t i = vo.size() - 1; i > 0; --i)
        cout << numPY[vo[i]] << ' ';
    cout << numPY[vo[0]] << endl;
    return 0;
}
