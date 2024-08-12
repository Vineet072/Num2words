#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main() {
    char *a[]={"One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    char *b[]={"Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    char *c[]={"Hundred","Thousand","Million","Billion"};
    int e,f,flag=0,flag2=0;
    scanf("%d",&e);
    char d[20][10];

    //Billion
    f=(e%1000000000000)/(1000000000);
    if (f/100>0) {
        strcpy(d[flag++],a[-1+(f/100)]);
        strcpy(d[flag++],c[0]);
        flag2++;
    }
    f=f%100;
    if (f<20 && f>0) {
        strcpy(d[flag++],a[f-1]);
        flag2++;
    }
    else if (f>19) {
        if (f%10==0) {
            strcpy(d[flag++],b[(f/10)-2]);
            strcpy(d[flag++],a[-1+f%10]);
            flag2++;
        }
        else if(f%10>0) {
            strcpy(d[flag++],b[(f/10)-2]);
            strcpy(d[flag++],a[-1+f%10]);
            flag2++;
        }
    }
    if (flag2>0) {
        strcpy(d[flag++],c[3]);
    }

    //Million
    f=(e%1000000000)/1000000;
    flag2=0;
    if (f/100>0) {
        strcpy(d[flag++],a[-1+(f/100)]);
        strcpy(d[flag++],c[0]);
        flag2++;
    }
    f=f%100;
    if (f<20 && f>0) {
        strcpy(d[flag++],a[f-1]);
        flag2++;
    }
    else if (f>19) {
        if (f%10==0) {
            strcpy(d[flag++],b[(f/10)-2]);
            flag2++;
        }
        else if(f%10>0) {
            
            strcpy(d[flag++],b[(f/10)-2]);
            strcpy(d[flag++],a[-1+f%10]);
            flag2++;
        }
    }
    if (flag2>0) {
        strcpy(d[flag++],c[2]);
    }

    //Thousand
    f=(e%1000000)/1000;
    if ((f%1000)/100>0) {
        strcpy(d[flag++],a[-1+f/100]);
        strcpy(d[flag++],c[0]);
        if ((e%100000)/1000==0) {
            strcpy(d[flag++],c[1]);
        }
    }
    f=(e%100000)/1000;
    if (f<20 && f>0) {
        strcpy(d[flag++],a[f-1]);
        strcpy(d[flag++],c[1]);
    }
    else if (f>19) {
        if (f%10==0) {
            strcpy(d[flag++],b[(f/10)-2]);
            strcpy(d[flag++],c[1]);
        }
        else if (f%10>0) {
            strcpy(d[flag++],b[(f/10)-2]);
            strcpy(d[flag++],a[-1+f%10]);
            strcpy(d[flag++],c[1]);
        }
    }

    //Hundred
    if ((e%1000)/100>0) {
        strcpy(d[flag++],a[-1+(e%1000)/100]);
        strcpy(d[flag++],c[0]);
    }

    //<100
    f=e%100;
    if (f<20 && f>0) {
        strcpy(d[flag++],a[f-1]);
    }
    else if (f>19) {
        if (f%10==0) {
            strcpy(d[flag++],b[(f/10)-2]);
        }
        else if (f%10>0) {
            strcpy(d[flag++],b[(f/10)-2]);
            strcpy(d[flag++],a[-1+f%10]);
        }
    }

    int total_length=0;

    for(int i=0;i<flag;i++) {
        total_length+=strlen(d[i])+1;
    }

    char *finalresult=(char *)malloc(total_length*sizeof(char));
    if (finalresult==NULL) {
        return "Zero";
    }

    finalresult[0]='\0';

    for(int i=0;i<flag;i++) {
        strcat(finalresult,d[i]);
        if (i<flag-1) {
            strcat(finalresult," ");
        }
    }

    printf("%s",finalresult);
}