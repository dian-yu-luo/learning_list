//
// Created by dianyuluo on 2021/1/30.
//
#include"iostream"

using namespace std;

template<typename Comparable>
struct AvlNode {
    Comparable element;
    AvlNode *left;
    AvlNode *right;
    int height;

    AvlNode(const Comparable &ele, AvlNode *lt, AvlNode *rt, int h = 0) :
            element(ele), left(lt), right(rt), height(h) {};

    AvlNode(Comparable &&ele, AvlNode *lt, AvlNode *rt, int h = 0) :
            element(std::move(ele)), left(lt), right(rt), height(h) {};

    int Height(AvlNode *t) const {
        return t == nullptr ? -1 : t->height;
    }

    void insert(const Comparable &x, AvlNode *&t) {
        if (t == nullptr) {
            t = new AvlNode{x, nullptr, nullptr};
        } else if (x < t->element) {
            insert(x, t->left);
        } else if (x > t->element) {
            insert(x, t->element);
        }
        balance(t);
    }

    static const int ALLOWED_IMBALANCE = 1;

    void balance(AvlNode *&t) {
        if(t== nullptr){
            return;
        }
        if (Height(t->left) - Height(t->right) > ALLOWED_IMBALANCE){
            if (Height(t->left->left) >= Height(t->left->right)){
                rotateWithLeftChild(t);
            } else{
                rotateWithrightChild(t);
            }

        } else{
            if (Height(t->right->right) >= Height(t->right->left)){
                rotateWithrightChild(t);
            } else{
                doubleWithrightchild(t);
            }
        }
    }


    void rotateWithLeftChild(AvlNode *&k2) {
        AvlNode *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = max(Height(k2->left), Height(k2->right)) + 1;
        k1->height = max(Height(k1->left, k2->height)) + 1;
        k2 = k1;
    }
    void rotateWithrightChild(AvlNode *&k2) {
        AvlNode *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = max(Height(k2->left), Height(k2->right)) + 1;
        k1->height = max(Height(k1->left, k2->height)) + 1;
        k2 = k1;
    }
    void doubleWithLeftchild(AvlNode*&k3){
        rotateWithrightChild(k3->left);
        rotateWithLeftChild(k3);
    }
    void doubleWithrightchild(AvlNode*&k3){
        rotateWithrightChild(k3->left);
        rotateWithLeftChild(k3);
    }

    void remove(const Comparable&x,AvlNode*&t){
        if (t== nullptr){
            return;
        }
        if (x<t->element){
            remove(x,t->left);
        } else if(x>t->right){
            remove(x,t->right);
        } else if(t->left!= nullptr&&t->right!= nullptr){
            t->element=finMin(t->right)->element;
            remove(t->element,t->right);
        } else{
            AvlNode*oldNode=t;
            t=(t->left!= nullptr)?t->left:t->right;
            delete oldNode;
        }
        balance(t);
    }


};

int main() {
    cout << "wenhua " << endl;
    AvlNode<int> a();


}

