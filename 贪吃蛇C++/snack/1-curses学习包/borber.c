#include <stdio.h>
#include <curses.h>

int lenth = 25 , width = 60;
int main(){
	initscr();

	WINDOW*  midscreen;
	midscreen = newwin(lenth,width,2,4);
	//box(midscreen,ACS_DIAMOND,ACS_DIAMOND);
	int a = ACS_CKBOARD;
	wborder(midscreen,a,a,a,a,a,a,a,a);
	refresh();
	wrefresh(midscreen);
	WINDOW*  midscreen1;
	midscreen1 = newwin(lenth,width-2,2,5);
	//box(midscreen,ACS_DIAMOND,ACS_DIAMOND);
	int b = ACS_CKBOARD;
	wborder(midscreen1,b,b,b,b,b,b,b,b);
	refresh();
	wrefresh(midscreen1);

	getch();
	endwin();
	return 0;
}
