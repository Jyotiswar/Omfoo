#include <iostream>
#include <unordered_map>
using namespace std;

// Define the structure for the tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int traversal(Node* root, unordered_map<int, int>& mp, int& k, int sum) {
        if (!root) return 0;

        int res = 0;
        int currSum = sum + root->data;

        if (mp.find(currSum - k) != mp.end())
            res += mp[currSum - k];

        mp[currSum]++;

        res += traversal(root->left, mp, k, currSum);
        res += traversal(root->right, mp, k, currSum);

        mp[currSum]--;
        return res;
    }

    int sumK(Node* root, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        return traversal(root, mp, k, 0);
    }
};

// Function to create a sample binary tree
Node* createSampleTree() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(-3);
    root->left->left = new Node(3);
    root->left->right = new Node(2);
    root->right->right = new Node(11);
    root->left->left->left = new Node(3);
    root->left->left->right = new Node(-2);
    root->left->right->right = new Node(1);
    return root;
}

int main() {
    Solution solution;
    
    // Create a sample binary tree
    Node* root = createSampleTree();

    // Specify the target sum 'k'
    int k = 8;

    // Calculate the number of subarrays with sum equal to 'k'
    int result = solution.sumK(root, k);

    // Display the result
    cout << "Number of subarrays with sum " << k << ": " << result << endl;

    return 0;
}
