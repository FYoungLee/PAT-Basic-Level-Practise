/*
给定任一个各位数字不完全相同的4位正整数，如果我们先把4个数字按非递增排序，再按非递减排序，然后用第1个数字减第2个数字，将得到一个新的数字。一直重复这样做，我们很快会停在有“数字黑洞”之称的6174，这个神奇的数字也叫Kaprekar常数。

例如，我们从6767开始，将得到

7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
7641 - 1467 = 6174
... ...

现给定任意4位正整数，请编写程序演示到达黑洞的过程。

输入格式：

输入给出一个(0, 10000)区间内的正整数N。

输出格式：

如果N的4位数字全相等，则在一行内输出“N - N = 0000”；否则将计算的每一步在一行内输出，直到6174作为差出现，输出格式见样例。注意每个数字按4位数格式输出。

输入样例1：
6767
输出样例1：
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
输入样例2：
2222
输出样例2：
2222 - 2222 = 0000
*/


#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int vec_to_int(const vector<int>& vi) {
    int i = 0;
    for (int s = 0, t = 1000; s < vi.size(); ++s) {
        i += vi[s] * t;
        t /= 10;
    }
    return i;
}
vector<int> int_to_vec(int x) {
    vector<int> vi;
    for (int t = 1000, i = 4; i--;) {
        vi.push_back(x / t);
        x %= t;
        t /= 10;
    }
    return vi;
}

vector<int> get_max(int x) {
    vector<int> vi = int_to_vec(x);
    sort(vi.begin(), vi.end(), [](int a, int b) { return a > b; });
    return vi;
}
vector<int> get_min(int x) {
    vector<int> vi = int_to_vec(x);
    sort(vi.begin(), vi.end(), [](int a, int b) { return a < b; });
    return vi;
}

int main() {
    int num;
    cin >> num;
    vector<int> small, big, result;
    do {
        big = get_max(num);
        for (auto& i : big)
            cout << i;
        cout << " - ";
        small = get_min(num);
        for (auto& i : small)
            cout << i;
        cout << " = ";
        num = vec_to_int(big) - vec_to_int(small);
        result = int_to_vec(num);
        for (auto& i : result)
            cout << i;
        cout << endl;
        if (num == 0)
            break;
    } while (num != 6174);
    return 0;
}
