#pragma once
#include "Member.h"

class Student : public Member
{
protected:
	// 지도교수
	string advisor;
public:
	Student() {}
	Student(string id, string name, string department, string advisor) : Member(id, name, department)
	{
		this->advisor = advisor;
	}
	~Student() {}

	// 출력함수
	void putMember() {}
};
