#include "node.hpp"

int Node::createKey(std::pair<unsigned int, unsigned int> pair){
    unsigned int sum = pair.first + pair.second;
    unsigned int k = sum % 2 == 0 ? pair.first : pair.second;
    return sum * (sum + 1) / 2 + k;
}