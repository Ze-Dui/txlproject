#pragma once
#include"Member.h"
class DataInterface
{
public:
	bool Open(CString Filepath);
	void Add(Member mMem);
	void Del(int index);
	void Amend(int index, Member mMem);
	Member Search(string information);
	bool Save(CString Filepath);
	Member* Find(int id);

	vector<Member>Mem;
};

