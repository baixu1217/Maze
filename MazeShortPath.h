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
	FILE* fout = fopen("Maze1.txt","r");
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

bool IsCheckPath(int *maze,size_t n,Pos cur,Pos next)
{
	if((next._row < 0 || next._row >= 10) 
		|| (next._col < 0 || next._col >= 10)
		||(maze[next._row*n+next._col] == 1))
	{
		return false;
	}
	
	if(maze[next._row*n+next._col] == 0)
	{
		return true;
	}

	return maze[next._row*n+next._col]+1 > maze[cur._row*n+cur._col];
}


//递归
void GetMazePath(int *maze,size_t n,Pos entry,stack<Pos>& s,stack<Pos>& ss)
{
		Pos cur;
		Pos next;
		s.push(entry);
		next = entry;
		if(entry._row == n-1)
		{
			if(ss.empty() || s.size() < ss.size())
			{
				ss = s;
			}
			s.pop();
			return;
		}
		

		//探测上下左右
		//上
		next = entry;
		cur = next;
		next._row-=1;
		if(IsCheckPath(maze,n,cur,next))
		{
			maze[next._row*n+next._col] = maze[cur._row*n+cur._col]+1;
			GetMazePath(maze,n,next,s,ss);
		}
		//右
		next = entry;
		cur = next;
		next._col+=1;
		if(IsCheckPath(maze,n,cur,next))
		{
			maze[next._row*n+next._col] = maze[cur._row*n+cur._col]+1;
			GetMazePath(maze,n,next,s,ss);
			
		}

		//下
		next = entry;
		cur = next;
		next._row+=1;
		if(IsCheckPath(maze,n,cur,next))
		{
			maze[next._row*n+next._col] = maze[cur._row*n+cur._col]+1;
			GetMazePath(maze,n,next,s,ss);
			
		}

		//左
		next = entry;
		cur = next;
		next._col-=1;
		if(IsCheckPath(maze,n,cur,next))
		{
			maze[next._row*n+next._col] = maze[cur._row*n+cur._col]+1;
			GetMazePath(maze,n,next,s,ss);
		}

		//四方都不通

		s.pop();
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