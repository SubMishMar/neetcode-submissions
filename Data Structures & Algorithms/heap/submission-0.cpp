class MinHeap {
public:
    std::vector<int> heap_;
    MinHeap() {
        heap_.push_back(0); // for convenience of indexing
    }

    void push(int val) {
        heap_.push_back(val);
        int i = heap_.size()-1;
        // i>1 because if i>0, i will be 1 at some point
        // resulting in comparison with 0 (1/2=0) index which 
        // happens to be a dummy element;
        while (i > 1 && heap_[i/2] > heap_[i]) {
            int temp = heap_[i/2];
            heap_[i/2] = heap_[i];
            heap_[i] = temp;
            i=i/2;
        }
    }

    int pop() {
        if(heap_.size()==1){ // no elements, 0th element is a dummy
            return -1;
        }
        if(heap_.size()==2){ // 1 element
            int top = heap_[1];
            heap_.pop_back();
            return top;
        }
        int res = heap_[1];
        heap_[1] = heap_[heap_.size()-1];
        heap_.pop_back();
        int max_index = heap_.size()-1;
        int i = 1;
        while(2*i<=max_index){ // go until left descendant is within bounds, if there's no left there will be no right
            if(2*i+1 <= max_index && // is right node present?
               heap_[2*i+1] < heap_[2*i] && // is right node smaller than left
               heap_[2*i+1] < heap_[i]){ // is right node smaller than respective parent
                // right node
                int temp = heap_[2*i+1];
                heap_[2*i+1] = heap_[i];
                heap_[i] = temp;
                i = 2*i+1;
            } else if(heap_[2*i] < heap_[i]) {
                // left node
                int temp = heap_[2*i];
                heap_[2*i] = heap_[i];
                heap_[i] = temp;
                i = 2*i;
            } else {
                break;
            }
        }
        return res;
    }

    int top() {
        if(heap_.size()==1){
            return -1;
        }
        return heap_[1];
    }

    void heapify(const vector<int>& arr) {
        heap_ = arr;
        heap_.push_back(heap_[0]);
        int max_index = heap_.size()-1;
        int curr = heap_.size()-1;
        // current should go till 1
        while(curr >= 1){
            int i = curr;
            while(2*i<=max_index){ // go until left descendant is within bounds, if there's no left there will be no right
                if(2*i+1 <= max_index && // is right node present?
                heap_[2*i+1] < heap_[2*i] && // is right node smaller than left
                heap_[2*i+1] < heap_[i]){ // is right node smaller than respective parent
                    // right node
                    int temp = heap_[2*i+1];
                    heap_[2*i+1] = heap_[i];
                    heap_[i] = temp;
                    i = 2*i+1;
                } else if(heap_[2*i] < heap_[i]) {
                    // left node
                    int temp = heap_[2*i];
                    heap_[2*i] = heap_[i];
                    heap_[i] = temp;
                    i = 2*i;
                } else {
                    break;
                }
            }
            curr--;
        }
    }
};
