#ifndef __NODE
#define __NODE

#include <memory>
// class HuffmanNode;

class HuffmanNode {
    private:
        std::shared_ptr<HuffmanNode> left, right;
        unsigned char letter;
        unsigned int frequency;
        unsigned int bit_length = 0;
    public:
        unsigned char bit_code; 

        HuffmanNode() : left (), right(), letter('\0'), frequency(0), bit_code ('\0') {}
        HuffmanNode(unsigned char _letter, unsigned int _freq, unsigned char b_code='\0') : letter (_letter), frequency(_freq), left(), right(), bit_code(b_code) {}
        HuffmanNode(HuffmanNode * _left, HuffmanNode * _right);
        HuffmanNode(const HuffmanNode & other);
        HuffmanNode(HuffmanNode && other);
        HuffmanNode & operator=(const HuffmanNode & other);
        HuffmanNode & operator=(HuffmanNode && other);
        ~HuffmanNode();

        friend bool operator<(const HuffmanNode & left, const HuffmanNode & right) { return left.frequency > right.frequency; }
        friend bool operator>(const HuffmanNode & left, const HuffmanNode & right) { return left.frequency < right.frequency; }

        unsigned int get_frequency () const { return frequency; }
        unsigned char get_letter() const { return letter; } 
        unsigned int get_bit_length() const { return bit_length; }
        bool increase_bit_length ( unsigned int b ) {
            if (b + bit_length > sizeof(unsigned char) * 8)
                return false;
            else {
                bit_length += b;
                return true;
            }
        }
        HuffmanNode * get_left () const { 
            if (left.get()) 
                return left.get(); 
            return nullptr;
        } 
        HuffmanNode * get_right () const { 
            if (right.get())
                return right.get(); 
            return nullptr;
        }
};

#endif
