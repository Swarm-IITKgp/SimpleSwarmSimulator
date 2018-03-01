#include <bits/stdc++.h>
#include <pthread.h>
#include <cstring>
#include "SwarmBot.h"

using namespace std;
#define NUM_THREADS 100

int botCount=0;

void* display(void *data){
  system("./Output");
  pthread_exit(NULL);
}

void* algo(void *data){
  string param=*((string *)data);
  system(param.c_str());
  pthread_exit(NULL);
}

int main(int argc, char** argv){

  system("./Start");
  if(argc>=2){
     string s = argv[1];
     if(!s.compare("dest-screen"))
       system("./dest");
     else if(!s.compare("circle")){
       cout<<"INSIDE\n";
      system("./circle");
    }
  }
  pthread_t disp_thread;
  int rc=pthread_create(&disp_thread,NULL,display,NULL);
  if (rc){
    cout << "Error:unable to create thread," << rc << endl;
    exit(-1);
  }

  string exec="./";
  string s=exec+argv[1];
  pthread_t threads[NUM_THREADS];
  string ar[NUM_THREADS];
  FILE *fp;
  SwarmBot v;
  int i=0;
  fp=fopen("POSE.txt","rb");
  if(fp){
    while(fread(&v,sizeof(SwarmBot),1,fp) != 0){
      string temp_s;
      string int_string=to_string(v.BotID);
      temp_s=s+" "+int_string;
      ar[i]=temp_s;
      rc=pthread_create(&threads[i],NULL,algo,(void *)&(ar[i]));
      if (rc){
	cout << "Error:unable to create thread," << rc << " for Bot ID "<<v.BotID<<endl;
      }
      i++;
    }   
    fclose(fp);
  } 
  pthread_exit(NULL);
  return 0;

}
