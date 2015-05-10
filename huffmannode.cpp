#include "huffmannode.h"

HuffmanNode::HuffmanNode(HuffmanNode * _left, HuffmanNode * _right) : letter('\0')
{
    left = std::shared_ptr<HuffmanNode>(_left);
    right = std::shared_ptr<HuffmanNode>(_right);
    frequency = _left->get_frequency() + _right->get_frequency();
    bit_code = 0;
}

HuffmanNode::HuffmanNode(const HuffmanNode & other) : 
    left(other.left), right(other.right), letter(other.letter), frequency(other.frequency),
    bit_code(other.bit_code)
{ }

HuffmanNode::HuffmanNode(HuffmanNode && other) :
    left(std::move(other.left)), right(std::move(other.right)), letter(other.letter), frequency(other.frequency),
    bit_code(other.bit_code)
{
    other.letter = '\0';
    other.frequency = 0;
    other.bit_code = 0;
}

HuffmanNode & HuffmanNode::operator=(const HuffmanNode & other)
{
    if (this != &other) {
        this->left.reset(other.left.get());
        this->right.reset(other.right.get());
        this->letter = other.letter;
        this->frequency = other.frequency;
        this->bit_code = other.bit_code;
    }
    return *this;
}

HuffmanNode & HuffmanNode::operator=(HuffmanNode && other)
{
    if (this != &other) {
        this->left.reset (other.left.get());
        other.left.release();
        this->right.reset (other.right.get());
        other.right.release();
        this->letter = other.letter;
        this->frequency = other.frequency;
        this->bit_code = other.bit_code;
        other.bit_code = 0;
        other.frequency = 0;
        other.letter = '\0';
    }
    return *this;
}

HuffmanNode::~HuffmanNode()
{
    left.release();
    right.release();
}
