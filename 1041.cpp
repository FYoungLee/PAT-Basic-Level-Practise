/*
每个PAT考生在参加考试时都会被分配两个座位号，一个是试机座位，一个是考试座位。正常情况下，考生在入场时先得到试机座位号码，
入座进入试机状态后，系统会显示该考生的考试座位号码，考试时考生需要换到考试座位就座。但有些考生迟到了，试机已经结束，
他们只能拿着领到的试机座位号码求助于你，从后台查出他们的考试座位号码。

输入格式：

输入第一行给出一个正整数N（<=1000），随后N行，每行给出一个考生的信息：“准考证号 试机座位号 考试座位号”。
其中准考证号由14位数字组成，座位从1到N编号。输入保证每个人的准考证号都不同，并且任何时候都不会把两个人分配到同一个座位上。

考生信息之后，给出一个正整数M（<=N），随后一行中给出M个待查询的试机座位号码，以空格分隔。

输出格式：

对应每个需要查询的试机座位号码，在一行中输出对应考生的准考证号和考试座位号码，中间用1个空格分隔。

输入样例：
4
10120150912233 2 4
10120150912119 4 1
10120150912126 1 3
10120150912002 3 2
2
3 4
输出样例：
10120150912002 2
10120150912119 1
*/

#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
struct stu_data {
    string id;
    size_t try_num;
    size_t exam_num;
};
const stu_data& get_info(const vector<stu_data>& d, size_t n) {
    for (size_t sz = 0; sz != d.size(); ++sz)
        if (n == d[sz].try_num)
            return d[sz];
}

int main() {
    size_t N;
    cin >> N;
    if (N > 1000) return -1;

    string id;
    size_t tr_n, ex_n;
    vector<stu_data> e_data;
    while (N--) {
        cin >> id >> tr_n >> ex_n;
        e_data.push_back(stu_data{id, tr_n, ex_n});
    }

    size_t n;
    cin >> n;
    if (n > N) return -1;

    vector<size_t> vipt;
    while (n--) {
        cin >> tr_n; vipt.push_back(tr_n);
    }

    for (auto p = vipt.cbegin(); p != vipt.cend(); ++p) {
        stu_data sdt = get_info(e_data, *p);
        cout << sdt.id << ' ' << sdt.exam_num << endl;
    }

    return 0;
}
