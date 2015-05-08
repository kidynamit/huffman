#ifndef __TREE
#define __TREE
#include "huffmannode.h"
#include <queue>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <string>

class HuffmanTree{
    private:
        std::shared_ptr<HuffmanNode> root;

    public:
        HuffmanTree () : root () {}
        HuffmanTree (HuffmanNode * _root) : root (_root) {}
        HuffmanTree (const HuffmanTree & other) : root(other.root) { }
        HuffmanTree (HuffmanTree && other) : root(std::move(other.root)) { }
        HuffmanTree & operator=(const HuffmanTree & other);
        HuffmanTree & operator=(HuffmanTree && other);
        ~HuffmanTree ();

        // constructs a frequency table from file
        void load_file (const std::string filename, std::unordered_map<unsigned char, unsigned int> & frequency_table);
};

#endif
