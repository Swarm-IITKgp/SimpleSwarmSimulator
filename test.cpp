#include "SwarmBot.h"
#include <bits/stdc++.h>
#include <unistd.h>
#include "Motion.h"
#include "Communication.h"

using namespace std;

int BOT_ID;

int main(int argcs, char** argv){
  SwarmBot v;
  vector<SwarmBot>bots;
  BOT_ID=atoi(argv[1]);
  while(true){
		 bots=getAllPose();
     move(BOT_ID, 10, 75.0, 50.0);
  }
  return 0;
  
}
