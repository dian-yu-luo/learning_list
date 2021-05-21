//
// Created by dianyuluo on 2021/3/2.
//
#include "iostream"
#include "vector"
#include "random"
#include "chrono"
#include "string"
#include "math.h"

using namespace std;


int nextPrime(int n) {
//get next Prime after by this one
    return 0;
}

static int currentTimeSeconds() {
    auto now = chrono::high_resolution_clock::now().time_since_epoch();
    return chrono::duration_cast<chrono::seconds>(now).count();
}

class UniformRandom {
private:
    mt19937 generator;
public:
    UniformRandom(int seed = currentTimeSeconds()) : generator(seed) {};

    int nextInt() {
        static uniform_int_distribution<unsigned int> distribution;
        return distribution(generator);
    }

    int nextInt(int low, int high) {
        uniform_int_distribution<int> distribution(low, high);
        return distribution(generator);
    }

    int nextInt(int high) {
        return nextInt(0, high - 1);
    }

    double nextDouble() {
        static uniform_real_distribution<double> distribution(0, 1);
        return distribution(generator);
    }

};

template<typename AnyType>
class CuckoohashFamily {
public:
    size_t hash(const AnyType &x, int which) const;

    int getNumberOfFunctions();

    void genrateNewFunctions();

};

template<int count>
class StringHashFamily {
private:
    vector<int> MULTIPLIERS;
    UniformRandom r;

public:
    void genrateNewFunctions() {
        for (auto &mult:MULTIPLIERS)
            mult = r.nextInt();
    };

    StringHashFamily() : MULTIPLIERS(count) {
        genrateNewFunctions();
    }

    size_t hash(const string &x, int which) const {
        const int multiplier = MULTIPLIERS[which];
        size_t hashVal = 0;
        for (auto ch:x) {
            hashVal = multiplier * hashVal + ch;
        }
        return hashVal;
    };

    int getNumberOfFunctions() {
        return count;
    };
};

template<typename Anytype, typename Hashfamily>
class CuckooHashTable {
private:
    struct HashEntry {
    public:
        Anytype element;
        bool isActive;

        HashEntry(const Anytype &e = Anytype(), bool a = false) :
                element(e), isActive(a) {};

        HashEntry(Anytype &&e, bool a = false) :
                element(std::move(e)), isActive(a) {};
    };

    static constexpr double MAX_LOAD = 0.40;
    static const int ALLOWED_REHASHS = 5;


    vector<HashEntry> array;
    int currentSize;
    int numberHashFunctions;
    int rehashes;
    UniformRandom r;
    StringHashFamily<5> hashFunctions;

    bool insertHelperl(const Anytype &xx) {
        const int COUNT_LIMIT = 100;
        Anytype x = xx;
        while (true) {
            int lastPos = -1;
            int pos;
            for (int count = 0; count < COUNT_LIMIT; ++count) {
                for (int i = 0; i < numberHashFunctions; ++i) {
                    pos = myhash(x, i);
                    if (!isActive(pos)) {
                        array[pos] = std::move(HashEntry{move(x), true});
                        ++currentSize;
                        return true;
                    }
                }
                int i = 0;
                do {
                    pos = myhash(x, r.nextInt(numberHashFunctions));
                } while (pos == lastPos && i++ < 5);
                lastPos=pos;
                swap(x,array[pos].element);
            }
            if (++rehashes>ALLOWED_REHASHS){
                expand();
                rehashes=0;
            } else{
                rehashes;
            }
        }
    };

    bool insertHelperl(Anytype &&xx);

    bool isActive(int);

    size_t myhash(const Anytype &x, int which) const {
        return hashFunctions.hash(x, which) % array.size();
    };

    int findPos(const Anytype &x) const {
        for (int i = 0; i < numberHashFunctions; ++i) {
            int pos = myhash(x, i);
            if (isActive(pos) && array[pos].element == x) {
                return pos;
            }
        }
        return -1;
    };

    void expand(){
        rehash(static_cast<int>(array.size()/MAX_LOAD));
    };

    void rehash(){
        hashFunctions.genrateNewFunctions();
        rehash(array.size());
    };

    void rehash(int newSize){
        vector<HashEntry>oldArray=array;
        array.resize(nextPrime(newSize));
        for(auto &entry:array){
            if (entry.isActive){
                insert(move(entry.element));
            }
        }
    };


public:
    explicit CuckooHashTable(int size = 101) : array(nextPrime(size)) {
        numberHashFunctions = hashFunctions.getNumberOfFunctions();
        rehashes = 0;
        makeEmpty();
    };

    void makeEmpty() {
        currentSize = 0;
        for (auto &entry:array) {
            entry.isActive = false;
        }
    };

    bool contains(const Anytype &x) const {
        return findPos(x) != -1;
    };

    bool remove(const Anytype &x) {
        int currentPos = findPos(x);
        if (!isActive(currentPos)) {
            return false;
        }
        array[currentPos].isActive = false;
        --currentSize;
        return true;
    };

    bool insert(const Anytype &x) {
        if (contains(x)) {
            return false;
        }
        if (currentSize >= array.size() * MAX_LOAD) {
            expand();
        }
        return insertHelperl(x);
    };

    bool insert(Anytype &&x);
};

int main() {

}
