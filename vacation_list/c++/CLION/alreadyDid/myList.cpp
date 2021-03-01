//
// Created by 点雨落山岚 on 2020/12/29.
//
#include "iostream"
#include "algorithm"

using namespace std;

template<typename Object>
class List {
private:
    struct Node {
        Object data;
        Node *prev;
        Node *next;

        Node(const Object &d = Object{}, Node *p = nullptr, Node *n = nullptr) : data(d), prev(p), next(n) {}

        Node(Object &&d, Node *p = nullptr, Node *n = nullptr)
                : data{move(d)}, prev(p), next(n) {}

    };

public:
    class const_iterator {
    public:
        const_iterator() : current(nullptr) {

        }

        const Object &operator*() const {
            return retrieve();
        }

        const_iterator &operator++() {
            current = current->next;
            return *this;
        }

        const_iterator operator++(int) {
            const_iterator old = *this;
            ++(*this);
            return old;
        }

        bool operator==(const const_iterator &rhs) const {
            return current == rhs.current;
        }

        bool operator!=(const const_iterator &rhs) const {
            return !(*this == rhs);

        }

    protected:
        Node *current;

        Object &retrieve() const {
            return current->data;
        }

        const_iterator(Node *p) : current(p) {

        }

        friend class List<Object>;
    };

    class iterator : public const_iterator {
    public:
        iterator() {

        }

        Object &operator*() {
            return const_iterator::retrieve();
        }

        const Object &operator*() const {
            return const_iterator::operator*();
        }

        iterator &operator++() {
            this->current = this->current->next;
            return *this;
        }

        iterator operator++(int) {
            iterator old = *this;
            ++(*this);
            return old;
        }

    protected:
        iterator(Node *p) : const_iterator(p) {}

        friend class List<Object>;
    };

public:
    List() {

    }

    List(const List &rhs) {

    }

    ~List() {

    }

    List &operator=() {

    }

    List(List &&rhs) {
//        we need to focus on that,I can't understand that &&
    }

    List &operator=(List &&rhs) {

    }


    //I need to overcome it after achieveing iterator
    iterator begin() {
        return ()
    }

    const_iterator begin() {

    }

    iterator end() {
        return tail;
    }

    const_iterator end() const {
        return tail;
    }

    int size() const {
        return theSize;
    }

    bool empty() const {
        return size() == 0;
    }

//    void clear(){
//        while (!empty())
//
//    }

    Object &front() {
        return *begin();
    }

    const Object &front() const {
        return *begin();
    }

    Object &back() {
        return *--end();
    }

    const Object &back() const {
        return *--end();
    }

    void push_front(const Object &x) {

    }

    //never know about &&
    void push_front(Object &&x) {

    }

    void push_back(const Object &x) {

    }

    void push_back(Object &&x) {

    }

    void pop_front() {

    }

    void pop_back() {

    }


    iterator insert(iterator itr, const Object &x) {

    }

    iterator insert(iterator itr, Object &&x) {

    }

    iterator erase(iterator itr) {

    }

    iterator erase(iterator from, iterator to) {

    }

    void init() {

    }


private:
    int theSize;
    Node *head;
    Node *tail;
};

int main() {

}

