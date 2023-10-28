#include <iostream>


typedef struct List
{
	int Data;
	struct List* Next = nullptr;
} Node ,* pNode;


typedef struct HashTabel
{
	int TabelMax = 0;
	pNode * Tabel;
	int Listmax[1000] = {0};
} HTabel,* pHTabel;

//��ʼ����ϣ��
pHTabel init_Tabel(int tabelmax);
//����һ��ֵ
void insert_Data(int data,pHTabel hashtabel);
//����һ��������
pNode create_Node(int data);
//����һ������
void insert_Node(int data, pNode header);
//����Ԫ��
pNode find_Data(int data, pHTabel hashtabel);
//��ӡ������ϣ��
void print_HashTabel(pHTabel hashtabel);
//��ӡһ������
void print_List(pNode header);

///��ϣ�� - �������ӷ�///

//ȡģ����ӳ���ϣ���ظ�Ԫ����������
//���¹��ܰ����Թ�ϣ��ĳ�ʼ��������ֵ����ӡ��ϣ������Ԫ�غͶ�����Ĵ���
//ûдɾ�����ܺ��ж��ձ�����Ϊ��
int main()
{
	//����һ����10ȡģ�Ĺ�ϣ��
	pHTabel HT = init_Tabel(10);
	insert_Data(1,HT);
	insert_Data(3,HT);
	insert_Data(5,HT);
	insert_Data(13,HT);
	insert_Data(18,HT);
	insert_Data(54,HT);
	insert_Data(2,HT);
	insert_Data(12,HT);
	insert_Data(16,HT);
	insert_Data(28,HT);
	insert_Data(11,HT);
	insert_Data(21,HT);
	insert_Data(60,HT);
	print_HashTabel(HT);
	std::cout << std:: endl;
	find_Data(21, HT);
	find_Data(22, HT);
	return 0;
}

pHTabel init_Tabel(int tabelmax)
{
	pHTabel new_Tabel = new HTabel;
	new_Tabel->TabelMax = tabelmax;
	new_Tabel->Tabel = new pNode[tabelmax];
	for (int i = 0; i < tabelmax; i++)
	{
		new_Tabel->Tabel[i] = nullptr;
	}
	std::cout << "�ѳ�ʼ��һ����ϣ��-�������ӷ���ȡģֵΪ��"<<tabelmax << std::endl;
	return new_Tabel;
}

void insert_Data(int data, pHTabel hashtabel)
{
	//���û�й�ϣ���Ӧ�������򴴽�һ������
	if (hashtabel->Tabel[data % hashtabel->TabelMax] == nullptr)
	{
		hashtabel->Tabel[data % hashtabel->TabelMax] = create_Node(data);
		hashtabel->Listmax[data % hashtabel->TabelMax] = 1;
	}
	//��֮����һ���½ڵ�
	else
	{
		insert_Node(data,hashtabel->Tabel[data % hashtabel->TabelMax]);
		hashtabel->Listmax[data % hashtabel->TabelMax]++;
	}
	std::cout << "�Ѳ���ֵ��" << data << std::endl;
}

pNode create_Node(int data)
{
	pNode new_node = new Node;
	new_node->Data = data;
	return new_node;
}

void insert_Node(int data, pNode header)
{
	pNode p;
	for (p = header; p->Next != nullptr; p = p->Next);
	p->Next = new Node;
	p->Next->Data = data;
}

pNode find_Data(int data,pHTabel hashtabel)
{
	pNode p;
	for (p = hashtabel->Tabel[data % hashtabel->TabelMax];p != nullptr;p = p->Next)
	{
		if (p->Data == data)
		{
			std::cout << "�ҵ��ˣ�" << data << std::endl;
			return p;
		}
	}
	std::cout << "û�ҵ���" << data << std::endl;

}

void print_HashTabel(pHTabel hashtabel)
{
	std::cout << "��ӡ��ϣ��" << std::endl;
	for (int i = 0; i < hashtabel->TabelMax; i++)
	{
		std::cout << i <<"��";
		print_List(hashtabel->Tabel[i]);
	}
}

void print_List(pNode header)
{
	pNode p = header;
	if (p == nullptr)
	{
		std::cout << "��" << std::endl;
		return;
	}
	for (p = header; p != nullptr; p = p->Next)
	{
		std::cout << p->Data << " ";
	}
	std::cout << std:: endl;
}