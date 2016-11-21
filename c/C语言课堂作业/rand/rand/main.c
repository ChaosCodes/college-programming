//
//  main.c
//  rand
//
//  Created by Zeng Mac on 2016/11/8.
//  Copyright © 2016年 Zeng Mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
void inprint1(int array[],int NUM);
void swap(int * a,int * b);

int main() {
    int cases;
    scanf("%d", &cases);
    int num[cases],num1[cases];
    for(int inn = 0;inn < cases;inn++){
        scanf("%d", &num[inn]);
        num1[inn] = num[inn];
    }
    unsigned seed;
    scanf("%u", &seed);
    srand(seed);
    inprint1(num,cases);
    inprint1(num1,cases);
    return 0;
}

void inprint1(int array[],int NUM){
    int count = NUM;
    for(int inn = 0;inn < NUM;inn++){
        int random = rand() % count;
        swap(&array[count - 1], &array[random]);
        count--;
    }
    printf("{%d",array[0]);
    for(int inn = 1;inn < NUM;inn++)
        printf(", %d",array[inn]);
    printf("}\n");
}
