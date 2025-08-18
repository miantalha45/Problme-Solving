class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();

        priority_queue<int> pq;

        for (int stone : stones) {
            pq.push(stone);
        }

        while (pq.size() > 1) {
            int heaviest = pq.top();
            pq.pop();
            int secondHeaviest = pq.top();
            pq.pop();

            if (heaviest != secondHeaviest) {
                int remaining = heaviest - secondHeaviest;

                pq.push(remaining);
            }
        }

        return pq.size() == 0 ? 0 : pq.top();
    }
};