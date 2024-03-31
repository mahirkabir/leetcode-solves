class Solution {
private:
    bool isPotential(vector<int> triplet, vector<int> target) {
        bool isPot = true;
        for (int i = 0; i < 3; ++i) isPot &= (triplet[i] <= target[i]);
        return isPot;
    }

    bool isEqual(vector<int> triplet, vector<int> target) {
        bool isPot = true;
        for (int i = 0; i < 3; ++i) isPot &= (triplet[i] == target[i]);
        return isPot;
    }

    vector<int> maxify(vector<int> triplet, vector<int> target) {
        for (int i = 0; i < 3; ++i) triplet[i] = max(triplet[i], target[i]);
        return triplet;
    }
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> curr;
        curr.push_back(0);curr.push_back(0);curr.push_back(0);

        for (auto& triplet: triplets) {
            if (isPotential(triplet, target)) {
                curr = maxify(curr, triplet);
            }
        }

        return isEqual(curr, target);
    }
};