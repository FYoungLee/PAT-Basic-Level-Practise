/*
大家应该都会玩“锤子剪刀布”的游戏：两人同时给出手势，胜负规则如图所示：


现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。

输入格式：

输入第1行给出正整数N（<=105），即双方交锋的次数。随后N行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。
C代表“锤子”、J代表“剪刀”、B代表“布”，第1个字母代表甲方，第2个代表乙方，中间有1个空格。

输出格式：

输出第1、2行分别给出甲、乙的胜、平、负次数，数字间以1个空格分隔。第3行给出两个字母，分别代表甲、乙获胜次数最多的手势，
中间有1个空格。如果解不唯一，则输出按字母序最小的解。

输入样例：
10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J
输出样例：
5 3 2
2 3 5
B B
*/

#include<iostream>
using namespace std;
class CJB {
    int C, J, B;
    int win, draw, lose;
public:
    CJB() { C = J = B = win = draw = lose = 0; }
    void Iwin(char ch) {
        ++win;
        switch (ch){
        case 'C': ++C; break;
        case 'J': ++J; break;
        case 'B': ++B; break;
        }
    }
    void Idraw() {
        ++draw;
    }
    void Ilose() {
        ++lose;
    }
    char best_one() {
        if (B >= C && B >= J)
            return 'B';
        else if (C >= J && C > B)
            return 'C';
        else if (J > C && J > B)
            return 'J';
    }
    friend ostream& operator<<(ostream& os, const CJB& cjb) {
        os << cjb.win << ' ' << cjb.draw << ' ' << cjb.lose;
        return os;
    }
};
int compare(const char& a, const char& b) {
    if (a == 'C') {
        if (b == 'C') return 0;
        if (b == 'J') return 1;
        if (b == 'B') return 2;
    }
    else if (a == 'J') {
        if (b == 'C') return 2;
        if (b == 'J') return 0;
        if (b == 'B') return 1;
    }
    else if (a == 'B') {
        if (b == 'C') return 1;
        if (b == 'J') return 2;
        if (b == 'B') return 0;
    }
    return -1;
}

int main() {
    CJB jia;
    CJB yi;
    int N, rt;
    cin >> N;
    for (char a, b; N--;) {
        cin >> a >> b;
        rt = compare(a, b);
        if (rt == 0) {
            jia.Idraw();
            yi.Idraw();
        }
        if (rt == 1) {
            jia.Iwin(a);
            yi.Ilose();
        }
        if (rt == 2) {
            jia.Ilose();
            yi.Iwin(b);
        }
    }
    cout << jia << endl;
    cout << yi << endl;
    cout << jia.best_one() << ' ' << yi.best_one() << endl;
    return 0;
}
