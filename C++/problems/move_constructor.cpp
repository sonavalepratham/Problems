#include<bits/stdc++.h>
using namespace std;

class String{
	private:
		char* m_Data;
		unsigned int m_Length;
	public:
	String() = default;
		// Constructor
		String(char* str)
		{
			cout<<"New Constructor\n";
			m_Length = strlen(str);
			m_Data = new char[m_Length];
			memcpy(m_Data, str, m_Length);
		}

		// Copy constructor
		String(const String& str){
			cout<<"Copying\n";
			m_Length = str.m_Length;
			m_Data = new char[m_Length];
			memcpy(m_Data, str.m_Data, m_Length);
		}
		// Move constructor, rvalue constructor
		String(String&& str) noexcept
		{
			cout<<"Moving\n";
			m_Length = str.m_Length;
			m_Data = str.m_Data;
			str.m_Length=0;
			str.m_Data = nullptr;
		}
		void Print(){
			int i=0;
			while(m_Data[i]) cout<<m_Data[i], i++;
			cout<<"\n";
		}
		~String(){
			cout<<"Destructing\n";
			delete m_Data;
		}
};


class Entity{
	private:
		String m_Str;
	public:
	// not move contructor
		Entity(const String& str) : m_Str(str){

		}

		Entity(String&& str) : m_Str(std::move(str)) // or typecast to String&&
		{
		}
		void Print(){
			m_Str.Print();
		}
};
int main(){
	Entity e(String("prathmesh"));
	e.Print();
	return 0;
}
