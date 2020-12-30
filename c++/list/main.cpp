#include <iostream>
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
    ilist():_at_front(0), _at_end(0),_size(0){    };

    void print_init(){
        cout<< this->_size<<" "<< this->_at_front<<" "<< this->_at_front<<endl;
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

inline int ilist::size() { return _size; }

int main() {
    int a;//lang
    printf("laing");//langÀÇ
    cout<<"»ÆºÓÔ¶ÉÏ°×ÔÆ¼ä";
}
