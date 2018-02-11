#include <bits/stdc++.h>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "SwarmBot.h"

using namespace std;
using namespace cv;

int sizeX=600;
int sizeY=600;
int BotSize=10;

vector <Points> pts;
Mat A;
int destCount=0;

bool isValid(int i,int j){
  return (i>=0 && i<=sizeX && j>=0 && j<=sizeY);
}

void showDest(){
  circle( A , Point2i(pts.at(pts.size()-1).x , pts.at(pts.size()-1).y) , 5 , Scalar( 0, 0, 255 ) , -1 , 8);
}
	
void CallBackFunc(int event, int i, int j, int flags, void* userdata){
  if(event == EVENT_LBUTTONDOWN){
    Points p;
    p.x=i;
    p.y=j; 
    pts.push_back(p);
    destCount++;
    showDest();
    imshow("InputDestWindow",A);
  }
  else if(event == EVENT_RBUTTONDOWN){
    fstream fs;
		fs.open("Dest.txt" , ios::out ); 
    for(int t=0;t<pts.size();t++){
      Points p=pts.at(t);
      destination(p);
    }
    fs.close();
    exit(0);
  }
}

int main(){

  A=Mat(sizeX,sizeY,CV_8UC3,Scalar(0,0,0));
  namedWindow("InputDestWindow",WINDOW_AUTOSIZE);
  setMouseCallback("InputDestWindow", CallBackFunc, NULL);
  imshow("InputDestWindow",A);
  waitKey(0);
  return 0;

}
