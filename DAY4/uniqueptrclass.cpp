#include<iostream>
#include<memory>

using namespace std;

class uptrmem
{
unique_ptr<int>p;

public:
uptrmem(int val):p(make_unique<int>(val))
{
cout<<"p intialized "<<*p<<endl;
}

void show()const
{
cout<<"p value: "<<*p<<endl;
}
};

int main()
{
uptrmem m1(10);
m1.show();

//utrmem m2=m1; //Error no Copy

uptrmem m2=move(m1);
m2.show();
//m1.show(); //Segmentation fault ownership tranferred to another so trying to access invalid memory location so error

return 0;
}
