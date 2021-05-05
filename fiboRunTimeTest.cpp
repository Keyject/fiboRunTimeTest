#include <iostream>
#include <cstdlib>
#include <math.h>
#include <ctime>
using namespace std;

long long int fibo1(int num)
{
  if (num <= 1)
  {
    return num;
  }
  return fibo1(num - 1) + fibo1(num - 2);
}

long long int fibo2(int num)
{
  long long int arr[num + 1];
  arr[0] = 0;
  arr[1] = 1;
  for (int i = 2; i <= num; i++)
  {
    arr[i] = arr[i - 1] + arr[i - 2];
  }
  return arr[num];
}

void timeDiffCalculate(int args)
{
  double timeFunction1, timeFunction2, diff;
  time_t tStart, tEnd;
  tStart = time(0);
  int temp = fibo1(args);
  // cout << "\n\t" << temp << "\n";
  tEnd = time(0);
  timeFunction1 = difftime(tEnd, tStart);

  tStart = time(0);
  temp = fibo2(args);
  // cout << "\n\t" << temp << "\n";
  tEnd = time(0);
  timeFunction2 = difftime(tEnd, tStart);

  diff = timeFunction1 > timeFunction2 ? timeFunction1 - timeFunction2 : timeFunction2 - timeFunction1;
  cout << "\nfibo1 run in :" << timeFunction1 << "\nfibo2 run in : " << timeFunction2 << "\ndiff : " << diff;
}
int main()
{
  timeDiffCalculate(100);

  return 0;
}