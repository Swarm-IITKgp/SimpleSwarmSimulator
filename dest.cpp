#include "SwarmBot.h"
#include <bits/stdc++.h>
#include <unistd.h>
#include <math.h>
#include "Motion.h"
#include "Communication.h"

#define D 20


using namespace std;

int BOT_ID;
vector <Points> pts;

int main(int argcs, char** argv){
	SwarmBot v;
	vector<SwarmBot>bots;
	bots=getAllPose();
	int numberOfBots = bots.size();
	numberOfBots-=1;
	cout<<numberOfBots<<endl;
	double theta = (360/numberOfBots)*PI/180;
	int i;
	double radius = fabs(D*20/(2*tan(theta)));
	for(i=0; i<numberOfBots; i++)
	{
		Points p;
		p.x = 300 + radius*cos(theta*i + (theta/2));
		p.y = 300 + radius*sin(theta*i + (theta/2));
		pts.push_back(p);
		cout<<p.x << "  "<< p.y<<endl;
	}

	cout<<pts.size()<<endl;
	fstream fs;
	fs.open("Dest.txt" , ios::out ); 
	for(int t=0;t<pts.size();t++){
	  Points p=pts.at(t);
	  destination(p);
	}
	fs.close();
	return 0;

}
