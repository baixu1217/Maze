#define _CRT_SECURE_NO_WARNINGS 1
#include"Maze.h"

//��ջ�͵ݹ�ʵ���Թ�����
const size_t N = 10;

void FunTest()
{
	int Maze[N][N];
	Pos entry = {2,0};
	stack<Pos> ss;
	GetMaze((int*)Maze,N);
	GetMazePath((int*)Maze,N,entry,ss);
	cout<<"�Թ��Ƿ��г��ڣ�"<<!ss.empty()<<endl;
	PrintMaze((int*)Maze,N);
}

int main()
{
	FunTest();
	return 0;
}