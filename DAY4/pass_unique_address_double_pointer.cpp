#include<iostream>
#include<memory>
using namespace std;

void AlterResource(unique_ptr<int>*ptr)
  {
  *ptr=make_unique<int>(200); //Replace the manged resouce
   cout<<"&ptr: "<<&ptr<<endl; //stack
   cout<<"*ptr: "<<(*ptr).get()<<endl; //stack

   cout<<"Resource inside function "<<**ptr<<endl;
  }

int main()
{
  
unique_ptr<int>uniqueptr=make_unique<int>(42);  //stack
cout<<"&uniqueptr: "<<&uniqueptr<<endl; //stack
cout<<"Uniqueptr: "<<uniqueptr.get()<<endl; //raw ptr-> heap segment
 
AlterResource(&uniqueptr); //pass pointer to unique ptr
cout<<"resouce after function: "<<*uniqueptr<<endl;

}

