#include <stdio.h>
#include <curses.h>

int main()
{
	initscr();//curses初始化
    addch('c');//输出字符
	addstr(" str");//输出字符串
	printw("%s %d\n","prntw",15);//格式化输出
	
	printw("please input a char \n");
	int ch = getch();//获取字符
	printw("\nthis char is %c\n",ch);

	printw("please input a str, a float and a char : \n");
	char a,c;
	float b;
	scanw("%s %f %c",&a,&b,&c);//格式化输入
	
	char str[3];
	printw("please input a str\n");
	getstr(str);//getstr（）从键盘接受字符串并且把它存放在变量name
	printw("this str is %s\n",str);

	printw("Enter any character to end the program !\n");
	getch();//在没输入字符的情况下可以达到暂停程序的作用
	endwin();//结束程序
	return 0;
}
