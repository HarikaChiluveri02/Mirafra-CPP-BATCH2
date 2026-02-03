#include<iostream>
#include<vector>

using namespace std;

int main()
{
vector<string>vect{"Harika","Bhanu","Honey"};

/*Reference program for each loop to avoid the copy of objects*/
for(const auto& x : vect)
cout<<x<<" ";
cout<<endl;
}
