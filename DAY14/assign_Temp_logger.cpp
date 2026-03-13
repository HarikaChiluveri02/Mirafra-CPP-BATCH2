#include <iostream>
#include <memory>
#include <optional>
#include <string>

using namespace std;

class Temp_logger
{
struct Node
{
string ID;
double temp;
unique_ptr<Node>left;
unique_ptr<Node>right;

Node(string id,double t):ID(id),temp(t)
{}

};
unique_ptr<Node>root;

public: 
void InsertReading(string id,double t)
{
Insertimply(root,id,t);
}

optional<double>SearchbyID(string id)
{
Node* res=Searchimply(root.get(),id);
if(res)
return res->temp;
return nullopt;
}

void Traverse()
{
Inorder(root.get());
}

optional<double>Maxtemp()
{
Node* node=root.get();
while(node->right)
node=node->right.get();

if(node)
return node->temp;
return nullopt;
}

optional<double>Mintemp()
{
Node* node=root.get();
while(node->left)
node=node->left.get();

if(node)
return node->temp;
return nullopt;
}

private:

void Insertimply(unique_ptr<Node>& node,string id,double t)
{

if(node==nullptr)
{
node= make_unique<Node>(id,t);
return;
}
if(t < node->temp)
Insertimply(node->left,id,t);

else if(t > node->temp)
Insertimply(node->right,id,t);

}

Node* Searchimply(Node* node,const string& id)
{
if(!node)
return nullptr;

if(node->ID == id)
return node;

Node* Leftree=Searchimply(node->left.get(),id);
if(Leftree)
return Leftree;
return Searchimply(node->right.get(),id);
}

void Inorder(const Node* node)
{
if(node==nullptr)
return;
Inorder(node->left.get());
cout<<"Sensor ID: "<<node->ID<<" with Temperature :"<<node->temp<<endl;
Inorder(node->right.get());
}


};


int main()
{
Temp_logger obj;

cout<<"Reading Sensor data"<<endl;
obj.InsertReading("SensorA",27.3);
obj.InsertReading("SensorB",3.14);
obj.InsertReading("SensorC",15.5);
obj.InsertReading("SensorD",12.5);
obj.InsertReading("Sensor12",18.3);
obj.InsertReading("Sensor3",22.2);

cout<<"Printing Sensor Data"<<endl;
obj.Traverse();

auto res=obj.Maxtemp();
if(res)
cout<<"\nMax Temperature is : "<<*res<<endl;
else
cout<<"Max Temperature not found"<<endl;

auto result=obj.Mintemp();
if(result)
cout<<"Min Temperature is : "<<*result<<endl;
else
cout<<"Min Temperature not found"<<endl;

auto temp=obj.SearchbyID("Sensor3");
if(temp)
cout<<"\nSensor Found by ID : Sensor3 with Temperature "<<*temp<<endl;
else
cout<<"Sensor ID is not found"<<endl;
}















