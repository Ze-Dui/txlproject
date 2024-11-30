#pragma once


class Member
{
public:
	Member();
	Member(string name,string phone,string family_phone,string office_phone,string e_mail,string group);
	//Member(CString name, CString phone, CString family_phone, CString office_phone, CString e_mail, CString group);

	void Load(ifstream& in);
	void Save(ofstream& out);

	string m_name;
	string m_phone;
	string m_family_phone;
	string m_office_phone;
	string m_e_mail;
	string m_group;
};

