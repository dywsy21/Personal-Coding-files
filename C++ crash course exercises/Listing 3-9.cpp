#include <bits/stdc++.h>



//example of a forward-linked list
class element{
    int serial_number;
public:
/*  element(int serial_number_in){
        serial_number=serial_number_in;
    }  这种初始化方式不推荐  */

    element(int serial_number_in):serial_number{serial_number_in} {}  //如果有多个class中的变量(object)需要初始化，直接逗号隔开就好

    element* next{};  //{}:初始化为空指针nullptr

    void insert_after(element* new_element){  //一个method
        new_element -> next = next;   //1->2,对1 insert 3,得1->3->2
        next= new_element;    //这两行单独的next等价于this->next
    }

    int get_serial_number() const{  //const可以防止你在该method里更改变量值，which is serial_number in this case.
        //serial_number++;  error:increment of member 'element::serial_number' in read-only object
        return serial_number;
    }
};

bool is_even_serial_number(const element& a){
    if(a.get_serial_number()%2==0) return true; //如果get_serial_number没有被标注为const: error:passing 'const element' as 'this' argument discards qualifiers [-fpermissive]
    else return false;
}





int main(){
    element a(1),b(2),c(3);

    a.next=&b;
    a.insert_after(&c);

    for(element* ptr=&a; ptr ; ptr= ptr->next){ //nullptr对应0(false)
        std::cout << ptr -> get_serial_number() << "\n";
    }

    if(is_even_serial_number(a)) std::cout << "1\n";
    else std::cout << "0\n";



    system("pause");
    return 0;
}