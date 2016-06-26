/*
字符串APPAPT中包含了两个单词“PAT”，其中第一个PAT是第2位(P),第4位(A),第6位(T)；第二个PAT是第3位(P),第4位(A),第6位(T)。

现给定字符串，问一共可以形成多少个PAT？

输入格式：

输入只有一行，包含一个字符串，长度不超过105，只包含P、A、T三种字母。

输出格式：

在一行中输出给定字符串中包含多少个PAT。由于结果可能比较大，只输出对1000000007取余数的结果。

输入样例：
APPAPT
输出样例：
2
*/
// 网上牛人的算法。
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string pat;
    cin >> pat;

    int numT = 0, numA = 0, num = 0;
    for (int i = pat.size(); istr--;)
    {
        if ('T' == pat[i])
            numT++;
        else if ('A' == pat[i])
            numA += numAT;
        else{
             num += numPAT;
             if (num>=1000000007) num %= 1000000007;
        }
    }

    cout << num << endl;
    return 0;
}

// 我的算法，没拿到全分，后3个测试点运算超时。
/********************************************
#include<iostream>
#include<string>

using namespace std;

int main() {
    string raw_line;
    size_t pos, a_pos = 0;
    int cnt = 0, p = 0, t = 0;
    cin >> raw_line;
    for (size_t i = 0; ;) {
        // get 'A's position first.
        pos = raw_line.find('A', i);
        if (pos != string::npos) {
            //count how many 'P' before that 'A'
            for (size_t n = a_pos; n < pos; ++n)
                if (raw_line[n] == 'P')
                    ++p;
            a_pos = pos + 1;
            //and how many 'T' after that 'A'
            for (size_t n = pos; n < raw_line.size(); ++n)
                if (raw_line[n] == 'T')
                    ++t;
            // multi both 'P's and 'T's, we will get pairs of "PAT".
            cnt += p * t;
            i = pos + 1;
            t = 0;
            // then repeat next 'A'.
        } else break;
    }
    if (cnt > 1000000007) cnt %= 1000000007;
    cout << cnt << endl;
    return 0;
}
********************************************/
