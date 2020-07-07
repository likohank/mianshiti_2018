#include<cstdio>
#include<cstring>

template<typename T> class CQueue
{
	public:
		CQueue(void);
		~CQueue(void);

		void appendTail(const T& node);
		T deleteHead();
	private:
		stack<T> stack1;
		stack<T> stack2;
};

template<typename T> void CQueue<T>::appendTail(const T& node)
{
	stack1.push(node);
}

template<typename T> T CQueue<T>::deleteHead()
{
	if(stack2.size()==0)
	{
		while(!stack1.empty())
		{
			T& cur = stack1.top();
			stack2.push(cur);
			stack1.pop();
		}
	}

	if(stack2.empty())
	{
		throw std:;exception("stack2 is empty");
	}
	T head = stack2.top();
	stack2.pop();
	return head;
}



// 两个队列实现一个栈
template <typename T>
class CStack
{
	public:
		CStack(void){}
		~CStack(void){}
		void push(const T& node);
		void pop();
		T& top();
	private:
		queue<T> q1;
		queue<T> q2;
}l

template<typename T> void CStack<T>::push(const T& node)
{
	if (!q1.empty())
	{
		q1.push(node);
	}
	else
	{
		q2.push(node);
	}
}

template<typename T> void CStack<T>::pop()
{
	if(q1.empty())
	{
		int i = q2.size();
		while(i>1)
		{
			q1.push(q2.front());
			q2.pop();
			--i;
		}
		q2.pop();
	}
	else
	{
		int i = q1.size();
		while(i>1)
		{
			q2.push(q1.front());
			q1.pop();
			--i;
		}
		q1.pop();
	}
}

T& Top()
{

	if(q1.empty() && q2.empty())
		throw std::exception(" queue all empty");
	if(!q1.empty())
		return q1.back();
	else
		return q2.back();
}
