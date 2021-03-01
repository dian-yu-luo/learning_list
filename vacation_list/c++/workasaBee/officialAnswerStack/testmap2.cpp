#include"iostream"
#include "list"

using namespace std;

int main() {
    cout << "liang" << endl;
    list<char> lic(5);
    cout << lic.size();
    lic.pop_back();
    cout << endl << lic.size() << endl;
    cout << lic.empty();
}