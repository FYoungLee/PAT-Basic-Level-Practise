/*
本题要求读入N名学生的成绩，将获得某一给定分数的学生人数输出。

输入格式：

输入在第1行给出不超过105的正整数N，即学生总人数。随后1行给出N名学生的百分制整数成绩，中间以空格分隔。最后1行给出要查询的分数个数K（不超过N的正整数），随后是K个分数，中间以空格分隔。

输出格式：

在一行中按查询顺序给出得分等于指定分数的学生人数，中间以空格分隔，但行末不得有多余空格。

输入样例：
10
60 75 90 55 75 99 82 90 75 50
3 75 90 88
输出样例：
3 2 0
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;
int compare(const vector<int>& vi, const int& x) {
    int cnt = 0;
    for (size_t i = 0; i < vi.size(); ++i)
        if (x == vi[i])
            ++cnt;
    return cnt;
}
int main() {
    int N, score;
    map<int, int> mi;
    vector<int> vf, rst;
    cin >> N;
    while (N--) {
        cin >> score;
        ++mi[score];
    }
    cin >> N;
    while (N--) {
        cin >> score;
        vf.push_back(score);
    }

    for (size_t i = 0; i < vf.size(); ++i) {
        cout << mi[vf[i]];
        if (i == vf.size() - 1) cout << '\n';
        else cout << ' ';
    }

    return 0;
}
