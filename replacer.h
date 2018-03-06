#ifndef _REPLACER__H
#define _REPLACER__H
#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;
class replacer{
 public:
  std::vector<int> replacee;
  int way;
public:
  replacer(int s,int w);
  ~replacer();
  virtual void update(int set, int bucket) = 0;
  virtual int  which2Replace(int set);

  friend std::ostream & operator << (std::ostream & ss, replacer * rep);
};

class FIFO: public replacer{
public:
  FIFO(int s, int w):replacer(s,w){}
  ~FIFO(){}
  virtual void update(int set,int bucket);
};



class LRU: public replacer{
 public:
  std::vector<std::vector<int> > track;
 public:
 LRU(int s,int w);
  ~LRU();
  virtual void update(int set,int bucket);
};


class NMRU:public replacer{
 public:
  NMRU(int s, int w);
  ~NMRU();
  virtual void update(int set,int bucket);
};

class RND: public replacer{
 public:
  RND(int s, int w);
  ~RND();
  virtual void update(int set, int bucket);
};


#endif

