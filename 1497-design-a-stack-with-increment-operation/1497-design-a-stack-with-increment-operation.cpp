class CustomStack {
    int ind;
    vector<int> vec;
    int len;
public:
    CustomStack(int maxSize) {
        vec.resize(maxSize);
        ind=0;
        len=maxSize;
        
    }
    
    void push(int x) {
        if(ind<len)
            vec[ind++]=x;

        
        
        
    }
    
    int pop() {
        if(ind==0)
            return -1;
        
        ind--;
        int val=vec[ind];
        vec[ind]=-1;

        return val;


        
    }
    
    void increment(int k, int val) {
        if(ind==0)
            return;

        int i=0;
        while(i<k && i<ind){
            vec[i]=vec[i]+val;
            i++;
        }
        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */