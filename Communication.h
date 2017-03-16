#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <bits/stdc++.h>
#include "SwarmBot.h"

using namespace std;

vector<SwarmBot> getAllPose(){
  FILE *fp;
  vector<SwarmBot>bots;
  fp=fopen("POSE.dat","rb");
  SwarmBot v;
  while(fread(&v,sizeof(SwarmBot),1,fp) != 0){
    bots.push_back(v);
  }
  fclose();
  return bots;
}

#endif



