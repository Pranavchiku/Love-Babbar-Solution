#include<stdio.h>
int x=22,y=13,z=15;

int call(int *a, int *b, int *c){
    int *string[]={a,b,c};
    int **pointer=string;
    **pointer++ +=*b;
    ++**pointer--;
    printf("%d ", ++**pointer);
}
int main(){
    int *p, *q, *r;
    p=&x,q=&y,r=&z  ;
    call(p,q,r);
    return 0;
}