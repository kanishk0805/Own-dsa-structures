template <typename T>
class BinaryTree{
    public:
    T data;
    BinaryTree<T> * Left;
    BinaryTree<T> *Right;
    BinaryTree(T data){
        this->data=data;
        Left=NULL;
        Right=NULL;
    }
    ~BinaryTree(){
        delete Right;
        delete Left;
    }
};