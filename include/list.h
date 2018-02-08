#pragma once
#include "node.h"

//---------------������ ������ ����������� ������ � �������---------------//
template<class dtype>
class list
{
private:
	node<dtype>* head;													//��������� �� ������
	node<dtype>* curr;													//��������� �� ������� �������
	void Clean();														//��������� �����, ������� ������
public:
	list();																//����������� �� ���������
	~list();															//����������
	list(const list<dtype>& src);										//����������� �����������
	list<dtype>& operator=(const list<dtype> &src);						//���������� ��������� ������������
	void Reset() { curr = head; }										//��������� curr �� ������
	bool IsEnded() const { return curr->next == head; }					//�������� �� ���������� *curr � ����� ������
	void GetNext() { curr = curr->next; }								//�������� curr �� ��������� �������
	void InsertInOrder(dtype elem);										//������� � ������������� ������
};
//------------------------------------------------------------------------//




//-----------------------������� ������-----------------------------------//
template <class dtype>
void list<dtype>::Clean()
{
	Reset();
	if (!IsEnded())
	{
		GetNext();
		while (curr != head)
		{
			node<dtype>* temp = curr->next;
			delete curr;
			curr = temp;
		}
		head->next = head;
	}
}

//-----------------------����������� �� ���������-------------------------//
template <class dtype>
list<dtype>::list()
{
	head = new node<dtype>;
	head->next = head;
	Reset();
}

//--------------------------------����������------------------------------//
template <class dtype>
list<dtype>::~list()
{
	Clean();
	delete head;
}

//----------------------����������� �����������---------------------------//
template <class dtype>
list<dtype>::list(const list<dtype>& src) : list()
{
	node<dtype>* psrc = src.head;
	node<dtype>* temp = head;
	while (psrc->next != src.head)
	{
		psrc = psrc->next;
		temp->next = new node<dtype>(psrc->data);
		temp = temp->next;
	}
	temp->next = head;
}

//----------------------�������� ������������-----------------------------//
template <class dtype>
list<dtype>& list<dtype>::operator=(const list<dtype>& src)
{
	Clean();
	node<dtype>* psrc = src.head;
	node<dtype>* temp = head;
	while (psrc->next != src.head)
	{
		psrc = psrc->next;
		temp->next = new node<dtype>(psrc->data);
		temp = temp->next;
	}
	temp->next = head;
	return *this;
}

//------------------������� � ������������� ������------------------------//
template <class dtype>
void list<dtype>::InsertInOrder(dtype elem)
{
	node<dtype>* temp = new node<dtype>(elem);
	Reset();

	while ((*(curr->next) < *temp) && !IsEnded())
			GetNext();
	node<dtype>* pn = curr->next;
	curr->next = temp;
	curr->next->next = pn;
}
