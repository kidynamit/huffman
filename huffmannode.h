#ifndef __NODE
#define __NODE

#include <memory>
class HuffmanNode;

class HuffmanNode {
    private:
        std::shared_ptr<HuffmanNode> left, right;
        char letter;
        unsigned int frequency;
    public:
        HuffmanNode() : left (), right(), letter('\0'), frequency(0) {}
        HuffmanNode(char _letter, unsigned int _freq) : letter (_letter), frequency(_freq), left(), right() {}
        HuffmanNode(HuffmanNode * _left, HuffmanNode * _right);
        HuffmanNode(const HuffmanNode & other);
        HuffmanNode(HuffmanNode && other);
        HuffmanNode & operator=(const HuffmanNode & other);
        HuffmanNode & operator=(HuffmanNode && other);
        ~HuffmanNode();

        friend bool operator<(const HuffmanNode & left, const HuffmanNode & right) { return left.frequency < right.frequency; }
        friend bool operator>(const HuffmanNode & left, const HuffmanNode & right) { return left.frequency > right.frequency; }

        unsigned int get_frequency () const { return frequency; }
        char get_letter() const { return letter; } 
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
