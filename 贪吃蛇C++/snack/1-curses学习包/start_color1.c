#include <stdio.h>
#include <curses.h>

int main()
{
	initscr();//curses初始化
    printw("wrong exmple\n");
    printw("wrong exmple\n");
    printw("wrong exmple\n");
	start_color();
	init_pair(1,COLOR_BLUE,COLOR_YELLOW);//颜色初始化
	attron(COLOR_PAIR(1));
	printw("Color is normal");
	attroff(COLOR_PAIR(1));
	getch();
	endwin();//结束程序
	return 0;
}
