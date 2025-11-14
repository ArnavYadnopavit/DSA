#include <stdlib.h>
#include <stdio.h>
#include <math.h>
typedef struct stack{
    char* arr;
    int top;
    int size;
}stack;

stack* init(int size){
    stack* st=(stack*)malloc(sizeof(stack));
    st->arr=(char*)malloc(sizeof(char)*size);
    st->top=-1;
    st->size=size;
    return st;
}

void push(stack* st,char x){
    if(st->top>=st->size-1){
        printf("FAIL! STACK FULL");
        return;
    }
    st->arr[++st->top]=x;
}

char pop(stack* st){
    if(st->top==-1){
        printf("FAIL! STACKK EMPTY!");
    }
    return st->arr[st->top--];
}

char peek(stack* st){
    if(st->top==-1){
        printf("FAIL! STACK EMPTY!");
    }
    return st->arr[st->top];
}


typedef struct fstack{
    float* arr;
    int top;
    int size;
}fstack;

fstack* finit(int size){
    fstack* st=(fstack*)malloc(sizeof(fstack));
    st->arr=(float*)malloc(sizeof(float)*size);
    st->top=-1;
    st->size=size;
    return st;
}

void fpush(fstack* st,float x){
    if(st->top>=st->size-1){
        printf("FAIL! STACK FULL");
        return;
    }
    st->arr[++st->top]=x;
}

float fpop(fstack* st){
    if(st->top==-1){
        printf("FAIL! STACKK EMPTY!");
    }
    return st->arr[st->top--];
}

float fpeek(fstack* st){
    if(st->top==-1){
        printf("FAIL! STACK EMPTY!");
    }
    return st->arr[st->top];
}


int IsOp(char c){
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^') return 1;
    else return 0;
}

int prior(char c){
    if(c=='+'||c=='-') return 1;
    if(c=='*'||c=='/')return 2;
    if(c=='^') return 3;
    return 0;
}

void InfixtoPostfix(char* in,char* out){
    stack* st=init(100);
    int i=0,j=0;
    while(in[i]!='\0'){
        if(!IsOp(in[i])) out[j++]=in[i++];
        else{
            if(st->top==-1) push(st,in[i++]);
            else{
                if(prior(peek(st))>prior(in[i])){
                    out[j++]=pop(st);
                }
                else{
                    push(st,in[i++]);
                }
            }
        }
    }
    while(j<i){
        out[j++]=pop(st);
    }
}

float EvalPostfix(char* in){
    fstack* st=finit(100);
    int i=0;
    float result=0;
    while(in[i]!='\0'){
        if(!IsOp(in[i])) fpush(st,atof(&in[i++]));
        else{
            float b=fpop(st);
            float a=fpop(st);
            if(in[i]=='+'){
                result=a+b;
                fpush(st,result);
            }
            else if(in[i]=='-'){
                result=a-b;
                fpush(st,result);
            }
            else if(in[i]=='*'){
                result=a*b;
                fpush(st,result);
            }
            else if(in[i]=='/'){
                result=a/b;
                fpush(st,result);
            }
            else if(in[i]=='^'){
                result=pow(a,b);
                fpush(st,result);
            }
            i++;
        }
    }
    return fpop(st);
}

/*
Input:
N number of infixes
infix1
infix2
...
infixN

Output:
outfix1=result

*/

int main(){
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        char in[100],out[100];
        scanf("%s",in);
        InfixtoPostfix(in,out);
        printf("%s = %f\n",out,EvalPostfix(out));
        
    }
}