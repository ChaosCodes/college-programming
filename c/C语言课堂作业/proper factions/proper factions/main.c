//
//  main.c
//  proper factions
//
//  Created by Zeng Mac on 2016/11/5.
//  Copyright © 2016年 Zeng Mac. All rights reserved.
//

#include <stdio.h>

int main() {
    int low;
    double num;
    double NUM[200];
    int count = 0;
    scanf("%d%lf",&low, &num);
    for(int i = 2;i <= low;i++){
        for(int n = 1;n < i;n++){
            if((double)n/i >= num)
                continue;
            int m;
            for(m = 0;m < count;m++){
                if((double)n/i == NUM[m])
                    break;
            }
            if(m == count){
                printf("%d/%d\n",n,i);
                NUM[count] = (double)n/i;
                count++;
            }
        }
    }
    return 0;
}
