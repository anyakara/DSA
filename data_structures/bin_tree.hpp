#ifndef __GENERIC_BINARY_TREE_HPP
#define __GENERIC_BINARY_TREE_HPP

#include <string>


class BinaryTreeEmptyException: public std::runtime_error {
public:
    explicit BinaryTreeEmptyException(const std::string &error): std::runtime_error(error) {}

};


template<typename K, typename V>
class BinaryTree {
private:
    size_t count;
    struct Node {
        Node(K k, V v) : key{k}, value{v}, parent{nullptr}, left_child{nullptr}, right_child{nullptr}
        {}
        K key;
        V value;
        Node *parent;
        Node *left_child;
        Node *right_child;
    };
    Node *root;
public:
    // most important functionality of tree access / delete procedures
    BinaryTree(); // constructor
    void deleteTreeRecursively(Node *root);
    ~BinaryTree(); // destructor
    [[nodiscard]] size_t size() const;
    [[nodiscard]] bool empty() const;

    void recursivelyInsert(K key, V value, Node *current);
    void insert(K key, V value);

    void recursivelyRemove(K key, V value, Node *current, Node *parent);
    void remove(K key, V value);
};


template<typename K, typename V>
BinaryTree<K, V>::BinaryTree(): count{0}, root{nullptr}
{ }

template<typename K, typename V>
void BinaryTree<K, V>::deleteTreeRecursively(BinaryTree::Node *r) {
    if (r == nullptr) {
        return;
    }
    deleteTreeRecursively(r->left);
    deleteTreeRecursively(r->right);
    delete r;
}

template<typename K, typename V>
BinaryTree<K, V>::~BinaryTree() {
    deleteTreeRecursively(root);
}

template<typename K, typename V>
size_t BinaryTree<K, V>::size() const {
    return count;
}

template<typename K, typename V>
bool BinaryTree<K, V>::empty() const {
    return count == 0;
}

// needs a recursive helper function to insert
template<typename K, typename V>
void BinaryTree<K, V>::recursivelyInsert(K key, V value, Node *current) {
    if (current == nullptr) {
        return;
    }
    if (key < current->key) {
        if (current->left == nullptr) {
            // make insertion
            Node *new_insertion = new Node(key, value);
            new_insertion->parent = current;
            current->left = new_insertion;
        } else {
            recursivelyInsert(key, value, current->left);
        }
    } else {
        if (current->right == nullptr) {
            Node *new_insertion = new Node(key, value);
            new_insertion->parent = current;
            current->right = new_insertion;
        } else {
            recursivelyInsert(key, value, current->right);
        }
    }
}

template<typename K, typename V>
void BinaryTree<K, V>::insert(K key, V value) {
    recursivelyInsert(key, value, root);
}


// not complete, we need more information regarding (whether it is a leaf node or not)
// depending on if it has one child or two.
template<typename K, typename V>
void BinaryTree<K, V>::recursivelyRemove(K key, V value, Node *current, Node *parent) {
    if (key == current->key) {
        if (current->right == nullptr && current->left == nullptr) { // leaf node
            if (current == parent->right) {
                parent->right = nullptr;
                delete current;
            } else {
                parent->left = nullptr;
                delete current;
            }
        } else if (current->left == nullptr) {
            if (current->right->left == nullptr) { // just take current->right (swap) and delete)
                std::swap(current, current->right);
                delete current->right;
                return;
            } else {
                Node *tmp{current->right->left};
                while (tmp->left != nullptr) {
                    tmp = tmp->left;
                }
                std::swap(current, tmp);
                delete tmp;
                return;
            }

        } else {
            if (current->left->right == nullptr) { // just take current->left (swap and delete)
                std::swap(current, current->left); // unsure if it just swaps nodes internal contents
                delete current->left;
                return;
            } else {
                Node *tmp{current->left->right};
                while (tmp->right != nullptr) {
                    tmp = tmp->right;
                }
                std::swap(current, tmp);
                delete tmp;
                return;
            }
        }
    } else if (key < current->key) {
        recursivelyRemove(key, value, current->left);
    } else {
        recursivelyRemove(key, value, current->right);
    }
}

template<typename K, typename V>
void BinaryTree<K, V>::remove(K key, V value) {
    recursivelyRemove(key, value, root, nullptr);
}


/*
Check the symmetry of the tree by providing the left and right node pointers.
The function returns if the binary tree is symmetric or not, recursively traversing
both halfs.
*/
bool checkSymmetry(node *right, node *left) {
    if (right == nullptr && left == nullptr) {
        return true;
    } else if (right != nullptr && left != nullptr) { // have this condition to check if r
        return (left->key == right->key) && checkSymmetry(right->right, left->left) && checkSymmetry(right->left, left->right);
    }
    return false;
}

#endif
