#pragma once
#include "InstanceCounter.hpp"

#include <memory>
#include <string>
class Node;

using NodePtr = std::unique_ptr<Node>;

class Node : public InstanceCounter
{
public:
    virtual std::string print() const = 0;
    virtual ~Node() {}; // dire que le destructeur a utilisé n'est pas celui par défaut
    virtual unsigned int height() const     = 0;
    virtual unsigned int node_count() const = 0;

private:
};
