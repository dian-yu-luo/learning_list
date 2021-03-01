#include"iostream"

using namespace std;

template<typename Object, typename Comparator=less<Object>>
class BinarySearchTree {
public:
private:
    BinaryNode *boot;
    Comparator isLessThan;


    struct BinaryNode {

    };

    bool contains(const Object &x, BinaryNode *t)const{
        if (t== nullptr){
            return false;
        } else if(isLessThan(x,t.element)){
            return contains(x,t->left);
        } else if(x>t->element){
            return contains(x,t->right);
        } else{
            return true;
        }
    };
};

int main() {
    cout << "liang" << endl;
}