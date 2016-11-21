//
//  json_parse.c
//  jason
//
//  Created by Zeng Mac on 2016/11/8.
//  Copyright © 2016年 Zeng Mac. All rights reserved.
//
#include <stdio.h>
#include <math.h>
#include "json_parse.h"


ErrCode jsonParse(const char* json_str){
    int count = 0,end;
    int blank = 0;
    int jugde = 0;
    int big = 0,small = 0;
    String str1;
    
    while(json_str[count] != '\0'){
        if(json_str[count] == '{'){
            printIndent(blank);
            printObject();
            blank++;
            if(jugde == 1){
                jugde = 0;
                big = 1;
            }
        }
        
        if(json_str[count] == '['){
            printIndent(blank);
            printArray();
            blank++;
            if(jugde == 1){
                jugde = 0;
                small = 1;
            }
        }
        
        if(json_str[count] == '"'){
            for(end = count + 1;end < MAX_SIZE + 1;end++){
                if(json_str[end] == '"')
                    break;
            }
            str1.begin = json_str + count + 1;
            str1.end = json_str + end - 1;
            count = end;
            printIndent(blank);
            if(json_str[count + 1] == ':'){
                printKey();
                count++;
                blank++;
                jugde = 1;
            }
            printString(str1);
        }
        
        if(json_str[count] >= '0' && json_str[count] <= '9'){
            int point = 0,num2 = 1;
            double sum = 0;
            for(end = count;(json_str[end] >= '0' && json_str[end] <= '9') || json_str[end] == '.';end++){
                if(json_str[end] == '.'){
                    point = 1;
                    continue;
                }
                if(point == 0)
                    sum = json_str[end] - '0' + sum * 10;
                else{
                    sum = sum + (json_str[end] - '0') * pow(10, -num2);
                    num2++;
                }
            }
            count = end - 1;
            printIndent(blank);
            printNumber(sum);
        }
        
        if(json_str[count] == ','){
            if(jugde == 1){
                jugde = 0;
                blank--;
            }
        }
        
        
        if(json_str[count] == '}'){
            blank--;
            if(big == 1){
                big = 0;
                jugde = 1;
            }
        }
        
        if(json_str[count] == ']'){
            blank--;
            if(small == 1){
                small = 0;
                jugde = 1;
            }
        }
        
        if(json_str[count] == 'f'){
            printIndent(blank);
            printBoolean(false);
            count += 4;
        }
        
        
        if(json_str[count] == 't'){
            printIndent(blank);
            printBoolean(true);
            count += 3;
        }
        
        
        if(json_str[count] == 'n'){
            printIndent(blank);
            printNull();
            count += 3;
        }
            count++;
    }
    return SUCCESS;
}
