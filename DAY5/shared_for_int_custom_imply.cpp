#include<iostream>
#include<memory>

using namespace std;

class shared
{
public:
int *data;
int *refcount;

public:

explicit shared(int value)
{
data=new int(value);
refcount=new int(1);
cout<<"The data intialized "<<*data<<"with refCount "<<*refcount<<endl;
}

//copy constructor
shared(const shared& obj)
{
data=obj.data;
refcount=obj.refcount;
++(*refcount);
cout<<"Ref Count from copy = "<<*refcount<<endl;
}

//copy Assignment constructor
shared& operator=(const shared& obj)
{
if(this==&obj)
return *this;
Release();
data=obj.data;
refcount=obj.refcount;
++(*refcount);
cout<<"Ref Count from copy Asn = "<<*refcount<<endl;
return *this;
}

//Move Constructor
shared(shared&& obj)noexcept
{
data=obj.data;
refcount=obj.refcount;
obj.data=NULL;
obj.refcount=NULL;
cout<<"Move Constructor refcount: "<<*refcount<<endl;
}

//Move Assignment operator
shared& operator=(shared&& obj)noexcept
{
if(this==&obj)
return *this;
Release();
data=obj.data;
refcount=obj.refcount;
obj.data=NULL;
obj.refcount=NULL;
cout<<"Move Assignment : "<<*refcount<<endl;
return *this;
}

//Destructor
~shared()
{
Release();
}
int get()const
{
return *data;
}

int RefCount()const
{
return *refcount;
}

private:
void Release()
{
if(refcount)
{
--(*refcount);
cout<<"Ref Count = "<<*refcount<<endl;
if(*refcount == 0)
{
cout<<"Deleting the data"<<endl;
delete data;
delete refcount;
}
}
}       

};

int main()
{
shared s1(10); // s1 and refcount=1 (s1)
{
shared s2=s1;  //s1 and s2 (copy) refcount=2 (s1,s2) 
shared s3=move(s2); //s2 moved to s3 refcount=2 (s1,s3)
shared s4=s3; //copy  (s4=s3) refcount=3 (s1,s3,s4)
s2=move(s4); //move asgn (s2=s4) refcount=3 (s1,s2,s3)
cout<<"REF COUNT "<<*(s2.refcount)<<endl;
s1=s2; //copy asgn (s1=s2) refcount=2 (s1,s3)
}
cout<<"Back to main"<<endl;
return 0;
}


















