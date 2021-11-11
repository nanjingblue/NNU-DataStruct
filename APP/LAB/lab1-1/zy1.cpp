#include<iostream>
using namespace std;
const int defaultSize = 100;
template<class T>
class SeqList
{
private:
	T* data;
	int maxSize;
	int last;
public:
	SeqList(int sz = defaultSize);
	SeqList(SeqList<T>& L);
	~SeqList() { delete[]data; }
	int Size()const { return maxSize; }
	void Sort();
	bool getData(int i,T& x)const
	{
		if (i > 0 && i < last + 1)
		{
			x = data[i - 1]; return true;
		}
		else
			return false;
	}
	int Length() const { return last + 1; }
	void MergeList_Seq(SeqList& La, SeqList& Lb, SeqList& Lc);
	void Print();
	void Input();
};
template<class T>
SeqList<T>::SeqList(int sz)
{
	if (sz > 0)
	{
		maxSize = sz;
		last = -1;
		data = new T[maxSize];
		if (data == NULL)
		{
			cerr << "储存分配失败" << endl;
			exit(1);
		}
	}
}
template<class T>
SeqList<T>::SeqList(SeqList<T>& L)
{
	maxSize = L.Size();
	last = L.Length() - 1;
	T value;
	data = new T[maxSize];
	if (data == NULL)
	{
		cerr << "储存分配失败" << endl;
		exit(1);
	}
	for (int i = 1; i <= last + 1; i++)
	{
		L.getData(i, value);
		data[i - 1] = value;
	}
}
template<class T>
void SeqList<T>::Sort()
{
	int k = 0, j = 0;
	for (int i = 0; i <= last; i++)
	{
		k = i;
		for (j = i; j <= last; j++)
		{
			if (data[j] < data[k])
				k = j;
		}
		if (k != i)
		{
			T temp = data[i];
			data[i] = data[k];
			data[k] = temp;
		}
	}
}
template<class T>
void SeqList<T>::MergeList_Seq(SeqList<T>& la, SeqList<T>& lb, SeqList<T>& lc)
{
	int a = la.Length(), b = lb.Length(), c;
	if( a+ b > maxSize)
	{
		cerr << "OVERFLOW!"; exit(1);
	}
	c = a + b;
	int i = 0, j = 0, k = 0;
	while (i < a && j < b)
	{
		if (la.data[i] < lb.data[j])
			lc.data[k++] = la.data[i++];
		else
			lc.data[k++] = lb.data[j++];
        cout << lc.data[k-1] << " ";
	}
	while (i < a) {
        lc.data[k++] = la.data[i++];
        cout << lc.data[k-1] << " ";
    }
	while (j < b) {
        lc.data[k++] = lb.data[j++];
        cout << lc.data[k-1] << " ";
    }
	last = c;
    lc.last = c - 1;
    lc.Print();
}
template<class T>
void SeqList<T>::Input()
{
	while (1)
	{
		cout << "和其中的元素：";
		int x = 0; 
		cin >> x;
		last = x - 1;
		if (last <= maxSize - 1)
			break;
		cout << "元素个数不能超过" << maxSize - 1 << ";";
	}
	for (int i = 0; i <= last; i++)
	{
		cin >> data[i];
	}
}
template<class T>
void SeqList<T>::Print()
{
	for (int i = 0; i <= last; i++)
		cout << data[i] << "  ";
	cout << endl;
}
int main()
{
	SeqList<int>s1(20), s2(20), s3(20),s(20);
	cout << "请输入第一个顺序表元素个数";
	s1.Input();
	cout << "请输入第二个顺序表元素个数";
	s2.Input();
	cout << "s1,s2排序后分别为："<<endl;
	s1.Sort();
	s1.Print();
	s2.Sort();
	s2.Print();
	cout << "两个顺序表排序并合并后为："<<endl;
	s.MergeList_Seq(s1, s2, s3);
	s3.Print();
	return 0;
}