#ifndef SWARMBOT_H
#define SWARMBOT_H

#include <bits/stdc++.h>

using namespace std;

class SwarmBot{
 public :
  int BotID;
  float x;
  float y;
  float theta;
  SwarmBot(int id){
    x=0;
    y=0;
    theta=0;
    BotID=id;
  }
  SwarmBot(int id,int x1, int x2){
    x=x1;
    y=x2;
    theta=0.0;
    BotID=id;
  }
  SwarmBot(){
    x=0;
    y=0;
    theta=0;
    BotID=0;
  }
};

void writeSwarmBot(SwarmBot v){
  fstream fs;
  fs.open("POSE.txt",ios::app);
  fs.write((char*)&v,sizeof(SwarmBot));
  fs.close();
}


vector<SwarmBot> getSwarmBots(){
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
