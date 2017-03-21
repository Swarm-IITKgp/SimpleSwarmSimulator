#include <bits/stdc++.h>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "SwarmBot.h"

using namespace std;
using namespace cv;

#define PI 3.14159
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
  /*for(int i=bots.at(bots.size()-1).x-BotSize;i<=bots.at(bots.size()-1).x+BotSize;i++){
    for(int j=bots.at(bots.size()-1).y-BotSize;j<=bots.at(bots.size()-1).y+BotSize;j++){
      if(isValid(i,j)){
	A.at<Vec3b>(j,i)[0]=A.at<Vec3b>(j,i)[1]=A.at<Vec3b>(j,i)[2]=255;
      }
    }
  }*/
	RotatedRect bot = RotatedRect(Point2f(bots.at(bots.size() - 1).x, bots.at(bots.size() - 1).y), Size2f(2*BotSize, 2*BotSize), bots.at(bots.size() - 1).theta);
	Point2f vertices[4];
	bot.points(vertices);
	for (int i = 0; i < 4; i++)
    line(A, vertices[i], vertices[(i+1)%4], Scalar(255,255,255));

}

void showBot(SwarmBot v){
  /*for(int i=v.x-BotSize;i<=v.x+BotSize;i++){
    for(int j=v.y-BotSize;j<=v.y+BotSize;j++){
      if(isValid(i,j)){
	A.at<Vec3b>(j, i)[0]=A.at<Vec3b>(j,i)[1]=A.at<Vec3b>(j,i)[2]=255;
      }
    }
  }*/
	RotatedRect bot = RotatedRect(Point2f(v.x, v.y), Size2f(2*BotSize, 3*BotSize), v.theta * 360 / (2 * PI));
	Point2f vertices[4];
	bot.points(vertices);
	for (int i = 0; i < 4; i++)
    line(A, vertices[i], vertices[(i+1)%4], Scalar(255,255,255));
}
	
int main(){

  namedWindow("OutputWindow",WINDOW_AUTOSIZE);
 
  while(true){
    A=Mat(sizeX,sizeY,CV_8UC3,Scalar(0,0,0));
    SwarmBot v;
    vector<SwarmBot> bots=getSwarmBots();
    for(int i=0;i<bots.size();i++){
      v=bots.at(i);
      showBot(v);
    }
    imshow("OutputWindow",A);
   	char c = waitKey(10);
		if(c == 27) break;
  }
}
