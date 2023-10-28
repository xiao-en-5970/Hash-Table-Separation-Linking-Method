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

//初始化哈希表
pHTabel init_Tabel(int tabelmax);
//插入一个值
void insert_Data(int data,pHTabel hashtabel);
//创建一个新链表
pNode create_Node(int data);
//插入一个链表
void insert_Node(int data, pNode header);
//查找元素
pNode find_Data(int data, pHTabel hashtabel);
//打印整个哈希表
void print_HashTabel(pHTabel hashtabel);
//打印一个链表
void print_List(pNode header);

///哈希表 - 分离链接法///

//取模方法映射哈希表，重复元素用链表处理
//以下功能包含对哈希表的初始化，插入值，打印哈希表，查找元素和对链表的处理
//没写删除功能和判定空表是因为懒
int main()
{
	//创建一个以10取模的哈希表
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
	std::cout << "已初始化一个哈希表-分离链接法，取模值为："<<tabelmax << std::endl;
	return new_Tabel;
}

void insert_Data(int data, pHTabel hashtabel)
{
	//如果没有哈希表对应的链表则创建一个链表
	if (hashtabel->Tabel[data % hashtabel->TabelMax] == nullptr)
	{
		hashtabel->Tabel[data % hashtabel->TabelMax] = create_Node(data);
		hashtabel->Listmax[data % hashtabel->TabelMax] = 1;
	}
	//反之加入一个新节点
	else
	{
		insert_Node(data,hashtabel->Tabel[data % hashtabel->TabelMax]);
		hashtabel->Listmax[data % hashtabel->TabelMax]++;
	}
	std::cout << "已插入值：" << data << std::endl;
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
			std::cout << "找到了：" << data << std::endl;
			return p;
		}
	}
	std::cout << "没找到：" << data << std::endl;

}

void print_HashTabel(pHTabel hashtabel)
{
	std::cout << "打印哈希表：" << std::endl;
	for (int i = 0; i < hashtabel->TabelMax; i++)
	{
		std::cout << i <<"：";
		print_List(hashtabel->Tabel[i]);
	}
}

void print_List(pNode header)
{
	pNode p = header;
	if (p == nullptr)
	{
		std::cout << "空" << std::endl;
		return;
	}
	for (p = header; p != nullptr; p = p->Next)
	{
		std::cout << p->Data << " ";
	}
	std::cout << std:: endl;
}