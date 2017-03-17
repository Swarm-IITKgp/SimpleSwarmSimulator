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
    if(BOT_ID%2 ==0)
      forward(BOT_ID);
    else
      backward(BOT_ID);
  }
  return 0;
  
}
