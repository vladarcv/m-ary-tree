#include"MSearchTree.h"

MSearchTree::MSearchTree(int m = 1) {
	root = new TreeNode(m);
}

MSearchTree::MSearchTree(const MSearchTree& obj) {
	root = copyNode(obj.root);
}

TreeNode* MSearchTree::copyNode(const TreeNode* node) {
	if (node == nullptr)
		return nullptr;
	TreeNode* newNode = new TreeNode(node->M);
	*newNode = TreeNode(*node);
	for (int i = 0; i < node->M + 1; i++)
		if (node->ptr.at(i) != nullptr)
			newNode->ptr.at(i) = copyNode(node->ptr.at(i));
	return newNode;
}

MSearchTree& MSearchTree::operator=(const MSearchTree& other) {
	if (other.root == nullptr)
		this->root = nullptr;
	return *this;
	MSearchTree* tree = new MSearchTree(other.root->M);
	tree->root = other.root;
	for (int i = 0; i < other.root->M + 1; i++) {
		if (other.root->ptr.at(i) != nullptr)
			tree->root->ptr.at(i) = copyNode(other.root->ptr.at(i));
	}
	return *tree;
}

MSearchTree& MSearchTree::operator=(MSearchTree&& other) {
	//ovo ne radi, ne razumem shta treba  ovaj opearator da radi
	return *this;
}

bool MSearchTree::insert(const Key& k) {
	return insert(root, k);
}

bool MSearchTree::insert(TreeNode* node, const Key& k) {
	if (node->contains(k))
		return false;
	else if (!node->isFull()) {
		node->add(k);
		return true;
	}
	else if (!node->getSubtree(k)) {
		TreeNode* trn = new TreeNode(node->M);
		node->setSubtree(k, trn);
		insert(node->getSubtree(k), k);
	}
	else
		insert(node->getSubtree(k), k);
}

bool MSearchTree::lookup(const Key& k) const {
	return lookup(root, k);
}

bool MSearchTree::lookup(TreeNode* node, const Key& k) const {
	if (node->contains(k))
		return true;
	else if (node->getSubtree(k))
		lookup(node->getSubtree(k), k);
	else
		return false;
}

void MSearchTree::traverse(Traversal& t) {
	//t.visit(root);
}

bool MSearchTree::remove(const Key& key) {
	if (!this->lookup(key))
		return false;
	else
		return remove(root, key, nullptr, 0);
}

bool MSearchTree::remove(TreeNode* node, const Key& key, TreeNode* previousNode, const Key& previousKey) {
	if (node->contains(key)) {
		int i = -1;
		while (node->keys.at(++i) != key);
		if (node->keys.at(i) == key)
			if (node->getRightSubtree(key)) {//prva izbor, pita dali postoji desno podstablo
				Key pom = getMinKeyTree(node->getRightSubtree(key));//ako postoji,trazhi minumum u tom podstablu i dodeljuje pomotjnoj pormoneljivoj pom tipa key
				remove(node->getRightSubtree(key), pom, node, key); //i onda poziva unishtenje minimalnog klucha u desnom podstablu
				node->keys.at(i) = pom;// kada se vrati iz rekurzije upisuje pomotjnu na mesto koje je trebalo izbrisati
			}
			else if (node->getLeftSubtree(key)) {
				Key pom = getMaxKeyTree(node->getLeftSubtree(key));
				remove(node->getLeftSubtree(key), pom, node, key);
				node->keys.at(i) = pom;
			}//radis sve isto kao prethodno samo za levu stranu, i umesto minimuma trazhi se maksimum u podstablu
			else if (i < node->M - 1) {//ako nema ni levog ni desnog podstabla i ako je indeks i nije na poslednjem mestu
				if (node->keys.at(i + 1) == 0) {// ako je sledetji kljuch u chvoru 0, tj. trenutni kljuch je zadnji 
					bool right = false;//odredjujivanje da li za prethodni chovr u predhodnom kljuchu treba da idemo desno ili levo,
					bool left = false; //odredjujivanje da li za prethodni chovr u predhodnom kljuchu treba da idemo desno ili levo,
					if (previousNode) {//samo ako nije pochetni chvor
						if (previousKey != 0) {//mera predostrozhnosti, da nebi prosledio 0 kao kljuch Treenode metodama
							if (previousNode->getRightSubtree(previousKey))//odredjivanje da li treba da unishtava levo ili desno podstablo u prethodnom nodu za predhhodni kljuch
								if (previousNode->getRightSubtree(previousKey)->contains(key))
									right = true;
							if (previousNode->getLeftSubtree(previousKey))
								if (previousNode->getLeftSubtree(previousKey)->contains(key))
									left = true;//odrjedjivanje da li treba da unishti levo ili desono podstabko u prethodnom nodu za predhhodni kljuch
						}
						node->keys.at(i) = 0;//trenutni kljuch se brishe
						if (node->isEmpty()) { // ako je trenutni kljuch bio prvi unutar chvora, i chvor postane prazan posle brisanja, mora da se odvezhe iz stabla
							int j = -1;
							while (previousNode->keys.at(++j) != previousKey);// pozicioniram prethodni kluch u predhodnom chvoru
							if (right) // ako je za prethodni kluch u predhodnom chvoru, oderedjena da desni pokazivach pokazije na sada prazan chvor
								if (previousNode->getRightSubtree(previousKey) != nullptr)//zashtita da se ne prosledi nullptr TreeNode metodi
									if (previousNode->getRightSubtree(previousKey)->isEmpty()) // ako je desni podchvor postoji i ako je prazn i ako je podvrdjeno da bash desna strana pokazuje na nod koji treba da unishtimo(bool right) 
										previousNode->ptr.at(++j) = nullptr;//onda izmezujemo prazan chvor tako shto prethodnom chvor u predhodni kljuch na denom pokazivachu upisujemo nullptr
							if (left)
								if (previousNode->getLeftSubtree(previousKey) != nullptr)
									if (previousNode->getLeftSubtree(previousKey)->isEmpty())
										previousNode->ptr.at(j) = nullptr;//sve isto kao za desnu stranu, ponovljenu za sluchaj kada se pokazalo da levi pokazivach pokazuje na chvor koji treba izbrisati
						}
					}
					else {// ovo je sluchaj kada treba da se izbrishe kljuch, a predhodni chvor ne postoji, tj, kada se radi o korenu stabla
						node->keys.at(i) = 0; 
						if (node->isEmpty())// ako je koren stabla prazna posle brisanja ljucha
							this->root = nullptr; //koren postavljama na nullptr, tj stablo postaje prazno
					}// ovo je sluchaj kada treba da se izbrishe kluch, a predhodni chvor ne postoji, tj, kada se radi o korenu stabla
					return true;// kada je doshao do poslednjeg sluchaja poziva rekurzije i odradio uklanjanja zadnjeg, funkcija vratja true i pochinje da se vratja u ranije pozive
				}
				else if (node->keys.at(i + 1) != 0) {// sluchaj kada ne posotje ni levo ni desno podstablo, ali postoji desni kljuch u chvoru
					Key pom = node->keys.at(i + 1); //pomotjini kljuch je sledetji iz chvora
					TreeNode* pomptr = node->ptr.at(i + 2);// pomotjni pokazaivac na chvor je  je desni pokazivach sledetjeg klucha
					remove(node, pom, node, key);// poziva se uklanjanja sledetjeg
					node->ptr.at(i + 2) = nullptr;// desni pokazivach, desnog klucha se postavlja na nulu
					node->keys.at(i) = pom;//kada se vrati treutnom kljuchu dodeljuje pomottjni, tj sledetji, koji je sada vetj uklonjen
					if (pomptr/*node->ptr.at(i + 1)*/)//ako je pomotjni pokazivach razlichit od nullptr, u kome je sachuvan desni pokazivac sldetjeg kljucha
						node->ptr.at(i + 1) = pomptr; //upisujemo ga u desni pokazivach trenutnog klucha
				}
			}
			else {// ako je kluch poslednji u chvoru, i nema ni levo ni desno podstablo, onda se on samo jednostavno postavlja na 0
				node->keys.at(i) = 0;
				return true;
			}// ako je kluch poslednji u chvoru, i nema ni levo ni desno podstablo, onda se on samo jednostavno postavlja na 0
	}
	else {//odredjivanje prethodnog klucha ako nije prosledjen  od prethodne rekurzivne funkcije
		Key pom;// tje predstavljati prethondi kljuch u prethodnom nodu pri pozivu rekurzije
		int i = -1;
		while (pom == 0) {//dok god je pomotjni kljuch nula , ponavlja se
			i++;
			if (node->getRightSubtree(node->keys.at(i))) {//zashtita da se TreeNode metodi ne dodeli nullptr, ili pitanje dali postoji desno podstablo na mestu kljucha sa indekosm i
				if (node->getRightSubtree(node->keys.at(i))->contains(key))//ako postoji i ako sadrzhi kluch key
					pom = node->keys.at(i);//onda pom postaje key od i
				else// ako podstablo ne sadrzhi key, oda ispituje da li se key nalazi mozhda izmedju dva kljucha  podstabla
					for (int j = 0; j < node->M - 1; j++)
						if ((node->getRightSubtree(node->keys.at(i))->keys.at(j) < key) && (key < node->getRightSubtree(node->keys.at(i))->keys.at(j + 1)))
							pom = node->keys.at(i);// ako se nalazi onda pom dobija vrednost key od i
			}//dakle pom tje dobiti vrednost key od i, ako desno podstablo sadrzhi key ili  se key nalazi izmedju ddva kljucha desnog podtsbla 
			if (pom == 0)
				if (node->getLeftSubtree(node->keys.at(i)))
					if (node->getLeftSubtree(node->keys.at(i))->contains(key))
						pom = node->keys.at(i);
					else
						for (int j = 0; j < node->M - 1; j++)
							if ((node->getLeftSubtree(node->keys.at(i))->keys.at(j) < key) && (key < node->getLeftSubtree(node->keys.at(i))->keys.at(j + 1)))
								pom = node->keys.at(i);// sve ono gore isto samo ponovljeno za levu stranu
		}//odredjivanje prethodnog klucha ako nije prosledjen  od prethodne rekurzivne funkcije
		return remove(node->getSubtree(key), key, node, pom);//ako trenutni chvor  ne sadrzhi dati kljuch kljuch, nalazi se koji chvor sadzizhi i poziva se rekurzija za taj chvor, takodje se prosledjuje trenutni node kao prethodnik, i pom key kao prethodni kjuch
	}  //prethodni node i prehodni kljuch se koriste pri odvezivanju praznih chvorova
}

TreeNode* MSearchTree::getNode(TreeNode* node, const Key& key) const {//nije koristjeno , iako sam mislio da tje mi trebati
	if (!node->contains(key))
		getNode(node->getSubtree(key), key);
	else
		return node;
}                                                                     //nije koristjeno , iako sam mislio da tje mi trebati

/*MSearchTree::MSearchTree(TreeNode* trnptr) {
	root = trnptr;
}*/

std::ostream& operator<<(std::ostream& out, const MSearchTree& mst) {
	if ((mst.root == nullptr) || (mst.root->isEmpty()))
		out << "Stablo ne postoji";
	else
		return printNode(out, *mst.root);
}

std::ostream& /*MSearchTree::*/printNode(std::ostream& out, const TreeNode& node) {
	out << "(";
	for (int i = 0; i < node.M; i++) {
		if (i == 0)
			if (node.getLeftSubtree(node.keys.at(i)) != nullptr) {
				printNode(out, *node.getLeftSubtree(node.keys.at(i)));
				out << ",";
			}
		if (i < node.M - 1) {
			out << node.keys.at(i);//ako nije zadnji
			if ((node.keys.at(i + 1).value == 0) && (!node.getRightSubtree(node.keys.at(i))))//ako je desni kljuch nula i ako desno podstablo ne postoji
				out << "";
			else
				out << ",";
		}
		else {
			out << node.keys.at(i);
			if (node.getRightSubtree(node.keys.at(i)))
				out << ",";
		}
		if (node.getRightSubtree(node.keys.at(i)) != nullptr) {
			printNode(out, *node.getRightSubtree(node.keys.at(i)));
			if (i < node.M - 1)
				out << ",";
			else
				out << "";
		}
	}
	out << ")";
	return out;
}

const Key& MSearchTree::getMaxKeyTree()const {
	return getMaxKeyTree(root);
}

Key& MSearchTree::getMaxKeyTree(TreeNode* node) const {
	if (node->getRightSubtree(node->getMaxKey()))
		getMaxKeyTree(node->getRightSubtree(node->getMaxKey()));
	else
		return node->getMaxKey();
}

const Key& MSearchTree::getMinKeyTree()const {
	return getMinKeyTree(root);
}

Key& MSearchTree::getMinKeyTree(TreeNode* node) const {
	if (node->ptr.at(0)/*getLeftSubtree(node->getMinKey())*/)
		getMinKeyTree(node->ptr.at(0)/*getLeftSubtree(node->getMaxKey())*/);
	else
		return node->keys.at(0)/*getMinKey()*/;
}

void MSearchTree::clearNode(TreeNode*& node) {
	if (node == nullptr)
		return;
	for (int i = 0; i < node->M + 1; i++)
		if (node->ptr.at(i) != nullptr)
			clearNode(node->ptr.at(i));
	node = nullptr;
}

MSearchTree::~MSearchTree() {
	clearNode(root);
}