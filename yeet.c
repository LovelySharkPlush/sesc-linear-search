#include <stdio.h>
#include <stdlib.h> 

struct Node{
  int value;
  struct Node * next;
};

int main() {
  int N, k;
  scanf("%d", &N);
  scanf("%d", &k);
  struct Node head;
  struct Node RIP;
  struct Node RIP1;
  scanf("%d", &head.value);
  head.next=&RIP;
  for(int i=1;i<N;i++){
    if (i%2==1){
      scanf("%d", &RIP.value);
      RIP.next=&RIP1;
    }else{
      scanf("%d", &RIP1.value);
      RIP1.next=&RIP;
    }
  }
  int last=-1, first=-1, count=0;
  struct Node curr;
  curr.next = head.next;
  curr.value = head.value;
  while (count<N){
    if (curr.value==k){
      if (first==-1){first=count;}
      last=count;
    }
    count++;
    curr.value=curr.next->value;
    curr.next=curr.next->next;
  }
  printf("%d %d", first, last);
  return 0;
}
