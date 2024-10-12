#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<int,string> m;
    m[1]="Keshav Sharma";
    m[2]="Suryansh Sharma";
    m[3]="Shubham Sharma";
    m[4]="Aditya Sharma";
    unordered_map<int,string> :: iterator it;
    for(it=m.begin();it!=m.end();it++){
        cout<<(*it).first<<"->"<<(*it).second<<endl;
    }
    return 0;
}