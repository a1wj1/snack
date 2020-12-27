#include <stdio.h>
#include <curses.h>

int main()
{
	initscr();//curses初始化
    printw("wrong exmple\n");
    printw("wrong exmple\n");
	//初始化在start_color前会出错
	init_pair(1,COLOR_BLUE,COLOR_YELLOW);//颜色初始化
    printw("wrong exmple\n");
	start_color();
	attron(COLOR_PAIR(1));
	printw("Color chaos\n");//出错
	attroff(COLOR_PAIR(1));
	getch();
	endwin();//结束程序
	return 0;
}
