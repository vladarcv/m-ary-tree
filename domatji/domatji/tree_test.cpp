#include<iostream>
#include<vector>
#include"Key.h"
#include"TreeNode.h"
#include"MSearchTree.h"
#include<string>

#define STUDENT_TEST
#if !defined (STUDENT_TEST) && !defined (PROF_TEST)

void test();

#elif defined (STUDENT_TEST) && !defined (PROF_TEST)

void test() {
	Key k1(5), k2(12), k3, k4(7), k5(32), k6(25), k7(1), k8(12), kmax, kmin, k9(14), k10(30);
	/*bool f, f1, e, e1, c;
	std::vector<Key> kljuchevi;
	if (k3 < k1)
		std::cout << "k3 je manje od k1" << std::endl;
	//else
	//	std::cout << "k2 nije manje" << std::endl;
	if (k3 <= k1)
		std::cout << "k3 je manjeJednako k1" << std::endl;
	if (k2 > k1)
		std::cout << "k2 je vetje od k1" << std::endl;
	if (k1 == k4)
		std::cout << "k1 je jednako k4" << std::endl;
	if (k2 != k3)
		std::cout << "k2 je razlichito od k3" << std::endl;
	if (k1 <= k4)
		std::cout << " k1 <<  je manjejednako << k4 " << std::endl;
	std::cout << k1;
	std::cout << std::endl;

	TreeNode chvor1(3), chvor2(3), *chvor3 = new TreeNode(3), *chvor4 = new TreeNode(3);
	f = chvor1.isFull();
	e = chvor1.isEmpty();
	chvor1.add(k7);
	chvor1.add(k5);
	chvor1.add(k2);
	kmax = chvor1.getMaxKey();
	kmin = chvor1.getMinKey();
	chvor2.add(k6);
	chvor2.add(k10);
	f1 = chvor1.isFull();
	e1 = chvor1.isEmpty();
	chvor1.add(k7);
	kljuchevi = chvor1.getKeys();
	c = chvor1.contains(k8);
	kmax = chvor1.getMaxKey();
	kmin = chvor1.getMinKey();
	chvor1.setSubtree(k6, &chvor2);
	chvor3 = chvor1.getRightSubtree(k2);
	chvor4 = chvor1.getSubtree(k6);
	//chvor1.remove(k8);
	std::cout << chvor1;
	std::cout << chvor2;
	std::cout << std::endl;*/

	MSearchTree stablo(3), *stablo2 = new MSearchTree(3);
	bool ima1, ima2;
	Key k40(40), k50(50), k60(60), k70(70), k80(80), k90(90), k95(95), k96(96), k97(97), k100(100), k102(102), k107(107), k109(109), k110(110), k120(120), k130(130), k140(140), k150(150), k160(160);
	stablo.insert(k110);
	std::cout << "stablo: " << std::endl;
	std::cout << stablo;
	std::cout << std::endl;
	stablo.insert(k70);
	std::cout << "stablo, posle dodavanja kljucha '70': " << std::endl;
	std::cout << stablo;
	std::cout << std::endl;
	stablo.insert(k130);
	std::cout << "stablo, posle dodavanja kljucha '130': " << std::endl;
	std::cout << stablo;
	std::cout << std::endl;
	stablo.insert(k160);
	std::cout << "stablo, posle dodavanja kljucha '160': " << std::endl;
	std::cout << stablo;
	std::cout << std::endl;
	stablo.insert(k50);
	std::cout << "stablo, posle dodavanja kljucha '50': " << std::endl;
	std::cout << stablo;
	std::cout << std::endl;
	stablo.insert(k40);
	std::cout << "stablo, posle dodavanja kljucha '40': " << std::endl;
	std::cout << stablo;
	std::cout << std::endl;
	stablo.insert(k80);
	std::cout << "stablo, posle dodavanja kljucha '80': " << std::endl;
	std::cout << stablo;
	std::cout << std::endl;
	stablo.insert(k7);//k7=1
	std::cout << "stablo, posle dodavanja kljucha '1': " << std::endl;
	std::cout << stablo;
	std::cout << std::endl;
	stablo.insert(k95);
	std::cout << "stablo, posle dodavanja kljucha '95': " << std::endl;
	std::cout << stablo;
	std::cout << std::endl;
	stablo.insert(k97);
	std::cout << "stablo, posle dodavanja kljucha '97': " << std::endl;
	std::cout << stablo;
	std::cout << std::endl;
	stablo.insert(k90);
	std::cout << "stablo, posle dodavanja kljucha '90': " << std::endl;
	std::cout << stablo;
	std::cout << std::endl;
	stablo.insert(k96);
	std::cout << "stablo, posle dodavanja kljucha '96': " << std::endl;
	std::cout << stablo;
	std::cout << std::endl;
	stablo.insert(k100);
	std::cout << "stablo, posle dodavanja kljucha '100': " << std::endl;
	std::cout << stablo;
	std::cout << std::endl;
	stablo.insert(k109);
	std::cout << "stablo, posle dodavanja kljucha '109': " << std::endl;
	std::cout << stablo;
	std::cout << std::endl;
	stablo.insert(k107);
	std::cout << "stablo, posle dodavanja kljucha '107': " << std::endl;
	std::cout << stablo;
	std::cout << std::endl;
	stablo.insert(k102);
	std::cout << "stablo, posle dodavanja kljucha '102': " << std::endl;
	std::cout << stablo;
	std::cout << std::endl;

	std::cout << "stablo: " << std::endl;
	std::cout << stablo;
	std::cout << std::endl;
	ima1 = stablo.lookup(k130);
	ima2 = stablo.lookup(k5);

	/*std::cout << "stablo: " << std::endl;
	std::cout << stablo;
	std::cout << std::endl;
	ima1 = stablo.lookup(k130);
	ima2 = stablo.lookup(k5);*/

	stablo.remove(k97);
	std::cout << "stablo, posle brisanje kljucha '97': " << std::endl;
	std::cout << stablo;
	std::cout << std::endl;
	stablo.remove(k110);
	std::cout << "stablo, posle brisanje kljucha '110': " << std::endl;
	std::cout << stablo;
	std::cout << std::endl;
	stablo.remove(k80);
	std::cout << "stablo, posle brisanje kljucha '80': " << std::endl;
	std::cout << stablo;
	std::cout << std::endl;
	stablo.remove(k90); 
	std::cout << "stablo, posle brisanje kljucha '90': " << std::endl;
	std::cout << stablo;
	std::cout << std::endl;
	stablo.remove(k7);
	std::cout << "stablo, posle brisanje kljucha '1': " << std::endl;
	std::cout << stablo;
	std::cout << std::endl;

	stablo.remove(k40);
	std::cout << "stablo, posle brisanje kljucha '40': " << std::endl;
	std::cout << stablo;
	std::cout << std::endl;
	stablo.remove(k96);
	std::cout << "stablo, posle brisanje kljucha '96': " << std::endl;
	std::cout << stablo;
	std::cout << std::endl;
	stablo.remove(k70);
	std::cout << "stablo, posle brisanje kljucha '70': " << std::endl;
	std::cout << stablo;
	std::cout << std::endl;
	stablo.remove(k95);
	std::cout << "stablo, posle brisanje kljucha '95': " << std::endl;
	std::cout << stablo;
	std::cout << std::endl;
	stablo.remove(k107);
	std::cout << "stablo, posle brisanje kljucha '107': " << std::endl;
	std::cout << stablo;
	std::cout << std::endl;
    stablo.remove(k102);
	std::cout << "stablo, posle brisanje kljucha '102': " << std::endl;
	std::cout << stablo;
	std::cout << std::endl;

	stablo.remove(k110);
	stablo.remove(k130);
	stablo.remove(k160);
	std::cout << "stablo, posle brisanje kljucha '110','130','160': " << std::endl;
	std::cout << stablo;
	std::cout << std::endl;

	stablo.remove(k50);
	std::cout << "stablo, posle brisanje kljucha '50': " << std::endl;
	std::cout << stablo;
	std::cout << std::endl;
	stablo.remove(k109);
	std::cout << "stablo, posle brisanje kljucha '109': " << std::endl;
	std::cout << stablo;
	std::cout << std::endl;

	stablo.remove(k100);
	std::cout << "stablo, posle brisanje kljucha '100': " << std::endl;
	std::cout << stablo;
	std::cout << std::endl;

	/*stablo.remove(k102);
	stablo.remove(k102);
	stablo.remove(k102);
	stablo.remove(k102);
	std::cout << "stablo, posle brisanje kljucha '97': " << std::endl;
	std::cout << stablo;
	std::cout << std::endl;*/

	/*MSearchTree stablo1 = stablo;
	//*stablo2 = stablo;
	MSearchTree stablo3(stablo);
	stablo3.insert(k100);
	std::cout << "stablo3: " << std::endl;
	std::cout << stablo3;
	std::cout << std::endl;
	std::cout << "stablo: " << std::endl;
	std::cout << stablo;
	std::cout << std::endl;
	stablo1.insert(k120);
	std::cout << "stablo1: " << std::endl;
	std::cout << stablo1;
	std::cout << std::endl;
	std::cout << "stablo: " << std::endl;
	std::cout << stablo;
	std::cout << std::endl;

	stablo.remove(k95);
	std::cout << "stablo, posle izbacivanja k95: " << std::endl;
	std::cout << stablo;
	std::cout << std::endl;

	/*stablo.~MSearchTree();
	std::cout << "stablo: " << std::endl;
	std::cout << stablo;
	std::cout << std::endl;*/
}

void errorDetected(std::string& msg) {
	std::cout << msg;
	getchar();
	exit(1);
}

#endif
#if defined(PROF_TEST)
void test();
#endif
int main() {
	test();
	getchar();
	return 0;
}