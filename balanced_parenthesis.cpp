#include <iostream>
#include <vector>
using namespace std;

class bal{
    private:
    int b, open, close;
    vector<string> paren;
    string op;
    public:
    bal();
    void solve(int open, int close, string op, vector<string> &paren);
};

void bal :: solve(int open, int close, string op, vector<string> &paren){
    if(open==0 && close==0){
        paren.push_back(op);
        return;
    }
    else if(open==close){
        string op1 = op + "{";
        solve(open-1, close, op1, paren);
    }
    else if(open>0 && open<close){
        // cout<<open<<" "<<close<<endl;
        string op1 = op + "{";
        solve(open-1, close, op1, paren);
        string op2 = op + "}";
        solve(open, close-1, op2, paren);
        
    }
    else if(open==0 && close>0){
        string op2 = op + "}";
        solve(open, close-1, op2, paren);
    }
}

bal :: bal(){
    cout<<"\n\nEnter the number of complete parenthesis for which you want to see combinations: "<<endl;
    cin>>b;
    open = b;
    close = b;
    op = "";
    solve(open, close, op, paren);
    for(int i=0; i<paren.size(); i++){
        cout<<paren[i]<<endl;
    }
    cout<<"Total combinations : "<<paren.size();
}

int main(){
    int T=5;
    bal cases[T];
    // for(int i=0; i<T; i++){
    //     bal.cases[i];
    // }
    return 0;
}