#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>
#include<vector>
#include "matrix.h"
using namespace std;
int c=0;
void drawBoard(char* spaces){
   cout<<"     "<<"|"<<"     "<<"|"<<"     "<<"\n";
   cout<<"  "<<spaces[0]<<"  "<<"|"<<"  "<<spaces[1]<<"  "<<"|"<<"  "<<spaces[2]<<"  "<<"\n";
   cout<<"_____"<<"|"<<"_____"<<"|"<<"_____"<<"\n";
   cout<<"     "<<"|"<<"     "<<"|"<<"     "<<"\n";
   cout<<"  "<<spaces[3]<<"  "<<"|"<<"  "<<spaces[4]<<"  "<<"|"<<"  "<<spaces[5]<<"  "<<"\n";
   cout<<"_____"<<"|"<<"_____"<<"|"<<"_____"<<"\n";
   cout<<"     "<<"|"<<"     "<<"|"<<"     "<<"\n";
   cout<<"  "<<spaces[6]<<"  "<<"|"<<"  "<<spaces[7]<<"  "<<"|"<<"  "<<spaces[8]<<"  "<<"\n";
   cout<<"     "<<"|"<<"     "<<"|"<<"     "<<"\n";
}

void playerMove(char user,char *spaces){
    int x;
    cout<<"enter a number between 0-8:\n";
    cin>>x;
    spaces[x]='X';
}
void computerMove(char s,char*spaces){
    cout<<"thinking..\n";
    srand(time(NULL));
    int x;
    do
    {
        x=rand()%9;
    } while (spaces[x]!=' ');
    spaces[x]=s;
    c++;
}
bool check(char x,char* spaces){
    for(int i=0;i<=6;i=i+3){
        if(spaces[i]==x && spaces[i+1]==x && spaces[i+2]==x){
            return true;
        }
    }
    for(int j=0;j<3;j++){
        if(spaces[j]==x && spaces[j+3]==x && spaces[j+6]==x){
            return true;
        }
    }
    if(spaces[4]==x){
        if(spaces[0]==x && spaces[8]==x){
            return true;
        }
        else if(spaces[2]==x && spaces[6]==x){
            return true;
        }
    }
    return false;
}

void computerMoveAdv(char sys,char* spaces){
    cout<<"focused Thinking..\n";
    for(auto x:matrix){
       if(c==2 && spaces[x[0]]==sys && spaces[x[1]]==sys && spaces[x[2]]==' '){
        spaces[x[2]]=sys;
        return;
       }
    }
    computerMove(sys,spaces);
}
bool itsDraw(char* spaces,char s,char u){
  for(int i=0;i<9;i++){
   if(spaces[i]==' '){
    return false;
   }
  }
  return true;
}
int main(){
    char spaces[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
    bool gameover=false;
    char user='X';
    char sym='O';
    bool uWinner=false;
    bool sWinner=false;
    bool nowinner=false;
    drawBoard(spaces);
    while (!gameover)
    {
        playerMove(user,spaces);
        gameover=check(user,spaces);
        if(gameover==true){
            uWinner=true;
            drawBoard(spaces);
            break;
        }
        if(itsDraw(spaces,sym,user)){
            nowinner=true;
            drawBoard(spaces);
            cout<<"IT'S A DRAW\n";
            break;
        }
        drawBoard(spaces);
        if(c>=1){
          computerMoveAdv(sym,spaces);
        }
        else{
        computerMove(sym,spaces);
        }
        gameover=check(sym,spaces);
        if(gameover==true){
            sWinner=true;
            drawBoard(spaces);
            break;
        }
        if(itsDraw(spaces,sym,user)){
            nowinner=true;
            drawBoard(spaces);
            cout<<"IT'S A DRAW\n";
            break;
        }
        drawBoard(spaces);
    }
    if(uWinner){
        cout<<"YOU WON !!\n";
    }
    else if(nowinner){
        cout<<"both are greedy\n";
    }
    else cout<<"YOU LOST !!\n";
    return 0;
}