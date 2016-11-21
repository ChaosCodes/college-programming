//
//  main.c
//  公约数
//
//  Created by Zeng Mac on 2016/11/15.
//  Copyright © 2016年 Zeng Mac. All rights reserved.
//

#include <stdio.h>

int cacu(int num1,int num2);

int main() {
    int fir,sec;
    scanf("%d%d",&fir, &sec);
    if(sec == 0)
        printf("invalid\n");
    else{
        int num;
        num = cacu(fir,sec);
        printf("%d %d\n",num,fir * sec / num);
    }
}

int cacu(int num1,int num2){
    while (num1 != num2) {
        if(num1 < num2){
            int exc;
            exc = num2;
            num2 = num1;
            num1 = exc;
        }
        int middle;
        middle = num1;
        num1 = num2;
        num2 = middle - num2;
    }
    return num1;
}
