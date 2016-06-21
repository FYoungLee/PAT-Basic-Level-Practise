/*
美国总统奥巴马不仅呼吁所有人都学习编程，甚至以身作则编写代码，成为美国历史上首位编写计算机代码的总统。
2014年底，为庆祝“计算机科学教育周”正式启动，奥巴马编写了很简单的计算机代码：在屏幕上画一个正方形。现在你也跟他一起画吧！

输入格式：

输入在一行中给出正方形边长N（3<=N<=20）和组成正方形边的某种字符C，间隔一个空格。

输出格式：

输出由给定字符C画出的正方形。但是注意到行间距比列间距大，所以为了让结果看上去更像正方形，我们输出的行数实际上是列数的50%（四舍五入取整）。

输入样例：
10 a
输出样例：
aaaaaaaaaa
a        a
a        a
a        a
aaaaaaaaaa
*/


#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
int main() {
    size_t n;
    char ch;
    cin >> n >> ch;
    if (n < 3 || n > 20) return -1;
    size_t m;
    if (n % 2 == 0)
        m = n / 2;
    else
        m = n / 2 + 1;
    vector<string> vsq;
    string otherline(n, ' ');
    otherline[0] = ch;
    otherline[otherline.size() - 1] = ch;
    bool first(true);
    while (m--) {
        if (first) {
            vsq.push_back(string(n, ch));
            first = false;
        } else if (m != 0) {
            vsq.push_back(otherline);
        } else
            vsq.push_back(string(n, ch));
    }

    for (auto & it : vsq)
        cout << it << endl;
    return 0;
}

