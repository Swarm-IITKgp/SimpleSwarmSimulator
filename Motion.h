#ifndef MOTION_H
#define MOTION_H

#include <bits/stdc++.h>
#include <unistd.h>
#include "SwarmBot.h"

//Remember this also includes a constant factor for conversion of RPM to rotations per milisecond.
#define WHEEL_RADIUS_CONSTANT 0.001
#define PI 3.14159
#define THRESHOLD 60.0

//10% error, unlike me, pretty accurate :P
float ERROR_PERCENTAGE=0.1;
float TURN_ERROR=1;
float TURN_CONSTANT=0.1;
int BotSize = 10;
/*
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
*/
void move(int BotID, int t = 10, float leftRPM = 0, float rightRPM = 0) {
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

	float velLeft = leftRPM * WHEEL_RADIUS_CONSTANT;
	float velRight = rightRPM * WHEEL_RADIUS_CONSTANT;
	//Assuming rotation around a fixed point (JEE ki yaad dila di! :D )
	float angVel = (velRight - velLeft) / (2 * BotSize);
	float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

	if(velLeft != velRight) {
		float AngRadius = (velLeft + velRight) * BotSize / (velRight - velLeft);
		float rotCenter_x = v.x + AngRadius * sin(v.theta);
		float rotCenter_y = v.y - AngRadius * cos(v.theta);
		float del_theta = -1 * angVel * t;

   	del_theta += (del_theta * (fmod(r,ERROR_PERCENTAGE)));
		v.theta += del_theta;

		while(v.theta > 2*PI) 
			v.theta -= 2*PI;
		while(v.theta < 0)
			v.theta += 2*PI;

		r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		v.x = rotCenter_x - AngRadius * sin(v.theta);
		v.x += (TURN_ERROR * (fmod(r,ERROR_PERCENTAGE)));
		r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		v.y = rotCenter_y + AngRadius * cos(v.theta);
		v.y += (TURN_ERROR * (fmod(r,ERROR_PERCENTAGE))); 
		//cout << v.x << " 10 " << v.y << " " << v.theta * 180 / (2*PI) << endl;
	}
	else {
		float vel = leftRPM * WHEEL_RADIUS_CONSTANT;
		float del_x = vel * t * cos(v.theta);
		float del_y = vel * t * sin(v.theta);
		
		r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		del_x += (del_x * fmod(r, ERROR_PERCENTAGE));
		v.x += del_x;
		r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		del_y += (del_y * fmod(r, ERROR_PERCENTAGE));
		v.y += del_y;
		//cout << v.x << " " << v.y << " " << v.theta << endl;
	}

  long pos = fs.tellp();
  fs.seekp(pos - sizeof(SwarmBot), ios::beg);
  fs.write((char*)&v, sizeof(SwarmBot));
  fs.close();
  usleep(t*1000);
}

//moves from intial position to i,j(destination)in a straight line smoothly
//1-x^2+0.5x^3-0.5x^4+2x^5-2x^6
void run(int BotID, int t = 10,int i = 0,int j = 0,float MAX_RPM = 0) {
  srand (time(NULL));
  SwarmBot v;
  v.BotID=-1;
  fstream fs;
  fs.open("POSE.txt");
  while(!fs.eof() && v.BotID!=BotID){
    fs.read((char*)&v,sizeof(SwarmBot));
  }
  
  if(t>10) t=10;

  const static float init_x = v.x;
  const static float init_y = v.y;
  float RPM;
  float a;
  
  //slope
  v.theta = atan2(j-init_y,i - init_x);
  float beta = (j-init_y)/(i - init_x);
  float alpha = (j-v.y)/(i-v.x);
  float threshold = min((float)THRESHOLD,sqrt(pow(i - init_x,2) + pow(j - init_y,2))/2);
  
  float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
  if( (sqrt(pow(v.x - i,2) + pow(v.y - j,2))) < 10 || alpha*beta<0)
    RPM = 0;
  //acceleration
  else if( (sqrt(pow(v.x - init_x,2) + pow(v.y - init_y,2))) < threshold && (sqrt(pow(v.x - i,2) + pow(v.y - j,2))) > threshold ){
    a = (sqrt(pow(v.x - init_x,2) + pow(v.y - init_y,2)))/threshold;
    float asqr = pow(a,2);
    float acube = asqr * a;
    float afour = acube * a;

    RPM = (1 -asqr + 0.5 * acube - 0.5 * afour + 2 * afour * a - 2 * afour * asqr ) * MAX_RPM + 5;
  }
  //constant velocity
  else if((sqrt(pow(v.x - init_x,2) + pow(v.y - init_y,2))) > threshold && (sqrt(pow(v.x - i,2) + pow(v.y - j,2))) > threshold ){
    RPM = MAX_RPM;
  }
  //deceleration
  else if((sqrt(pow(v.x - init_x,2) + pow(v.y - init_y,2))) > threshold && (sqrt(pow(v.x - i,2) + pow(v.y - j,2)) < threshold)){ 
    a = (sqrt(pow(v.x - i,2) + pow(v.y - j,2)))/threshold; 
    float asqr = pow(a,2);
    float acube = asqr * a;
    float afour = acube * a;

    RPM = (1 -asqr + 0.5 * acube - 0.5 * afour + 2 * afour * a - 2 * afour * asqr) * MAX_RPM;
   }
  
  float velLeft = RPM * WHEEL_RADIUS_CONSTANT;
  float velRight = RPM * WHEEL_RADIUS_CONSTANT;

  float del_x = velLeft * t * cos(v.theta);
  float del_y = velRight * t * sin(v.theta);

  //print velocites
  //cout<<velLeft * 1000<<endl;
    
  r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
  del_x += (del_x * fmod(r, ERROR_PERCENTAGE));

  v.x += del_x;
  r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
  del_y += (del_y * fmod(r, ERROR_PERCENTAGE));
  v.y += del_y;

  long pos = fs.tellp();
  fs.seekp(pos - sizeof(SwarmBot), ios::beg);
  fs.write((char*)&v, sizeof(SwarmBot));
  fs.close();
  usleep(t*1000);
}


#endif
