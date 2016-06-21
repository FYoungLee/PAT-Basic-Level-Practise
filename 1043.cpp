/*
给定一个长度不超过10000的、仅由英文字母构成的字符串。请将字符重新调整顺序，按“PATestPATest....”这样的顺序输出，并忽略其它字符。当然，六种字符的个数不一定是一样多的，若某种字符已经输出完，则余下的字符仍按PATest的顺序打印，直到所有字符都被输出。
输入格式：
输入在一行中给出一个长度不超过10000的、仅由英文字母构成的非空字符串。
输出格式：
在一行中按题目要求输出排序后的字符串。题目保证输出非空。
输入样例：
redlesPayBestPATTopTeePHPereatitAPPT
输出样例：
PATestPATestPTetPTePePee
*/

#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
int main() {
    string sample("PATest");
    string ipt;
    cin >> ipt;
    if (ipt.size() > 10000) return -1;
    string res;
    for (auto p = ipt.begin(); p != ipt.end(); ++p)
        if (sample.find(*p) != string::npos)
            res += std::move(*p);
    size_t index(0);
    while (res.size()) {
        size_t n = res.find(sample[index]);
        if (n != string::npos) {
            cout << sample[index];
            res.erase(res.begin() + n);
        }
        ++index;
        if (index > sample.size() - 1)
            index = 0;
    }
    cout << endl;
    return 0;
}

