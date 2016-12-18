#ifndef MSEARCHTREE_H_
#define MSEARCHTREE_H_

#include"key.h"
#include"TreeNode.h"
#include<iostream>

class MSearchTree {
	extern friend void test();
	extern friend void errorDetected(std::string&);
public:
	MSearchTree(int m);
	MSearchTree(const MSearchTree& obj);
	MSearchTree& operator=(const MSearchTree& other);
	MSearchTree& operator=(MSearchTree&& other);
	bool insert(const Key& k);
	bool lookup(const Key&) const;
	friend class Traversal;
	void traverse(Traversal& t);
	bool remove(const Key& key);
	friend std::ostream& operator<<(std::ostream& out, const MSearchTree& mst);
	extern friend void test();
	extern friend void errorDetected(std::string&);
	~MSearchTree();

private:
	TreeNode* root;
	//Key max;
	bool insert(TreeNode* node, const Key& k);
	bool lookup(TreeNode* node, const Key&) const;
	TreeNode* copyNode(const TreeNode* node);
	bool remove(TreeNode* node, const Key& key, TreeNode* PreviousNode, const Key& previosKey);
	TreeNode* getNode(TreeNode* node, const Key& key)const;//nije korishtjeno, iako sam mislio da tje trebati
	friend std::ostream& printNode(std::ostream& out, const TreeNode& node);
	//MSearchTree(TreeNode* trnptr);
	const Key& getMaxKeyTree()const;
	Key& getMaxKeyTree(TreeNode* node)const;
	const Key& getMinKeyTree()const;
	Key& getMinKeyTree(TreeNode* node)const;
	void clearNode(TreeNode*& node);
};

#endif // !MSEARCHTREE_H_