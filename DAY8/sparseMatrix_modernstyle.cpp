#include<iostream>
#include<vector>
using namespace std;

int main()
{
vector<pair<int,int>>sparse; //storing non-zero elements as a std::vector<pair<,>>
sparse.push_back({2,10});
sparse.push_back({5,50});

for(const auto& [index,value] : sparse) //Printing vector<pair<,>>
{
cout<<"Index : "<<index<<" Value : "<<value<<endl;
}
return 0;
}
