/*
 Data containers include vector,deque,list,queue,bitset,set and so on.
 This template introduces commonly used methods regarding vector,list and queue.

List's elements aren't stored continiously in memory, so you can't use [] to access its elements.
However, this feature of list makes inserting and removing elements in a list much faster than vectors.





*/





#include <bits/stdc++.h>




int main(){

//section 'vector'
//定义向量的一般方法
    std::vector<int> vec1{1,2,3,4,5};
    std::vector<int> vec2(5,1); //vec2=={1,1,1,1,1}  use parentheses to invoke the built-in 'fill' method


//整体或部分复制粘贴向量的方法
    std::vector<int> vec1_cpy(vec1.begin(),vec1.end()); //vec1_cpy==vec1=={1,2,3,4,5}
    std::vector<int> vec1_segment(vec1.begin()+1,vec1.end()-2); //vec1_segment=={2,3}
assert(vec1_segment[0]==2 && vec1_segment[1]==3);


//取头尾元素的方法
//注意front,back与begin,end的区别：前面两个取值，后面两个取地址
    int first_element_of_vec1 {vec1.front()};
    int last_element_of_vec1 {vec1.back()};
assert(first_element_of_vec1==1 && last_element_of_vec1==5);


//以类似数组的形式处理向量的方法——取指针
    int* vec1_ptr {vec1.data()}; //vec1_ptr现在指向vec1首元素的地址


//取向量大小的方法
    int vec1_size {vec1.size()};
assert(vec1_size==5);


//直接整体替换向量中现有元素的方法: 'assign'
    std::vector<int> vec3 {1,2,3,4,5};
    vec3.assign({6,7,8}); //vec3 now equals to {6,7,8}


//向向量中插入元素的方法：'insert'
    std::vector<int> vec4 {1,2,3,4,5};
    vec4.insert(vec4.begin()+1 , 100);  //vec4 now equals to {1,100,2,3,4,5}
assert(vec4[1]==100 && vec4[2]==2);


//向向量的末尾插入元素的方法：'push_back'
    std::vector<int> vec5 {1,2,3,4,5};
    vec5.push_back(100); //vec5 now equals to {1,2,3,4,5,100}
assert(vec5[5]==100);


//<...>里面可以塞进去std::里面其他类型的东西
    std::vector<std::pair<int,int>> vec6 {{1,2},{1,2},{1,2}};
assert(vec6[0].first==1 && vec6[0].second==2);


//对于像vec6的这种向量，不能用'insert'插入数据，而要用'emplace'和'emplace_back'
    vec6.emplace(vec6.begin()+1, 100, 100);
    vec6.emplace_back(100, 100); //vec6 now equals to {{1,2},{100,100},{1,2},{1,2},{100,100}}
assert(vec6[1].first==100 && vec6[1].second==100);
assert(vec6[4].first==100 && vec6[4].second==100);


//清空向量：'clear'，查看是否是空向量：'empty'
    std::vector<int> vec7 {1,1,1};
    vec7.clear();
assert(vec7.empty());  //empty():如果确实是空就return true，不然return false


//两个向量间的运算:'=',swap(),'==','>','<',...
    std::vector<int> vec8 {1,2,3,4,5};
    std::vector<int> vec9 {6,7,8,9,10};

assert(vec8<vec9);  //每个元素从前往后比较
assert(!(vec8==vec9)); //和数学里两个向量相等的定义一致

    swap(vec8,vec9); //vec8与vec9整体互换
    vec8=vec9; //vec8整体被替换成vec9
assert(vec8[0]==1);



//section 'list'
    std::list<int> list1 {1,2,3,4,5};
    
    list1.push_front(1);
    list1.pop_front();
    list1.push_back(1);
    list1.pop_back();
//... see the pic in folder some_useful_pics


//section 'priority_queue'
//priority queue's elements are in descending order by default, and the 'pop' method removes the largest element from it.

    std::priority_queue<double> pq1;
    pq1.push(1.2);
    pq1.push(2.3);
    pq1.push(-0.5); //{2.3, 1.2, -0.5}
    pq1.pop();  //{1.2, -0.5}
assert(pq1.top()==1.2);



    system("pause");
    return 0;
}
