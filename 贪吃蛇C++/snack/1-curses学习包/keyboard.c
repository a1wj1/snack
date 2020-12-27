#include <stdio.h>
#include <curses.h>
int main(){
	initscr();//初始化屏幕
	clear();//清屏函数
	keypad(stdscr,1);//开启功能键
	int year,month,day;
	printw("please input year , month and day\n");
	scanw("%d %d %d",&year,&month,&day);
	bool button = 1;
	int ch;
    while(button){
        ch = getch();
		switch(ch){
			case KEY_RIGHT: month += 1;printw("%d\n", month); break;
			case KEY_LEFT: month -= 1;printw("%d\n", month); break;
			case KEY_UP: year -= 1;printw("%d\n",year);break;
			case KEY_DOWN: year += 1;printw("%d\n",year); break;
			case 27 : button=0;break;//27表示的是Esc键
		}
    }
	endwin();//关闭curses状态
	return 0;
}
