#include <iostream>

using namespace std;

template <typename T>
struct Node {
    Node<T>* left;
    Node<T>* right;
    T value;
    bool isNull;
    Node(T _value, bool _isNull) {
        value = _value;
        isNull = _isNull;
    }
};

template <typename T>
struct BST {
    Node<T>* root;
    BST(T value) {
        root = new Node<T>(value, false);
        root->left = new Node<T>(0, true);
        root->right = new Node<T>(0, true);
    }
    Node<T>* create_null_node() {
        return new Node<T>(0, true);
    }
    Node<T>* create_node(T value) {
        Node<T>* newNode = new Node<T>(value, false);
        newNode->left = create_null_node();
        newNode->right = create_null_node();
        return newNode;
    }
    Node<T>* search_real(Node<T>* curr, T value) {
        if (curr->isNull) return curr;
        if (curr->value == value) return curr;
        if (value > curr->value) return search_real(curr->right, value);
        else return search_real(curr->left, value);
    }
    Node<T>* search(T value) {
        return search_real(root, value);
    }
    void insert_real(Node<T>* curr, T value) {
        while ((!curr->isNull) && value < curr->value) curr = curr->left; 
        while ((!curr->isNull) && value > curr->value) curr = curr->right;
        if (curr->isNull) *curr = *create_node(value);
        else if (value > curr->value) curr->right = create_node(value);
        else curr->left = create_node(value);
    }
    void insert(T value) {
        insert_real(root, value);
    }
    void remove_real(Node<T>* curr, T value) {
        
    }
    void print_dump_real(Node<T>* curr) {
        if (curr->isNull) return;
        cout << curr->value << " ";
        print_dump_real(curr->left);
        print_dump_real(curr->right);
    }
    void print_dump() {
        print_dump_real(root);
    }
};

int main() {
    BST<int> test_tree(100);
    test_tree.insert(10);
    test_tree.insert(210);
    test_tree.insert(5);
    test_tree.insert(15);
    test_tree.insert(205);
    test_tree.insert(202);
    test_tree.insert(207);
    test_tree.print_dump();
}