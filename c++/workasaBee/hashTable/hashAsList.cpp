//
// Created by dianyuluo on 2021/2/3.
//

#include "vector"
#include "iostream"
#include "list"

using namespace std;

template<typename HashObj>
class HashTable {
public:
    explicit HashTable(int size = 10);

    bool contains(const HashObj &x) const{
        auto &whichList=theList[myhash(x)];
        return find(begin(whichList),end(whichList),x)!=end(whichList);

    }

    void makeEmpty(){
        for(auto &thislist:theList){
            thislist.clear();
        }
    }

    bool insert(const HashObj &x){

    }

    bool insert(HashTable &&x);

    bool remove(const HashObj &x){
        auto &whichList=theList[myhash(x)];
        auto itr =find(begin(whichList),end(whichList),x);
        if (itr==end(whichList)){
            return false;
        }
        whichList.erase(itr);
        --currentSize;
        return true;
    }

private:
    vector<list<HashObj>> theList;
    int currentSize;

    void rehash();

    size_t myhash(const HashObj &x) const;
};

class Emplyee {
public:
    const string &getName() const;

    bool operator==(const Emplyee &rhs) const;

    bool operator!=(const Emplyee &ths) const;

private:
    string name;
    double salary;
    int seniority;

};

template<>
class hash<Emplyee>
{
public:
    size_t operator()(const Emplyee &item){
        static hash<string>hf;
        return hf(item.getName());
    }
};
int main() {
    vector<int> a;
    cout << "liang" << endl;
}