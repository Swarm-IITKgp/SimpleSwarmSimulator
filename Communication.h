#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <bits/stdc++.h>
#include "SwarmBot.h"

using namespace std;

vector<SwarmBot> getAllPose(){
  vector<SwarmBot> bots;
  SwarmBot v;
  fstream fs;
  fs.open("POSE.txt");
  while(!fs.eof()){
    fs>>v.BotID>>v.x>>v.y>>v.theta>>v.RPM;
    bots.push_back(v);
  }
  return bots;
}

#endif



