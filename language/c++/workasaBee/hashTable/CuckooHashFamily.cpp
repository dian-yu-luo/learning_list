//
// Created by dianyuluo on 2021/2/16.
//

#include"iostream"
#include "vector"
#include "random"

using namespace std;

template<typename AnyType>
class CuckooHashFamily {
public:
    size_t hash(const AnyType &x, int which) const;

    int getNumberOfFunctions();

    void generateNewFunction();
};

template<int count>
class STRingHashFamily {
private:
    vector<int> MULTIPLIERS;
    uniform_int_distribution<int> r;
public:
    STRingHashFamily() : MULTIPLIERS(count) {

    };

    int getNumberofFunctions() const {
        return count;
    }

    void generateNewFunctions() {
        for (auto &mult:MULTIPLIERS) {
            mult = r.b();
        }
    }

    size_t hash(const string &x, int which) const {
        const int multiplier = MULTIPLIERS[which];
        size_t hashVal = 0;
        for(auto ch :x)
        hashVal =multiplier*hashVal+ch;
        return hashVal;
    }
};

template<typename AnyType, typename HashFamily>
class CuckooHashTable {
public:
    explicit CuckooHashTable(int size = 101) : array() {
//        numHashFunctions = hashFunctions.hash();
        rehashes = 0;
        makeEmpty();
    }

    bool contains(const AnyType &x) const {
        return findPos(x) != -1;
    }

    void makeEmpty() {
        currentSize = 0;
        for (auto &entry:array) {
            entry.isActive = false;
        }
    };

    bool constains(const AnyType &x) const {
        return findPos(x) != -1;
    };

    bool remove(const AnyType &x) {
        int currentPos = findPos(x);
        if (!isActive(currentPos)) {
            return false;
        }
        array[currentPos].isActive = false;
        --currentSize;
        return true;
    };

    bool insert(const AnyType &x) {
        if (constains(x)) {
            return false;
        }
        if (currentSize >= array.size() * MAX_LOAD) {
            expend();
        }
        return insertHelperl(x);
    };


    bool insert(AnyType &&x);

private:
    struct HashEntry {
        AnyType element;
        bool isActive;

//        HashEntry(const AnyType &e = AnyType(), bool a = false) :
//                element(e), isActive(a) {};

        HashEntry(AnyType &&e, bool a = false) :
                element(std::move(e)), isActive(a) {};
    };

    bool insertHelperl(const AnyType &xx) {
        const int COUNT_LIMIT = 100;
        AnyType x = xx;
        while (true) {
            int lastPos = -1;
            int pos;
            for (int count = 0; count < COUNT_LIMIT; ++count) {
                for (int i = 0; i < numHashFunctions; ++i) {
                    pos = myhash(x, i);
                    if (isActive(pos)) {
                        array[pos] = move(HashEntry{move(x), true});
                        ++currentSize;
                        return true;

                    }
                }
                int i = 0;
                do {
                    pos = myhash(x, r.nextInt(numHashFunctions));
                } while (pos == lastPos && i++ < 5);
                lastPos = pos;
                swap(x, array[pos].element);
            }
            if (++rehashes > ALLOWED_REHASHES) {
                expend();
                rehashes = 0;
            } else { rehash(); }
        }
    };
//
//    bool insertHelperl(AnyType &&xx);

    bool isActive(int currentPos) const;

    size_t myhash(const AnyType &x, int which) const {
        return hashFunctions.hash(x, which) % array.size();
    };

    int findPos(const AnyType &x) const {
        for (int i = 0; i < numHashFunctions; ++i) {
            int pos = myhash(x, i);
            if (isActive(pos) && array[pos].element == x) {
                return pos;
            }
        }
        return -1;
    };

    void expend() {
        rehash(static_cast<int>(array.size() / MAX_LOAD));
    };

    void rehash() {
        hashFunctions.generateNewFunction();
        rehash(array.size());
    };

    void rehash(int newSize) {
        vector<HashEntry> oldArray = array;
        array.resize(nextPrime(newSize));
        for (auto &entry:array) {
            entry.isActive = false;
        }
        currentSize = 0;
        for (auto &entry:oldArray) {
            if (entry.isActive) {
                insert(move(entry.element));
            }
        }
    };

    static constexpr double MAX_LOAD = 0.4;
    static const int ALLOWED_REHASHES = 5;
    vector<HashEntry> array;
    int currentSize;
    int numHashFunctions;
    int rehashes;
    uniform_int_distribution<int> r;
    CuckooHashFamily<int> hashFunctions;
};

int main() {
    cout << "lzhongguoiang" << endl;
}


















