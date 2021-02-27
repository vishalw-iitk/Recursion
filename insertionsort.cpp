#include <iostream>
#include <vector>
using namespace std;

void sort(vector<int> &v);
void insert(vector<int> &v, int temp);

void sort(vector<int> &v){
    if(v.size()==1)
        return;
    int temp = v[v.size()-1];
    v.pop_back();
    sort(v);
    insert(v, temp);
    // return;
}

void insert(vector<int> &v, int temp){
    if(v.size()==0 || v[v.size()-1]<=temp){
        v.push_back(temp);
        return;
    }
    int val = v[v.size()-1];
    v.pop_back();
    insert(v, temp);
    v.push_back(val);
    // return;
}

int main(){
    cout<<"Enter the size of the vector which you want to sort in the ascending order: "<<endl;
    int size;
    cin>>size;
    vector<int> v;
    int ele;
    cout<<"Enter the elemenst of the vector : "<<endl;
    for(int i = 0; i<size; i++){
        cin>>ele;
        v.push_back(ele);
    }
    cout<<"Sorted vector"<<endl;
    sort(v);
    for(int i = 0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    
    return 0;
}