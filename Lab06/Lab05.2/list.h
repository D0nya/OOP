#include <iostream>

using namespace std;

template <typename T>
class stack
{
public:
	stack() :top(NULL)
	{

	}
	~stack()
	{
		while (top)
		{
			Node *pv = top;
			top = top->p;
			delete pv;
		}

	}
	stack operator = (const stack &st)
	{
		Node* tmp = st.top;
		if (tmp)
		{
			Node* newNode = new Node();
			newNode->news_st = T(tmp->news_st);
			this->top = newNode;
			while (tmp->p)
			{
				tmp = tmp->p;
				newNode->p = new Node();
				newNode = newNode->p;
				newNode->news_st = T(tmp->news_st);
			}
		}
		size = st.size;
		return *this;
	}
	void Push(T data)
	{
		Node *pv = new Node;
		pv->news_st = data;
		pv->p = top;
		top = pv;
		size++;
	}
	T Pop()
	{
		if (isEmpty())
		{
			return NULL;
		}
		T temp;
		temp = this->top->news_st;
		this->top = this->top->p;
		size--;
		return temp;
	}
	bool isEmpty()
	{
		return top ? false : true;
	}
	T  operator[](int index)
	{
		int i = 0;
		stack *tmp = new stack(*this);
		while (!tmp->isEmpty())
		{
			if (i == index)
				return tmp->Pop();
			tmp->Pop();
			i++;
		}
		delete tmp;
		return NULL;
	}
	int stack_size()
	{
		return size;
	}

	stack(stack const & obj)
	{
		Node* tmp = obj.top;
		if (tmp)
		{
			Node* newNode = new Node();
			newNode->news_st = T(tmp->news_st);
			this->top = newNode;
			while (tmp->p)
			{
				tmp = tmp->p;
				newNode->p = new Node();
				newNode = newNode->p;
				newNode->news_st = T(tmp->news_st);
			}
		}
		size = obj.size;
	}
	void del_el(T n)
	{

		if (n == top->news_st)
		{
			Node * tmp = top;
			top = top->p;
			delete tmp;
			size--;
			return;
		}
		Node * tmp_prev = top;
		while (!isEmpty())
		{
			if (n == tmp_prev->p->news_st)
			{
				Node * tmp = tmp_prev->p;
				tmp_prev->p = tmp_prev->p->p;
				delete tmp;
				size--;
				return;
			}
			tmp_prev = tmp_prev->p;
		}
		throw "Not found!";

	}
private:
	struct Node
	{
		T news_st;
		Node *p;
	};
	int size = 0;
	Node *top;
};
