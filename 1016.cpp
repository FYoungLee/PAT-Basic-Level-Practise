/*
正整数A的“DA（为1位整数）部分”定义为由A中所有DA组成的新整数PA。例如：给定A = 3862767，DA = 6，则A的“6部分”PA是66，
因为A中有2个6。

现给定A、DA、B、DB，请编写程序计算PA + PB。

输入格式：

输入在一行中依次给出A、DA、B、DB，中间以空格分隔，其中0 < A, B < 1010。

输出格式：

在一行中输出PA + PB的值。

输入样例1：
3862767 6 13530293 3
输出样例1：
399
输入样例2：
3862767 1 13530293 8
输出样例2：
0
*/

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    string A, Da, B, Db;
    cin >> A >> Da >> B >> Db;
    string nDa;
    string nDb;
    size_t n = A.find(Da, 0);
    while (n != string::npos) {
        nDa += Da;
        n = A.find(Da, n + 1);
    }
    n = B.find(Db, 0);
    while (n != string::npos) {
        nDb += Db;
        n = B.find(Db, n + 1);
    }

    size_t cnt(0);
    n = 1;
    for (size_t i = 0; i < nDa.size(); ++i) {
        cnt += (nDa[i] - '0') * n;
        n *= 10;
    }
    n = 1;
    for (size_t i = 0; i < nDb.size(); ++i) {
        cnt += (nDb[i] - '0') * n;
        n *= 10;
    }
    cout << cnt << endl;

    return 0;
}

