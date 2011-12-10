#include <iostream>

#include <queue>
#include <stack>

using namespace std;

struct max_stack
{
	stack<int> s;
	stack<int> max_s;

	void push(const int& x)
	{
		s.push(x);
		if (max_s.empty())
			max_s.push(x);
		else
			max_s.push(std::max(x,max_s.top()));
	}
	void pop()
	{
		s.pop();
		max_s.pop();
	}
	
	int top()
	{
		return s.top();
	}

	int max()
	{
		return max_s.top();
	}

	bool empty()
	{
		return s.empty();
	}
};

struct max_queue
{
	max_stack head;
	max_stack tail;

	void push(const int& x)
	{
		tail.push(x);
	}

	void pop()
	{
		if (head.empty())
		{
			while (!tail.empty())
			{
				head.push(tail.top());
				tail.pop();
			}
		}
		head.pop();
	}

	bool empty ()
	{
		return head.empty() && tail.empty();
	}

	int max()
	{
		if (empty()) return 0;
		if (head.empty()) 
			return tail.max();
		if (tail.empty()) 
			return head.max();
		else
			return std::max(tail.max(),head.max());
	}

};

int main()
{
	max_queue mq;
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i=0;i<n;i++)
		cin >> a[i];
	int m;
	cin >> m;
	mq.push(a[0]);
	for (int i=0,j=1;i<m;i++)
	{
		string cmd;
		cin >> cmd;
		if (cmd=="R")
			mq.push(a[j++]);
		if (cmd=="L")
			mq.pop();
		cout << mq.max() << " ";
	}
	cout << endl;
	delete [] a;

	return 0;
}
