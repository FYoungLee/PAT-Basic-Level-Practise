/*
编程团体赛的规则为：每个参赛队由若干队员组成；所有队员独立比赛；参赛队的成绩为所有队员的成绩和；成绩最高的队获胜。

现给定所有队员的比赛成绩，请你编写程序找出冠军队。

输入格式：

输入第一行给出一个正整数N（<=10000），即所有参赛队员总数。随后N行，每行给出一位队员的成绩，格式为：“队伍编号-队员编号 成绩”，
其中“队伍编号”为1到1000的正整数，“队员编号”为1到10的正整数，“成绩”为0到100的整数。

输出格式：

在一行中输出冠军队的编号和总成绩，其间以一个空格分隔。注意：题目保证冠军队是唯一的。

输入样例：
6
3-10 99
11-5 87
102-1 0
102-3 100
11-9 89
3-2 61
输出样例：
11 176
*/


#include <iostream>
#include <string>
#include <map>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::map;
inline string get_grpN(const string& grp) {
    size_t n = grp.find("-");
    string grpN(grp, 0, n);
    return grpN;
}

int main() {
    size_t N;
    cin >> N;
    if (N > 10000) return -1;
    map<string, size_t> data;
    string grp;
    size_t score;
    while (N--) {
        cin >> grp >> score;
        data[get_grpN(grp)] += score;
    }
    score = 0;
    for (auto & i : data)
        if (i.second > score) {
            grp = i.first;
            score = i.second;
        }
    cout << grp << ' ' << score << endl;

    return 0;
}

