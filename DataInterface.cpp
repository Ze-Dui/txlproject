#include "pch.h"
#include "DataInterface.h"

bool DataInterface::Open(CString Filepath)
{
	ifstream in(Filepath, ios::in);
	if (in.is_open())
	{
		int num;
		in >> num;
		for (int i = 0; i < num; i++)
		{
			Member mMem;
			mMem.Load(in);
			Mem.push_back(mMem);
		}
		return true;
	}
	return false;
}

void DataInterface::Add(Member mMem)
{
	Mem.push_back(mMem);
}

void DataInterface::Del(int index)
{
	Mem.erase(Mem.begin() + index);

}

void DataInterface::Amend(int index, Member mMem)
{
	Mem[index] = mMem;

}

Member DataInterface::Search(string information)
{
	for (int i = 0; i < Mem.size();i++)
	{
		if (Mem[i].m_name == information || Mem[i].m_phone == information)
			return Mem[i];
	}
	return Member(TEXT(""), TEXT(""), TEXT(""), TEXT(""), TEXT(""), TEXT(""));
}

bool DataInterface::Save(CString Filepath)
{
	ofstream out(Filepath, ios::out);
	if (out.is_open())
	{
		out << Mem.size() << endl;
		for (int i = 0; i < Mem.size();i++)
		{
			Mem[i].Save(out);
		}
		out.close();
		return true;
	}
	return false;
}

Member* DataInterface::Find(int id)
{
	Member* array=new Member[10];
	int j = 0;
	for (int i=0; i < Mem.size(); i++)
	{
		if (Mem[i].m_group == Mem[id].m_group)
		{
			array[j++] = Mem[i];
		}
	}
	return  array;
}
