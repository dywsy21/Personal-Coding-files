#include <bits/stdc++.h>
using namespace std;

class SmallestInfiniteSet {
    unordered_set<int> not_contained;
    int min;
public:
    SmallestInfiniteSet(): not_contained(), min(1){}
    
    int popSmallest() {
        int temp = min;
        not_contained.insert(min);
        while(not_contained.count(min)) min++;
        return temp;
    }
    
    void addBack(int num) {
        if(not_contained.count(num)){
            not_contained.erase(num);
            if(num < min) min = num;
        } 
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */