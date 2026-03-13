#include <iostream>
#include<map>
#include<unordered_map>
#include<list>
#include<utility>
#include<climits>
#include<iomanip>
using namespace std;


class UnDirectedGraph
{
	unordered_map<string,list<pair<string,int>>>adjlist;

	public:

	void AddEdge(string u,string v,int distance)
	{
		adjlist[u].push_back({v,distance});
		adjlist[v].push_back({u,distance});
	}

	void print()
	{
		for(const auto& vertex:adjlist)
		{
			cout<<"City:"<<setw(2)<<vertex.first<<"->";
			for(const auto& [node,time]:vertex.second)
			{
				cout<<setw(2)<<"["<<node<<","<<time<<"]"<<" ";
			}
			cout<<endl;
		}
	}

	pair<string,int> Shortest_Time(string vertex)
	{
		int flag=0,min=INT_MAX;
		string result=" ";
		for(auto& scity:adjlist)
		{
			if(scity.first==vertex)
			{
				flag=1;
				for(auto& [dcity,distance]:scity.second)
				{
					if(min > distance)
					{
						min=distance;
						result=dcity;
					}
				}
			}
			if(flag==1)
				return {result,min};
		}
		return {"Not Found",0};
	}

};

int main() {
	UnDirectedGraph g;
	g.AddEdge("Knr","Jgtl",80);
	g.AddEdge("Knr","Mll",90);
	g.AddEdge("Jgtl","MTPL",50);
	g.AddEdge("Jgtl","HYD",180);
	g.AddEdge("HYD","Knr",200);
	g.AddEdge("MTPL","Mll",90);
	g.AddEdge("Mll","Jgtl",15);
	g.print();
	pair<string,int>result=g.Shortest_Time("Knr");
	cout<<"The shortest distance from Knr to ["<<result.first<<"] is : ["<<result.second<<"kms]"<<endl;
	return 0;
}



