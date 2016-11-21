//
//  main.c
//  简单归并
//
//  Created by Zeng Mac on 2016/11/21.
//  Copyright © 2016年 Zeng Mac. All rights reserved.
//

#include <stdio.h>
int num[100];
void gsort(int start,int end,int all);

int main() {
    int n;
    scanf("%d",&n);
    if(n == 0)
        return 0;
    for(int i = 0;i < n;i++)
        scanf("%d",&num[i]);
    gsort(0, n-1,n);
    return 0;
}

void gsort(int start,int end,int all){
    if(start == end)
        return;
    gsort(start,(start + end)/2,all);
    gsort((start + end)/2 + 1, end,all);
    //int temp[end - start + 1];
    int temp[200];
    int i = start,m = (start + end)/2 + 1,count = 0;
    while(i <= (start + end)/2 && m <= end){
        if(num[i] < num[m])
            temp[count] = num[i++];
        else
            temp[count] = num[m++];
        count++;
    }
    if(i > (start + end)/2)
        for(;m <= end;m++){
            temp[count] = num[m];
            count++;
        }
    else{
        for(;i <= end;i++){
            temp[count] = num[i];
            count++;
        }
    }
    count = 0;
    for(int p = start;p <= end;p++){
        num[p] = temp[count++];
    }
    count = 0;
    printf("%d",num[0]);
    for(int k = 1;k < all;k++)
        printf(" %d",num[k]);
    printf("\n");
    return;
}
