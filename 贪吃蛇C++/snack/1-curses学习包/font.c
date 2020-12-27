#include <stdio.h>
#include <curses.h>
int main()
{
	initscr();//curses初始化
	
	attrset(A_BOLD);//加粗属性
	printw("BOLD\n");
	attrset(A_BLINK);//闪烁属性
	printw("A_BLINK\n");
	attrset(A_DIM);//半透明属性
	printw("A_DIM\n");
	attrset(A_REVERSE);//反显属性
	printw("A_REVERSE\n");
	attrset(A_STANDOUT);//高亮度显示属性
	printw("A_STANDOUT\n");
	attrset(A_UNDERLINE);//加下划线
	printw("A_UNDERLINE\n");
	attrset(A_ALTCHARSET);//可代替字符集
	printw("A_ALTCHARSET\n");
	attrset(A_BOLD | A_UNDERLINE);//加粗并且加下滑线
	printw("A_BOLD AND A_UNDERLINE\n");
	attrset(0);//取消字符属性
	
	getch();
	endwin();//结束程序
	return 0;
}
