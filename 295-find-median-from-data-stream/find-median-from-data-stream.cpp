class MedianFinder {
public:
priority_queue<int> maxheap;
priority_queue<int , vector<int> , greater<int>> minheap;

    MedianFinder() {

    }
    
    void addNum(int num) {
        if ( maxheap.empty() && minheap.empty()){
            maxheap.push(num);
        }
       else if ( num < maxheap.top()){///writing " else if " is very important here , i wrote just if in beginning so when i entered first number instead of just enterign maxheap once it again counter this function and pushed again into maxheap .
            maxheap.push(num);
        }
        else 
        minheap.push(num);

        int n = maxheap.size();
        int m = minheap.size();
        if ( (n+m)%2 == 0 ){
            if ( n < m ){
                maxheap.push(minheap.top());
                minheap.pop();
            }
            else if ( n> m)
            {minheap.push(maxheap.top());
            maxheap.pop();}
        }
    }
    
    double findMedian() {
            int n = maxheap.size();
        int m = minheap.size();
        if ( (n +m )%2 == 0){
            return ((double)maxheap.top() +minheap.top())/2;
        }
        else
        {
            if ( n > m )return (double)maxheap.top();
            else
            return (double)minheap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */