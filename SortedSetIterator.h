#pragma once
#include "SortedSet.h"
#include <deque>

//DO NOT CHANGE THIS PART
class SortedSetIterator
{
	friend class SortedSet;
private:
	const SortedSet& multime;
	SortedSetIterator(const SortedSet& m);

    struct Node{
        TElem data;
        Node* right;
        Node* left;
        Node* parent;
    };
Node* current;
bool visited[10000]{};
std::deque<Node*> q;


public:
	void first();
	void next();
	TElem getCurrent();
	bool valid() const;
};

