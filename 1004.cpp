/*
读入n名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。

输入格式：每个测试输入包含1个测试用例，格式为

  第1行：正整数n
  第2行：第1个学生的姓名 学号 成绩
  第3行：第2个学生的姓名 学号 成绩
  ... ... ...
  第n+1行：第n个学生的姓名 学号 成绩
其中姓名和学号均为不超过10个字符的字符串，成绩为0到100之间的一个整数，这里保证在一组测试用例中没有两个学生的成绩是相同的。
输出格式：对每个测试用例输出2行，第1行是成绩最高学生的姓名和学号，第2行是成绩最低学生的姓名和学号，字符串间有1空格。

输入样例：
3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
输出样例：
Mike CS991301
Joe Math990112
*/


#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct stu_score {
    string nm;
    string id;
    unsigned score;
    stu_score(string n = "null", string i = "null", unsigned s = 0): nm(n), id(i), score(s) {}
    stu_score(const stu_score& ss): nm(ss.nm), id(ss.id), score(ss.score) {}
    friend bool operator<(const stu_score& ls, const stu_score& rs) { return ls.score < rs.score; }
    friend bool operator>(const stu_score& ls, const stu_score& rs) { return ls.score > rs.score; }
};

class stu_data {
    vector<stu_score>* all_stu;
public:
    stu_data(): all_stu(new vector<stu_score>) {}
    ~stu_data() { delete all_stu; }
    void push_back(const stu_score& s) { all_stu->push_back(s); }
    stu_score get_best() {
        stu_score best;
        for (auto p = all_stu->begin(); p != all_stu->end(); ++p)
            if (best < *p) best = *p;
        return best;
    }
    stu_score get_worst() {
        stu_score worst((*all_stu)[0]);
        for (auto p = all_stu->begin(); p != all_stu->end(); ++p)
            if (worst > *p) worst = *p;
        return worst;
    }
};

int main() {
    size_t n;
    cin >> n;
    stu_data sdd;
    while (n--) {
        string nm, id;
        unsigned score;
        cin >> nm >> id >> score;
        sdd.push_back(stu_score(nm, id, score));
    }
    stu_score bestone(sdd.get_best());
    stu_score worstone(sdd.get_worst());
    cout << bestone.nm << ' ' << bestone.id << endl;
    cout << worstone.nm << ' ' << worstone.id << endl;
    return 0;
}

