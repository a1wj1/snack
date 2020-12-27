#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <time.h>

int beginy = 3;
int beginx = 6;
int snack[1500][2][2];

int main(){
	initscr();
	start_color();
	init_pair(1,COLOR_BLACK,COLOR_YELLOW);
    attron(COLOR_PAIR(1));

    bool run =1;
    int ra = 1,rb = 1;
    int ch;
    int a[4][2]={ {1,0}, {2,1}, {3,2}, {4,3} };
    while(run){
        halfdelay(8);
        ch = getch();
        clear();
        if(ch == 'k'){
            srand(time(0));
            ra = rand() % (4);
            rb = rand() % (4);
            for(int k=0;k<4;k++){
                if(a[k][0]==ra && a[k][1]==rb){
                    srand(time(0));
                    ra = rand() % (4);
                    rb = rand() % (4);
                }
            }
            printw("%d %d",ra,rb);
        }
        else if(ch == 'j') run = 0;
        else printw("%d %d",ra,rb);
        refresh();
    }
	endwin();
	return 0;
}
