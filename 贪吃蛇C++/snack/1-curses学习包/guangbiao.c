#include <stdio.h>
#include <curses.h>

int main()
{
	initscr();//curses初始化
	move(2,4);//移动光标
	printw("move(2,4)");
	mvprintw(5,11,"mvprintw\n");//mvfunc应用
	printw("plese input a char and then system will clear the screen \n");
	getch();
	clear();//清屏
	mvaddstr(7,12,"mvaddstr");//mvfunc
	printw("\nenter any char to end the program!\n");
	getch();
	endwin();//结束程序
	return 0;
}
