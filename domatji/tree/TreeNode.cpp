#include"TreeNode.h"

TreeNode::TreeNode(int m) {
	M = m;
	for (int i = 0; i < M + 1; i++) {
		if (i < M)
			keys.push_back(Key(0));
		ptr.push_back(nullptr);
	}
}

TreeNode::TreeNode(const TreeNode& obj) {
	M = obj.M;
	for (int i = 0; i < M + 1; i++) {
		if (i < M)
			keys.push_back(obj.keys.at(i));
		ptr.push_back(nullptr);
	}
}

bool TreeNode::add(const Key& k) {
	//if (this->contains(k)) errorDetected("TreeNode::add: Dati kljuch vetj postoji u chvoru")
	if (this->isFull())
		return false;
	else {
		if (this->isEmpty()) {
			keys.at(0) = k;
			return true;
		}
		for (int i = 0; i < M; i++) {
			if ((k < keys.at(i)) || (keys.at(i).value == 0))
				if (i < M - 1) {
					Key pom1 = keys.at(i);
					for (int j = i + 1; j < M; j++) {
						Key pom2 = keys.at(j);
						keys.at(j) = pom1;
						pom1 = pom2;
					}
					keys.at(i) = k;
					return true;
				}
				else {
					keys.at(i) = k;
					return true;
				}
		}
	}
}

bool TreeNode::isFull() const {
	if (keys.at(M - 1).value > 0)
		return true;
	else
		return false;
}

bool TreeNode::isEmpty() const {
	//if (this == nullptr)
		if (keys.at(0).value == 0)
			return true;
	else
		return false;
}

std::vector<Key> TreeNode::getKeys() const {
	return keys;
}

TreeNode* TreeNode::getLeftSubtree(const Key& k) const {
	if (!this->contains(k)) {
		std::string s = "TreeNode::getLeftSubtree:Zadati kljuch se ne nalazi u chvoru";
		errorDetected(s);
	}
	for (int i = 1; i < M + 1; i++)
		if (keys.at(i - 1) == k)
			return ptr.at(i - 1);
}
TreeNode* TreeNode::getRightSubtree(const Key& k) const {
	if (!this->contains(k)) {
		std::string s = "TreeNode::getRightSubtree: Zadati kljuch se ne nalazi u chvoru";
		errorDetected(s);
	}
	for (int i = 1; i < M + 1; i++)
		if (keys.at(i - 1) == k)
			return ptr.at(i);
}

Key TreeNode::getMaxKey() const {
	if (this->isEmpty()) {
		std::string s = "TreeNode::getMaxKey: Chvor je prazan";
		errorDetected(s);
	}
	else {
		for (int i = 0; i < M; i++)
			if (keys.at(i) == 0)
				return keys.at(i - 1);
		return keys.at(M - 1);
	}
}

Key TreeNode::getMinKey() const {
	if (this->isEmpty()) {
		std::string s = "TreeNode::getMinKey: Chvor je prazan";
		errorDetected(s);
	}
	else
		return keys.at(0);
}

bool TreeNode::contains(const Key& k) const {
	if (this->isEmpty())
		return false;
	for (int i = 0; i < M; i++)
		if (keys.at(i) == k) {
			return true;
		}
	return false;
}

TreeNode* TreeNode::getSubtree(const Key& k) const {
	if (this->contains(k)) {
		std::string s = "TreeNode::getSubtree: Kljuch se nalazi u chvoru, umesto u podchvoru";
		errorDetected(s);
	}
	else if (this->isEmpty()) {
		std::string s = "TreeNode::getSubtree: Chvor je prazan, nema podchvorove";
		errorDetected(s);
	}
	/*else if (!this->isFull()) {
		std::string s = "TreeNode::getSubtree: Chvor nije pun, nema podchvorove";
		errorDetected(s);
	}*/
	else {
		if (k < keys.at(0))
			return this->getLeftSubtree(keys.at(0));
		for (int i = 0; i < M - 1; i++) {
			if ((k > keys.at(i)) && (k < (keys.at(i + 1))))
				return this->getRightSubtree(keys.at(i));
		}
		if (k > keys.at(M - 1))
			return this->getRightSubtree(keys.at(M - 1));
	}
}

bool TreeNode::setSubtree(const Key& k, TreeNode* subnode) {
	if (this->contains(k))
		return false;
	else
		if (this->getSubtree(k) != nullptr)
			return false;
		else {
			if (k < keys.at(0)) {
				ptr.at(0) = subnode;
				return true;
			}
			for (int i = 1; i < M; i++) {
				if ((k > keys.at(i - 1)) && (k < (keys.at(i)))) {
					ptr.at(i) = subnode;
					return true;
				}
			}
			if (k > keys.at(M - 1)) {
				ptr.at(M) = subnode;
				return true;
			}
		}
}

bool TreeNode::remove(const Key& k) {
	if (this->contains(k)) {
		for (int i = 1; i < M + 1; i++) {
			if (keys.at(i - 1) == k) {
				if ((!this->getLeftSubtree(k)) && (!this->getRightSubtree(k))) {
					for (int j = i; j < M + 1; j++) {
						if (j < M)
							keys.at(j - 1) = keys.at(j);
						ptr.at(j - 1) = ptr.at(j);
					}
					keys.at(M - 1) = 0;
					ptr.at(M) = nullptr;
					return true;
				}
				/*else {
				keys.at(i - 1).value = 0;
				return true;
				}*/
			}
		}
	}
	else
		return false;
}

std::ostream& operator<<(std::ostream& out, const TreeNode& t) {
	out << "(";
	for (int i = 0; i < t.M; i++) {
		if (i == 0)
			if (t.getLeftSubtree(t.keys.at(i)) != nullptr)
				operator<<(out, *t.getLeftSubtree(t.keys.at(i)));
		if (i < t.M - 1) {
			out << t.keys.at(i);
			if (t.keys.at(i + 1).value != 0)
				out << ", ";
		}
		else
			out << t.keys.at(i);
		if (t.getRightSubtree(t.keys.at(i)) != nullptr)
			operator<<(out, *t.getRightSubtree(t.keys.at(i)));
	}
	out << ").";
	return out;
}

TreeNode::~TreeNode() {

}