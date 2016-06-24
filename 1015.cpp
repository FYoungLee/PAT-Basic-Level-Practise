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
