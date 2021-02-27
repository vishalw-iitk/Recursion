// delete the middle element and reverse the stack after the deletion which will print the transformed stack in the original order
#include <iostream>
#include <stack>
using namespace std;

class deletemiddle{
    private:
    int ele;
    int mid;
    stack<int> s;
    int size;

    public:
    deletemiddle();
    void remove(stack<int> &s,int mid);
    void reverse(stack<int> &s);
    void insert_reverse(stack<int> &s, int p);
};

void deletemiddle :: insert_reverse(stack<int> &s, int p){
    
    if(s.size()==0){
        s.push(p);
        // s.push(ptemp);
        return;
    }
    int ptemp = s.top();
    s.pop();
    insert_reverse(s, p);
    s.push(ptemp);
    
    
}

void deletemiddle :: reverse(stack<int> &s){
    if(s.size()==1){
        return;
    }
    int p = s.top();
    s.pop();
    reverse(s);
    insert_reverse(s, p);
    
}

void deletemiddle :: remove(stack<int> &s,int mid){
    if(s.size()==0)
        return;
    if(s.size()==mid){
        s.pop();
        return;
    }
    int top = s.top();
    s.pop();
    remove(s, mid);
    s.push(top);
}

deletemiddle :: deletemiddle(){
    cout<<"\nEnter the size of the stack: "<<endl;
    cin>>size;
    cout<<"Enter the elements in the stack: "<<endl;
    for(int i=0; i<size; i++){
        cin>>ele;
        s.push(ele);
    }
    mid = s.size()/2 + 1;
    remove(s,mid);
    reverse(s);
    cout<<"After the deletion of the middle element: "<<endl;
    for(int i=0; i<size-1; i++){
        cout<<s.top()<<" ";
        s.pop();
    }
}

int main(){
    deletemiddle d1, d2;
    return 0;
}