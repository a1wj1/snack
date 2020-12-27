#include <stdio.h>
#include <curses.h>

int main()
{
	initscr();//curses初始化
	for(int k=0; k<15; k++){
		move(k,k);
		printw("(%d,%d) is here",k,k);
	}
	getch();
	endwin();//结束程序
	return 0;
}
