#include "iostream"
#include "vector"

using namespace std;

class UnderflowException {
};

template<typename Comparable>
class BinaryHeap {
public:
    explicit BinaryHeap(int capacity = 100);

    explicit BinaryHeap(const vector<Comparable> &items) : array(items.size() + 10), currentSize(items.size()) {
        for (int i = 0; i < items.size(); ++i) {
            array[i+1]=items[i];
        }buildHeap();
    };

    bool isEmpty() const;

    const Comparable &findMin() const;

    void insert(const Comparable &x) {
        if (currentSize == array.size() - 1) {
            array.resize(array.size() * 2);
        }
        int hole = ++currentSize;
        Comparable copy = x;
        //为了不去直接操作x
        array[0] = move(copy);
        for (; x < array[hole / 2]; hole /= 2) {
            array[hole] = move(array[hole / 2]);
        }
        array[hole] = move(array[0]);
        //array[0]的值没有被重复置零，但是被改变下一次被调用是被改变归一

    };

    void insert(Comparable &&x);

    void deleteMin() {
        if (isEmpty())
            throw UnderflowException{};
        array[1] = move(array[currentSize--]);
        percolateDown(1);
    };

    void deleteMin(Comparable &minItem) {
        if (isEmpty())
            throw UnderflowException{};
        minItem = move(array[1]);
        array[1] = move(array[currentSize--]);
        percolateDown(1);
    };

    void makeEmpty();

private:
    int currentSize;

    vector<Comparable> array;
//    表示把所有的元素存在一个实例中

    void buildHeap() {
        for(int i=currentSize/2;i>0;--i){
            percolateDown(i);
        }
    };

    void percolateDown(int hole) {
        int child;
        Comparable tmp = move(array[hole]);
        for (; hole * 2 <= currentSize; hole = child) {
            child = hole * 2;
            if (child != currentSize && array[child + 1] < array[child]) {
                ++child;
            }
            if (array[child] < tmp) {
                array[hole] = move(array[child]);
            } else
                break;
        }
    };

};

int main() {

    cout << "liangzho拉水电费看 ";
}