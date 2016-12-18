#ifndef KEY_H_
#define KEY_H_

#include<iostream>

class Key {
	extern friend void test();
	extern friend void errorDetected(std::string&);
public:
	Key() :value(0) {};
	Key(int val);
	friend bool operator<(const Key& k1, const Key& k2);
	friend bool operator<=(const Key& k1, const Key& k2);
	friend bool operator>(const Key& k1, const Key& k2);
	friend bool operator>=(const Key& k1, const Key& k2);
	friend bool operator==(const Key& k1, const Key& k2);
	friend bool operator!=(const Key& k1, const Key& k2);
	friend std::ostream& operator<<(std::ostream& out, const Key& k);
	friend class TreeNode;
	friend class MSearchTree;
	friend std::ostream& operator<<(std::ostream& out, const TreeNode& t);

private:
	int value;
	friend std::ostream& printNode(std::ostream& out, const TreeNode& node);
};

#endif // !KEY_H_