#ifndef __TREE
#define __TREE
#include "huffmannode.h"
#include <queue>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <string>
#include <bitset>

class HuffmanTree{
    private:
        std::shared_ptr<HuffmanNode> root;

        void traverse_tree(HuffmanNode * parent, std::unordered_map<unsigned char, unsigned char> & code_table);
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
        // constructs a huffman tree with a priority queue
        void build_tree (const std::unordered_map<unsigned char, unsigned int> freq_table);
        void construct_code_table (std::unordered_map<unsigned char, unsigned char> & code_table);
        HuffmanNode * get_root () const{ return root.get(); }
};

#endif
