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
    unsigned char inchar;
    if ((input.rdstate() & std::ifstream::failbit) != 0 ) {
        std::cerr << "ERROR opening file " << filename << std::endl;
        return;
    }
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

void HuffmanTree::build_tree (std::unordered_map<unsigned char, unsigned int> freq_table)
{
    std::priority_queue<HuffmanNode *> build_queue;
    for (std::unordered_map<unsigned char, unsigned int>::iterator it = freq_table.begin (); it != freq_table.end(); ++it) {
        build_queue.push(new HuffmanNode (it->first, it->second));
    }

    while (build_queue.size () != 1) {
        HuffmanNode * left = build_queue.top (); build_queue.pop();
        HuffmanNode * right = build_queue.top (); build_queue.pop();
        build_queue.push (new HuffmanNode(left, right));
    }
    HuffmanNode * root_ = build_queue.top ();
    this->root.reset (root_);

}

void HuffmanTree::construct_code_table (std::unordered_map<unsigned char, unsigned char> & code_table)
{
    HuffmanNode * root_ = this->root.get();
    traverse_tree (root_, code_table);
    for (auto it = code_table.begin (); it !=code_table.end(); ++it) 
        std::cout << std::hex << it->first << " : " << (std::bitset<8>)it->second << std::endl;

}

void HuffmanTree::traverse_tree ( HuffmanNode * parent, std::unordered_map<unsigned char, unsigned char> & code_table ) 
{
    if (parent->get_letter() != '\0') {
        code_table[parent->get_letter()] = parent->bit_code;
        return;
    }

    unsigned char parent_code = parent->bit_code;
    unsigned int parent_len = parent->get_bit_length();
    HuffmanNode * left = parent->get_left();
    HuffmanNode * right = parent->get_right ();
    if (left) {
        left->bit_code = ((parent_code << 1) | 0x1);
        if (!left->increase_bit_length(parent_len + 1))
            std::cerr << "ERROR bit length out of range: char " << left->get_letter() << std::endl;
        traverse_tree (left, code_table);
    } 
    if (right) {
        right->bit_code = (parent_code << 1) ;
        if (!right->increase_bit_length(parent_len + 1))
            std::cerr << "ERROR bit length out of range: char " << right->get_letter() << std::endl;
        traverse_tree (right, code_table);
    }
}


