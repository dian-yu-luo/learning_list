#include <iostream>
#include <cstdlib>
using namespace std;

class ilist_item{
public:
    ilist_item(int value,ilist_item *item_to_link_to = 0);
private:
    int _value;
    ilist_item * _next;
};

inline ilist_item::ilist_item(int value, ilist_item *item_to_link_to) {
    _value=value;
    if(!item_to_link_to){
        _next = 0;
    } else{
        _next =item_to_link_to->_next;
        item_to_link_to->_next = this;
    }
}
class ilist{
public:
    void insert_front(int value);
    void insert_end(int value);
    void find(int value);
    void bump_up_size();
    void bump_down_size();
    ilist():_at_front(0), _at_end(0),_size(0){    };

    void print_init(){
        cout<< this->_size<<" "<< this->_at_front<<" "<< this->_at_front<<endl;
    }
    void insert(ilist_item*ptr,int value){
        new ilist_item(value,ptr);
        ++_size;
    }
    void insert_front(ilist_item){

    }




    int size();
private:
    ilist_item * _at_front;//text
    ilist_item * _at_end ;
    int _size;

    int _value;
    ilist *_next;

    ilist(const ilist&);
    ilist &operator=(const ilist&);
};

ilist_item* ilist::find(int value) {

}

inline void ilist::insert_front(int value) {
    ilist_item*ptr = new ilist_item(value);
    if(!_at_front){
        _at_front=_at_end=ptr;
    } else{

        _at_front=ptr;
    }
    bump_up_size();
}
inline void ilist::insert_end(int value) {
    if(!_at_end){
        _at_end=_at_front=new ilist_item(value);
    } else{
        _at_end=new ilist_item(value,_at_end);

    }
    bump_up_size();
}
inline void ilist::bump_up_size() {
    _size++;
}
inline void ilist::bump_down_size() {
    _size--;
}
inline int ilist::size() { return _size; }

int main() {



}
