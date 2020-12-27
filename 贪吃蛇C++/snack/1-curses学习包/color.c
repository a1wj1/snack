#include <stdio.h>
#include <curses.h>
int main()
{
	initscr();//curses初始化
    start_color();
	init_pair(1, COLOR_RED, COLOR_WHITE);
	init_pair(2, COLOR_GREEN, COLOR_WHITE);
	init_pair(3, COLOR_BLUE, COLOR_WHITE);
	
	attron(COLOR_PAIR(1));
	printw("red\n");
	attroff(COLOR_PAIR(1));
	
	attron(COLOR_PAIR(2));
	printw("green\n");
	attroff(COLOR_PAIR(2));
	
	attron(COLOR_PAIR(3));
	printw("blue\n");
	attroff(COLOR_PAIR(3));
	
	getch();//获取字符
    endwin();//结束程序
	return 0;
}
