#include <iostream>
#include <string>
#include <sstream>
#include "binary.h"


template<typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::findPredecessor(const T& value) const {
    if (root == nullptr)
        return nullptr;

    Node* current = root;
    Node* predecessor = nullptr;

    while (current != nullptr) {
        if (value < current->data) {
            current = current->left;
        } else if (value > current->data) {
            predecessor = current;
            current = current->right;
        } else {
            if (current->left != nullptr) {
                Node* temp = current->left;
                while (temp->right != nullptr)
                    temp = temp->right;
                predecessor = temp;
            }
            break;
        }
    }

    return predecessor;
}

template<typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::findSuccessor(const T& value) const {
    if (root == nullptr)
        return nullptr;

    Node* current = root;
    Node* successor = nullptr;

    while (current != nullptr) {
        if (value < current->data) {
            successor = current;
            current = current->left;
        } else if (value > current->data) {
            current = current->right;
        } else {
            if (current->right != nullptr) {
                Node* temp = current->right;
                while (temp->left != nullptr)
                    temp = temp->left;
                successor = temp;
            }
            break;
        }
    }

    return successor;
}

template<typename T>
void BinaryTree<T>::destroyTree(Node* node) {
    if (node == nullptr) {
        return;
    }

    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
}

template<typename T>
BinaryTree<T>::BinaryTree() : root(nullptr) {}

template<typename T>
BinaryTree<T>::~BinaryTree() {
    destroyTree(root);
}

template<typename T>
void BinaryTree<T>::processBinaryTree() {
    int ch;
    char dec;
    T searchKey;
    T new_numb;
    BinaryTree<T> tree;
    std::string input;
    T value;
    std::cout << "Enter value for adding(enter NULL for exit): ";
    std::cin.ignore();
    while (std::getline(std::cin, input) && !input.empty()) {
        std::stringstream ss(input);
        if (ss >> value) {
            tree.insert(value);
        } else {
            std::cout << "Invalid input. Retry." << std::endl;
        }
    }
    tree.printTree(tree);
    BinaryTree<T>::Iterator iterator = tree.begin();
    if (!tree.isEmpty()){
        do {
            std::cout << "1 for NEXT, 2 for PREVIOUS, 3 for ROOT." << std::endl;
            std::cin >> ch;

            switch (ch) {
                case 1: {
                    ++iterator;
                    break;
                }
                case 2: {
                    --iterator;
                    break;
                }
                case 3: {
                    iterator.getRoot();
                    std::cout << "Root of the tree: " << *iterator << std::endl;
                    break;
                }
                default: {
                    break;
                }
            }

            if (ch == 1 || ch == 2 || ch == 3) {
                std::cout << "Do you want ti change current element " << *iterator << "? (y/n)";
                std::cin >> dec;
                if (dec == 'y') {
                    std::cout << "Enter new element: ";
                    std::cin >> new_numb;
                    iterator.modify(new_numb);
                    std::cout << "Modified value: " << *iterator << std::endl;
                }
            }
        } while (ch == 1 || ch == 2 || ch == 3);
        std::cout << "Enter key for search of previous element: ";
        std::cin >> searchKey;

        BinaryTree<T>::Node* predecessor = tree.findPredecessor(searchKey);
        if (predecessor != nullptr) {
            std::cout << "Previous value was found: " << predecessor->data << std::endl;
        } else {
            std::cout << "Previous value wasn't found." << std::endl;
        }
    }
}

template<typename T>
void BinaryTree<T>::printTree(BinaryTree<T>& tree) {
    std::cout << "Is tree empty? " << (tree.isEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "Tree size: " << tree.getSize() << std::endl;
    if (!tree.isEmpty()){
        std::cout << "Inorder traversal: ";
        tree.inorderTraversal();
        BinaryTree<T>::Iterator iterator = tree.begin();
        std::cout << "Tree root: " << iterator.getRoot() << std::endl;
    }
}

template<typename T>
void BinaryTree<T>::insert(const T& value) {
    Node* newNode = new Node(value);

    if (root == nullptr) {
        root = newNode;
        return;
    }

    Node* current = root;
    while (true) {
        if (value < current->data) {
            if (current->left == nullptr) {
                current->left = newNode;
                return;
            }
            current = current->left;
        } else {
            if (current->right == nullptr) {
                current->right = newNode;
                return;
            }
            current = current->right;
        }
    }
}

template<typename T>
bool BinaryTree<T>::isEmpty() const {
    return root == nullptr;
}

template<typename T>
int BinaryTree<T>::getSize() const {
    if (root == nullptr) {
        return 0;
    }

    int size = 0;
    Node* current = root;
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current->left == nullptr) {
            size++;
            current = current->right;
        } else {
            prev = current->left;

            while (prev->right != nullptr && prev->right != current) {
                prev = prev->right;
            }

            if (prev->right == nullptr) {
                prev->right = current;
                current = current->left;
            } else {
                prev->right = nullptr;
                size++;
                current = current->right;
            }
        }
    }

    return size;
}

template<typename T>
void BinaryTree<T>::inorderTraversal() const {
    if (root == nullptr) {
        return;
    }

    Node** traversalStack = new Node*[getSize()];
    int top = -1;
    Node* current = root;

    while (current != nullptr || top >= 0) {
        while (current != nullptr) {
            traversalStack[++top] = current;
            current = current->left;
        }

        current = traversalStack[top--];

        std::cout << current->data << " ";

        current = current->right;
    }

    std::cout << std::endl;

    delete[] traversalStack;
}

template<typename T>
BinaryTree<T>::Iterator::Iterator(Node* node, BinaryTree<T>* binaryTree) : current(node), tree(binaryTree) {}

template<typename T>
T BinaryTree<T>::Iterator::operator*() const {
    return current->data;
}

template<typename T>
T BinaryTree<T>::Iterator::getRoot() {
    current = tree->root;
    return current->data;
}

template<typename T>
typename BinaryTree<T>::Iterator& BinaryTree<T>::Iterator::operator++() {
    if (!current) {
        std::cout << "Tree is empty." << std::endl;
        return *this;
    }

    Node* nextNode = tree->findSuccessor(current->data);
    if (nextNode != nullptr) {
        current = nextNode;
    } else {
        std::cout << "Next node wasn't found." << std::endl;
    }

    return *this;
}

template<typename T>
typename BinaryTree<T>::Iterator& BinaryTree<T>::Iterator::operator--() {
    if (!current) {
        std::cout << "Tree is empty." << std::endl;
        return *this;
    }

    Node* predecessor = tree->findPredecessor(current->data);
    if (predecessor != nullptr) {
        current = predecessor;
    } else {
        std::cout << "Previous node wasn't found" << std::endl;
    }

    return *this;
}

template<typename T>
void BinaryTree<T>::Iterator::modify(const T& newValue) {
    if (!current) {
        std::cout << "Current node doesn't exist.." << std::endl;
        return;
    }
    current->data = newValue;
}

template<typename T>
typename BinaryTree<T>::Iterator BinaryTree<T>::begin() {
    Iterator iterator(root, this);
    return iterator;
}

template class BinaryTree<int>;
template class BinaryTree<float>;
template class BinaryTree<char>;
template class BinaryTree<std::string>;