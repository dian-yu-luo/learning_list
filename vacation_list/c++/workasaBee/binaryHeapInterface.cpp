//
// Created by dianyuluo on 2021/3/31.
//
#include "iostream"
#include "vector"

class UnderflowException {
};


using namespace std;

template<typename Comparable>
class BinaryHeap {
public:
    explicit BinaryHeap(int capacity = 100);

    explicit BinaryHeap(const vector<Comparable> &item);

    bool isEmpty() const;

    const Comparable &finMin() const;

    void insert(const Comparable &x) {

        if (currentSize == array.size() - 1) {
            array.resize(array.size() * 2);
        }
//        因为0位置没有值的存在，如果继续填充将会爆栈，resize将数组的空间扩大一倍
        int hole = ++currentSize;
//        先自增在赋值，++currentsize表示推到空洞的位置

        Comparable copy = x;
//        新建copy，为了之后的移动构造
        array[0] = move(copy);
//        这个时候就用到了copy的问题，因为x还在之后的判断使用不能直接被释放
        for (; x < array[hole / 2]; hole /= 2) {
            array[hole] = move(array[hole / 2]);
        }
        array[hole] = std::move(array[0]);
//        最后将代码0的空间使用掉
    };

    void insert(Comparable &&x);

    void deleteMin() {
        if (isEmpty()) {
            throw UnderflowException{};
        }
        array[1] = move(array[currentSize--]);
        precolateDown(1);
    };

    void deleteMin(Comparable &minItem) {

    }

    void makeEmpty();

private:
    int currentSize;
    vector<Comparable> array;

    void buildHeap();

    void precolateDown(int hole);

};

int main() {
    cout << "zhn" << endl;
}
