class Node {
public:
    Node* links[2];

    Node() {
        for (int i = 0; i < 2; i++) {
            links[i] = nullptr;
        }
    }

    bool ck(int bit) {
        return links[bit] != nullptr;
    }

    void set(int bit, Node* node) {
        links[bit] = node;
    }

    Node* get(int bit) {
        return links[bit];
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

    vector<int> maximizeXor(vector<int>& nums,
                            vector<vector<int>>& queries) {

        sort(nums.begin(), nums.end());

        int q = queries.size();

        // {mi, {xi, original_index}}
        vector<pair<int, pair<int, int>>> offlineQueries;

        for (int i = 0; i < q; i++) {

            int xi = queries[i][0];
            int mi = queries[i][1];

            offlineQueries.push_back({mi, {xi, i}});
        }

        sort(offlineQueries.begin(), offlineQueries.end());

        Trie trie;

        vector<int> ans(q);

        int ind = 0;
        int n = nums.size();

        for (int i = 0; i < q; i++) {

            int ai = offlineQueries[i].first;
            int xi = offlineQueries[i].second.first;
            int qInd = offlineQueries[i].second.second;

            while (ind < n && nums[ind] <= ai) {

                trie.insert(nums[ind]);
                ind++;
            }

            if (ind == 0) {
                ans[qInd] = -1;
            }
            else {
                ans[qInd] = trie.getMax(xi);
            }
        }

        return ans;
    }
};