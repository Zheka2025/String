#include<iostream>
using namespace std;

#define delimiter "\n=============================================================================\n";

//#define CONSTRUCTOR_CHEK

class String;
String operator+(const String& left, const String& right);
class String
{

	int size; // Размер строки
	char* str;
public:
	int get_size() const
	{
		return size;
	}
	char* get_str() const
	{
		return str;
	}
	//							Constructor:
	String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefConstructor:\t" << this << endl;
	}
	String(const char* str)
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; str[i]; i++)this->str[i] = str[i];
		cout << "Constructor:\t" << this << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char [size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConstructor: " << this << endl;
	}
	String(String&& other)
	{
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		cout << "MoveConstructor: " << this << endl;
	}


	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t" << this << endl;
	}
	//				Operators:
	String& operator=(const String& other)
	{
		if (this == &other) return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char [size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssignment: " << this << endl;
		return *this;
	}

	String& operator = (String&& other)
	{
		delete[] this->str;
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		cout << "MoveAssigment: " << this << endl;
		return *this;
	}

	String& operator +=(const String& other)
	{
		return *this = *this + other;
	}

	char& operator [](int i)
	{
		return this->str[i];
	}
	const char& operator [](int i) const
	{
		return this->str[i];
	}




	void print()
	{
		cout << "size:\t" << size << endl;
		cout << "str:\t" << str << endl;
	}
};

String operator+(const String& left, const String& right)
{
	String buffer = (left.get_size() + right.get_size() - 1);
	/*for (int i = 0; left.get_str()[i]; i++)
	buffer.get_str()[i] = left.get_str()[i];
	for (int i = 0; right.get_str()[i]; i++)
	buffer.get_str()[i + left.get_size() - 1] = right.get_str()[i];*/
	for (int i = 0; left[i]; i++)
		buffer[i] = left[i];
	for (int i = 0; right[i]; i++)
		buffer[i + left.get_size() - 1] = right[i];
	return buffer;

}
//String& operator+(String left, String right)
//{
//	left.get_str();
//	right.get_str();
//	return String(left.get_str * right.get_str);
//}
ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}
void main()
{
#ifdef CONSTRUCTOR_CHEK

	setlocale(LC_ALL, "");
	String str0;
	//str0.print();
	cout << str0 << endl;
	cout << typeid(typeid("Hello").name()).name() << endl;
	String str1 = "Hello";
	cout << str1 << endl;
	str1.print();
	cout << str1 << endl;
	String str2 = str1;
	str0 = str1;
	cout << str0 << endl;
	str2 = str2;
#endif
	String str1 = "Hello";
	String str2 = "Word";
	cout << delimiter;
	String str3;
	str3 = str1 + " " + str2;
	cout << str3 << endl;
	cout << delimiter;
}

