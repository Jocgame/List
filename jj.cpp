#include <iostream> 


using namespace std; 

#include <iostream>
using namespace std;

ostream& operator<<(ostream& o, string& s)
{
	o << s.c_str();
	return o;
}
istream& operator>>(istream& i, string& s)
{
	char buf[256];
	i >> buf;
	string tmp(buf);
	s = tmp;
	return i;
}
template<typename T> 
class AbstractList
{
protected:
	T _default;
public :
	virtual void sort(bool (*f) (T* first, T* second)) = 0;
	virtual T get(int index) = 0;//
	virtual void set(int index, T data) = 0;//
	virtual void insert(int index, T data) = 0;//
	virtual T remove(int index) = 0;
	virtual int len() = 0;
	void push(T data)
	{
		insert(0, data);
	}
	virtual T pop()
	{
		if (empty())
			return _default;
		else
			return remove(0);
	}
	virtual bool empty()
	{
		return len() == 0;
	}
	virtual ostream& print(ostream& o)
	{
		for (int i = 0; i < len(); i ++)
		{
			o << get(i) << endl;
		}
		return o;
	}
	virtual istream& read(istream& in)
	{
		int count;
		in >> count;
		for (int i = 0 ; i < count ; i ++)
		{
			T tmp;
			in >> tmp;
			insert(len(), tmp);
		}
		return in;
	}

};
template<typename T>
class Student:public AbstractList<T>
{
public:
	Student *next;
	T data;
	T huy;
	int len()
	{
		if(this->data!=NULL)
		{
		Student*b=new Student;
		b->next=this->next;
		b->data=this->data;
		b->huy=this->huy;
		this->next=b;
		}
		if(this->next==NULL)
		{
			return 0;
	}
		Student* head=this;
		head=this;
		int i=0;
		while(head->next!=NULL)
		{
			head=head->next;
			i++;
		}
		return i;
	}
	Student()
	{
		next=NULL;
		

	}
	Student(T data)
	{
		this->huy=data;
		this->next=NULL;
	}
	~Student()
	{

		//cout<<"fuck"<<endl;
	}
	Student(T data,T huy)
	{
		Student*a=new Student;
		a->data=data;
		a->huy=huy;
		a->next=NULL;
		this->next=a;
		this->data=NULL;
		this->huy=huy;

	}

	void set(int index, T data)
	{
		if(this->next==NULL)
		{
			return;
		}

		Student* head=this;
		int i=0;
		while(head->next!=NULL)
		{
			if(i==index)
				break;
			head=head->next;
			i++;
		}
		head->data=data;
		return;
	}


	void insert(int index, T data)
	{

		if(this->next==NULL)
		{
			return;
		}


		Student* head=this;

		int i=0;


		while((head->next!=NULL))
		{
			if(i==(index))
				break;
			head=head->next;
			i++;
		}

		Student* tmp=new Student;
		tmp->data=data;
		tmp->huy=this->huy;
		tmp->next=head->next;
		head->next=tmp;


		return;
	}
	Student(const Student& a)
	{
		this->data=a.data;
		this->next=a.next;
		this->huy=a.huy;
	}
	Student & operator =(Student& a)
	{
		this->data=a.data;
		this->next=a.next;
		this->huy=a.huy;
		return *this;


	}

	T remove(int index)
	{

		if(this->next==NULL)
		{
			return huy;
		}

		Student* head=this;

		Student* prev;

		int i=0;
		while(head->next!=NULL)
		{
		
			if(i==index+1)
				break;
			prev=head;
			head=head->next;
			i++;
		}
		T tmp=head->data;

		prev->next=head->next;
		delete head;

		return tmp;



	}
	T get(int index)
	{
		if(this->next==NULL)
			return this->huy;
		Student* head=this;

		int i=0;
		while(head->next!=NULL)
		{
			if(i==index+1)
				break;

			head=head->next;
			i++;
		}
		return head->data;

	}
	void sort(bool (*f) (T* first, T* second))
	{
		int i=0;
		while(i!=this->len())
		{
			change(f);
			i++;
		}

	}
	void change(bool (*f) (T* first, T* second))
	{
        if(next->next->next == NULL)
            return;
        else
        {
            if(f(&(next->data), &(next->next->data)))
            {
                Student* tmp = next->next;
                next->next = next->next->next;
                tmp->next = next;
                next = tmp;
            }
            return next->change(f);
        }
    
	}

//	friend bool foo(T* first, T* second);
};
Student<string>* get_init()
{
   Student<string>* init=new Student<string>("fail");
    return init;
}
template<typename T>
	bool foo(T* first, T* second)
{
    if(*first > *second)
        return true;
    return false;
}/*
void main()
{
	Student<int> *a=new Student<int>(1,89);
	a->insert(7,6);
	while(true)
	{
		a->insert(7,9);
		a->remove(1);
	}

}*/
