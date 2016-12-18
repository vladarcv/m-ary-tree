#ifndef TREENODE_H_
#define TREENODE_H_

#include<vector>
#include"Key.h"

class TreeNode {
	extern friend void test();
	extern friend void errorDetected(std::string&);
public:
	TreeNode(int m);
	TreeNode(const TreeNode& obj);
	bool add(const Key& k);
	bool isFull() const;
	bool isEmpty() const;
	std::vector<Key> getKeys() const;
	TreeNode* getLeftSubtree(const Key&) const;
	TreeNode* getRightSubtree(const Key&) const;
	Key getMaxKey() const;
	Key getMinKey() const;
	bool contains(const Key& k) const;
	TreeNode* getSubtree(const Key& k) const;
	bool setSubtree(const Key& k, TreeNode* subnode);
	bool remove(const Key& k);
	friend std::ostream& operator<<(std::ostream& out, const TreeNode& t);
	~TreeNode();
	friend class MSearchTree;
	friend std::ostream& operator<<(std::ostream& out, const MSearchTree& mst);

private:
	int M;
	std::vector<Key> keys;
	std::vector<TreeNode*> ptr;
	friend std::ostream& printNode(std::ostream& out, const TreeNode& node);
};

#endif // !TREENODE_H_