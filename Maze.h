#include<iostream>
using namespace std;
#include<assert.h>
#include<stack>

struct Pos
{
	int _row;
	int _col;
};

void GetMaze(int *Maze,size_t N)
{
	FILE* fout = fopen("Maze.txt","r");
	assert(fout);
	for(size_t i = 0; i < N; ++i)
	{
		for(size_t j = 0; j < N; )
		{
			int value = fgetc(fout);
			if(value == '1' || value == '0')
			{
				Maze[i*N+j] = value - '0';
				++j;
			}
			else if(value == EOF)
			{
				cout<<"Maze error!"<<endl;
				return;
			}
		}
	}
}

bool IsCheckPath(int *maze,size_t n,Pos path)
{
	if((path._row >= 0 && path._row < 10) 
		&& (path._col >= 0 && path._col < 10) 
		&& (maze[path._row*n+path._col] == 0))
	{
		return true;
	}
	return false;
}

//栈求解迷宫路径
void GetMazePath(int *maze,size_t n,Pos entry,stack<Pos>& s)
{
	Pos cur = entry;
	Pos next = cur;
	maze[cur._row*n+cur._col] = 2;
	s.push(entry);
	while(!s.empty())
	{
		if(s.top()._row  == n-1)
		{
			return;
		}
		//探测上下左右
		//上
		next = s.top();
		next._row-=1;
		if(IsCheckPath(maze,n,next))
		{
			s.push(next);
			maze[next._row*n+next._col] = 2;
			continue;
		}

		//右
		next = s.top();
		next._col+=1;
		if(IsCheckPath(maze,n,next))
		{
			s.push(next);
			maze[next._row*n+next._col] = 2;
			continue;
		}

		//下
		next = s.top();
		next._row+=1;
		if(IsCheckPath(maze,n,next))
		{
			s.push(next);
			maze[next._row*n+next._col] = 2;
			continue;
		}

		//左
		next = s.top();
		next._col-=1;
		if(IsCheckPath(maze,n,next))
		{
			s.push(next);
			maze[next._row*n+next._col] = 2;
			continue;
		}

		//没有通路
		Pos tmp = s.top();
		maze[tmp._row*n+tmp._col] = 3;
		s.pop();
	}
}

//递归
void GetMazePath(int *maze,size_t n,Pos entry,stack<Pos>& s)
{
		Pos next = entry;
		maze[next._row*n+next._col] = 2;
		s.push(entry);
	
		if(next._row == n-1)
		{
			return;
		}

		//探测上下左右
		//上
		next = entry;
		next._row-=1;
		if(IsCheckPath(maze,n,next))
		{
			GetMazePath(maze,n,next,s);
			
		}
		//右
		next = entry;
		next._col+=1;
		if(IsCheckPath(maze,n,next))
		{
			GetMazePath(maze,n,next,s);
			
		}

		//下
		next = entry;
		next._row+=1;
		if(IsCheckPath(maze,n,next))
		{
			GetMazePath(maze,n,next,s);
			
		}

		//左
		next = entry;
		next._col-=1;
		if(IsCheckPath(maze,n,next))
		{
			GetMazePath(maze,n,next,s);
		}
}

void PrintMaze(int *maze,size_t n)
{
	cout<<"迷宫显示:>"<<endl;
	for(size_t i = 0; i < n; ++i)
	{
		for(size_t j = 0; j < n; ++j)
		{
			cout<<maze[i*n+j]<<" ";
		}
		cout<<endl;
	}
}