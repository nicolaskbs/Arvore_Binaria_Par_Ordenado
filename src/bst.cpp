#include "bst.hpp"

void BST::printTree_private(Node* node, const std::string& prefix, bool is_left) {
    
    if (node == nullptr) {
        return;
    }

    if (node->right_child) {
        printTree_private(node->right_child, prefix + (is_left ? "│   " : "    "), false);
    }

    std::cout << prefix << (is_left ? "└── " : "┌── ");

    std::cout << "("
              << node->data.first
              << ", "
              << node->data.second
              << ")"
              << " = "
              << node->key
              << std::endl;

    if (node->left_child) {
        printTree_private(node->left_child, prefix + (is_left ? "    " : "│   "), true);
    }
}

void BST::printTree() {
    if (pointer_to_root == nullptr) {
        std::cout << "A árvore está vazia." << std::endl;
    } else {
        printTree_private(pointer_to_root, "", true);
    }
    std::cout << "----------------------------------------" << std::endl;
}

void BST::insert(std::pair<unsigned int, unsigned int> data) {
    
    unsigned int key = Node::createKey(data);

    if(this->pointer_to_root == nullptr){
        this->pointer_to_root = new Node(key, data, nullptr);
    } else{
        insert_private(key, data, this->pointer_to_root, nullptr);
    }    
}

void BST::insert_private(unsigned int key,
                         std::pair<unsigned int, unsigned int> data,
                         Node* current_node, 
                         Node* parent){
    bool is_left_side;
    if(key <= current_node->key ){
        parent = current_node;
        current_node = current_node->left_child;
        is_left_side = true;
    } else if(key > current_node->key ){
        parent = current_node;
        current_node = current_node->right_child;
        is_left_side = false;
    }
    if(current_node == nullptr){
        current_node = new Node(key, data, parent);
        if(is_left_side){
            parent->left_child = current_node;
        } else{
            parent->right_child = current_node;
        }
        return;
    }

    insert_private(key, data, current_node, parent);
}

void BST::deleteNode(std::pair<unsigned int, unsigned int> data){
    unsigned int key = Node::createKey(data);

    delete_private(key, this->pointer_to_root);
}

void BST::delete_private(unsigned int key, Node* current_node) {
    if (current_node == nullptr) {
        return;
    }

    if (key < current_node->key) {
        delete_private(key, current_node->left_child);
    } else if (key > current_node->key) {
        delete_private(key, current_node->right_child);
    } else {
        if (current_node->left_child == nullptr && current_node->right_child == nullptr) {
            if (current_node->parent == nullptr) {
                pointer_to_root = nullptr;
            } else if (current_node->parent->left_child == current_node) {
                current_node->parent->left_child = nullptr;
            } else {
                current_node->parent->right_child = nullptr;
            }
            delete current_node;
        }
        else if (current_node->left_child != nullptr && current_node->right_child != nullptr) {
            Node* successor = find_leaf(current_node);
            current_node->key = successor->key;
            current_node->data = successor->data;
            delete_private(successor->key, successor);
        }
        else {
            Node* child = (current_node->left_child != nullptr) ? current_node->left_child : current_node->right_child;
            if (current_node->parent == nullptr) {
                pointer_to_root = child;
                child->parent = nullptr;
            } else {
                if (current_node->parent->left_child == current_node) {
                    current_node->parent->left_child = child;
                } else {
                    current_node->parent->right_child = child;
                }
                child->parent = current_node->parent;
            }
            delete current_node;
        }
    }
}

Node* BST::find_leaf(Node* current_node){
    if(current_node->left_child != nullptr){
        current_node = current_node->left_child;
        while(current_node->right_child){
            current_node = current_node->right_child;
        }
    } else {
        current_node = current_node->right_child;
        while(current_node->left_child){
            current_node = current_node->left_child;
        }
    }
    return current_node;
}

Node* BST::search(std::pair<unsigned int, unsigned int> data){
    unsigned int key = Node::createKey(data);
    return search_private(key, this->pointer_to_root);
}

Node* BST::search_private(unsigned int key, Node* current_node){
    if(current_node == nullptr){
        return nullptr;
    }
    if(current_node->key == key){
        return current_node;
    }
    if(current_node->key < key){
        return search_private(key, current_node->right_child);
    }
    return search_private(key, current_node->left_child);

}