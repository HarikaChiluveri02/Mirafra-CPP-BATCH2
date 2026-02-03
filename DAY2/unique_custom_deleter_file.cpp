#include<iostream>
#include<memory>

using namespace std;

class FileDeleter
{
public:void operator()(FILE* file)const
{
if(file)
{
cout<<"Closing File through Custom deleter"<<endl;
fclose(file);
}
}
};

int main()
{
unique_ptr<FILE,FileDeleter>filePtr(fopen("example.txt","w"));
if(filePtr)
cout<<"Opened succesfully"<<endl;
}
