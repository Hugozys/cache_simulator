#include "replacer.h"

int replacer::which2Replace(int set){
  return replacee[set];
}



replacer::replacer(int s, int w):replacee(s),way(w){}

replacer::~replacer(){}




void FIFO::update(int set, int bucket){
  replacee[set] = (replacee[set] + 1) % way; //update only happened when kick out
}


LRU::LRU(int s, int w):replacer(s,w),track(s){
  for (int i = 0; i < s; i++){
      track[i] = vector<int> (w,0);
      for (int j = 0; j < w; j++){
	track[i][j] = w - 1 - j; // suppose we have 5-way, initial value should be 4 3 2 1 0
      }
  }
}


LRU::~LRU(){}


void LRU::update(int set, int bucket){
  int temp = track[set][bucket];
    track[set][bucket] = 0; //this becomes most recently use
    for (int i = 0; i < (int) track[set].size(); ++i){
      if( i != bucket){ //skip the bucket that we have already changed
	if (track[set][i] < temp ){ //if the value inside of the bucket is less than the value replaced
	  ++track[set][i];   //increment by 1
	}
      }
    }
    for (int i = 0; i < (int) track[set].size(); ++i){
      if(track[set][i] == way - 1){
	replacee[set] = i;
	break;
      }
    }
}


NMRU::NMRU(int s, int w):replacer(s,w){}

NMRU::~NMRU(){}

void NMRU::update(int set, int bucket){
  if (bucket == 0){
      replacee[set] = bucket + 1;
    }
    else{
      replacee[set] = bucket - 1;
    }  
}

RND::RND(int s, int w):replacer(s,w){}

RND::~RND(){}

void RND::update(int set, int bucket){
    replacee[set] = rand() % (way);
}

