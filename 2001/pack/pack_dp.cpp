#include <stdio.h>
#include <string.h>

#define MAX 20000

/*
动态规划，设：dp[i,j] 表示选前i个物品刚好能装满 j 空间 (bool),则有：
dp[i,j] = a[i-1, j] or a[i-1, j-v[i]]  j>v[i]
a[i,0] = 0 ;
不过，这题有点特殊：
就是：
a[i,j]只与: i-1有关
所以可以降到一维...
*/
int main(void)
{
   int V; // volumn of the box;
   int n; // number of items
   scanf ("%d", &V);
   scanf ("%d", &n);

   int* items = new int [n]; // storing the volum of each item
   for (int i = 0; i < n; i++) {
      scanf ("%d", &items[i]);
   }

   bool* dp = new bool [MAX+1]; // from 0 to MAX
   memset (dp, 0, sizeof(bool)* (MAX+1));
   dp [0] = true; // 0 item can fill volumn 0
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < MAX+1; j++) {
         if (j >= items [i]) {
            dp[j] |= dp[ j - items[i]];
         }
      }
   }
   
   for (int j = MAX; j >=1; j--) {
      if (dp[j]) {
         printf ("%d\n", MAX-j);
         break;
      }
   }
   delete [] dp;
   delete [] items;
   return 0;
}
