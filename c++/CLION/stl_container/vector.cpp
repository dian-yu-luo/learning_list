#include <iostream>
#include <algorithm>
using namespace std;

template<typename Object>
class Vector{
public:
    explicit Vector(int initSize =0) : theSize(initSize),
    theCapatity(initSize+SPARE_CAPACITY){
        objects = new Object[theCapatity];
    }

    Vector(const Vector& rhs):theSize{rhs.theSize},
    theCapatity{rhs.theCapatity},objects{nullptr}{
        objects = new Object[theCapatity ];
        for (int i = 0; i < theSize; ++i) {
            objects[i]=rhs.objects[i];
        }
    }

    Vector & operator =(const Vector & rhs){
        Vector copy = rhs;
        swap(*this ,copy);
        return *this;
    }

    ~Vector(){

        delete[]objects;

    }

    Vector(Vector &&rhs):theSize(rhs.theSize),theCapatity(rhs.theCapatity),objects{rhs.objects}{
        rhs.objects = nullptr;
        rhs.theSize = 0;
        rhs.theCapatity = 0;
    }

    Vector & operator =(Vector && rhs){
        swap(theSize,rhs.theSize);
        swap(theCapatity,rhs.theCapatity);
        swap(objects,rhs.objects);
        return *this;
    }

    void resize(int newCapacity){
        if (newCapacity<theSize){
            return;
        }

        Object *newArray = new Object[newCapacity];
        for (int i = 0; i < theSize; ++i) {
            newArray[i] = move(objects[i]);
        }

        theCapatity = newCapacity;
        swap(objects,newArray);
        delete[]newArray;
    }

    Object& operator[](int index){
        return objects[index];
    }
    const Object & operator[](int index)const{
        return objects[index];
    }

    bool empty()const{
        return size()==0;

    }

    int size()const{
        return theSize;
    }

    void push_back(const Object & x){
        if (theSize == theCapatity){
            resize(2*theCapatity+1);
        } else{
            objects[theSize++]=move(x);
        }
    }
    void pop_back(){
        --theSize;
    }
    const Object & back(){
        return objects[theSize - 1];
    }

    typedef Object * iterator;
    typedef const Object* const_iterator;

    iterator begin(){
        return &objects[0];
    }

    iterator end(){
        return &objects[size()];
    }


    static const int SPARE_CAPACITY = 16;

    void pri(int k= 3){
        cout<<objects[k]<<endl;
    }
    ;
    int theSize;
    int theCapatity;
    Object * objects;
};


int main(){
    Vector<int> v1;
    for (int i = 0; i < 16; ++i) {
        v1.push_back(i);
        cout<<v1[i]<<"  ";
        //cout<<v1[i]<<" ";
    }
    cout<<v1.empty();cout<<endl;
    cout<<v1.theSize;cout<<endl;
    Vector<int> v2(  v1);
    for (int i = 0; i < 16; ++i) {
        cout<<v2[i]<<"  ";
    }

}