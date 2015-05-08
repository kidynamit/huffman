#include "huffmantree.h"

int main (int argc, char ** argv) 
{
    if (argc == 2) {
        HuffmanTree htree;
        std::unordered_map<unsigned char, unsigned int> frequency_table;
        const std::string input (argv[1]);
        htree.load_file (input, frequency_table);
        for (std::unordered_map<unsigned char, unsigned int>::iterator it = frequency_table.begin (); it != frequency_table.end(); ++it) 
            std::cout << it->first << " : " << it->second << std::endl;
        HuffmanNode * root = NULL;
        root = htree.get_root();
        std::cout << "Root: " << root << std::endl;
        htree.build_tree (frequency_table);
        root = htree.get_root ();
        std::cout << "Root: " << root << std::endl;
        std::unordered_map<unsigned char, unsigned char> code_table;
        htree.construct_code_table (code_table) ;
    
    } else if (argc == 3) {

    } else {
        std::cout << "usage: ./huffencode <uncoded_file> <encoded_file>" << std::endl;
    }
    return 0;
}
