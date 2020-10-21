#ifndef SegmentT
#define ST
using namespace std;

class SegmentTree{
  private:
  vector < int> st ,A;
  int n;
  int left(int);
  int right(int);
  void build(int , int , int );
  int rmq(int , int, int , int , int );

 public:

 SegmentTree(vector<int> &);
 int RMQ(int, int );
};
#endif
