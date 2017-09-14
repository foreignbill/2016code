#include <stdio.h>
#include <stdlib.h>
#define N 1000001
typedef struct{
   int value;
   int index;
}QUE;
QUE min_que[N], max_que[N];
int n, k, num[N],front,rear;
int delete_rear_inc(int f, int r, int d){
   int mid;
   while(f <= r){
      mid = (f+r)/2;
      if( min_que[mid].value == d )
         return mid;
      if( min_que[mid].value > d)
          r = mid-1;
      else
          f = mid + 1;
   }
   return f;
}
int delete_rear_dec(int f, int r, int d){
   int mid;
   while(f <= r){
      mid = (f+r)/2;
      if( max_que[mid].value == d)
         return mid;
      if( max_que[mid].value > d)
          f = mid + 1;
      else
          r = mid - 1;
   }
   return f;
}
 
main(){
   int  i;
       scanf("%d %d",&n,&k);
       for(i=1;i<=n;i++)
          scanf("%d",&num[i]);
       min_que[1].value = num[1];
       min_que[1].index = 1;
       front = 1;
       rear = 1;
       for(i=2;i<=k;i++){ 
           rear = delete_rear_inc(front,rear,num[i]);
           min_que[rear].value = num[i];
           min_que[rear].index = i;
       }
       printf("%d",min_que[1].value);

       for(i=k+1;i<=n;i++){ 
           rear = delete_rear_inc(front,rear,num[i]);
           min_que[rear].value = num[i];
           min_que[rear].index = i;
           if( i - min_que[front].index >= k)
              front ++;
           printf(" %d",min_que[front].value);
       }
       printf("\n");
       max_que[1].value = num[1];
       max_que[1].index = 1;
       front = 1;
       rear = 1;
       for(i=2;i<=k;i++){
           rear = delete_rear_dec(front,rear,num[i]);
           max_que[rear].value = num[i];
           max_que[rear].index = i;
       }
       printf("%d",max_que[1].value);
       for(i=k+1;i<=n;i++){
           rear = delete_rear_dec(front,rear,num[i]);
           max_que[rear].value = num[i];
           max_que[rear].index = i;
           if(i - max_que[front].index >= k)
              front ++;
           printf(" %d",max_que[front].value);
       }
       printf("\n");
   system("pause");
   return 0;
}