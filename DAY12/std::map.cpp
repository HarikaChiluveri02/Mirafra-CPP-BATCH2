#include <iostream>
#include<map>

using namespace std;

int main() {

map<string,int>m;
m["Harika"]=22;
m["Bhanu"]=25;

m.insert(make_pair("Apple",10));
m.insert(make_pair("Maha",22));
m.emplace("keer",15);
m.insert(make_pair("keer",15));//duplicates are not allowed
m.emplace("Honey",11);

for(auto const& [n,a]:m)
cout<<n<<" "<<a<<endl;
}



