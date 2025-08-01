/*4. Write a program to store a binary search tree in array based representation:
- Any node can appear at any index
- index of root node is maintained separately
- For i=0 to n-1,
	* key[i] stores the key
	* left[i]/right[i] stores the index of the left or right child (-1 it does not exist) 
	* Your program must support insertion and deletion in tree (if a key) already exists no change is made
Sample Tree:

Size: 8
Root: 3
-------------------------------------------
Index: 0   1    2    3    4    5   6    7
-------------------------------------------
Key:   9   12   21   17   32   4   25   6
Left:  -1  -1   -1   7    2    -1  -1   5
Right: 1   -1   6    4    -1   -1  -1   0
*/
#include <iostream>
#include <vector>
using namespace std;

// Constants
const int SIZE = 8;   // Maximum size of the tree
const int EMPTY = -1; // Constant for empty node

// Arrays to store the tree
int key[SIZE];         // key[i] stores the key at index i
int left[SIZE];        // left[i] stores the index of left child of node at index i
int right[SIZE];       // right[i] stores the index of right child of node at index i
int root = EMPTY;      // Root index is maintained separately

// Function to initialize the tree with -1
void initializeTree() {
    for (int i = 0; i < SIZE; ++i) {
        key[i] = EMPTY;
        ::left[i] = EMPTY;
        ::right[i] = EMPTY;
    }
}

// Helper function to find an empty index in the array
int findEmptyIndex() {
    for (int i = 0; i < SIZE; ++i) {
        if (key[i] == EMPTY) {
            return i;
        }
    }
    return EMPTY;  // Return -1 if no empty index is found
}

// Recursive function to insert a key into the tree
void insert(int &node, int newKey) {
    if (node == EMPTY) {
        // Find an empty index to store the new key
        int index = findEmptyIndex();
        if (index == EMPTY) {
            cout << "Tree is Full. Cannot Insert more Nodes.\n";
            return; 
        }
        node = index;
        key[node] = newKey;
        ::left[node] = EMPTY;   // Explicitly using global left array
        ::right[node] = EMPTY;  // Explicitly using global right array
        return;
    }

    // Traverse the tree to find the correct position
    if (newKey < key[node]) {
        insert(::left[node], newKey);  // Use global left array
    } else if (newKey > key[node]) {
        insert(::right[node], newKey);  // Use global right array
    } else {
        cout << "Key " << newKey << " already exists in the tree.\n";
    }
}

// Recursive function to find the minimum value node in the tree
int findMin(int node) {
    while (::left[node] != EMPTY) {  // Use global left array
        node = ::left[node];
    }
    return node;
}

// Recursive function to delete a key from the tree
int deleteNode(int node, int delKey) {
    if (node == EMPTY) {
        cout << "Key " << delKey << " not found in the tree.\n";
        return node;
    }

    if (delKey < key[node]) {
        ::left[node] = deleteNode(::left[node], delKey);  // Use global left array
    } else if (delKey > key[node]) {
        ::right[node] = deleteNode(::right[node], delKey);  // Use global right array
    } else {
        // Node with one child or no child
        if (::left[node] == EMPTY) {  // Use global left array
            int temp = ::right[node];  // Use global right array
            key[node] = EMPTY;
            return temp;
        } else if (::right[node] == EMPTY) {  // Use global right array
            int temp = ::left[node];  // Use global left array
            key[node] = EMPTY;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        int minIndex = findMin(::right[node]);  // Use global right array
        key[node] = key[minIndex];
        ::right[node] = deleteNode(::right[node], key[minIndex]);  // Use global right array
    }

    return node;
}

// Function to display the tree
void displayTree() {
    cout << "-------------------------------------------\n";
    cout << "Index: ";
    for (int i = 0; i < SIZE; ++i) {
        cout << i << "   ";
    }
    cout << "\n-------------------------------------------\n";
    cout << "Key:   ";
    for (int i = 0; i < SIZE; ++i) {
        cout << (key[i] == EMPTY ? -1 : key[i]) << "   ";
    }
    cout << "\nLeft:  ";
    for (int i = 0; i < SIZE; ++i) {
        cout << ::left[i] << "   ";
    }
    cout << "\nRight: ";
    for (int i = 0; i < SIZE; ++i) {
        cout << ::right[i] << "   ";
    }
    cout << "\n-------------------------------------------\n";
}

// Main function to test the BST
int main() {
    // Initialize the tree
    initializeTree();

    // Insert keys into the tree
    insert(root, 17);  // Root
    insert(root, 6);
    insert(root, 4);
    insert(root, 9);
    insert(root, 12);
    insert(root, 21);
    insert(root, 32);
    insert(root, 25);

    // Display the tree
    cout << "Initial Tree: \n";
    displayTree();

    // Delete a node
    cout << "Deleting key 21...\n";
    deleteNode(root, 21);
    displayTree();

    // Insert a duplicate key
    cout << "Trying to insert duplicate key 12...\n";
    insert(root, 12);

    // Insert a new key
    cout << "Inserting key 13...\n";
    insert(root, 13);
    displayTree();

    return 0;
}

