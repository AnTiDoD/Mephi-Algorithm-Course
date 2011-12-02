// Пьяница (реализация на очереди)

#include <iostream>

using std::cin;
using std::cout;
using std::endl;


const int MAX_SIZE = 10;

int c_first, c_second, c_botva;

/*Очередь*/
struct Queue 
{
	int elements[MAX_SIZE];
	int elements_count;
	int head_index;
	int tail_index;

	void Init();
	void Clear();
	int Size();
	bool Empty();
	bool Push(int newbie);
	bool Pop(int *result);
};

void Queue::Init()
{
	elements_count = 0;
	head_index = 0;
	tail_index = 0;
}

void Queue::Clear() 
{
	elements_count = 0;
	head_index = 0; 
	tail_index = 0;
}

int Queue::Size() 
{
	return elements_count;
}

bool Queue::Empty() 
{
	return Size() == 0;
}

bool Queue::Push(int newbie) 
{

	if (Size() == MAX_SIZE) 
		return false;
	else 
	{
		elements[tail_index] = newbie;
		tail_index = (tail_index + 1) % MAX_SIZE;
		++elements_count;
		return true;
	}
}

bool Queue::Pop(int* result) 
{
	if (Empty()) 
		return false;
	else 
	{
		*result = elements[head_index];
		head_index = (head_index + 1) % MAX_SIZE;
		--elements_count;
		return true;
	}
}

int main() 
{
	Queue q1,q2;
	q1.Init();
	q2.Init();
	for (int i=0;i<5;i++)
	{
		int data;
		cin >> data;
		q1.Push(data);
	}

	for (int i=0;i<5;i++)
	{
		int data;
		cin >> data;
		q2.Push(data);
	}

	int i;
	for(i=0;i<1E6;i++)
	{
		int card1,card2;
		if (q1.Pop(&card1)&&q2.Pop(&card2))
			if (card1==0 && card2==9 || card1==9 && card2==0)	
			{
				if (card1==0)
				{
					q1.Push(card1);
					q1.Push(card2);
				}
				else	//card2==0
				{
					q2.Push(card1);
					q2.Push(card2);
				}

			}
			else
				if (card1>card2)
				{
					q1.Push(card1);
					q1.Push(card2);					
				}
				else
				{
					q2.Push(card1);
					q2.Push(card2);
				}
		else
			break;
	}

	if (q1.Empty())	//win second
		cout << "second " << i <<endl;
	if (q2.Empty())	//win first
		cout << "first " << i << endl;
	if(!q1.Empty()&&!q2.Empty())
		cout << "botva" << " " << i<< endl;			
	return 0;
}