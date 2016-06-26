/*
旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出应该输入的一段文字、以及实际被输入的文字，请你列出肯定坏掉的那些键。

输入格式：

输入在2行中分别给出应该输入的文字、以及实际被输入的文字。每段文字是不超过80个字符的串，由字母A-Z（包括大、小写）、数字0-9、以及下划线“_”（代表空格）组成。题目保证2个字符串均非空。

输出格式：

按照发现顺序，在一行中输出坏掉的键。其中英文字母只输出大写，每个坏键只输出一次。题目保证至少有1个坏键。

输入样例：
7_This_is_a_test
_hs_s_a_es
输出样例：
7TI
*/

#include<iostream>
#include<algorithm>
#include<string>
#include<cctype>
using namespace std;
void make_upper(string& str) {
    for (auto p = str.begin(); p != str.end(); ++p)
        *p = toupper(*p);
}

int main() {
    string first_line, second_line, rst;
    getline(cin, first_line);
    getline(cin, second_line);
    make_upper(first_line);
    make_upper(second_line);

    for (auto p = first_line.begin(); p!= first_line.end(); ++p)
        if (second_line.find(*p) == string::npos && rst.find(*p) == string::npos)
            rst += *p;
    cout << rst << endl;
}
