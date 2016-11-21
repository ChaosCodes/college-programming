//
//  json_parse.h
//  jason
//
//  Created by Zeng Mac on 2016/11/8.
//  Copyright © 2016年 Zeng Mac. All rights reserved.
//

#ifndef JSON_PARSE
#define JSON_PARSE

#include <string.h>

#define EXPECT_SINGLE_VALUE     1
#define EXPECT_ARRAY_BEGIN      2
#define EXPECT_ARRAY_END        4
#define EXPECT_ARRAY_VALUE      8
#define EXPECT_COMMA           16
#define EXPECT_OBJECT_BEGIN    32
#define EXPECT_OBJECT_END      64
#define EXPECT_OBJECT_KEY     128
#define EXPECT_OBJECT_VALUE   256
#define EXPECT_COLON          512
#define EXPECT_JSON_END      1024

#define true   1
#define false  0
#define err   -1

#define MAX_SIZE 5000

typedef int Boolean;

typedef int Status;

typedef double Number;

typedef struct {
    const char *begin;
    const char *end;
} String;

typedef enum {
    JS_NUMBER,
    JS_STRING,
    JS_BOOLEAN,
    JS_NULL,
    JS_OBJECT_BEGIN,
    JS_OBJECT_END,
    JS_ARRAY_BEGIN,
    JS_ARRAY_END,
    JS_COMMA,
    JS_COLON,
    JS_KEY,
    JS_VALUE,
    JS_END,
    ERR
} TokenType;

typedef enum {
    FAILED,
    SUCCESS
} ErrCode;

/* Stack */

typedef struct {
    TokenType stack_storage[MAX_SIZE];
    int top_ptr;
} TokenStack;

void TokenStack_init(TokenStack *stack);//done

Boolean TokenStack_empty(TokenStack *stack);//done

TokenType TokenStack_top(TokenStack *stack);//done

ErrCode TokenStack_pop(TokenStack *stack);//done

ErrCode TokenStack_push(TokenStack *stack, TokenType val);//done

/* End Stack */

/* TokenReader */

TokenType peekNextToken(const char *begin);

ErrCode skipToken(const char* begin, const char **next_token_begin);

Number readNumber(const char *begin, const char **next_token_begin);

String readString(const char *begin, const char **next_token_begin);

Boolean readBoolean(const char *begin, const char **next_token_begin);

int readNull(const char *begin, const char **next_token_begin);

/* End TokenReader */

/* Util */

Boolean has_status(Status now_status, Status status);//done

void printIndent(int times);//done

void printKey();//done

void printNumber(Number num);//done

void printBoolean(Boolean boo);//done

void printNull();//done

void printString(String str);//done

void printObject();//done

void printArray();//done

/* End Util */

ErrCode jsonParse(const char* json_str);

#endif
