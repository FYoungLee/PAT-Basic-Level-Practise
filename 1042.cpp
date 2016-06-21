/*
请编写程序，找出一段给定文字中出现最频繁的那个英文字母。

输入格式：

输入在一行中给出一个长度不超过1000的字符串。字符串由ASCII码表中任意可见字符及空格组成，至少包含1个英文字母，
以回车结束（回车不算在内）。

输出格式：

在一行中输出出现频率最高的那个英文字母及其出现次数，其间以空格分隔。如果有并列，则输出按字母序最小的那个字母。
统计时不区分大小写，输出小写字母。

输入样例：
This is a simple TEST.  There ARE numbers and other symbols 1&2&3...........
输出样例：
e 7
*/

#include <iostream>
#include <string>
#include <map>
#include <set>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;
int main() {
    string sline;
    getline(cin, sline);
    if (sline.size() > 1000) return -1;

    map<char, size_t> mdata;

    for (size_t sz = 0; sz < sline.size(); ++sz) {
        if (isalpha(sline[sz]))
            ++mdata[tolower(sline[sz])];
    }
    
    size_t biggest(0);
    char rst;

    for (auto& it : mdata) {
        if (biggest < it.second) {
            biggest = it.second; rst = it.first;
        }
    }
    std::set<char> set_rst;
    set_rst.insert(rst);
    for (auto& it : mdata)
        if (it.second == biggest)
            set_rst.insert(it.first);

    cout << *set_rst.begin() << " " << biggest << endl;
    return 0;
}

