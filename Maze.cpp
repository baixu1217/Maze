#define _CRT_SECURE_NO_WARNINGS 1
#include"Maze.h"

//用栈和递归实现迷宫问题
const size_t N = 10;

void FunTest()
{
	int Maze[N][N];
	Pos entry = {2,0};
	stack<Pos> ss;
	GetMaze((int*)Maze,N);
	GetMazePath((int*)Maze,N,entry,ss);
	cout<<"迷宫是否有出口？"<<!ss.empty()<<endl;
	PrintMaze((int*)Maze,N);
}

int main()
{
	FunTest();
	return 0;
}