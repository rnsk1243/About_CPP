#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Person
{
    public:
        Person()
		{
			cout << "�⺻ ������ ȣ��" << endl;
		}

        Person(int* age) :mAge(age)
        {   
			cout << "������ ȣ��" << endl;
        }   
		Person(const Person& p/*������ �ҽ�*/)
		{
			cout << "���� ������ ȣ��" << endl;  
			//cout << "���� ����" << endl;
			mAge = new int();
			*mAge = *p.mAge;
			// ���� �ڵ�� �߸���. ���� Person ��ü�� �������� ���������� �����ڸ� ���������� ������
			//cout << "���� ������ ȣ��" << endl;
			//Person copyP;
			//copyP.mName = new char[strlen(p.mName) + 1];
			//strcpy(copyP.mName, p.mName);
			//copyP.mAge = p.mAge;
		}

        ~Person()
        {   
            cout << "Person �Ҹ��� ȣ��" << endl;
            if(nullptr != mAge)    
            {   
                cout << "mName ����" << endl;
                delete mAge;
                mAge = nullptr;
            }   
            cout << "===========" << endl;
        }   

        void print()
        {   
            cout << "Person" << endl;
            cout << "����: " << mAge << endl;
            cout << "===========" << endl;
        }   
		// ������ �߻���Ű�� �Լ� // void foo(Person* p) ����
		void foo(Person p) // �μ��� const Person p �̸� ��������� ȣ���ϰ� const Person& p �̸� ȣ�� ����.
		{
			//Person t = p;
			cout << "����� p.age = " << p.mAge << endl;
			cout << "foo(const Person p)" << endl;
			cout << "===========" << endl;
			//return t;
			// �Լ��� �����鼭 ���θ������ ����� Person p�� �Ҹ��ڰ� ȣ��Ǿ� ������. 
		}
        //char* mName;
        int* mAge;
    private:
};



int main()
{
	int a = 3;
    Person p(&a);
 //   p.print();
	//cout << "p.name = " << p.mName << endl;
   p.foo(p);
//    p.print();
   cout << "dkdk" << p.mAge << endl;
    return 0; // foo�Լ��� �����鼭 ����� Person p�� �Ҹ� �Ǿ��µ� main�Լ��� �����鼭 �� �Ҹ��ڰ� ȣ��Ǿ� ������.
}

//#include <iostream>
//using namespace std;
//
//class Test
//{
//    public:
//		Test() { cout << "�⺻ ������" << endl; }
//        ~Test(){}
//
//        Test(const Test& rhs)
//        {
//            cout << "Test ��������� ȣ��" << endl;
//        }
//};
//
//// 2. ��ü�� ���ڷ� ������ ���
//void foo(const Test t)
//{
//    cout << "foo()" << endl;
//}
//
//// 3. ��ü�� �״�� ��ȯ�ϴ� ���
//Test boo(const Test t)
//{
//   // �ӽð�ü�� ���� ���� ������ ȣ��
//   cout << "boo()" << endl;
//   return t;
//}
//
//int main()
//{
//    Test t1;
//
//    cout << "=======================" << endl;
//    cout << "1. ���� ��������� ȣ��" << endl;
//    Test t2(t1);
//    cout << "=======================" << endl;
//
//    cout << "2. ��ü�� ���ڷ� ������ ���" << endl;
//    foo(t1);
//    cout << "=======================" << endl;
//
//    cout << "3. ��ü�� �״�� ��ȯ�ϴ� ���" << endl;
//    Test t3 = boo(t1);
//    cout << "=======================" << endl;
//
//    return 0;
//}

//
//#include <iostream>
//using namespace std;
//
//class Test
//{
//    public:
//        Test()
//        {
//            // Default
//            mName = new char[8];
//            strcpy(mName, "Default");
//        }
//
//        Test(const char* name)
//        :mName(nullptr)
//        {
//            if(nullptr == name)
//            {
//                return;
//            }
//
//            mName = new char[strlen(name) + 1];
//            strcpy(mName, name);
//        }
//
//        ~Test()
//        {
//            if(nullptr != mName)
//            {
//                delete [] mName;
//                mName = nullptr;
//            }
//        }
//
//        Test& operator=(const Test& rhs)
//        {
//            cout << "Test ���Կ����� ȣ��" << endl;
//
//            // 1. �ڱ� �ڽſ� ���� ������ ��� ���
//            if(this == &rhs)
//            {
//				cout << "�ڱ� �ڽ�" << endl;
//                return *this;
//            }
//
//            // 2. Deep Copy Area
//            if(nullptr != this->mName)
//            {
//				cout << "Deep Copy" << endl;
//                delete [] this->mName;
//                this->mName = nullptr;
//            }
//
//            mName = new char[strlen(rhs.mName) + 1];
//            strcpy(mName, rhs.mName);
//
//            // 3. �ڱ��ڽ��� �������� ��ȯ
//            return *this;
//        }
//
//        void print()
//        {
//            cout << "name: " << mName << endl;
//        }
//
//    private:
//        char* mName;
//};
//
//int main()
//{
//    Test* t1 = new Test;
//    Test t2("Tuyy");
//    t1->print();
//    t2.print();
//
//    cout << "\n================" << endl;
//    t2 = *t1;
//    t1->print();
//    delete t1;
//
//    t2.print();
//
//    return 0;
//}

//#include <iostream>
//using namespace std;
//
//class Test
//{
//    public:
//        Test()
//        {
//            cout << "Test �⺻������ ȣ��" << endl; 
//        }
//
//        Test(const Test& rhs)
//        {
//            cout << "Test ��������� ȣ��" << endl; 
//        }
//
//        ~Test() {}
//
//        Test& operator=(const Test& rhs)
//        {
//            cout << "Test ���Կ����� ȣ��" << endl; 
//            return *this;
//        }
//};
//
//int main()
//{
//    Test t1;
//    // ����! �Ʒ� �ڵ�� ���� ������ ȣ���� �ƴ϶�
//    // t1�� ���ڸ� ���� t2�� ��������ڸ� ȣ���Ѵ�.
//	// ��, t2.Test(t1);
//    Test t2 = t1;
//
//    // t1�� ���ڸ� ���� t2�� ���Կ����� ȣ��
//    t2 = t1;
//
//    return 0;
//}
//
//#include <iostream>
//#include<string>
//using namespace std;
//
//class Parent
//{
//    public:
//        Parent() {}
//
//        Parent(std::string name)
//        :mName(name) {}
//
//        Parent(const Parent& rhs)
//        {
//            std::cout << "��������� ȣ�� Parent(const Parent& rhs)" << std::endl;
//            mName = rhs.mName;
//        }
//
//        virtual ~Parent() {}
//
//        Parent& operator=(const Parent& rhs)
//        {
//            std::cout << "���Կ����� ȣ�� Parent& operator=(const Parent& rhs)" << std::endl;
//            if(this == &rhs)
//            {
//                // �ڱ� �ڽſ� ���� ȣ��� ���
//                return *this;
//            }
//
//            mName = rhs.mName;
//            // this�� ���� ���� ��ȯ
//            return *this;
//        }
//
//        virtual void print() const
//        {
//            cout << "�̸� = " << mName << endl;
//        }
//
//    private:
//        std::string mName;
//};
//
//class Child: public Parent
//{
//    public:
//        Child() {}
//
//        Child(std::string name)
//        :Parent(name), mSubject("�Ҽ�") {}
//
//        ~Child() {}
//
//        // *�θ� ��������� ȣ��
//        Child(const Child& rhs)
//        :Parent(rhs), mSubject("�Ҽ�")
//        {
//            std::cout << "��������� ȣ�� Child(const Child& rhs)" << std::endl;
//        }
//
//        Child& operator=(const Child& rhs)
//        {
//            std::cout << "���Կ����� ȣ�� Child& operator=(const NChildovel& rhs)" << std::endl;
//            if(this == &rhs)
//            {
//                // �ڱ� �ڽſ� ���� ȣ��� ���
//                return *this;
//            }
//
//            // *�θ� ���Կ����� ȣ��
//            Parent::operator=(rhs);
//            this->mSubject = rhs.mSubject;
//
//            return *this;
//        }
//
//        void print() const
//        {
//            std::cout << "Child.print()" << std::endl;
//            Parent::print();
//            std::cout << "����: " << mSubject << std::endl;
//            std::cout << "=============" << std::endl;
//        }
//
//    private:
//        std::string mSubject;
//};
//
//int main()
//{
//    Child child1("Child First");
//    Parent* parent1 = new Child(child1);
//    parent1->print();
//
//    Child* child2 = new Child("CHild Second");
//    Parent* parent2 = new Child(*child2);
//    parent2->print();
//
//    // �θ��̸����� ����ϴ� Child ��ü����(������)
//    Parent* bp = new Child("������");
//
//    // �ٿ�ĳ����
//    Child* child3 = static_cast<Child*>(bp);
//    Parent* parent3 = new Child(*child3);
//    parent3->print();
//
//    delete child2;
//    delete child3;
//    delete parent1;
//    delete parent2;
//    delete parent3;
//
//    return 0;
//}
