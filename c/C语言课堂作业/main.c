//
//  main.c
//  逃跑问题
//
//  Created by Zeng Mac on 2016/11/21.
//  Copyright © 2016年 Zeng Mac. All rights reserved.
//

#include <stdio.h>

int magic,distance,totime,now_time,now_dis;
int whether_end();
int escape();
int game();
/*
int main() {
    int flag = 0;
    while(scanf("%d%d%d",&magic,&distance,&totime) != 3){
        flag = 0;
        while(magic >= 10){
            magic -= 10;
            now_dis += 60;
            now_time++;
            if(whether_end() == 1){
                flag = 1;
                break;
            }
        }
        if(flag == 1)
            continue;
        while(escape() != 1){
            if(whether_end() == 1){
                flag = 1;
                break;
            }
        }
        if(flag == 1)
            continue;
        while(whether_end() != 1){
            now_dis += 17;
            now_time++;
     }
    }
    return 0;
}*/
int main (){
    while (game() != 1)
         continue;
    return 0;
}


int whether_end(){
    if(now_time >= totime && now_dis < distance){
        printf("No\n%d\n",now_dis);
        return 1;
    }
    if(now_dis >= distance){
        printf("Yes\n%d\n",now_time);
        return 1;
    }

    return 0;
}


int escape(){
    switch (magic) {
        case 1:
        case 0:
            if(totime - now_time < 7)
                return 1;
            if(distance - now_dis < 120)
                return 1;
            now_dis += 120;
            now_time += 7;
            break;
        case 3:
        case 4:
        case 5:
        case 2:
            if(totime - now_time < 3)
                return 1;
            if(distance - now_dis <= 51)
                return 1;
            now_dis += 60;
            now_time += 3;
            break;
        case 6:
        case 7:
        case 8:
        case 9:
            if(totime - now_time < 2)
                return 1;
            if(distance - now_dis <= 34)
                return 1;
            now_dis += 60;
            now_time += 2;
            break;
        default:
            break;
    }
    
    return 0;
}
int game(){
    now_dis = 0;now_time = 0;
    if(scanf("%d%d%d",&magic,&distance,&totime) != 3)
        return 1;
    while(magic >= 10){
        magic -= 10;
        now_dis += 60;
        now_time++;
        if(whether_end() == 1)
            return 0;
    }
    while(escape() != 1){
        if(whether_end() == 1)
            return 0;
    }
    while(whether_end() != 1){
        now_dis += 17;
        now_time++;
    }
    return 0;
}
