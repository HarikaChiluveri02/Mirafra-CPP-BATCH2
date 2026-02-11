#include<iostream>
#include<vector>
#include<ranges>
using namespace std;

int main()
{
vector<int>v={1,3,5,6,2};
vector<int>sensor={25,30,40,10,15};
auto even = v| views::filter([](int x)
{
return x % 2==0;
});

for(int x :even) //Evaluation happens here
cout<<x<<" ";

 auto sensor_filter = sensor | views::filter([](int y) {
        return y > 25; 
    });

    cout << "\nSensor values > 25: ";
    for (int y : sensor_filter) cout << y << " ";
    cout << endl;

/*auto sensor_filter = sensor | views::filter([](int y)
{
return y>25;
});

for(int y : sensor_filter)
cout<<y<<" ";
cout<<endl;
*/
auto square = v | views::transform([](int x)
{
return x*x;
});
cout<<"Transformed Vector\n";
for(int x : square)
cout<<x<<" ";
cout<<endl;
cout<<"finding even from v:"<<endl;
for(int x : even) //original will not getting changed
cout<<x<<" ";
}
