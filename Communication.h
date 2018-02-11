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
    fs.read((char*)&v,sizeof(SwarmBot));
    bots.push_back(v);
  }
  fs.close();
  return bots;

}


#endif



