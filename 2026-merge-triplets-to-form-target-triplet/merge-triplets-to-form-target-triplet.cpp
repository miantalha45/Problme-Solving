class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> maxTriplet(3, 0);
        for(auto& triplet : triplets)
        {
            if(triplet[0] <= target[0] &&
               triplet[1] <= target[1] &&
               triplet[2] <= target[2])
            {
                maxTriplet[0] = max(maxTriplet[0], triplet[0]);
                maxTriplet[1] = max(maxTriplet[1], triplet[1]);
                maxTriplet[2] = max(maxTriplet[2], triplet[2]);
            }
        }

        return (maxTriplet[0] == target[0] &&
               maxTriplet[1] == target[1] &&
               maxTriplet[2] == target[2]);
    }
};