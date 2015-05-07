#include "huffmannode.h"

HuffmanNode::HuffmanNode(HuffmanNode * _left, HuffmanNode * _right) : letter('\0')
{
    left = std::shared_ptr<HuffmanNode>(_left);
    right = std::shared_ptr<HuffmanNode>(_right);
    frequency = _left->get_frequency() + _right->get_frequency();
}

HuffmanNode::HuffmanNode(const HuffmanNode & other) : 
    left(other.left), right(other.right), letter(other.letter), frequency(other.frequency)
{ }

HuffmanNode::HuffmanNode(HuffmanNode && other) :
    left(std::move(other.left)), right(std::move(other.right)), letter(other.letter), frequency(other.frequency)
{
    other.letter = '\0';
    other.frequency = 0;
}

HuffmanNode & HuffmanNode::operator=(const HuffmanNode & other)
{
    if (this != &other) {
        this->left.reset(other.left.get());
        this->right.reset(other.right.get());
        this->letter = other.letter;
        this->frequency = other.frequency;
    }
    return *this;
}

HuffmanNode & HuffmanNode::operator=(HuffmanNode && other)
{
    if (this != &other) {
        this->left.reset (other.left.get());
        this->right.reset (other.right.get());
        this->letter = other.letter;
        this->frequency = other.frequency;
        other.frequency = 0;
        other.letter = '\0';
    }
    return *this;
}

HuffmanNode::~HuffmanNode()
{
    left.reset();
    right.reset();
}
