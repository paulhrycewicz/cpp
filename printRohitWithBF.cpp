template <class T>
/* prints the tree vertically
 * First, a string is generated for each line. Because this results in very wide trees, the second part of the function makes it so that the space between each node is equal to GAP
 *
 * Preconditions:
 * none
 *
 * Postconditions:
 * tree has been printed
 */
/* Created by Rohit Jaganathan for Professor Hrycewicz's CS 21 class on 11/27/2020
 *
 * Prints the tree vertically
 * First, a string is generated for each line. Because this results in very wide trees, the second part of the function makes it so that the space between each node is equal to GAP
 *
 * Preconditions:
 * none
 *
 * Postconditions:
 * tree has been printed
 *
 * Usage:
 *      treename.printRohit();		// treename is the name of a BinarySearchTree object
 *
 *      The BinarySearchTree class must have a tree root (pointer) named treeRoot
 *      A class or struct named Treenode must be used with the following members:
 *           Lchild - pointer to the left subtree
 *           Rchild - pointer to the right subtree
 *           nodeValue - an integer containing the node's key value
 *      When a subtree is null, the pointer must contain nullptr
 */
	template <class T>
	void BSTree<T>::printRohitWithBF(){		// pjh orig width=3 gap=5
	const int WIDTH = 7;		//must be greater than the max characters printed per node; for example, if printing 2 digit numbers, WIDTH should be >= 3
	const int GAP = 4;			//gap between each node
	int height = this->height();
	string lines[height+1];

	//generates a string for each level of the tree
	for(int i=1; i<=height+1; i++){
		string line;
		printRohitWithBFLevel(tRoot, i, i, height, line, WIDTH);
		lines[i-1] = line;
	}

	//removes the unnecessary spaces from the lines
	int space = 0;
	bool allSpace;
	for(unsigned int i=0; i<lines[0].length()-1; i++){	// pjh mod goes until length()-1 from length()
		allSpace = true;
		for(string line: lines){
			if(line.at(i) != ' '){
				allSpace = false;
			}
		}
		if(allSpace){		//every line has a space at this index
			space += 1;
		}
		else{
			if(space > GAP){		//the space is too long and must be reduced to GAP
				for(string& line: lines){
					line.erase(i-space, space-GAP);
				}
				i-= (space-GAP);
			}
			else if(space < GAP && space>0){		//the space is too small and must be expanded to GAP
				string spaces;
				for(int j=0; j< (GAP-space); j++){
					spaces += " ";
				}
				for(string& line: lines){
					line.insert(i-space, spaces);
				}
				i += (GAP-space);
			}
			space = 0;
		}
	}

	//prints out each line
	for(string line: lines){
		cout << line << endl << endl << endl;
	}
}

/* Generates a string for each level for the tree.
 * Recursively reaches the specified level
 * A multiple of WIDTH number of spaces is added before and after each node which is necessary so that everything is lined up correctly. The multiple is determined using powers of 2 based on the relation of level to height
 *
 * Preconditions:
 * node- the node currently being examined; starts with root node
 * x- starts as the level to print; is decreased with each recursion until it becomes one, which means we are at the right level or we reach a null node
 * level- the level to print; does not change with recursion
 * height- the height of the tree
 * print- the string to store the data in; passed by reference
 * WIDTH- the max number of characters of a printed node
 *
 * Postconditions:
 * print now contains the string with this level's nodes
 */
template <class T>
void BSTree<T>::printRohitWithBFLevel(Tnode<T>* node, int x, int level, int height, string& print, const int WIDTH){

	if(node == nullptr){		//this node is empty so generates enough spaces based on which level the node is located on in relation to the level that must be printed and the height of the tree
		for(int i=0; i< WIDTH*pow(2,height+1-level+x); i++)
			print+= " ";
	}
	else if(x == 1){		//the node is on the right level
		for(int i=0; i< WIDTH*(pow(2,height+1-level)); i++)		//space to print before node
			print+= " ";
		int val = node->nodeValue;
		string value = to_string(val);
		print+= value;
		int bal = node->balance;				// start pjh mods
		string baln = to_string (bal);
		print+= "(";
		print+= baln;
		print+= ")";							// end pjh mods
		for(unsigned int i=0; i< (WIDTH-value.length()); i++)		//if the width of the node is less than WIDTH, prints spaces
			print+= " ";
		for(int i=0; i< WIDTH*(pow(2,height+1-level)-1); i++)		//space to print after node
			print+= " ";
	}
	else{
		printRohitWithBFLevel(node->Lchild, x-1, level, height, print, WIDTH);
		printRohitWithBFLevel(node->Rchild, x-1, level, height, print, WIDTH);

	}
}
