#include <iostream>
#include<list>
using namespace std;

int main() {

list<int> l1 = {1,2,3};
list<int> l2 = {10,20};
auto it = l2.begin();// points to 10

l1.splice(l1.begin(), l2, it);
for (int x : l1)
cout << x <<" ";
cout<<endl;

auto first=l2.begin();
auto last=l2.end();
l1.splice(l1.begin(),l2,first,last);

for(int a : l1)
cout<<a<<" ";
}



