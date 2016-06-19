/*
让我们定义 dn 为：dn = pn+1 - pn，其中 pi 是第i个素数。显然有 d1=1 且对于n>1有 dn 是偶数。
“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。

现给定任意正整数N (< 105)，请计算不超过N的满足猜想的素数对的个数。

输入格式：每个测试输入包含1个测试用例，给出正整数N。

输出格式：每个测试用例的输出占一行，不超过N的满足猜想的素数对的个数。

输入样例：
20
输出样例：
4

*/


#include <iostream>
#include <vector>

using namespace std;

bool is_primer(size_t num);
size_t get_primer(size_t num);

int main()
{
    size_t n;
    while (cin >> n)
        cout << get_primer(n) << endl;
    return 0;
}

bool is_primer(size_t num)
{
    for (size_t i = 2; i * i <= num; ++i)
        if ( num % i == 0 ) return false;
    return true;
}

size_t get_primer(size_t num)
{
    size_t ret(0);
    size_t last(0);
    for (size_t n = 2; n <= num; ++n) {
        if (is_primer(n)){
            if (last && (n == last + 2))
                ++ret;
            last = n;
        }
    }
    return ret;
}
