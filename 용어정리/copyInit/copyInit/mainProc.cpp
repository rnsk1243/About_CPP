#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Person
{
    public:
        Person()
		{
			cout << "기본 생성자 호출" << endl;
		}

        Person(int* age) :mAge(age)
        {   
			cout << "생성자 호출" << endl;
        }   
		Person(const Person& p/*복사대상 소스*/)
		{
			cout << "복사 생성자 호출" << endl;  
			//cout << "깊은 복사" << endl;
			mAge = new int();
			*mAge = *p.mAge;
			// 다음 코드는 잘못됨. 이유 Person 객체를 만들어봐야 지역변수라서 생성자를 빠져나가면 삭제됨
			//cout << "복사 생성자 호출" << endl;
			//Person copyP;
			//copyP.mName = new char[strlen(p.mName) + 1];
			//strcpy(copyP.mName, p.mName);
			//copyP.mAge = p.mAge;
		}

        ~Person()
        {   
            cout << "Person 소멸자 호출" << endl;
            if(nullptr != mAge)    
            {   
                cout << "mName 삭제" << endl;
                delete mAge;
                mAge = nullptr;
            }   
            cout << "===========" << endl;
        }   

        void print()
        {   
            cout << "Person" << endl;
            cout << "나이: " << mAge << endl;
            cout << "===========" << endl;
        }   
		// 문제를 발생시키는 함수 // void foo(Person* p) 정상
		void foo(Person p) // 인수가 const Person p 이면 복사생성자 호출하고 const Person& p 이면 호출 안함.
		{
			//Person t = p;
			cout << "복사된 p.age = " << p.mAge << endl;
			cout << "foo(const Person p)" << endl;
			cout << "===========" << endl;
			//return t;
			// 함수가 끝나면서 새로만들어져 복사된 Person p는 소멸자가 호출되어 삭제됨. 
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
    return 0; // foo함수가 끝나면서 복사된 Person p가 소멸 되었는데 main함수가 끝나면서 또 소멸자가 호출되어 오류됨.
}

//#include <iostream>
//using namespace std;
//
//class Test
//{
//    public:
//		Test() { cout << "기본 생성자" << endl; }
//        ~Test(){}
//
//        Test(const Test& rhs)
//        {
//            cout << "Test 복사생성자 호출" << endl;
//        }
//};
//
//// 2. 객체를 인자로 전달한 경우
//void foo(const Test t)
//{
//    cout << "foo()" << endl;
//}
//
//// 3. 객체를 그대로 반환하는 경우
//Test boo(const Test t)
//{
//   // 임시객체에 대한 복사 생성자 호출
//   cout << "boo()" << endl;
//   return t;
//}
//
//int main()
//{
//    Test t1;
//
//    cout << "=======================" << endl;
//    cout << "1. 직접 복사생성자 호출" << endl;
//    Test t2(t1);
//    cout << "=======================" << endl;
//
//    cout << "2. 객체를 인자로 전달한 경우" << endl;
//    foo(t1);
//    cout << "=======================" << endl;
//
//    cout << "3. 객체를 그대로 반환하는 경우" << endl;
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
//            cout << "Test 대입연산자 호출" << endl;
//
//            // 1. 자기 자신에 대한 대입일 경우 대비
//            if(this == &rhs)
//            {
//				cout << "자기 자신" << endl;
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
//            // 3. 자기자신의 참조값을 반환
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
//            cout << "Test 기본생성자 호출" << endl; 
//        }
//
//        Test(const Test& rhs)
//        {
//            cout << "Test 복사생성자 호출" << endl; 
//        }
//
//        ~Test() {}
//
//        Test& operator=(const Test& rhs)
//        {
//            cout << "Test 대입연산자 호출" << endl; 
//            return *this;
//        }
//};
//
//int main()
//{
//    Test t1;
//    // 주의! 아래 코드는 대입 연산자 호출이 아니라
//    // t1의 인자를 가진 t2의 복사생성자를 호출한다.
//	// 즉, t2.Test(t1);
//    Test t2 = t1;
//
//    // t1의 인자를 가진 t2의 대입연산자 호출
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
//            std::cout << "복사생성자 호출 Parent(const Parent& rhs)" << std::endl;
//            mName = rhs.mName;
//        }
//
//        virtual ~Parent() {}
//
//        Parent& operator=(const Parent& rhs)
//        {
//            std::cout << "대입연산자 호출 Parent& operator=(const Parent& rhs)" << std::endl;
//            if(this == &rhs)
//            {
//                // 자기 자신에 대한 호출시 사용
//                return *this;
//            }
//
//            mName = rhs.mName;
//            // this에 대한 참조 반환
//            return *this;
//        }
//
//        virtual void print() const
//        {
//            cout << "이름 = " << mName << endl;
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
//        :Parent(name), mSubject("소설") {}
//
//        ~Child() {}
//
//        // *부모 복사생성자 호출
//        Child(const Child& rhs)
//        :Parent(rhs), mSubject("소설")
//        {
//            std::cout << "복사생성자 호출 Child(const Child& rhs)" << std::endl;
//        }
//
//        Child& operator=(const Child& rhs)
//        {
//            std::cout << "대입연산자 호출 Child& operator=(const NChildovel& rhs)" << std::endl;
//            if(this == &rhs)
//            {
//                // 자기 자신에 대한 호출시 사용
//                return *this;
//            }
//
//            // *부모 대입연산자 호출
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
//            std::cout << "주제: " << mSubject << std::endl;
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
//    // 부모이름으로 사용하는 Child 객체생성(다형성)
//    Parent* bp = new Child("다형성");
//
//    // 다운캐스팅
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
