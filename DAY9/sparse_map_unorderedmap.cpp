#include <iostream>
#include <iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main() {
   map<int,int>sparsemap;
sparsemap[1]=10;
sparsemap[5]=30;
for(auto[i,v]:sparsemap)
{
cout<<"Index : "<<i<<" Value : "<<v<<endl;
}
unordered_map<int,int>sparse_unmap;
sparse_unmap[3]=10;
sparse_unmap[2]=40;
cout<<sparse_unmap[3]<<endl;

    return 0;
}



