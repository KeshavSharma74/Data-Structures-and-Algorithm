#include<bits/stdc++.h>
using namespace std;

int main(){
    cout<<"keshav sharma"<<endl;
    cout<<"Enter n : ";
    int n;
    cin>>n;
    cout<<"Enter names : ";
    vector<string> v(n);
    for(int i=0;i<n;i++){
        string name;
        cin>>name;
        v.push_back(name);
    }
    for(auto element : v)   cout<<element<<"  ";
    
    return 0;
}