#include "pch.h"
#include "Member.h"

Member::Member()
{
}

Member::Member(string name, string phone, string family_phone, string office_phone, string e_mail, string group)
{
	this->m_name = name;
	this->m_phone = phone;
	this->m_family_phone = family_phone;
	this->m_office_phone = office_phone;
	this->m_e_mail = e_mail;
	this->m_group = group;

}

void Member::Load(ifstream& in)
{
	in >> m_name;
	in >> m_phone;
	in >> m_family_phone;
	in >> m_office_phone;
	in >> m_e_mail;
	in >> m_group;
}

void Member::Save(ofstream& out)
{
	out << m_name<<"\t";
	out << m_phone<<"\t";
	out << m_family_phone<<"\t";
	out << m_office_phone << "\t";
	out << m_e_mail << "\t";
	out << m_group << "\t"<<endl;
}

