#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include <graphics.h>
using namespace std;

// To design board of tic tac toe
void design()
{
    settextstyle(10,0,6);	// to modify the size, direction ans font of text
    int w=textwidth("Tic Tac Toe"); 	// to find the width of the text
    setcolor(14);
    outtextxy((400-w)/2,80,"Tic Tac Toe");	// To write the text to the given cordinates
	
	setcolor(3);
	// three line function is used to increase the width of the tic tac toe board
	line(160,220,160,460);
	line(160+1,220,160+1,460);
	line(160+2,220,160+2,460);
	line(160-1,220,160-1,460);
	line(160-2,220,160-2,460);

	line(80,300,320,300);
	line(80,300+1,320,300+1);
	line(80,300+2,320,300+2);
	line(80,300-1,320,300-1);
	line(80,300-2,320,300-2);

	line(80,380,320,380);
	line(80,380+1,320,380+1);
	line(80,380+2,320,380+2);
	line(80,380-1,320,380-1);
	line(80,380-2,320,380-2);

	line(240,220,240,460);
	line(240+1,220,240+1,460);
	line(240+2,220,240+2,460);
	line(240-1,220,240-1,460);
	line(240-2,220,240-2,460);

	setcolor(14);
    settextstyle(10,0,2);
    int h=textheight("By Amit and Chetan");
    w=textwidth("By Amit and Chetan");
    outtextxy(400-w-5,600-h,"By Amit and Chetan");
}

// dis function is called to mark X and O on tci tac toe Board
void dis(int turn, int p)
{
    settextstyle(10,0,6);
    int w=0,h=0;
    if(turn==1){
    	setcolor(11);
        h=textheight("X");
        w=textwidth("X");
    }
    else{
    	setcolor(5);
        h=textheight("O");
        w=textwidth("O");
    }
    int x=(80-w)/2;
    int y=(80-h)/2;
    
    // p determine the the block to mark with X and O
    switch(p)
    {
        case 1:
            if(turn==1)
                outtextxy(x+80,y+220,"X");
            else
                outtextxy(x+80,y+220,"O");
            break;
        case 2:
            if(turn==1)
                outtextxy(x+160,y+220,"X");
            else
                outtextxy(x+160,y+220,"O");
            break;
        case 3:
            if(turn==1)
                outtextxy(x+240,y+220,"X");
            else
                outtextxy(x+240,y+220,"O");
            break;
        case 4:
            if(turn==1)
                outtextxy(x+80,y+300,"X");
            else
                outtextxy(x+80,y+300,"O");
            break;
        case 5:
            if(turn==1)
                outtextxy(x+160,y+300,"X");
            else
                outtextxy(x+160,y+300,"O");
            break;
        case 6:
            if(turn==1)
                outtextxy(x+240,y+300,"X");
            else
                outtextxy(x+240,y+300,"O");
            break;
        case 7:
            if(turn==1)
                outtextxy(x+80,y+380,"X");
            else
                outtextxy(x+80,y+380,"O");
            break;
        case 8:
            if(turn==1)
                outtextxy(x+160,y+380,"X");
            else
                outtextxy(x+160,y+380,"O");
            break;
        case 9:
            if(turn==1)
                outtextxy(x+240,y+380,"X");
            else
                outtextxy(x+240,y+380,"O");
            break;

    }


}

// fun check if the winning condition of either player is fullfilled or not
int fun(char *a){
    // return || 0 for no result || 1 for player 1 || 2 for player 2
    // Here pointer a point to a char array with store the state of board

    //diagonal check
    if((a[0]==a[4] && a[0]==a[8] && a[0]=='X') || (a[2]==a[4] && a[2]==a[6] && a[2]=='X'))
        return 1;
    else if((a[0]==a[4] && a[0]==a[8] && a[0]=='O') || (a[2]==a[4] && a[2]==a[6] && a[2]=='O'))
        return 2;

    // horizontal check
    if((a[0]==a[1] && a[1]==a[2] && a[0]=='X') || (a[3]==a[4] && a[4]==a[5] && a[3]=='X') || (a[6]==a[7] && a[7]==a[8] && a[6]=='X'))
        return 1;
    else if((a[0]==a[1] && a[1]==a[2] && a[0]=='O') || (a[3]==a[4] && a[4]==a[5] && a[3]=='O') || (a[6]==a[7] && a[7]==a[8] && a[6]=='O'))
        return 2;

    //vertical check
    if((a[0]==a[3] && a[3]==a[6] && a[0]=='X') || (a[1]==a[4] && a[4]==a[7] && a[1]=='X') || (a[2]==a[5] && a[5]==a[8] && a[2]=='X'))
        return 1;
    if((a[0]==a[3] && a[3]==a[6] && a[0]=='O') || (a[1]==a[4] && a[4]==a[7] && a[1]=='O') || (a[2]==a[5] && a[5]==a[8] && a[2]=='O'))
        return 2;
    return 0;
}

void computer(char *a,int turn){
    int cnt[8],p[8];
    for(int i=0;i<8;i++){
        cnt[i]=0;p[i]=-1;
    }
    // attack
    for(int i=0;i<9;i++){
        if(a[i]=='O'){
            cnt[i/3]++;
            cnt[3+i%3]++;
            if(i%4==0)
                cnt[6]++;
            if(i==2 || i==4 || i==6)
                cnt[7]++;
        }
        else if(a[i]==0){
            p[i/3]=i;
            p[3+i%3]=i;
            if(i%4==0)
                p[6]=i;
            if(i==2 || i==4 || i==6)
                p[7]=i;
        }
    }
    for(int i=0;i<8;i++){
        if(cnt[i]==2 && p[i]!=-1){
            dis(0,p[i]+1);
            a[p[i]]='O';
            return;
        }
        p[i]=-1;cnt[i]=0;
    }
    // defend
    for(int i=0;i<9;i++){
        if(a[i]=='X'){
            cnt[i/3]++;
            cnt[3+i%3]++;
            if(i%4==0)
                cnt[6]++;
            if(i==2 || i==4 || i==6)
                cnt[7]++;
        }
        else if(a[i]==0){
            p[i/3]=i;
            p[3+i%3]=i;
            if(i%4==0)
                p[6]=i;
            if(i==2 || i==4 || i==6)
                p[7]=i;
        }
    }
    for(int i=0;i<8;i++){
        if(cnt[i]==2 && p[i]!=-1){
            dis(0,p[i]+1);
            a[p[i]]='O';
            return;
        }
        p[i]=-1;cnt[i]=0;
    }
    if(a[4]==0){
        dis(0,5);
        a[4]='O';
        return;
    }
    if(turn==1){
        dis(0,1);
        a[0]='O';
        return;
    }
    if(turn==3){
        if(a[4]=='X'){
            dis(0,3);
            a[2]='O';
            return;
        }
        p[0]=p[1]=-1;int j=0;
        for(int i=0;i<9;i++)
            if(a[i]=='X')
                p[j++]=i;
        if((p[0]==3 && p[1]==5) || (p[0]==2 && p[1]==7)){
            dis(0,1);
            a[0]='O';
            return;
        }
        if(p[0]+p[1]==8){
            dis(0,2);
            a[1]='O';
            return;
        }
        if(p[0]==0 || p[0]==1){
            if(p[1]==5 || p[1]==8){
                dis(0,3);
                a[2]='O';
                return;
            }
            else if(p[1]==3 || p[1]==6){
                dis(0,1);
                a[0]='O';
                return;
            }
            else{
                dis(0,7);
                a[6]='O';
                return;
            }
        }
        else if(p[0]==1 || p[0]==2){
            if(p[1]==3 || p[1]==6){
                dis(0,1);
                a[0]='O';
                return;
            }
            else{
                dis(0,9);
                a[8]='O';
                return;
            }
        }
        else if(p[0]==3){
            dis(0,7);
            a[6]='O';
            return;
        }
        dis(0,9);
        a[8]='O';
        return;
    }
    for(int i=0;i<9;i++){
        if(a[i]==0){
            dis(0,1+i);
            a[i]='O';
            return;
        }
    }
}

void PlayerVsPlayer() {
	int x=0;
    // POINT is a stucture which define the x and y cordinates of a points and pos is a object of POINT
    POINT pos; 
    int turn=0;
    char b[9]={0};
    for(int i=0;i<9;i++)
        b[i]=0;
    settextstyle(10,0,3);
    int w=textwidth("Your Turn !!");
    outtextxy((400-w)/2,500,"Your Turn !!");
    while(x==0 && turn<=9)
    {	
    	// check the state of mouse if the left button is clicked or not
    	// VL_KBUTTON -> return the status of left key in mouse (0 -> not pressed, 1-> pressed)
    	// GetAsyncKeyState -> check if the left key is pressed or not at the time of evaluation
        if(GetAsyncKeyState(VK_LBUTTON))
        {
        	// GetCurSorPos -> retrives the position of mouse pointer
            GetCursorPos(&pos);
            // mousex() and mousey() are the function provided by graohic.h
            long X=mousex(); // return the most recent x coordinate of mouse within graphics window
            long Y=mousey(); // return the most recent y coordinate of mouse within graohics window 
            int mov=0;
            if(turn%2==0){
                if(X>80 && X<160 && Y>220 && Y<300 && b[0]==0)     //b1
                {
                    dis(1,1);
                    mov=1;
                    b[0]='X';
                }
                else if(X>160 && X<240 && Y>220 && Y<300 && b[1]==0)     //b2
                {
                    dis(1,2);
                    mov=1;
                    b[1]='X';
                }
                else if(X>240 && X<320 && Y>220 && Y<300 && b[2]==0)     //b3
                {
                    dis(1,3);
                    mov=1;
                    b[2]='X';
                }
                else if(X>80 && X<160 && Y>300 && Y<380 && b[3]==0)     //b4
                {
                    dis(1,4);
                    mov=1;
                    b[3]='X';
                }
                else if(X>160 && X<240 && Y>300 && Y<380 && b[4]==0)     //b5
                {
                    dis(1,5);
                    mov=1;
                    b[4]='X';
                }
                else if(X>240 && X<320 && Y>300 && Y<380 && b[5]==0)     //b6
                {
                    dis(1,6);
                    mov=1;
                    b[5]='X';
                }
                else if(X>80 && X<160 && Y>380 && Y<460 && b[6]==0)     //b7
                {
                    dis(1,7);
                    mov=1;
                    b[6]='X';
                }
                else if(X>160 && X<240 && Y>380 && Y<460 && b[7]==0)     //b8
                {
                    dis(1,8);
                    mov=1;
                    b[7]='X';
                }
                else if(X>240 && X<320 && Y>380 && Y<460 && b[8]==0)     //b9
                {
                    dis(1,9);
                    b[8]='X';
                    mov=1;
                }
            } else {
            	if(X>80 && X<160 && Y>220 && Y<300 && b[0]==0)     //b1
                {
                    dis(2,1);
                    mov=1;
                    b[0]='O';
                }
                else if(X>160 && X<240 && Y>220 && Y<300 && b[1]==0)     //b2
                {
                    dis(2,2);
                    mov=1;
                    b[1]='O';
                }
                else if(X>240 && X<320 && Y>220 && Y<300 && b[2]==0)     //b3
                {
                    dis(2,3);
                    mov=1;
                    b[2]='O';
                }
                else if(X>80 && X<160 && Y>300 && Y<380 && b[3]==0)     //b4
                {
                    dis(2,4);
                    mov=1;
                    b[3]='O';
                }
                else if(X>160 && X<240 && Y>300 && Y<380 && b[4]==0)     //b5
                {
                    dis(2,5);
                    mov=1;
                    b[4]='O';
                }
                else if(X>240 && X<320 && Y>300 && Y<380 && b[5]==0)     //b6
                {
                    dis(2,6);
                    mov=1;
                    b[5]='O';
                }
                else if(X>80 && X<160 && Y>380 && Y<460 && b[6]==0)     //b7
                {
                    dis(2,7);
                    mov=1;
                    b[6]='O';
                }
                else if(X>160 && X<240 && Y>380 && Y<460 && b[7]==0)     //b8
                {
                    dis(2,8);
                    mov=1;
                    b[7]='O';
                }
                else if(X>240 && X<320 && Y>380 && Y<460 && b[8]==0)     //b9
                {
                    dis(2,9);
                    b[8]='O';
                    mov=1;
                }
			}
			if(mov) {
				turn++;
				x = fun(b);
				
				if(x != 0 || turn == 9)
					break;
			}
        }
    }
    printf("Thank You !!");
    if(x==1){
    	setcolor(11);
        settextstyle(10,0,3);
        int w=textwidth("Player 1 Wins !!");
        outtextxy((400-w)/2,500,"Player 1 Wins !!");
    }
    else if(x==2){
    	setcolor(5);
        settextstyle(10,0,3);
        int w=textwidth("Player 2 Wins !!");
        outtextxy((400-w)/2,500,"Player 2 Wins !!");
    }
    else if(x==0){
    	setcolor(10);
        settextstyle(10,0,3);
        int w=textwidth("Its a Draw !!");
        outtextxy((400-w)/2,500,"Its a Draw !!");
    }
}

void PlayerVsComputer() {
	int x=0;
    POINT pos;
    int turn=0;
    char b[9]={0};
    for(int i=0;i<9;i++)
        b[i]=0;
    settextstyle(10,0,3);
    int w=textwidth("Your Turn !!");
    outtextxy((400-w)/2,500,"Your Turn !!");
    while(x==0 && turn<=9)
    {
        if(GetAsyncKeyState(VK_LBUTTON))
        {
            GetCursorPos(&pos);
            long X=mousex();
            long Y=mousey();
            int mov=0;
            if(turn%2==0){
                if(X>80 && X<160 && Y>220 && Y<300 && b[0]==0)     //b1
                {
                    dis(1,1);
                    mov=1;
                    b[0]='X';
                }
                else if(X>160 && X<240 && Y>220 && Y<300 && b[1]==0)     //b2
                {
                    dis(1,2);
                    mov=1;
                    b[1]='X';
                }
                else if(X>240 && X<320 && Y>220 && Y<300 && b[2]==0)     //b3
                {
                    dis(1,3);
                    mov=1;
                    b[2]='X';
                }
                else if(X>80 && X<160 && Y>300 && Y<380 && b[3]==0)     //b4
                {
                    dis(1,4);
                    mov=1;
                    b[3]='X';
                }
                else if(X>160 && X<240 && Y>300 && Y<380 && b[4]==0)     //b5
                {
                    dis(1,5);
                    mov=1;
                    b[4]='X';
                }
                else if(X>240 && X<320 && Y>300 && Y<380 && b[5]==0)     //b6
                {
                    dis(1,6);
                    mov=1;
                    b[5]='X';
                }
                else if(X>80 && X<160 && Y>380 && Y<460 && b[6]==0)     //b7
                {
                    dis(1,7);
                    mov=1;
                    b[6]='X';
                }
                else if(X>160 && X<240 && Y>380 && Y<460 && b[7]==0)     //b8
                {
                    dis(1,8);
                    mov=1;
                    b[7]='X';
                }
                else if(X>240 && X<320 && Y>380 && Y<460 && b[8]==0)     //b9
                {
                    dis(1,9);
                    b[8]='X';
                    mov=1;
                }
                if(mov){
                    turn++;
                    x=fun(b);
                    delay(200);
                    if(x!=0 || turn==9)
                        break;
                    // computers turn
                    computer(b,turn);
                    turn++;
                    x=fun(b);
                }
            }
        }
    }
    cout<<"Thank You !!";
    if(x==1){
        settextstyle(10,0,3);
        int w=textwidth("You Wins !!");
        outtextxy((400-w)/2,500,"You Wins !!");
    }
    else if(x==2){
        settextstyle(10,0,3);
        int w=textwidth("Computer Wins !!");
        outtextxy((400-w)/2,500,"Computer Wins !!");
    }
    else if(x==0){
        settextstyle(10,0,3);
        int w=textwidth("Its a Draw !!");
        outtextxy((400-w)/2,500,"Its a Draw !!");
    }
}

int main()
{
	int ch;
	printf("Please Select mode to play (1 or 2):-");
	printf("\n1. Player vs Player");
	printf("\n2. Player vs Computer\n");
	scanf("%d", &ch);

    //Tic Tac Toe
	initwindow(400,600,"Tic Tac Toe");
    
	// To create board
    design();
	    
    if(ch == 1) {
    	PlayerVsPlayer();
	} else if(ch == 2) {
		PlayerVsComputer();	
	} else {
		printf("Wrong Choice !!");
	}
	
    getch();
    closegraph();
    
    return 0;
}
