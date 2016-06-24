/*
输入格式：

输入第1行给出3个正整数，分别为：N（<=105），即考生总数；L（>=60），为录取最低分数线，
即德分和才分均不低于L的考生才有资格被考虑录取；H（<100），为优先录取线——德分和才分均不低于此线的被定义为“才德全尽”，
此类考生按德才总分从高到低排序；
才分不到但德分到线的一类考生属于“德胜才”，也按总分排序，但排在第一类考生之后；德才分均低于H，
但是德分不低于才分的考生属于“才德兼亡”但尚有“德胜才”者，按总分排序，但排在第二类考生之后；
其他达到最低线L的考生也按总分排序，但排在第三类考生之后。

随后N行，每行给出一位考生的信息，包括：准考证号、德分、才分，其中准考证号为8位整数，德才分为区间[0, 100]内的整数。
数字间以空格分隔。

输出格式：

输出第1行首先给出达到最低分数线的考生人数M，随后M行，每行按照输入格式输出一位考生的信息，考生按输入中说明的规则从高到低排序。当某类考生中有多人总分相同时，按其德分降序排列；若德分也并列，则按准考证号的升序输出。

输入样例：
14 60 80
10000001 64 90
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90
10000010 88 45
10000012 80 100
10000013 90 99
10000014 66 60
输出样例：
12
10000013 90 99
10000012 80 100
10000003 85 80
10000011 85 80
10000004 80 85
10000007 90 78
10000006 83 76
10000005 82 77
10000002 90 60
10000014 66 60
10000008 75 79
10000001 64 90
*/

#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;
struct Stu_d {
   int id;
   int d_score;
   int c_score;
   int all;
};
bool s_comp(const Stu_d& a, const Stu_d& b) {
    if(a.all > b.all)
        return true;
    else if(a.all == b.all) {
        if(a.d_score > b.d_score)
            return true;
        else if(a.d_score == b.d_score) {
            if(a.id < b.id)
                return true;
        }
    }
    return false;
}

int main() {
    vector<Stu_d> s1, s2, s3, s4;
    Stu_d t_data;
    int N, low, high;
    scanf("%d %d %d", &N, &low, &high);
    int n = 0;
    while (N--) {
        int id, d_sc, c_sc;
        scanf("%d %d %d", &id, &d_sc, &c_sc);
        t_data.id = id;
        t_data.d_score = d_sc;
        t_data.c_score = c_sc;
        t_data.all = d_sc + c_sc;
        if (d_sc >= low && c_sc >= low) {
            ++n;
            if (d_sc >= high && c_sc >= high)
                s1.push_back(t_data);
            else if (d_sc >= high && c_sc < high)
                s2.push_back(t_data);
            else if (d_sc < high && c_sc < high && d_sc >= c_sc)
                s3.push_back(t_data);
            else
                s4.push_back(t_data);
        }
    }
    sort(s1.begin(), s1.end(), s_comp);
    sort(s2.begin(), s2.end(), s_comp);
    sort(s3.begin(), s3.end(), s_comp);
    sort(s4.begin(), s4.end(), s_comp);
    printf("%d\n", n);
    for (auto p = s1.cbegin(); p != s1.cend(); ++p)
        printf("%d %d %d\n", p->id, p->d_score, p->c_score);
    for (auto p = s2.cbegin(); p != s2.cend(); ++p)
        printf("%d %d %d\n", p->id, p->d_score, p->c_score);
    for (auto p = s3.cbegin(); p != s3.cend(); ++p)
        printf("%d %d %d\n", p->id, p->d_score, p->c_score);
    for (auto p = s4.cbegin(); p != s4.cend(); ++p)
        printf("%d %d %d\n", p->id, p->d_score, p->c_score);
}
