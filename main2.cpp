#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Node {
public:
    int l, r;
    int max_val;
    int count;
    Node* left_child;
    Node* right_child;

    Node(int l, int r) {
        this->l = l;
        this->r = r;
        this->max_val = 0;
        this->count = 0;
        this->left_child = nullptr;
        this->right_child = nullptr;
    }

    ~Node() {
        delete left_child;
        delete right_child;
    }
};

class SegmentTree {
public:
    SegmentTree(vector<int>& arr) {
        root = build_tree(arr, 0, arr.size()-1);
    }

    ~SegmentTree() {
        delete root;
    }

    void update(int index, int value) {
        update_node(root, index, value);
    }

    int query(int l, int r, int x) {
        return query_node(root, l, r, x);
    }

private:
    Node* root;

    Node* build_tree(vector<int>& arr, int l, int r) {
        if (l > r) {
            return nullptr;
        }

        Node* node = new Node(l, r);

        if (l == r) {
            node->max_val = arr[l];
            node->count = 1;
            return node;
        }

        int mid = l + (r-l)/2;
        node->left_child = build_tree(arr, l, mid);
        node->right_child = build_tree(arr, mid+1, r);

        node->max_val = max(node->left_child->max_val, node->right_child->max_val);
        node->count = node->left_child->count + node->right_child->count;

        return node;
    }

    void update_node(Node* node, int index, int value) {
        if (node->l == index && node->r == index) {
            node->max_val = value;
            return;
        }

        int mid = node->l + (node->r - node->l) / 2;
        if (index <= mid) {
            update_node(node->left_child, index, value);
        } else {
            update_node(node->right_child, index, value);
        }

        node->max_val = max(node->left_child->max_val, node->right_child->max_val);
        node->count = node->left_child->count + node->right_child->count;
    }

    int query_node(Node* node, int l, int r, int x) {
        if (node == nullptr) {
            return 0;
        }

        if (node->l >= l && node->r <= r) {
            if (node->max_val < x) {
                return 0;
            }
            return node->count;
        }

        int mid = node->l + (node->r - node->l) / 2;
        int res = 0;

        if (l <= mid) {
            res += query_node(node->left_child, l, r, x);
        }

        if (r > mid) {
            res += query_node(node->right_child, l, r, x);
        }

        return res;
    }
};

int main() {
    vector<int> arr = {3, 1, 5, 6, 4, 2};
    SegmentTree tree(arr);
}
   
