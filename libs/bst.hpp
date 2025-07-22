#pragma once

#include <string>
#include <iostream>

#include "node.hpp"

class BST {

private:

    Node* pointer_to_root = nullptr;

    void printTree_private(Node* node, const std::string& prefix, bool is_left);

    void insert_private(unsigned int key, 
                        std::pair<unsigned int, unsigned int> data,
                        Node* node, 
                        Node* parent);

    void delete_private(unsigned int key, Node* current_node);

    Node* find_leaf(unsigned int key, Node* current_node);

    Node* search_private(unsigned int key, Node* current_node);

public:

    // --- Função para inserir um nodo ---
    void insert(std::pair<unsigned int, unsigned int> data);

    // --- Função para buscar a informação de um nodo (sem remover o nodo) ---
    Node* search(std::pair<unsigned int, unsigned int> data);

    // --- Função para remover um nodo ---
    void deleteNode(std::pair<unsigned int, unsigned int> data);

    void printTree();

};