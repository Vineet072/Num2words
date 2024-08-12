#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main() {
    char *a[]={"ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE","TEN","ELEVEN","TWELVE","THIRTEEN","FOURTEEN","FIFTEEN","SIXTEEN","SEVENTEEN","EIGHTEEN","NINETEEN"};
    char *b[]={"TWENTY","THIRTY","FORTY","FIFTY","SIXTY","SEVENTY","EIGHTY","NINETY"};
    char *c[]={"HUNDRED","THOUSAND","LAKH","CRORE"};
    int e,f,flag=0;
    scanf("%d",&e);
    char d[10][10];

    //Crore
    f=(e%1000000000)/(10000000);
    if (f<20 && f>0) {
        strcpy(d[flag++],a[f-1]);
        strcpy(d[flag++],c[3]);
    }
    else if (f>19) {
        if (f%10==0) {
            strcpy(d[flag++],b[(f/10)-2]);
            strcpy(d[flag++],c[3]);
        }
        else if(f%10>0) {
            strcpy(d[flag++],b[(f/10)-2]);
            strcpy(d[flag++],a[-1+f%10]);
            strcpy(d[flag++],c[3]);
        }
    }

    //Lakh
    f=(e%10000000)/(100000);
    if (f<20 && f>0) {
        strcpy(d[flag++],a[f-1]);
        strcpy(d[flag++],c[2]);
    }
    else if (f>19) {
        if (f%10==0) {
            strcpy(d[flag++],b[(f/10)-2]);
            strcpy(d[flag++],c[2]);
        }
        else if (f%10>0) {
            strcpy(d[flag++],b[(f/10)-2]);
            strcpy(d[flag++],a[-1+f%10]);
            strcpy(d[flag++],c[2]);
        }
    }

    //Thousand
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
    

    //Display
    for(int i=0;i<flag;i++) {
        printf("%s ",d[i]);
    }
}