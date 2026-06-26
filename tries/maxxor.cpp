class Node {
public:
    Node* links[2];

    Node() {
        for (int i = 0; i < 2; i++) {
            links[i] = nullptr;
        }
    }

    bool ck(int id) {
        return (links[id] != nullptr);
    }

    void set(int id, Node* node) {
        links[id] = node;
    }

    Node* get(int id) {
        return links[id];
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node* node = root;

        for (int i = 31; i >= 0; i--) {

            int bit = (num >> i) & 1;

            if (!node->ck(bit)) {
                node->set(bit, new Node());
            }

            node = node->get(bit);
        }
    }

    int getMax(int num) {

        Node* node = root;
        int maxi = 0;

        for (int i = 31; i >= 0; i--) {

            int bit = (num >> i) & 1;

            // opposite bit preferred
            if (node->ck(1 - bit)) {

                maxi = maxi | (1 << i);

                node = node->get(1 - bit);
            }
            else {
                node = node->get(bit);
            }
        }

        return maxi;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {

        Trie trie;

        for (auto &it : nums) {
            trie.insert(it);
        }

        int maxi = 0;

        for (auto &it : nums) {
            maxi = max(maxi, trie.getMax(it));
        }

        return maxi;
    }
};