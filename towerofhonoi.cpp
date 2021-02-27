#include <iostream>
using namespace std;

void solve(int n, char s, char h, char d);

void solve(int n, char s, char h, char d, int &count){
    count++;
    if(n==1){
        cout<<"Put the plate "<<n<<" from "<<s<<" to "<<d<<endl;
        return;
    }
    
    solve(n-1, s, d, h, count);
    cout<<"Put the plate "<<n<<" from "<<s<<" to "<<d<<endl;
    solve(n-1, h, s, d, count);
    
    
}

int main(){
    int n;
    cout<<"\nEnter the number of plates: ";
    cin>>n;
    int count = 0;
    solve(n, 's', 'h', 'd', count);
    cout<<"Number of steps : "<<count<<endl;
    return 0;
}