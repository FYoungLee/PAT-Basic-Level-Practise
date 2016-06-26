/*

#include<iostream>
#include<string>
using namespace std;

int main() {
    string vendor, buyer;
    size_t no = 0;
    cin >> vendor >> buyer;
    for (size_t i = 0; i < buyer.size();) {
        size_t p = vendor.find(buyer[i]);
        if (p != string::npos) {
            buyer.erase(buyer.begin() + i);
            vendor.erase(vendor.begin() + p);
        } else
            ++no, ++i;
    }
    if (no)
        cout << "No " << no << endl;
    else
        cout << "Yes " << vendor.size() << endl;
    return 0;
}

*/

#include<iostream>
#include<string>
using namespace std;

int main() {
    string vendor, buyer;
    size_t no = 0;
    cin >> vendor >> buyer;
    for (size_t i = 0; i < buyer.size();) {
        size_t p = vendor.find(buyer[i]);
        if (p != string::npos) {
            buyer.erase(buyer.begin() + i);
            vendor.erase(vendor.begin() + p);
        } else
            ++no, ++i;
    }
    if (no)
        cout << "No " << no << endl;
    else
        cout << "Yes " << vendor.size() << endl;
    return 0;
}
