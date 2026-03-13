#include <iostream>
#include<map>
#include<unordered_map>
#include<list>
#include<utility>
#include<climits>

using namespace std;


class DirectedGraph
{
	unordered_map<string,list<pair<string,int>>>adjlist;

	public:

	void AddEdge(string u,string v,int time)
	{
		adjlist[u].push_back({v,time});
	}

	void print()
	{
		for(const auto& vertex:adjlist)
		{
			cout<<"City:"<<vertex.first<<"->";
			for(const auto& [place,time]:vertex.second)
			{
				cout<<"["<<place<<","<<time<<"]"<<" ";
			}
			cout<<endl;
		}
	}

	pair<string,int> Shortest_Time(string vertex)
	{
		int flag=0,min=INT_MAX;
		string result=" ";
		for(auto& splace:adjlist)
		{
			if(splace.first==vertex)
			{
				flag=1;
				for(auto& [dcity,time]:splace.second)
				{
					if(min > time)
					{
						min=time;
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
	DirectedGraph g;
	g.AddEdge("Ameerpet","srnagar",8);
	g.AddEdge("Ameerpet","Begumpet",10);
	g.AddEdge("Begumpet","Jublie Hills",40);
	g.AddEdge("Prakashnagar","Madhapur",35);
	g.AddEdge("Madhapur","Hitech city",12);
	g.AddEdge("Kothaguda","Hitech city",20);
	g.AddEdge("Jublie Hills","Ameerpet",30);
	g.print();
	pair<string,int>result=g.Shortest_Time("Ameerpet");
	cout<<"The shortest time from Ameerpet to ["<<result.first<<"] is : ["<<result.second<<"mins]"<<endl;
	return 0;
}



