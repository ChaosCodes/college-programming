//
//  main.c
//  string
//
//  Created by Zeng Mac on 2016/11/7.
//  Copyright © 2016年 Zeng Mac. All rights reserved.
//
#include <stdio.h>
#include <string.h>

int main (){
    
    char str1[40],str2[40];
    scanf("%s%s", str1, str2);
    int num,start,end;
    
    scanf("%d",&num);
    
    if(strcmp(str1,str2) > 0)
        printf("%s > %s\n", str1, str2);
    
    else if(strcmp(str1,str2) < 0)
        printf("%s < %s\n", str1, str2);
    
    else
        printf("%s = %s\n", str1, str2);
    
    int str1_num,i;
    strncat(str1,str2,num);
    
    if(scanf("%d%d",&start, &end) == 2)
    for(i = start;i <= end;i++)
        if(str1[i] >= 'a' && str1[i] <= 'z')
            str1[i] = str1[i] + 'A' - 'a';
    
    printf("the length of \"%s\" is %d\n", str1,(int)strlen(str1));
    
    strcpy(str2,str1);
    str1_num = (int)strlen(str1);
    for(i = 0;i < (int)strlen(str2);i++)
        if(str2[i] >= 'A' && str2[i] <= 'Z')
            str2[i] = str2[i] + 'a' - 'A';
    
    if(strcmp(str1,str2) > 0)
        printf("%s > %s\n", str1, str2);
    
    else if(strcmp(str1,str2) < 0)
        printf("%s < %s\n", str1, str2);
    
    else 
        printf("%s = %s\n", str1, str2);
    
    if((str1_num / 2) - 10 > 0)
        printf("%s\n", str1);
    else
        printf("%s\n", str2);
    return 0;

}
