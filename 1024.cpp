/*
科学计数法是科学家用来表示很大或很小的数字的一种方便的方法，其满足正则表达式[+-][1-9]"."[0-9]+E[+-][0-9]+，即数字的整数部分只有1位，小数部分至少有1位，该数字及其指数部分的正负号即使对正数也必定明确给出。

现以科学计数法的格式给出实数A，请编写程序按普通数字表示法输出A，并保证所有有效位都被保留。

输入格式：

每个输入包含1个测试用例，即一个以科学计数法表示的实数A。该数字的存储长度不超过9999字节，且其指数的绝对值不超过9999。

输出格式：

对每个测试用例，在一行中按普通数字表示法输出A，并保证所有有效位都被保留，包括末尾的0。

输入样例1：
+1.23400E-03
输出样例1：
0.00123400
输入样例2：
-1.2E+10
输出样例2：
-12000000000
*/


#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

string trans_n(const char& f_sign, const string& f_num, const char& s_sign, const string& s_num) {
    string ret_val;
    int exp_cnt = atoi(s_num.c_str());
    if (exp_cnt == 0) return f_num;

    if (s_sign == '-') {
        for (size_t sz = 0; sz < f_num.size(); ++sz)
            if (f_num[sz] != '.')
                ret_val += f_num[sz];
        ret_val = string("0.") + string(exp_cnt - 1, '0') + ret_val;
    } else if (s_sign == '+'){
        int n = f_num.find('.'), m = exp_cnt;
        m -= f_num.size() - n - 1;
        for (size_t sz = 0; sz < f_num.size(); ++sz)
            if (f_num[sz] != '.')
                ret_val += f_num[sz];
        if (m >= 0)                 // this condition is very important to avoid error. if the input is like +1.234E+02
            ret_val = ret_val + string(m, '0');
        else
            ret_val.insert(ret_val.begin() + exp_cnt + 1, '.');
    }
    if (f_sign == '-')
        return ret_val = string("-") + ret_val;
    else return ret_val;
}

int main() {
    char f_sign, s_sign;
    string f_Num, s_Num;
    cin >> f_sign;
    for (char tchar; cin >> tchar && tchar != 'E';)
        f_Num += tchar;
    cin >> s_sign >> s_Num;
    cout << trans_n(f_sign, f_Num, s_sign, s_Num) << endl;

    return 0;
}
