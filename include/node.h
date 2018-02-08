#pragma once

//������ ������ ������� ������
template<class dtype>
class node
{
public:
	dtype data;		//������ � ��������
	node* next;		//��������� �� ��������� ��-�
	bool operator< (const node& n) { return (data<n.data); }	//��������� 
	bool operator> (const node& n) { return (data>n.data); }	//���������
	node(dtype in) { data = in; next = NULL; }					//����������� � ����������
	node() { next = NULL; }										//����������� �� ���������
};