//sort the stack in ascending order and print in descending order
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class stacksortnow{
    private:
    stack<int> s;
    // int temp;

    public:
    int size, ele;
    stacksortnow();
    void sort(stack<int> &s);
    void insert(stack<int> &s, int temp);

};


void stacksortnow :: sort(stack<int> &s){
    
    if(s.size()==1){
        return;
    }
    int temp = s.top();
    s.pop();
    stacksortnow :: sort(s);

    stacksortnow :: insert(s, temp);

    return;
}

void stacksortnow :: insert(stack<int> &s, int temp){
    if(s.size()==0 || s.top()<=temp){
        s.push(temp);
        return;
    }
    int val = s.top();
    
    s.pop();
    stacksortnow :: insert(s, temp);
    s.push(val);
    return;
}

stacksortnow :: stacksortnow(){
    cout<<"\nEnter the size of the stack :";
    cin>>size;
    cout<<"Put the elements in the stack: "<<endl;
    for(int i=0; i<size; i++){
        cin>>ele;
        s.push(ele);
    }
    sort(s);
    cout<<"sorted stack is: "<<endl;
    for(int i=0; i<size; i++){
        cout<<s.top()<<" ";
        s.pop();
    }
}

int main(){
    stacksortnow s1, s2;
    return 0;
}