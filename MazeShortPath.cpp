#define _CRT_SECURE_NO_WARNINGS 1
#include"Maze1.h"

//��ջ�͵ݹ�ʵ���Թ�����
const size_t N = 10;

void FunTest()
{
	int Maze[N][N];
	Pos entry = {2,0};
	stack<Pos> ss;
	stack<Pos> ss1;
	GetMaze((int*)Maze,N);
	Maze[entry._row][entry._col] = 2;
	GetMazePath((int*)Maze,N,entry,ss,ss1);
//	GetMazePath((int*)Maze,N,entry,ss);
	cout<<"�Թ��Ƿ��г��ڣ�"<<!ss.empty()<<endl;
	PrintMaze((int*)Maze,N);
}

int main()
{
	FunTest();
	return 0;
}