#include <bits/stdc++.h>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "SwarmBot.h"

using namespace std;
using namespace cv;

int sizeX=600;
int sizeY=600;
int BotSize=5;

vector<SwarmBot>bots;
Mat A;
int botCount=0;

bool isValid(int i,int j){
  return (i>=0 && i<=sizeX && j>=0 && j<=sizeY);
}

void showBot(){
  for(int i=bots.at(bots.size()-1).x-BotSize;i<=bots.at(bots.size()-1).x+BotSize;i++){
    for(int j=bots.at(bots.size()-1).y-BotSize;j<=bots.at(bots.size()-1).y+BotSize;j++){
      if(isValid(i,j)){
	A.at<Vec3b>(i,j)[0]=A.at<Vec3b>(i,j)[1]=A.at<Vec3b>(i,j)[2]=255;
      }
    }
  }
}
	
void CallBackFunc(int event, int i, int j, int flags, void* userdata){
  if(event == EVENT_LBUTTONDOWN){
    bots.push_back(SwarmBot(botCount,j,i));
    botCount++;
    showBot();
    imshow("InputWindow",A);
  }
  else if(event == EVENT_RBUTTONDOWN){
    FILE *fp;
    fp=fopen("POSE.dat","wb");
    for(int t=0;t<bots.size();t++){
      SwarmBot v=bots.at(t);
      fwrite(&v,sizeof(SwarmBot),1,fp);
    }
    fclose(fp);
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
