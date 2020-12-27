#include <stdio.h>
#include <curses.h>

int lenth = 25 , width = 60;
int main(){
	initscr();

	mvprintw(2,2,"123");
	halfdelay(13);
	getch();
	//halfdelay(1);
	endwin();
	return 0;
}
