//
//  main.c
//  分数相乘
//
//  Created by Zeng Mac on 2016/11/14.
//  Copyright © 2016年 Zeng Mac. All rights reserved.
//

#include <stdio.h>
int cacu(int num1,int num2);

int main() {
    int cases;
    scanf("%d", &cases);
    for(int i = 0;i < cases;i++){
        int up1,down1,up2,down2;
        int first,second;
        scanf("%d%d%d%d",&up1,&down1,&up2,&down2);
        if(down1 == 0 || down2 == 0)
            printf("Not A Number\n");
        else if(up1 == 0 || up2 == 0)
            printf("%d\n",0);
        else{
            first = up1 * up2;
            second = down1 * down2;
            up1 = cacu(first, second);
               if(second / up1 == 1)
                printf("%d\n",first/up1);
            else{
                printf("%d/%d\n",first/up1,second/up1);
            }
        }
    }
    return 0;
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
