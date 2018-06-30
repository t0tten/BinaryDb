#ifndef _TREE_H_
#define _TREE_H_

#include <unistd.h>

template <class T>
class Tree {
	private:
		template <class N>
		class Node {
			public:
				static const int LEFT 	= 1;
				static const int RIGHT	= 2;
				static const int NONE 	= 0;
				static const int ERROR	= -1;

				Node<N>* left, * right, * parent;
				N item;

				Node(N item, Node<N>* parent, Node<N>* left = NULL, Node<N>* right = NULL) {
					this->item = item;
					this->parent = parent;
					this->left = left;
					this->right = right;
				}

				~Node() {
					delete this->left;
					delete this->right;
				}
		};

		int iSize;
		Node<T>* root;

	public:
		Tree ();
		~Tree ();

		void add (T item);
		bool remove (T item);
		T find (T item);

		T getMin ();
		T getMax ();

		bool isEmpty ();
		int size ();
		void clear ();
};

template <class T>
Tree<T>::Tree () {
	this->root = NULL;
	this->iSize = 0;
}

template <class T>
Tree<T>::~Tree () {
	this->clear();
}

template <class T>
void Tree<T>::add (T item) {
	this->iSize++;
	if (this->root == NULL) {
		this->root = new Node<T>(item, NULL);
		return;
	}

	Node<T>* walker = this->root;
	while (walker != NULL) {
		if (item > walker->item) {
			if (walker->right == NULL) {
				walker->right = new Node<T>(item, walker);
				break;
			} else {
				walker = walker->right;
			}
		} else {
			if (walker->left == NULL) {
				walker->left = new Node<T>(item, walker);
				break;
			} else {
				walker = walker->left;
			}
		}
	}
}

template <class T>
bool Tree<T>::remove (T item) {
	Node<T>* walker = this->root;

	// Find correct node
	int lastNode = Node<T>::NONE;
	while (walker != NULL && item != walker->item) {
		if (item > walker->item) {
			walker = walker->right;
			lastNode = Node<T>::RIGHT;
		} else if (item < walker->item) {
			walker = walker->left;
			lastNode = Node<T>::LEFT;
		}
	}

	// Node has been found
	if (walker != NULL) {
		
		Node<T>* garbage = walker;

		if (walker->left != NULL && walker->right != NULL) {

			// Save right node
			Node<T>* right = walker->right;

			if (lastNode == Node<T>::LEFT) {
				walker->parent->left = walker->left;
			} else if (lastNode == Node<T>::RIGHT) {
				walker->parent->right = walker->left;
			} else if (lastNode == Node<T>::NONE) {
				this->root = walker->left;
				this->root->parent = NULL;	
			}

			// Find correct spot for right node
			walker = walker->left;
			while (walker->right != NULL) {
				walker = walker->right;
			}
			walker->right = right;

		} else if (walker->left == NULL && walker->right != NULL) {
			if (lastNode == Node<T>::LEFT) {
				walker->parent->left = walker->right;	
			} else if (lastNode == Node<T>::RIGHT) {
				walker->parent->right = walker->right;
			} else if (lastNode == Node<T>::NONE) {
				this->root = walker->right;
				this->root->parent = NULL;
			}
		} else if (walker->left != NULL && walker->right == NULL) {
			if (lastNode == Node<T>::LEFT) {
				walker->parent->left = walker->left;
			} else if (lastNode == Node<T>::RIGHT) {
				walker->parent->right = walker->left;
			} else if (lastNode == Node<T>::NONE) {
				this->root = walker->left;
				this->root->parent = NULL;
			}
		} else {
			if (lastNode == Node<T>::LEFT) {
				walker->parent->left = NULL;
			} else if (lastNode == Node<T>::RIGHT) {
				walker->parent->right = NULL;
			} else if (lastNode == Node<T>::NONE) {
				this->root = NULL;
			}
		}	

		garbage->left = NULL;
		garbage->right = NULL;
		delete garbage;

		this->iSize--;
		return true;	
	}

	return false;
}

template <class T>
T Tree<T>::find (T item) {
	Node<T>* walker = this->root;
	while (walker != NULL) {
		if (item == walker->item) {
			return walker->item;
		} else if (item > walker->item) {
			walker = walker->right;
		} else if (item < walker->item) {
			walker = walker->left;
		}
	}

	throw "No match found.";
}

template <class T>
T Tree<T>::getMin () {
	Node<T>* walker = this->root;
	while (walker->left != NULL) {
		walker = walker->left;
	}
	return walker->item;
}

template <class T>
T Tree<T>::getMax () {
	Node<T>* walker = this->root;
	while (walker->right != NULL) {
		walker = walker->right;
	}
	return walker->item;
}

template <class T>
bool Tree<T>::isEmpty () {
	return this->root == NULL;
}

template <class T>
int Tree<T>::size () {
	return this->iSize;
}

template <class T>
void Tree<T>::clear () {
	if (this->root != NULL) {
		delete this->root;
		this->root = NULL;
	}
	this->iSize = 0;
}

#endif // _TREE_H_
