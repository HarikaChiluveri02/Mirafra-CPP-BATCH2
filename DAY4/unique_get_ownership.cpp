#include<iostream>
#include<memory>

using namespace std;

/*void AlterResource(int *ptr) // Tranferring as a rqw pointer
{
*ptr=100;
cout<<"Resource inside function "<<*ptr<<endl;
cout<<"Adress of resource inside function "<<ptr<<endl;
}*/

//void AlterResource(unique_ptr<int>&&ptr) //if we use rvalue ownership is not transsferred
void AlterResource(unique_ptr<int>ptr)
{
*ptr=100;
 cout<<"Resource inside function "<<*ptr<<endl;
// cout<<"Adress of resource inside function "<<ptr<<endl;
 }

int main()
{

unique_ptr<int>uniqueptr=make_unique<int>(42);

cout<<"unique ptr before function call "<<*uniqueptr<<endl;
cout<<"Adress of uiqueptr resouce "<<uniqueptr.get()<<endl;

//AlterResource(uniqueptr.get());
AlterResource(move(uniqueptr));
//cout<<"uniqueptr after function call "<<*uniqueptr<<endl;
//cout<<"Address of uniqueptr resouce "<<uniqueptr.get()<<endl;

if(!uniqueptr)
cout<<"uniqueptr is null after function"<<endl;
else
cout<<"Uniqueptr still holds the resouce"<<endl;

}

