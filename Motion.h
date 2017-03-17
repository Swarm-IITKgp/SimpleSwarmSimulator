#ifndef MOTION_H
#define MOTION_H

#include <bits/stdc++.h>
#include <unistd.h>
#include "SwarmBot.h"

//Remember this also includes a constant factor for conversion of RPM to rotations per milisecond.
#define WHEEL_RADIUS_CONSTANT 0.001
#define PI 3.14159

//10% error, unlike me, pretty accurate :P
float ERROR_PERCENTAGE=0.1;
float TURN_ERROR=1;
float TURN_CONSTANT=0.1;

void forward(int BotID,int t=10){
  srand (time(NULL));
  SwarmBot v;
  v.BotID=-1;
  fstream fs;
  fs.open("POSE.txt");
  while(!fs.eof() && v.BotID!=BotID){
    fs.read((char*)&v,sizeof(SwarmBot));
  }
  if(t>10)
    t=10;

  // Boring, tough Maths with Randomisation.
  float delta_x=(v.RPM*WHEEL_RADIUS_CONSTANT*t)*cos(v.theta);
  float delta_y=(v.RPM*WHEEL_RADIUS_CONSTANT*t)*sin(v.theta);
  float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
  delta_x+=(delta_x * (fmod(r,ERROR_PERCENTAGE)));
  r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
  delta_y+=(delta_y * (fmod(r,ERROR_PERCENTAGE)));

  v.x+=delta_x;
  v.y+=delta_y;

  long pos=fs.tellp();
  fs.seekp(pos-sizeof(SwarmBot),ios::beg);
  fs.write((char*)&v,sizeof(SwarmBot));
  fs.close();
  usleep(t*1000);
}

void backward(int BotID,int t=10){
  srand (time(NULL));
  SwarmBot v;
  v.BotID=-1;
  fstream fs;
  fs.open("POSE.txt");
  while(!fs.eof() && v.BotID!=BotID){
    fs.read((char*)&v,sizeof(SwarmBot));
  }
  if(t>10)
    t=10;

  // Boring, tough Maths with Randomisation.
  float delta_x=(v.RPM*WHEEL_RADIUS_CONSTANT*t)*cos(v.theta);
  float delta_y=(v.RPM*WHEEL_RADIUS_CONSTANT*t)*sin(v.theta);
  float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
  delta_x+=(delta_x * (fmod(r,ERROR_PERCENTAGE)));
  r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
  delta_y+=(delta_y * (fmod(r,ERROR_PERCENTAGE)));

  v.x-=delta_x;
  v.y-=delta_y;

  long pos=fs.tellp();
  fs.seekp(pos-sizeof(SwarmBot),ios::beg);
  fs.write((char*)&v,sizeof(SwarmBot));
  fs.close();
  usleep(t*1000);
}

void rightTurn(int BotID,int t=10){
  srand (time(NULL));
  SwarmBot v;
  v.BotID=-1;
  fstream fs;
  fs.open("POSE.txt");
  while(!fs.eof() && v.BotID!=BotID){
    fs.read((char*)&v,sizeof(SwarmBot));
  }
  if(t>10)
    t=10;

  // Boring, tough Maths with Randomisation.
  float delta_x=0.0;
  float delta_y=0.0;
  float delta_theta=fmod((v.RPM * TURN_CONSTANT*t),2*PI);
  float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
  delta_x+=(TURN_ERROR * (fmod(r,ERROR_PERCENTAGE)));
  r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
  delta_y+=(TURN_ERROR * (fmod(r,ERROR_PERCENTAGE)));
  r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
  delta_theta+=(delta_theta * (fmod(r,ERROR_PERCENTAGE)));

  v.x+=delta_x;
  v.y+=delta_y;
  v.theta+=delta_theta;
  v.theta=fmod(v.theta,2*PI);

  long pos=fs.tellp();
  fs.seekp(pos-sizeof(SwarmBot),ios::beg);
  fs.write((char*)&v,sizeof(SwarmBot));
  fs.close();
  usleep(t*1000);
}

void leftTurn(int BotID, int t=10){
    srand (time(NULL));
  SwarmBot v;
  v.BotID=-1;
  fstream fs;
  fs.open("POSE.txt");
  while(!fs.eof() && v.BotID!=BotID){
    fs.read((char*)&v,sizeof(SwarmBot));
  }
  if(t>10)
    t=10;

  // Boring, tough Maths with Randomisation.
  float delta_x=0.0;
  float delta_y=0.0;
  float delta_theta=fmod((v.RPM * TURN_CONSTANT*t),2*PI);
  float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
  delta_x+=(TURN_ERROR * (fmod(r,ERROR_PERCENTAGE)));
  r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
  delta_y+=(TURN_ERROR * (fmod(r,ERROR_PERCENTAGE)));
  r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
  delta_theta+=(delta_theta * (fmod(r,ERROR_PERCENTAGE)));

  v.x+=delta_x;
  v.y+=delta_y;
  v.theta-=delta_theta;
  v.theta=fmod(v.theta,2*PI);

  long pos=fs.tellp();
  fs.seekp(pos-sizeof(SwarmBot),ios::beg);
  fs.write((char*)&v,sizeof(SwarmBot));
  fs.close();
  usleep(t*1000);
}

#endif
