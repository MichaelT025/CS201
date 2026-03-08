/*
Name: Michael Tesfaye
Email:mktesfaye@crimson.ua.edu
Course Section: Spring 2026 CS 201 – 002    
Homework #:2
To Compile: g++ STMain.cpp -o STMain
To Run: ./STMain
*/


#ifndef _ST_HPP_
#define _ST_HPP_

#include <utility>

#include "RBT.hpp"
#include "RBTPrint.hpp"
#include <iostream>
#include <functional>
#include <vector>


template <class Key, class Type>
class ST : public RedBlackTree<Key, Type> {
public:
	typedef RBTNode<Key, Type>* iterator;

	// Constructors
	// constant
	ST() : nodeCount(0) {
	}

	// Destructor
	// linear in the size of the ST
	~ST() {
		this->DeleteTree(this->root);
		this->root = nullptr;
		nodeCount = 0;
	}

	// access or insert specifies element
	// inserts if the key is not present and returns a reference to
	// the value corresponding to that key
	// O(LogN), N size of ST
	Type& operator[](const Key& key) {
		iterator found=this->find(key);
		if(found) return found->value;
		else{
			iterator newNode= this->Insert(key, Type());
			nodeCount++;
			return newNode->value;
		}
	}; 

	// insert a (key, value) pair, if the key already exists
	// set the new value to the existing key
	// O(LogN), N size of ST
	void insert(const Key& key, const Type& value) {
		iterator exists=this->Search(key);
		//check if exists, if so update value
		if(exists) exists->value=value;
		else{ //otherwise insert new node
			this->Insert(key, value);
			nodeCount++;
		}
	};

	// remove element at the given position
	// amortized constant
	void remove(iterator position) {
		if(!position) return;
		this->RemoveNode(position);
		nodeCount--;
	};

        // remove element with keyvalue key and 
	// return number of elements removed (either 0 or 1)
	// O(logN), N size of ST
	std::size_t remove(const Key& key) {
		if(this->Remove(key)) {
			nodeCount--;
			return 1;
		}
		return 0;
	};  

	// removes all elements from the ST, after this size() returns 0
	// linear in the size of the ST
	void clear() {
		this->DeleteTree(this->root);
		this->root = nullptr;
		nodeCount = 0;
	}; 

	// checks if ST has no elements; true is empty, false otherwise
	// constant
	bool empty() const {
		if (!this->root) return true;
		return false;
	}; 

	// returns number of elements in ST
	// constant
	std::size_t size() const {	
		return nodeCount;
	}; 

	// returns number of elements that match keyvalue key
	// value returned is 0 or 1 since keys are unique
	// O(LogN), N size of ST
	std::size_t count(const Key& key) {
		return this->Search(key)? 1:0;
	}; 

	// find an element with keyvalue key and return 
	// the iterator to the element found, nullptr if not found
	// O(LogN), N size of ST
	iterator find(const Key& key) {
		iterator found=this->Search(key);
		return found;
	};

	// check if key exists in ST
	// O(LogN), N size of ST
	bool contains(const Key& key) {
		return this->find(key)? true:false;
	};

        // return contents of ST as a vector of (key,value) pairs
        // O(N), N size of ST
        std::vector<std::pair<Key, Type> > toVector() {
			std::vector<std::pair<Key, Type>> result;
			std::function<void (RBTNode<Key, Type>*)> inorder=[&](RBTNode<Key, Type>* node){
				if(!node) return;
				inorder(node->left);
				result.push_back({node->key, node->value});
				inorder(node->right);
			};
			inorder(this->root);
			return result;
		};

	// print the symbol table as Red-Black Tree
	// O(N), N size of ST
	void displayTree() {
		std::cout << RBTPrint<Key,Type>::TreeToString(RedBlackTree<Key,Type>::root) << std::endl;
	};

	// print the symbol table in sorted order
	// O(N), N size of ST
	void display() {
		std::vector<std::pair<Key, Type>> table=toVector();
		for(const auto &it: table){
			std::cout<<it.first<<": "<<it.second<<std::endl;
		}
	};

private:
	std::size_t nodeCount;

};

#endif

