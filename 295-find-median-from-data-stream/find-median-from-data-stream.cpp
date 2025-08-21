class MedianFinder {
public:
    // Left heap
    priority_queue<int> maxHeap;
    // Right Heap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // Step 1: Insert into left heap first
        maxHeap.push(num);
        
        // Step 2: Move the largest from left heap to right heap
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        
        // Step 3: Balance the heaps (keep left heap same size or 1 larger)
        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if((minHeap.size() + maxHeap.size()) % 2 == 0)
        {
            return double(double(minHeap.top() + maxHeap.top()) / 2);
        }
        else
        {
            return min(minHeap.top(), maxHeap.top());
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */