#include <iostream>
#include<set>
using namespace std;

int main() {
set<int>s={2,4,5,1,9};
s.insert(2);
s.insert(7);

auto it=s.find(5);
if(*it)
cout<<"5 found "<<endl;
else
cout<<"5 is not found"<<endl;    

for(auto x : s)
cout<<x<<" ";
cout<<endl;

cout<<"Erasing 1"<<endl;
s.erase(1);
for(auto v : s)
cout<<v<<" ";
cout<<endl;
    return 0;
}



