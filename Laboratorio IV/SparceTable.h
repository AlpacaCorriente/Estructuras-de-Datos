#ifndef SparceT
#define STABLE
#define LOG_TWO_N 10
#define MAX_N 1000

using namespace std;

class SparceTable{
  private:
  int A[MAX_N], SpT[MAX_N][LOG_TWO_N];
 public:
 SparceTable(int , vector<int> &);
 int query(int, int);
};
#endif
