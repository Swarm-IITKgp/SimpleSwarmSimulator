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
    if(BOT_ID%2)
       rightTurn(BOT_ID,10,300,300,50,75);
    else
       leftTurn(BOT_ID,10,300,300,50,75);
  }
  return 0;
  
}
