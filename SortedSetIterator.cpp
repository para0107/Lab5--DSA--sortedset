#include "SortedSetIterator.h"
#include <exception>

using namespace std;

SortedSetIterator::SortedSetIterator(const SortedSet& m) : multime(m)
{
	this->current = reinterpret_cast<Node *>(m.root);
    for(bool & i : visited)
    {
        i = false;
    }
}


void SortedSetIterator::first() {
	this->current = reinterpret_cast<Node *>(multime.root);
}


void SortedSetIterator::next() {
    if(!this->valid())
        throw exception();
    if(current->left != nullptr && !visited[current->left->data])
    {
        q.push_back(current);
        current = current->left;
        return;
    }
    if(current->right != nullptr && !visited[current->right->data])
    {
        q.push_back(current);
        current = current->right;
        return;
    }
    if(q.empty())
    {
        current = nullptr;
        return;
    }
    current = q.back();
    q.pop_back();
    visited[current->data] = true;
    next();

}


TElem SortedSetIterator::getCurrent()
{ if(!this->valid())
    return NULL_TELEM;
    else
    return current->data;

}

bool SortedSetIterator::valid() const {
	return current != nullptr;

}

