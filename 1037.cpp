/*
如果你是哈利·波特迷，你会知道魔法世界有它自己的货币系统 —— 就如海格告诉哈利的：“十七个银西可(Sickle)兑一个加隆(Galleon)，
二十九个纳特(Knut)兑一个西可，很容易。”现在，给定哈利应付的价钱P和他实付的钱A，你的任务是写一个程序来计算他应该被找的零钱。

输入格式：

输入在1行中分别给出P和A，格式为“Galleon.Sickle.Knut”，其间用1个空格分隔。这里Galleon是[0, 107]区间内的整数，
Sickle是[0, 17)区间内的整数，Knut是[0, 29)区间内的整数。

输出格式：

在一行中用与输入同样的格式输出哈利应该被找的零钱。如果他没带够钱，那么输出的应该是负数。

输入样例1：
10.16.27 14.1.28
输出样例1：
3.2.1
输入样例2：
14.1.28 10.16.27
输出样例2：
-3.2.1
*/


#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class h_money {
    int Gallen = 0, Sickle = 0, Knut = 0;
    int trans(string& s);
    void update();
public:
    h_money() = default;
    h_money(const h_money& hm) : Gallen(hm.Gallen), Sickle(hm.Sickle), Knut(hm.Knut) {}
    h_money(string s) {
        Gallen = trans(s);
        Sickle = trans(s);
        Knut = trans(s);
        update();
    }
    friend bool operator>(const h_money& lfs, const h_money& rhs);
    friend h_money operator-(const h_money& lfs, const h_money& rhs);
    void show() {
        cout << Gallen << "." << Sickle << "." << Knut << endl;
    }

};

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    h_money h1(str1);
    h_money h2(str2);
    h_money h3;
    if (h1 > h2){
        h3 = h1 - h2;
        cout << '-';
        h3.show();
    }
    else {
        h3 = h2 - h1;
        h3.show();
    }
    return 0;
}

int h_money::trans(string& s) {
    int n = s.find('.'), ret(0);
    string tp;
    if (n != string::npos) {
        tp = string(s.begin(), s.begin() + n);
        s.erase(0, n + 1);
    } else tp = s;
    n = 1;
    for (int i = tp.size() - 1; i >= 0; --i) {
        ret += (tp[i] - '0') * n; n *= 10;
    }
    return ret;
}

void h_money::update() {
    if (Knut >= 29) {
        ++Sickle;
        Knut -= 29;
    }
    if (Sickle >= 17) {
        ++Gallen;
        Sickle -= 17;
    }
    if (Knut < 0) {
        --Sickle;
        Knut += 29;
    }
    if (Sickle < 0) {
        --Gallen;
        Sickle += 17;
    }
}

bool operator>(const h_money& lfs, const h_money& rhs) {
    if (lfs.Gallen != rhs.Gallen) return lfs.Gallen > rhs.Gallen;
    else if (lfs.Sickle != rhs.Sickle) return lfs.Sickle > rhs.Sickle;
    else return lfs.Knut > lfs.Knut;
}

h_money operator-(const h_money& lfs, const h_money& rhs) {
    h_money ret(lfs);
    if (lfs.Knut < rhs.Knut) {
        --ret.Sickle;
        ret.Knut += 29;
    }
    ret.Knut = ret.Knut - rhs.Knut;
    if (ret.Sickle > rhs.Sickle) {
        --ret.Gallen;
        ret.Sickle += 17;
    }
    ret.Sickle = ret.Sickle - rhs.Sickle;
    ret.Gallen = ret.Gallen - rhs.Gallen;
    ret.update();
    return ret;
}

