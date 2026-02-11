#include <iostream>
#include<map>
#include<iostream>

using namespace std;

int main() {
    map<int,string>m={{1,"One"},{2,"Two"}};
    cout<<"Printing older method"<<endl;
    for(const auto& [key,value] : m)
cout<<key<<"->"<<value<<endl;

cout<<"Printing new Method"<<endl;
for(const auto& element : m)
{
cout<<element.first<<"->"<<element.second<<endl;
}
    return 0;
}



