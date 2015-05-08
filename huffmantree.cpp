#include "huffmantree.h"

HuffmanTree::~HuffmanTree ()
{
    root.reset ();
}

HuffmanTree & HuffmanTree::operator=(const HuffmanTree & other)
{
    if (this != &other) {
        this->root.reset(other.root.get () ) ;
    } 
    return *this;
}

HuffmanTree & HuffmanTree::operator=(HuffmanTree && other)
{
    if (this != &other) {
        this->root.reset(other.root.get());
        other.root.reset ();
    } 
    return *this;
}

void HuffmanTree::load_file(const std::string filename, std::unordered_map<unsigned char, unsigned int> & frequency_table) 
{
    std::ifstream input (filename, std::ifstream::in | std::ifstream::binary);
    char inchar;
    while (input.good()) {
        input >> std::noskipws;
        input >> inchar;
        if (inchar == '\n') 
            continue;
        std::unordered_map<unsigned char, unsigned int>::iterator insert;
        if ((insert = frequency_table.find (inchar)) == frequency_table.end())
            frequency_table[inchar] = 1;
        else 
            frequency_table[inchar] = frequency_table[inchar] + 1;
    }
    input.close ();
}
