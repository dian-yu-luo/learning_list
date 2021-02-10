//
// Created by dianyuluo on 2021/2/5.
//

#include"iostream"
#include "vector"
#include "math.h"
#include "list"

using namespace std;

template<typename HashedObj>
class HashTable {
public:
    explicit HashTable(int size = 101) : array(nextPrime(size)) {
        makeEmpty();
    };

    bool contains(const HashedObj &x) const {
        return isActive(findPos(x));
    }

    void makeEmpty() {
        currentSize = 0;
        for (auto &entry:array) {
            entry.info = EMPTY;
        }
    };

    bool insert(const HashedObj &x) {
        int currentPos = findPos(x);
        if (isActive(currentPos)) {
            return false;
        }
        array[currentPos].element = x;
        array[currentPos].info = ACTIVE;
        if (++currentPos > array.size()) {
            reHash();
        }
        return true;


    };

    bool insert(HashedObj &&x);

    bool remove(const HashedObj &x) {
        int currentPos = findPos(x);
        if (!isActive(currentPos)) {
            return false;
        }
        array[currentPos].info = DELETED;
        return true;
    };

    enum EntryType {
        ACTIVE, EMPTY, DELETED
    };
private:
    struct HashEntry {
        HashedObj element;
        EntryType info;

        HashEntry(const HashedObj &e = HashedObj{}, EntryType i = EMPTY) :
                element(e), info(i) {}

        HashEntry(HashedObj &&e, EntryType i = EMPTY) : element(std::move(e)), info(i) {

        }
    };

    vector<HashEntry> array;
    int currentSize;

    bool isActive(int currentPos) const {
        return array[currentPos].info == ACTIVE;
    };

    int findPos(const HashedObj &x) const {
        int offset = 1;
        int currentPos = myhash(x);
        while (array[currentPos].info != EMPTY &&
               array[currentPos].element != x) {
            currentPos += offset;
            offset += 2;
            if (currentPos >= array.size()) {
                currentPos -= array.size();
            }
        }
        return currentPos;
    };

    void reHash() {
        vector<HashEntry> oleArray = array;
        array.resize(nextPrime(2 * oleArray.size()));
        for (auto &entry:array) {
            entry.info = EMPTY;

        }
        currentSize = 0;
        for (auto &entry:oleArray) {
            if (entry.info == ACTIVE) {
                insert(std::move(entry.element));
            }
        }
    };

    void reehash() {
        vector<list<HashedObj>> oldLists=theLists;


    }

    size_t myhash(const HashedObj &x) const;

};

int main() {
    cout << "qq" << endl;
}