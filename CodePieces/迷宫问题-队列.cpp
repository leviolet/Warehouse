#include <stdio.h>
#include <stdlib.h>
#define MaxSize 128
#define M 10
#define N 10

int mg[M][N] = {
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,0,0,1,1,0,0,1},
	{1,0,1,1,1,0,0,0,0,1},
	{1,0,0,0,1,0,0,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},
	{1,0,1,1,1,0,1,1,0,1},
	{1,1,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1}
};
typedef struct {
	int i;
	int j;
	int di;
} Box;
typedef struct {
	Box data[MaxSize];
	int top;
}  StType;


void InitStack(StType*& s) {
	s = (StType*)malloc(sizeof(StType));
	s->top = -1;
}

int Push(StType*& s, Box e) {
	if (s->top == MaxSize - 1) return 0;
	s->top++;
	s->data[s->top] = e;
	return 1;
}
int Pop(StType*& s, Box& e) {
	if (s->top == -1) return 0;

	e = s->data[s->top];
	s->top--;
	return 1;
}
int StackEmpty(StType* s) {
	return(s->top == -1);
}

int GetTop(StType* s, Box& e) {
	if (s->top == -1) return 0;
	e = s->data[s->top];
	return 1;
}

void ClearStack(StType*& s) {
	free(s);
}

int i;

bool mgpath(int xi, int yi, int xe, int ye) {
	Box path[MaxSize], e;
	int i, j, di, i1, j1, k;
	bool find;
	StType* st;
	InitStack(st);
	e.i = xi;
	e.j = yi;
	e.di = -1;
	Push(st, e);
	mg[xi][yi] = -1;
	while (!StackEmpty(st)) {
		GetTop(st, e);
		i = e.i;
		j = e.j;
		di = e.di;
		if (i == xe && j == ye) {
			printf("有一路径:\n");
			k = 0;
			while (!StackEmpty(st)) {
				Pop(st, e);
				path[k++] = e;
			}
			while (k >= 1) {
				k--;
				printf("\t(%d,%d)", path[k].i, path[k].j);
				if ((k + 2) % 5 == 0)
					printf("\n");
			}
			printf("\n");
			ClearStack(st);
			return true;
		}
		find = false;
		while (di < 4 && !find) {
			di++;
			switch (di) {
			case 0:
				i1 = i - 1;
				j1 = j;
				break;
			case 1:
				i1 = i;
				j1 = j + 1;
				break;
			case 2:
				i1 = i + 1;
				j1 = j;
				break;
			case 3:
				i1 = i;
				j1 = j - 1;
				break;
			}
			if (mg[i1][j1] == 0)  find = true;

		}
		if (find) {
			st->data[st->top].di = di;
			e.i = i1;
			e.j = j1;
			e.di = -1;
			Push(st, e);
			mg[i1][j1] = -1;
		}
		else {
			Pop(st, e);
			mg[e.i][e.j] = 0;
		}
	}
	ClearStack(st);
	return false;
}

int main() {
	if (!mgpath(1, 1, M-2, N-2))
		printf("没有解!");
	return 0;
}
