#ifndef SWARMBOT
#define SWARMBOT

#include <bits/stdc++.h>

class SwarmBot{
 public :
  int BotID;
  float x;
  float y;
  float theta;
  float RPM;
  SwarmBot(int id){
    x=0;
    y=0;
    theta=0;
    RPM=75;
    BotID=id;
  }
  SwarmBot(int id,int x1, int x2){
    x=x1;
    y=x2;
    theta=0.0;
    RPM=75;
    BotID=id;
  }
  SwarmBot(){
    x=0;
    y=0;
    theta=0;
    RPM=75;
    BotID=0;
  }
};

#endif
