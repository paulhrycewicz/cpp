Binary Search Tree print function

Displays a BST as follows:

                                                      60                                      


                                 50                          70                               


     30                                 53                                        80          


                   35                          57                   75                        


            32            40                                               77   


Developed by Rohit Jaganathan, Novemner 2020, as an extra credit development effort 
for CS20, Las Positas College, Livermore, CA.  Implemented as a recursive level-order traversal.

The spacing between nodes can be varied to adjust for large and small trees; refer to the
code documentation for details.

Implemented as a pair of member functions for a class named BinarySearchTree.  
	printRohit is callable by the user via
		treename.printRohit();   where treename is the name of a BinarySearchTree object
	printRohitLevel is internal and can be private.

The functions are templated, but the template can be removed if class BinarySearchTree 
is not templated.

It's assumed that the BST nodes are described by a class named Treenode with these members:

	Lchild - pointer to the left subtree
	Rchild - pointer to the right subtree 
 	nodeValue - an integer containing the node's key value

It's also assumed that BinarySearchTree contains a member named treeRoot which contains a
pointer to the root node.