#include "../libs/bst.hpp"
#include "../libs/node.hpp"
#include <vector>
#include <random>
#include <ctime>

void insert_ten_random_pairs(BST &tree, std::vector<std::pair<unsigned int, unsigned int>> &inserted_pairs){

    std::cout << "Inserindo 10 pares aleatórios na árvore:" << std::endl;
    for (int i = 0; i < 10; ++i) {
        unsigned int first_val = std::rand() % 1001;
        unsigned int second_val = std::rand() % 1001;
        std::pair<unsigned int, unsigned int> random_pair = {first_val, second_val};
        
        // Evitar inserir pares duplicados
        bool exists = false;
        for(const auto& p : inserted_pairs){
            if(p.first == random_pair.first && p.second == random_pair.second){
                exists = true;
                break;
            }
        }
        if(!exists){
            tree.insert(random_pair);
            inserted_pairs.push_back(random_pair);
            std::cout << "Inserido: (" << random_pair.first << ", " << random_pair.second << ")" << std::endl;
        } else {
            i--;
        }
    }
}

int main() {

    // Tempo e vetor para pares aleatórios
    std::srand(time(0));
    std::vector<std::pair<unsigned int, unsigned int>> inserted_pairs;

    BST tree;

    insert_ten_random_pairs(tree, inserted_pairs);

    std::cout << "\nImpressão da árvore:" << std::endl;
    tree.printTree();

    std::cout << "\nBuscando alguns valores:" << std::endl;

    // Busca um nó que foi inserido
    std::pair<unsigned int, unsigned int> pair_to_find = inserted_pairs[std::rand() % 11];
    Node* search_true = tree.search(pair_to_find);
    if (search_true) {
        std::cout << "Par (" << pair_to_find.first << ", " << pair_to_find.second << ") encontrado com chave " << search_true->key << std::endl;
    } else {
        std::cout << "Par (" << pair_to_find.first << ", " << pair_to_find.second << ") nao encontrado" << std::endl;
    }
    
    // Tenta buscar um nó que NÃO foi inserido
    Node* search_fake = tree.search({5, 1003});
    if (search_fake) {
        std::cout << "Par (5, 1003) encontrado com chave " << search_fake->key << std::endl;
    } else {
        std::cout << "Par (5, 1003) não encontrado" << std::endl;
    }

    // Remover alguns nós da árvore
    std::pair<unsigned int, unsigned int> pair_to_delete1 = inserted_pairs[std::rand() % 11];
    std::pair<unsigned int, unsigned int> pair_to_delete2 = inserted_pairs[std::rand() % 11];
    std::pair<unsigned int, unsigned int> pair_to_delete3 = inserted_pairs[std::rand() % 11];
    std::cout << "\nRemovendo os pares (" 
              << pair_to_delete1.first << ", " << pair_to_delete1.second
              << ") ; (" 
              << pair_to_delete2.first << ", " << pair_to_delete2.second 
              << ") e (" 
              << pair_to_delete3.first << ", " << pair_to_delete3.second 
              << ")..." << std::endl;
    tree.deleteNode(pair_to_delete1);
    tree.deleteNode(pair_to_delete2);
    tree.deleteNode(pair_to_delete3);

    std::cout << "\nImpressão da árvore apos a remoção:" << std::endl;
    tree.printTree();

    return 0;
}