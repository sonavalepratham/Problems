#include<bits/stdc++.h>
using namespace std;

// it will not share ownership of object.
// clean up after going out of scope.
// better for scope based pointers.

class A{
	public:
		void printData(){
		cout<<"Data\n";
		}
		~A(){
		cout<<"A destructed\n";
	}
};

template<typename T>
class unique_ptr1{
private:
	T* m_ptr;
public:

	// explicit don't allow conversion from single parameter.
	// eg. unique_ptr_obj == some_address; this will throw error as we created explicit constructor, else will construct object from some_addr and does comparison.
	explicit unique_ptr1(T* ptr) : m_ptr(ptr){

}

// don't allow copy constructor & assignment operator.
unique_ptr1(const unique_ptr1&) = delete;
unique_ptr1& operator=(const unique_ptr1&) = delete;

	T* operator ->(){
		return this->m_ptr;
	}

	T& operator *(){
	return *this->m_ptr;
	}

	bool operator ==(const unique_ptr1 rhObj){
		return rhObj.m_ptr==this->m_ptr;
	}

	~unique_ptr1(){
		delete m_ptr;
	}
};

int main(){
	unique_ptr1<A> ptr = unique_ptr1<A>(new A());
	ptr->printData();
	(*ptr).printData();
	// cout<<(ptr==(A*)100)<<"\n"; this will work if constructor is not explicit
	return 0;
}
