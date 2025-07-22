#pragma once

// --- Estrutura para representar os pares ordenados de inteiros ---
#include <utility> // std::pair

// --- Estrutura para os nodos da Árvore Binária de Busca ---
class Node {

public:    
    
    unsigned int key;
    std::pair<unsigned int, unsigned int> data;
    Node* left_child = nullptr;  
    Node* right_child = nullptr; 
    Node* parent = nullptr;

    // --- Função para criar um novo nodo ---
    Node(unsigned int k,
         std::pair<unsigned int, unsigned int> d,
         Node* p) :
        key(k), data(d), parent(p) {}
 
    // --- Função que gera chaves para os pares ordenados
    static int createKey(std::pair<unsigned int, unsigned int> pair);
};