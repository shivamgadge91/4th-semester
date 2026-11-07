Member Variables
int data;
Stores the actual value/number inside the node (for example, 50, 30, or 20).
Node* left;
A pointer that connects to the left child node. In a BST, any value on the left side is always smaller than the current node's data.
ode* right;
A pointer that connects to the right child node. In a BST, any value on the right side is always larger than the current node's data.
The Constructor

Node(int val) {
    data = val;
    left = nullptr;
    right = nullptr;
}
What it does: Whenever you create a new node (e.g., Node* newNode = new Node(50);), this constructor automatically runs.
data = val;: Sets the node's value to whatever number you passed in (e.g., 50).
left = nullptr; & right = nullptr;: Initializes both child pointers to nullptr because when a node is newly created, it doesn't have any children yet (it's a leaf node initially).

2.Left Subtree: All values are smaller than the current node.

Right Subtree: All values are larger than the current node.
2.1 The Base Case (Finding the Empty Spot)

if (root == nullptr) {
    return new Node(val);
}
What it does: The function checks if the current pointer (root) is nullptr (meaning we've reached an empty spot or the end of a branch).

Action: When it finds that empty spot, it dynamically creates a new node containing the value (new Node(val)) and returns its memory address back up to the previous function call. 
2.2 Comparing and Choosing the Direction

if (val < root->data) {
    root->left = insert(root->left, val);
} else if (val > root->data) {
    root->right = insert(root->right, val);
}
If val < root->data: The new value is smaller than the current node, so it needs to go to the left subtree. It calls insert again, passing the left child as the new root.

If val > root->data: The new value is larger, so it goes to the right subtree. It calls insert again, passing the right child as the new root.
2.3 Reconnecting Pointers and Returning the Root

root->left = insert(root->left, val);
// and later:
return root;
Why assign root->left = ...? When the new node is finally created at the bottom, the recursive calls unwind. This assignment ensures that the parent node correctly links to its new child node.

return root;: For all the existing nodes that are not changing, the function simply returns the current root pointer unchanged, keeping the structure of the tree intact.
3 Inorder Traversal Function (inorder)
The Base Case (if (root == nullptr) return;): If the current node is empty (end of a branch), the function stops and steps back.

Step 1: Go Left (inorder(root->left);): Recursively dives down the left subtree first. Because smaller values are always on the left, this ensures we reach the smallest value in the tree first.

Step 2: Print Current Data (cout << root->data << " ";): Prints the value of the current node once its left branch is fully processed.

Step 3: Go Right (inorder(root->right);): Finally, explores the right subtree for larger values.
3.2 Longest Path / Height Function (longestPath)
Step-by-Step Logic
The Base Case (if (root == nullptr) return 0;): If the current node doesn't exist (it's empty), its length is 0.

Step 1: Measure Left Subtree (int leftHeight = longestPath(root->left);): Recursively calculates the height of the left branch.

Step 2: Measure Right Subtree (int rightHeight = longestPath(root->right);): Recursively calculates the height of the right branch.

Step 3: Compare and Add One (return max(leftHeight, rightHeight) + 1;):

max() compares the left and right heights and picks the taller branch.

+ 1 adds the current node itself to the count, returning the total height upward to the parent node.
4 Checking if the Tree is Empty

if (root == nullptr) {
    cout << "Tree is empty!" << endl;
    return -1;
}
What it does: Before doing anything, it checks if the root pointer is nullptr.

Why: If the tree has no nodes, there is no minimum value to find. It prints an error message and returns -1 to safely handle the empty case.

4. 2. Setting Up a Traversal Pointer

Node* current = root;
What it does: Creates a temporary pointer called current and sets it to the root of the tree.

Why: We never want to lose or modify the actual root pointer of our tree, so we use a temporary helper pointer to walk through the nodes.

4.3. Traveling to the Leftmost Node

while (current->left != nullptr) {
    current = current->left; 
}
What it does: A while loop that keeps moving current to its left child (current = current->left) as long as a left child exists (!= nullptr).

Why: Since smaller elements live on the left side of a BST, the absolute minimum value will reside at the deepest bottom-left leaf node. Once current->left becomes nullptr, we know we've hit the end of the left path.

4.4. Returning the Minimum Value

return current->data;
What it does: Once the loop stops, current points to the node with the smallest value. The function extracts and returns its data.

5. The Base Case (End of Branch)

if (root == nullptr) {
    return;
}
What it does: Checks if the current node is empty (nullptr).

Why: When recursion reaches past a leaf node (the end of a branch), it stops executing and steps back up.

5.2. Swapping the Left and Right Pointers

Node* temp = root->left;
root->left = root->right;
root->right = temp;
Node* temp = root->left;: Temporarily stores the left child pointer so we don't lose its address.

root->left = root->right;: Overwrites the left pointer with the right child pointer.

root->right = temp;: Assigns the original left child (stored in temp) to the right pointer.

Result: The children of the current node have successfully swapped places.

5.3. Recursing Through the Subtrees

mirrorTree(root->left);
mirrorTree(root->right);
What it does: Recursively calls mirrorTree on the newly swapped left and right children.

Why: This ensures that the mirroring process ripples down to every single node throughout the entire tree, rather than just swapping the root's immediate children.

6. The Base Case (End of Branch / Not Found)

if (root == nullptr) {
    return false;
}
What it does: Checks if the current node is empty (nullptr).

Why: If the search path leads to a dead end (a nullptr), it means the value is not in the tree, so the function returns false.

6.2. Checking for a Match

if (root->data == key) {
    return true;
}
What it does: Compares the target key with the data of the current node.

Why: If they match, we have successfully found the value, so the function returns true.

6. 3. Deciding Which Way to Search (Navigation Logic)

if (key > root->data) {
    return searchBST(root->left, key);
} else {
    return searchBST(root->right, key);
}
Note on BST Rules: In a standard Binary Search Tree, smaller values go to the left and larger values go to the right.

In this specific snippet:

If key > root->data, it goes left (searchBST(root->left, key)). (Note: If your tree is a standard BST where larger values are on the right, you would typically check key < root->data to go left, or this snippet represents a search on a tree where the layout is reversed/mirrored).

Otherwise (else), it searches the right subtree (searchBST(root->right, key)).

