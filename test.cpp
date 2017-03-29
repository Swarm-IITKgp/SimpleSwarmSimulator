#include "SwarmBot.h"
#include <bits/stdc++.h>
#include <unistd.h>
#include "Motion.h"

using namespace std;

int BOT_ID;

int main(int argcs, char** argv){
	SwarmBot v;
	vector<SwarmBot>bots;
	BOT_ID=atoi(argv[1]);
	while(true){
		bots=getSwarmBots();
		//move(BOT_ID, 10, 75.0, 50.0);
		run(BOT_ID,10,300,300,180);
	}
	return 0;

}
