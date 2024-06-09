#include<stdio.h>
#include<stdlib.h>
#include<string.h>//strlen() function
#include<unistd.h>//getpass function 
#include<ctype.h>// for checking the the letters
// global variables
int l;
int upper=0;
int lower=0;
int digits=0;
int syb=0;
int prev=0; 
int sequential=0; 
void password(char *pass){ // to check the pass word by letter by letter
    if (l>=8)
    {
       
        for (int i = 0; i < l; i++,pass++){
            if (isupper(*pass)){
                upper=upper+1;
              
             }
            else if (islower(*pass))
            {
                lower=lower+1;
                
            }
            else if (isdigit(*pass))
            {
                digits=digits+1;
                if (prev != 0 && *pass != prev + 1) {
                    sequential = 1;
            }
            prev = *pass;
            }
            else
                syb=syb+1;
        }
    }
    else
        printf("the password is [WEAKEST]");
}
int mark(int score){ // assinging the score and the password according to the rules
    if (l>=8)
    {
        score=score+1;
    }
    if (upper>=1)
    {
        score=score+1;
    }
    if (lower>=3){
        score=score+3;
    }
    if (syb>=1)
    {
        score=score+1;
    }
    if (digits>=3)
    {
        if (sequential==0)
        {
            score=score+2;
            printf("the digis are sequential\n");
        }
        else{
            score=score+3;
        }
    }
    return score;
}
int main(){//mait function
    int score=0;
    int c=0;
    char *pass=getpass("\nenter the password:");//the the password from the screen
    l=strlen(pass);//geting the lenth of the passowed
    password(pass);
    c=mark(score);
    if (c==2)//assiging the title according to the score 
    {
        printf("the password is [WEAK], score[%d]\n",c);
    }
    else if (c==4)
    {
        printf("the password is [AVERAGE],score[%d]\n",c);
    }
    else if (c==6)
    {
        printf("the password is [MEDIUM],score[%d]\n",c);
    }
    else if (c==7)
    {
        printf("the password is [STRONG],score[%d]\n",c);
    }
    else if (c==8)
    {
        printf("the password is [STRONG],score[%d]\n",c);
    }
    else if (c==9)
    {
        printf("the password is [STRONGEST],score[%d]\n",c);
    }
    

}
