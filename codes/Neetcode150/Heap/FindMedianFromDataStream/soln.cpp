class MedianFinder {
    priority_queue <int,vector<int>,greater<int>> min_heap;
    priority_queue <int> max_heap;
public:
    MedianFinder() {
        min_heap = priority_queue <int,vector<int>,greater<int>>();
        max_heap = priority_queue <int>();
        min_heap.push(1e5+1);
        max_heap.push(-1e5-1);
    }
    
    void addNum(int num) {
        if(min_heap.size()==max_heap.size()){
            if(num>min_heap.top()) min_heap.push(num);
            else if(num<max_heap.top()) max_heap.push(num);
            else min_heap.push(num);
        }
        else if(min_heap.size()<max_heap.size()){
            if(num>min_heap.top()) min_heap.push(num);
            else if(num<max_heap.top()){
                min_heap.push(max_heap.top());
                max_heap.pop();
                max_heap.push(num);
            }
            else min_heap.push(num);
        }
        else {
            if(num<max_heap.top()) max_heap.push(num);
            else if(num>min_heap.top()){
                max_heap.push(min_heap.top());
                min_heap.pop();
                min_heap.push(num);
            }
            else max_heap.push(num);
        }
    }
    
    double findMedian() {
        if(min_heap.size()==max_heap.size()) return (float)(min_heap.top()+max_heap.top())/2;
        else if(min_heap.size()>max_heap.size()) return min_heap.top();
        else return max_heap.top();
    }
};
