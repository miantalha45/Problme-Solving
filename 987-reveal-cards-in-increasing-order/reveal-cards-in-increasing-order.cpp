class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();

        sort(deck.begin(), deck.end());

        deque<int> q;

        for(int i = n - 1; i >= 0; i--)
        {
            if(q.size() > 0)
            {
                q.push_front(q.back());
                q.pop_back();
            }
            q.push_front(deck[i]);
        }

        return vector<int>(q.begin(), q.end());
    }
};