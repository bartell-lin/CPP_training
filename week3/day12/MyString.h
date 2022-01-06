class MyString {
public:
	char* mstring;
	MyString(char* str);
	~MyString();
	
	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
	MyString(MyString&& other);
	MyString& operator=(MyString&& other);
	
	MyString operator+(const MyString& other);
	char* operator+(int x);
	MyString operator*(int x);
	char& operator[](int x);
};



