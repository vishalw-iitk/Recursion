//print all the subsets of the string
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class subs{
    private:
    string ip, op, temp;
    vector<string> unique_subsets;
    public:
    subs();
    void solve(string ip, string op, vector<string> &unqiue_subsets);
};

void subs :: solve(string ip, string op, vector<string> &unique_subsets){
    if(ip.length() == 0){
        // cout<<op<<endl;
        unique_subsets.push_back(op);
        return;
    }
    string op1 = op;
    string op2 = op + ip[0];
    // op.push_back(ip[0]);
    ip.erase(ip.begin());
    solve(ip, op1, unique_subsets);
    solve(ip, op2, unique_subsets);
}

subs :: subs(){
    cout<<"\n\nEnter the string : "<<endl;
    cin>>ip;
    op = "";
    solve(ip, op, unique_subsets);
    // cout<<unique_subsets.size();
    // unique(unique_subsets.begin(), unique_subsets.end());
    for(int i=0; i<unique_subsets.size(); i++){
        cout<<unique_subsets[i]<<" ";
    }
}

int main(){
    subs s1;
    return 0;
}