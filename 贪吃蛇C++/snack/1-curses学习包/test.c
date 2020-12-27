#include <stdio.h>
#include <curses.h>

int beginy = 3;
int beginx = 6;
int lenth = 3;
int snack[1500][2][2];

void cut(){
    for(int k=1;k<=lenth;k++){
        for(int j=0;j<2;j++){
            snack[k][j][0] = snack[k+1][j][0];
            snack[k][j][1] = snack[k+1][j][1];
        }
    }
    lenth -= 1;
	
}

int main(){
	initscr();
	start_color();
	init_pair(1,COLOR_BLACK,COLOR_YELLOW);//ÑÕÉ«³õÊ¼»¯
    attron(COLOR_PAIR(1));
    keypad(stdscr,1);
    
	int snack[1500][2][2] = {
    {{0,0},{0,0}},
    {{beginy,beginx},{beginy,beginx+1}},
    {{beginy,beginx+2},{beginy,beginx+3}},
    {{beginy+1,beginx+2},{beginy+1,beginx+3}}
	};

    for(int k=1;k<=lenth;k++){
        for(int j=0;j<2;j++){
            snack[k][j][0] = snack[k+1][j][0];
            snack[k][j][1] = snack[k+1][j][1];
        }
    }
    lenth -= 1;
	
	cut();

    for(int k=1;k<=lenth;k++){
        for(int j=0;j<2;j++){
            move(snack[k][j][0],snack[k][j][1]);
            printw("%c", '+' );
        }
    }
    getch();

    refresh();
	endwin();
	return 0;
}
