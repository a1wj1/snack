#include <stdio.h>
#include <curses.h>

int main()
{
	initscr();//curses初始化
    getch();//获取字符
    endwin();//结束程序
	return 0;
}
