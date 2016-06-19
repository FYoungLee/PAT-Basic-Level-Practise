/*
“答案正确”是自动判题系统给出的最令人欢喜的回复。本题属于PAT的“答案正确”大派送 —— 只要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。

得到“答案正确”的条件是：

1. 字符串中必须仅有P, A, T这三种字符，不可以包含其它字符；
2. 任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
3. 如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a, b, c 均或者是空字符串，或者是仅由字母 A 组成的字符串。

现在就请你为PAT写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。
输入格式： 每个测试输入包含1个测试用例。第1行给出一个自然数n (<10)，是需要检测的字符串个数。接下来每个字符串占一行，字符串长度不超过100，且不包含空格。

输出格式：每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出YES，否则输出NO。

输入样例：
8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA
输出样例：
YES
YES
YES
YES
NO
NO
NO
NO
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;
bool is_contain(const string& s) {
    int idxT,idxP,len;
    len = s.size();
    idxP = s.find('P',0);
    idxT = s.find('T',0);
    if(idxP == string::npos || idxT == string::npos || (idxP >= idxT - 1))
        return false;
    else {
        string A(idxP, 'A');
        string SP(idxP, ' ');
        string a(s,0,idxP);
        string b(s,idxP+1,idxT-idxP-1);
        string c(s,idxT+1,len-idxT-1);
        string ans= a + b + c;
        if (s.find("PAT") && A == a && A == c)
            return true;
        else if (s.find("PAT") && SP == a  && SP == c)
            return true;
        else if (ans.find_first_not_of('A') != string::npos)
            return false;
        else if (idxP == 0 && len - idxT - 1 == 0)
            return true;
        else if (idxP * (idxT - idxP - 1) == len - idxT - 1)
            return true;
        else
            return false;
    }
}

int main() {
    size_t n;
    cin >> n;
    if (n >= 10) return -1;
    vector<string> vs;
    while (n--) {
        string s;
        cin >> s;
        vs.push_back(s);
    }
    for (size_t i = 0; i < vs.size(); ++i)
        cout << (is_contain(vs[i]) ? "YES\n" : "NO\n");

    return 0;
}

