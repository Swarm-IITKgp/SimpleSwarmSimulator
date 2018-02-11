#include "SwarmBot.h"
#include <bits/stdc++.h>
#include <unistd.h>
#include "Motion.h"
#include "Communication.h"

using namespace std;

int BOT_ID;

int main(int argcs, char** argv){
	
	SwarmBot v;
	Points p;
	vector<SwarmBot>bots;
	vector<Points> pts;
	map<int,Points> mp;
	int *d,*key,j;
	BOT_ID=atoi(argv[1]);
	d=(int*)malloc(pts.size()*sizeof(int));
	key=(int*)malloc(pts.size()*sizeof(int));
	pts=getAllDest();
	bots=getAllPose();
	
	for(int i=0;i<pts.size();i++){
		mp[i]=pts[i];
	}
	cout<<BOT_ID<<endl;
	for(j=0;j<=BOT_ID;j++){
		
		for(int i = 0; i <pts.size()-1 ; ++i){

			d[i] = (pts[i].x - bots[j].x)*(pts[i].x - bots[j].x)+(pts[i].y - bots[j].y)*(pts[i].y - bots[j].y);
				if(i != 0){
					if(d[i]<d[0]){
						int swap=d[i];
						d[i]=d[0];
						d[0]=swap;
						key[j]=i;
						mp[j]=pts[i];
				}
			}
			else{
				
				key[j]=i;
				mp[j]=pts[i];
				}
		}	cout<<pts.size()<<" "<<key[j]<<endl;
			pts.erase(pts.begin()+key[j]);
			//if(j==3||j==2)
				cout<<"hi"<<j<<" "<<pts.size()<<" "<<mp[j].x<<" "<<mp[j].y<<endl;
				

	}
	
	while(true){

			pts=getAllDest();
			run( BOT_ID , 10 , mp[BOT_ID].x , mp[BOT_ID].y , 180 );

	}


	/*while( true ){
	
		bots=getAllPose();
		

		for(int i=0; i < pts.size() ; i++){
			d[i] = (pts[i].x - bots[BOT_ID].x)*(pts[i].x - bots[BOT_ID].x)+(pts[i].y - bots[BOT_ID].y)*(pts[i].y - bots[BOT_ID].y);
			if(i!=0){
				if(d[i]<d[0]){
					int swap=d[i];
						d[i]=d[0];
						d[0]=swap;
						key=i;

				}
			}
			else
				key=0;
		}
		run( BOT_ID , 10 , pts[key].x , pts[key].y , 180 );
		//pts.erase(pts.begin()+key);
		//move(BOT_ID, 10, 75.0, 50.0);
		//if(bots[BOT_ID].x>30&&bots[BOT_ID].y>100)
		/*if( BOT_ID > 0)
		{	
			//while(i<bots.size()){
			
			//if(bots[0].x>bots[BOT_ID].x)
				run( BOT_ID , 10 , pts[BOT_ID].x , pts[BOT_ID].y , 180 );
			
			//else
			//	run(BOT_ID,10,300,300,180);
		}
		else
			run( BOT_ID , 10 , pts[BOT_ID].x , pts[BOT_ID].y , 180 );
			*/
		
	//}
	return 0;

}
