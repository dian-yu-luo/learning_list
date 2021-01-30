//
// Created by dianyuluo on 2021/1/24.
//

#include "iostream"

using namespace std;

template<typename Comparable>
class BinarySearchTree {
public:
    BinarySearchTree();

    BinarySearchTree(const BinarySearchTree &rhs) : root(nullptr) {
        root = clone(rhs.root);
    };

    BinarySearchTree(BinarySearchTree &&rhs);

    ~BinarySearchTree() {
        makeEmpty();
    };

    const Comparable &findMin() const;

    const Comparable &finMax() const;

    bool contains(const Comparable &x) const;

    bool isEmpty() const;

    void printTree(ostream &out = cout) const {
        if (isEmpty()) {
            out << "Empty tree" << endl;

        } else printTree(root, out);
    };




    void makeEmpty();

    void insert(const Comparable &x);

    void insert(Comparable &&x);

    void remove(const Comparable &x);

    BinarySearchTree &operator=(const BinarySearchTree &rhs);

    BinarySearchTree &operator=(BinarySearchTree &&rhs);

private:
    struct BinaryNode {
        Comparable element;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode(const Comparable &theElement, BinaryNode *lt, BinaryNode *rt) :
                element(theElement), left(lt), right(rt) {};

        BinaryNode(Comparable &&theElement, BinaryNode *lt, BinaryNode *rt) :
                element{std::move(theElement)}, left(lt), right(rt) {};
    };

    BinaryNode *root;

    void insert(const Comparable &x, BinaryNode *&t) {
        if (t == nullptr) {
            t = new BinaryNode{x, nullptr, nullptr};
        } else if (x < t->element) {
            insert(x, t->left);
        } else if (x > t->element) {
            insert(x, t->right);
        } else;
    };

    void insert(Comparable &&x, BinaryNode *&t) {
        if (t == nullptr) {
            t = new BinaryNode{move(x), nullptr, nullptr};
        } else if (x < t->element) {
            if (t->left == nullptr) {
                insert(move(x), t->left);
            } else;
        } else if (x > t->element) {
            if (t->right == nullptr) {
                insert(move(x), t->right);
            } else;
        } else;
    };

    BinaryNode *finMin(BinaryNode *t) const {
        if (t == nullptr)return nullptr;
        else if (t->left == nullptr) {
            return t;
        } else return finMin(t->left);
    }

    BinaryNode *finMax(BinaryNode *t) const {
        if (t != nullptr) {
            while (t->right != nullptr) {
                t = t->right;
            }
        }
        return t;
    };

    bool contains(const Comparable &x, BinaryNode *t) const {
        if (t == nullptr) {
            return false;
        } else if (x < t->element) {
            return contains(x, t->left);
        } else if (x > t->element) {
            return contains(x, t->right);
        } else {
            return true;
        }
    }

    void makeEmpty(BinaryNode *&t) {
        if (t != nullptr) {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        t = nullptr;
    };

    void remove(const Comparable &x, BinaryNode *&t) {
        if (t == nullptr) {
            return;
        } else if (x < t->element) {
            remove(x, t->left);
        } else if (x > t->element) {
            remove(x, t->right);
        } else if (t->left != nullptr && t->right != nullptr) {
            t->element = finMin(t->right)->element;
            remove(t->element, t->right);
        } else {
            BinaryNode *oldNode = t;
            t = (t->right != nullptr) ? t->left : t->right;
            delete oldNode;
        }
    }

    void printTree(BinaryNode *&t) const {
        if (t== nullptr){
            return -1;

        } else {
            return 1+
        }
    };

    BinaryNode *clone(BinaryNode *t) const {
        if (t == nullptr) {
            return nullptr;
        } else {
            return new BinaryNode(t->element, clone(t->left), clone(t->right));
        }
    };
public:
    void printTree(BinaryNode*t, ostream &out)const{
        if (t!= nullptr){
            printTree(t->left,out);
            out<<t->element<<endl;
            printTree(t->right,out);
        }
    }
};

int main() {
    cout << "lasdfasdfg" << endl;
}