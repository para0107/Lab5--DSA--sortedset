#include "SortedSet.h"
#include "SortedSetIterator.h"

SortedSet::SortedSet(Relation r) {
this->Size = 0;
this->root = nullptr;
this->r = r;
}




bool SortedSet::add(TComp elem) {
    Node* current = root;
    while (current != nullptr)
    {
        if (current->data == elem)
        {
            return false;
        }
        if (r(current->data, elem))
        {
            current = current->left;
        }
        else
            if(r(elem, current->data))
        {
            current = current->right;
        }}
        current = new Node;
        current->data = elem;
        current->left = nullptr;
        current->right = nullptr;
        Size++;
        return true;

}


bool SortedSet::remove(TComp elem) {
	Node* current = root;
    while (current != nullptr)
    {
        if (r(current->data, elem))
        {
            current = current->right;
        }
        else if (r(elem, current->data))
        {
            current = current->left;
        } else
        {
            if (current->left == nullptr && current->right == nullptr)
            {
                if (current->parent->left == current)
                {
                    current->parent->left = nullptr;
                }
                else
                {
                    current->parent->right = nullptr;
                }
                delete current;
                Size--;
                return true;
            }
            else if (current->left == nullptr)
            {
                if (current->parent->left == current) {
                    current->parent->left = current->right;
                }
                else
                {
                    current->parent->right = current->right;
                }
                delete current;
                Size--;
                return true;
            }
            else if (current->right == nullptr)
            {
                if (current->parent->left == current)
                {
                    current->parent->left = current->left;
                }
                else
                {
                    current->parent->right = current->left;
                }
                delete current;
                Size--;
                return true;
            }
            else
            {
                Node* temp = current->right;
                while (temp->left != nullptr)
                {
                    temp = temp->left;
                }
                current->data = temp->data;
                if (temp->parent->left == temp) {
                    temp->parent->left = temp->right;
                }
                else
                {
                    temp->parent->right = temp->right;
                }
                delete temp;
                Size--;
                return true;
            }
        }
    }
	return false;
}


bool SortedSet::search(TComp elem) const {
	Node* current = root;
    while (current != nullptr)
    {
        if (r(current->data, elem))
        {
            current = current->right;
        }
        else if (r(elem, current->data))
        {
            current = current->left;
        }
        else
        {
            return true;
        }
    }
	return false;
}


int SortedSet::size() const {
	return this->Size;
	return 0;
}



bool SortedSet::isEmpty() const {
	return this->Size == 0;
}

SortedSetIterator SortedSet::iterator() const {
	return SortedSetIterator(*this);
}


SortedSet::~SortedSet() {
    while (root != nullptr) {
        remove(root->data);
    }
}

void SortedSet::print(Node* x)
{
    while (x != nullptr)
    {
        print(x->left);
        std::cout << x->data << " ";
        print(x->right);
    }
}


