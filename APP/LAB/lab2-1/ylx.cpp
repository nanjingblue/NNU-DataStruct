#include<iostream>
#include<string>
using namespace std;
template<class T,int MaxSize>
class SeqStack
{
	T data[MaxSize];
	int top;
public:
	SeqStack();
	void Push(T x);
	T Pop();
	T Top();
	bool Empty();
	void Print();
};
template<class T, int MaxSize>
SeqStack<T,MaxSize>::SeqStack()
{
	top = -1;
}
template<class T, int MaxSize>
void SeqStack<T, MaxSize>::Push(T x)
{
	if(top==MaxSize-1)
	{
		cerr << "上溢"; exit(1);
	}
	top++;
	data[top] = x;
}
template<class T, int MaxSize>
T SeqStack<T, MaxSize>::Pop()
{
	if(top==-1)
	{
		cerr << "下溢"; exit(1);
	}
	T x = data[top];
	top--;
	return x;
}
template<class T, int MaxSize>
T SeqStack<T, MaxSize>::Top()
{
	if(top==-1)
	{
		cerr << "下溢"; exit(1);
	}
	return data[top];
}
template<class T, int MaxSize>
bool SeqStack<T, MaxSize>::Empty()
{
	return top == -1;
}
template<class T, int MaxSize>
void SeqStack<T, MaxSize>::Print()
{
	for (int i = 0; i <= top; i++)
		cout << data[i] << " ";
}
char Precede(char a, char b)
{
	if (b == '+')
	{
		if (a == '(' || a == '@')return '<';
		return '>';
	}
	if (b == '-')
	{
		if (a == '(' || a == '@')
			return '<';
		return '>';
	}
	if (b == '*')
	{
		if (a == '*' || a == '/' || a == ')')
			return '>';
		return '<';
	}
	if (b == '/')
	{
		if (a == '*' || a == '/' || a == ')')
			return '>';
		return '<';
	}
	if (b == '(')return '<';
	if (b == ')')
	{
		if (a == '(')return '=';
		return '>';
	}
	if (b == '@')
	{
		if (a == '@')return '=';
		return '>';
	}
}
double Operate(double a, char theta, double b)
{
	if (theta == '+')return a + b;
	if (theta == '-')return a - b;
	if (theta == '*')return a * b;
	if (theta == '/')return a / b;
}
double Expression1()
{
	SeqStack<char, 100>OPTR;
	SeqStack<double, 100>OPND;
	OPTR.Push('@');
	char ch;
	cout << "请输入表达式：";
	ch = getchar();
	ch = getchar();
	while (ch != '@' || OPTR.Top() != '@')
	{
		if (ch >= '0' && ch <= '9')
		{
			OPND.Push(ch - '0');
			ch = getchar();
		}
		else
		{
			char pre_op, a, b;
			pre_op = OPTR.Top();
			switch (Precede(pre_op, ch))
			{
			case'<':
				OPTR.Push(ch);
				ch = getchar();
				break;
			case'=':
				OPTR.Pop();
				ch = getchar();
				break;
			case'>':
				b = OPND.Pop();
				a = OPND.Pop();
				pre_op = OPTR.Pop();
				OPND.Push(Operate(a, pre_op, b));
				break;
			}
		}
	}
	return OPND.Top();
}
int main()
{
	SeqStack<int, 100>SStack;
	bool opt = true;
	int n;
	cout << "已建栈\n";
	while (opt == true)
	{
		cout << "0.退出\n";
		cout << "1.直接计算中缀表达式\n";
		cout << "2.转换为后缀表达式后计算值\n";
		char x;
		cin >> x;
		switch (x)
		{
		case '0':opt = 0;
			break;
		case '1':Expression1();
			break;
		/*case '2':Expression2();
			break;*/
		default:cout << "输入非法请重新选择\n";
			break;
		}
	}
	return 0;
}



