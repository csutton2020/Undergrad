/* Olivia liepa
 * chris sutton
 * cisc220 032L
 */


#include "AVLTree.h"
using namespace std;

AVLTree::AVLTree() {
    // constructor, sets AVLflag to false
    AVLflag = false;
    root = NULL;

}

AVLTree::AVLTree(bool flag) {
    // constructor, sets AVLflag to flag
    root = NULL;
    AVLflag = flag;

}

void AVLTree::addNode(Z_Obj *n, ZNode *r) {
    // adds a new node to the tree. It starts
    // traversing the tree at r
    // if you donít do this recursively, you donít need
    // the ZNode field.

    if (AVLflag == false) {
        addHelper3(n, r); // if just a search tree
    } else if (AVLflag == true) { // flag = true, a AVLtree
        ZNode *output;
        output = addHelper3(n, r); // if just a search tree
        while (output != NULL) {
            adjustBalances(output);
            output = output->parent;
        }
    }
}
    
//adds nodes to tree, returns new leaf
ZNode *AVLTree::addHelper3(Z_Obj *n, ZNode *r) {

    if (root == NULL) {
        ZNode *newTree; // new tree of root NULL
        newTree = NULL;
        newTree =	new ZNode(n);
        root = newTree; // set pointer
        return newTree; // return node
    }
    ZNode *last = NULL; //last node
    while (r != NULL) {
        last = r; // keep track of last node
        if (n->lessThan(r->zObj)) {
            r = r->left; //go left
        } else {
            r = r->right; // go right
        }
    }
    if (n->lessThan(last->zObj)) {

         last->left = new ZNode(n); // build left node
        last->left->parent = last; // set pointer to parent
        return last->left;
    } else {
        last->right = new ZNode(n); // build right node
        last->right->parent = last; // set pointer
        return last->right;
    }
}

ZNode *AVLTree::findZip(int z, ZNode *n) {
    if (n == NULL || n->zObj->zip == z) {
        return n; //checks for zip equality and returns if true
    } else if ((n->left->zObj->zip < z) && (n->right != NULL)) {
        findZip(z, n->right); //checks if zip is less than left child
        //and right is not empty, if true recursively calls find zip on the right
        //child and proceeds right down the tree
    } else if (n->left != NULL) {
        findZip(z, n->left); //if root left is greater than z and not empty,
        //traverses left down the tree
    } else return NULL; //else returns NULL
}//findZip



void AVLTree::adjustBalances(ZNode *n) {
    updateHeight(n);
    int balance = (n->right == NULL? 0: n->right->height) - (n->left == NULL? 0: n->left->height) ; //constant int balance
    if (balance <= 1 && balance >= -1) {
        return; //balanced node
    } else if (balance < -1) {
        if (((n->left->right == NULL? 0: n->left->left->height) - (n->left->right == NULL? 0: n->left->left->height)) > 0) {
            //inside case - requires left rotation on child
            rotateLeft(n->left);
        }
        rotateRight(n); //outside case - requires only one rotation
    } else if (balance > 1) {
        if (((n->right->right->height) - (n->right->left->height)) < 0) {
            //inside case - requires right rotation on child
            rotateRight(n->right);
        }
        rotateLeft(n); //outside case - requires only one rotation
    }
}//adjustBalances
//adjusts balance of one node


//updates height of one node
void AVLTree::updateHeight(ZNode *n) {
    n->height = (max(n->left == NULL? 0: n->left->height,n->right == NULL? 0: n->right->height) + 1);
}//updates height of one node


// rotates right around node n, returns root of rotated tree
ZNode *AVLTree::rotateRight(ZNode *n) {

    // rotates right around n
    ZNode *x = n->left;
    ZNode *tmp = x->right;
    ZNode *tmp2 = x->parent;

    // Perform rotation
    x->right = n;
    n->left = tmp;

    // change pointers
    x->parent = n->parent;
    n->parent = tmp->parent;
    tmp->parent = tmp2;


    return x; // return new root of tree or subtree

}
// rotates left around node n, returns root of rotated tree
ZNode *AVLTree::rotateLeft(ZNode *n) {
	//rotates left around node n,
    ZNode *x = n->right;
    ZNode *tmp = x->left;
    ZNode *tmp2 = x->parent;

    // Perform rotation
    x->left = n;
    n->right = tmp;

    // change pointers
    x->parent = n->parent;
    n->parent = tmp->parent;
    tmp->parent = tmp2;

    return x;
}

void AVLTree::printIO(ZNode *root) {
    // print tree in order
    if(root == NULL){
        return;
    } //goes back to previous root if null
    printIO(root->left); //visit left side of root and print first
    root->printZ(); //print root
    printIO(root->right); //visit right side of root and print afterwards
}

void AVLTree::printPre(ZNode *root) {
    // print tree in preorder
    if(root == NULL){
        return;
    }
    root->printZ(); //print root first
    printPre(root->left); //visit left side of root
    printPre(root->right); //visit right side of root
}

void AVLTree::printPost(ZNode *root) {
    if(root == NULL){
        return;
    }
    printPost(root->left); //visit left side of root
    printPost(root->right); //visit right side of root
    root->printZ(); //print root last
    // print tree in postorder
}

AVLTree::~AVLTree() {

}
