#include <bits/stdc++.h>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "SwarmBot.h"

using namespace std;
using namespace cv;

int sizeX=600;
int sizeY=600;
int BotSize=10;

vector<SwarmBot>bots;
Mat A;
int botCount=0;

bool isValid(int i,int j){
  return (i>=0 && i<=sizeX && j>=0 && j<=sizeY);
}

void showBot(){
	/*
  for(int i=bots.at(bots.size()-1).x-BotSize;i<=bots.at(bots.size()-1).x+BotSize;i++){
    for(int j=bots.at(bots.size()-1).y-BotSize;j<=bots.at(bots.size()-1).y+BotSize;j++){
      if(isValid(i,j)){
	A.at<Vec3b>(j,i)[0]=A.at<Vec3b>(j,i)[1]=A.at<Vec3b>(j,i)[2]=255;
      }
    }
  }*/
	RotatedRect bot = RotatedRect(Point2f(bots.at(bots.size() - 1).x, bots.at(bots.size() - 1).y), Size2f(2*BotSize, 3*BotSize), bots.at(bots.size() - 1).theta);
	Point2f vertices[4];
	bot.points(vertices);
	for (int i = 0; i < 4; i++)
    line(A, vertices[i], vertices[(i+1)%4], Scalar(255,255,255));
	//cout << bots.at(bots.size() - 1).x << " " << bots.at(bots.size() - 1).y << endl;
}
	
void CallBackFunc(int event, int i, int j, int flags, void* userdata){
  if(event == EVENT_LBUTTONDOWN){
    bots.push_back(SwarmBot(botCount,i,j));
    botCount++;
    showBot();
    imshow("InputWindow",A);
  }
  else if(event == EVENT_RBUTTONDOWN){
    fstream fs;
		fs.open("POSE.txt" , ios::out ); 
    for(int t=0;t<bots.size();t++){
      SwarmBot v=bots.at(t);
      writeSwarmBot(v);
    }
    fs.close();
    exit(0);
  }
}

int main(){

  A=Mat(sizeX,sizeY,CV_8UC3,Scalar(0,0,0));
  namedWindow("InputWindow",WINDOW_AUTOSIZE);
  setMouseCallback("InputWindow", CallBackFunc, NULL);
  imshow("InputWindow",A);
  waitKey(0);
  return 0;

}
