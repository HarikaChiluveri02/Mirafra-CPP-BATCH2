#include<bits/stdc++.h>

using namespace std;
class vehicle
{
	public:
		int fuel;
		int* vnum;
		vehicle(int f=0,int v=0):fuel(f),vnum(new int(v))
	{
		cout<<"constructor"<<endl;
	}
	//	vehicle(const car&) = delete;
	//	vehicle& operator=(const car&) = delete;
		~vehicle()
		{
			delete vnum;
			cout<<"destructor"<<endl;
		}
		void transfer(vehicle&& o)
		{
			fuel=o.fuel;
			vnum=o.vnum;
			o.fuel=0;
			o. vnum=nullptr;
		}

};
void passbyvalue(vehicle o)
{
	cout<<"fuel is:"<<o.fuel<<endl;
	cout<<"vehicle number:"<<(*o.vnum)<<endl;
}
void passbyreference (vehicle& o)
{
	o.fuel=30;
	*(o.vnum)=1111;
}
void constref(const vehicle &o)
{
cout<<"fuel is:"<<o.fuel<<endl;
cout<<"vehicle number:"<<*(o.vnum)<<endl;
}
int main()
{
vehicle c1(24,5678);
vehicle c2;
passbyvalue(c1);
passbyreference(c2);
constref(c2);
vehicle c3;

c3.transfer(move(c2));
}
