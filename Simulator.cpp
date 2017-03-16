#include <bits/stdc++.h>
#include <pthread.h>
#include <string>
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
  
  pthread_t disp_thread;
  int rc=pthread_create(&disp_thread,NULL,display,NULL);
  if (rc){
    cout << "Error:unable to create thread," << rc << endl;
    exit(-1);
  }

  string s=argv[1];
  pthread_t threads[NUM_THREADS];
  FILE *fp;
  SwarmBot v;
  int i=0;
  fp=fopen("POSE.dat","rb");
  if(fp){
    while(fread(&v,sizeof(SwarmBot),1,fp) != 0){
      string temp_s;
      temp_s=s+' '+to_string(v.BotID);
      rc=pthread_create(&threads[i],NULL,algo,(void *)&temp_s);
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
