//2.Cai dat mot cau truc list quan ly sinh vien.Thong tin ve sinh vien duoc bieu dien boi mot struct gom ma sinh vien(int), ho ten sinh vien (string), lop (string).Cac thao tac can thuc hien 
//Them SV vao dau danh sach
//Them SV vao cuoi danh sach
//Tim sinh vien theo ten
//Xoa sinh vien theo ten
//Thuc hien yeu cau tren ca 2 ngon ngu C va C++
#include<iostream>
#include<string.h>
#include<fstream>
#include<iomanip>
#include<sstream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
template <typename T>
class NodeData
{
public:
	NodeData() : next_(NULL) { ; }
	void         set_data(T val) { data_ = val; }
	T            get_data() const { return data_; }
	void         set_next(NodeData<T>* next) { next_ = next; }
	NodeData<T>* get_next() const { return next_; };
private:
	T            data_;  // dữ liệu kiểu template
	NodeData<T>* next_;
};
template<typename T>
class LinkedList
{
public:
	LinkedList() : p_head_(NULL) {};
	~LinkedList() { ; };

	void InsetFront(T val)     // Hàm chèn phần tử vào trước danh sách
	{
		NodeData<T>* temp = new NodeData<T>();
		temp->set_data(val);
		temp->set_next(p_head_);
		p_head_ = temp;
	}

	void RemoveFront()   // Remove phần tử đầu danh sách
	{
		if (p_head_ != NULL)
		{
			NodeData<T>* temp = p_head_;
			p_head_ = p_head_->get_next();
			delete temp;
		}
	}

	NodeData<T>* head() { return p_head_; };

public:
	NodeData<T>* p_head_;    // Luôn có con trỏ pHead trỏ vào phần tử đầu tiên. 
							 // Có thể coi đây là linked list dạng single
};
class Person
{
public:
	Person() { ; };
	Person(std::string name, unsigned int age, bool sex);
	~Person() { ; };
	void operator =(Person& p);
	std::string get_name() const { return name_; }
	unsigned int get_age() const { return age_; }
	bool get_sex() const { return sex_; }

	void ShowInfo()
	{
		std::cout << "  Name = " << name_.c_str();
		std::cout << "  Age = " << age_;
		std::cout << "  Sex = " << ((sex_ == 1) ? "Male" : "Female");
	}
private:
	std::string name_;
	unsigned int age_;
	bool sex_;
};

Person::Person(std::string name, unsigned int age, bool sex)
{
	name_ = name;
	age_ = age;
	sex_ = sex;
}

void Person::operator =(Person& p) //Lưu ý là khi xây dựng các lơp đối tượng, hãy dựng các phép toán cho lớp.
{
	this->name_ = p.name_;
	this->age_ = p.age_;
	this->sex_ = p.sex_;
}
int main() {
	LinkedList<Person> data_list;
	Person person1("Pham A", 20, 1);
	Person person2("Pham B", 20, 0);
	Person person3("Pham C", 20, 1);
	Person person4("Pham D", 20, 0);

	data_list.InsetFront(person1);
	data_list.InsetFront(person2);
	data_list.InsetFront(person3);
	data_list.InsetFront(person4);

	// In danh sách.
	NodeData<Person>* p_head = data_list.head();
	if (p_head != NULL)
	{
		NodeData<Person>* temp = p_head;
		while (temp != NULL)
		{
			temp->get_data().ShowInfo();
			std::cout << "\n\n\n";
			temp = temp->get_next();
		}
	}
	return 0;
}