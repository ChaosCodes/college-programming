//
//  main.c
//  dd
//
//  Created by Zeng Mac on 2016/11/14.
//  Copyright © 2016年 Zeng Mac. All rights reserved.
//

#include <stdio.h>

int judge(long int block,int base);
int digits[100];
int count;
int main() {
    int cases;
    scanf("%d", &cases);
    for(int i = 0;i < cases;++i){
        long int num;
        scanf("%ld", &num);
        while(1){
            num++;
            count = 0;
            for(int n = 2;n <= 10;n++){
                if(judge(num,n) == 1)
                    count++;
                if(count == 2)
                    break;
            }
            if(count == 2)
                break;
        }
        printf("%ld\n",num);
    }
    return 0;
}

int judge(long int block,int base){
    int num = 0;
    while (block > 0) {
        digits[num++] = block % base;
        block = block / base;
    }
    for(int m = 0;m < num/2;m++){
        if(digits[m] != digits[num - 1 - m])
            return 0;
    }
    return 1;
}
