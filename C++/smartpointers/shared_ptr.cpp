/*
1. It shares ownership of objects (managed object).
2. manages lifetime of object. - smart ptr
3. it keeps reference count to maintain how many shared ptr are pointing to same object.
   once last object goes out of scope then managed object get deleted.
4. shared_ptr is thread safe & also not.
   a. control block is thread safe.
   b. managed object is not.
5. 3 Ways when managed object get destroyed.
    a. If last shared ptr goes out of scope.
    b. If you initialize shared ptr with some other shared ptr.
    c. If you reset shared ptr.
6. Referene cnt will not work when we use reference or pointer of shared ptr.
*/

#include<iostream>
using namespace std;

// default constructor
// parameterized constructor
// copy constructor
// move constructor
// copy assignment operator
// move assignment operator
// -> operator
// * operator
// reset
// get_count
// get

template<typename T>
class sharedptr
{
   private:
      int* count_ptr;
      T* m_data;
      void increment(){
         if(count_ptr){
            (*count_ptr)++;
         }
      }

      void decrement(){
         if(count_ptr){
            (*count_ptr)--;
            if((*count_ptr) == 0){
               delete count_ptr;
               delete m_data;
            }
         }
      }
   public:
   // default and parameterized constructor.
      sharedptr(T* ptr = nullptr) : m_data(ptr), count_ptr(new int(1)){
         cout <<"Constructor called\n";
      }

   // copy constructor
      sharedptr(const sharedptr& from){
         m_data = from.m_data;
         count_ptr = from.count_ptr;
         increment();
      }
   
   // move consctructor
      sharedptr(sharedptr&& from){
         count_ptr = from.count_ptr;
         m_data = from.m_data;
         from.m_data = nullptr;
         from.count_ptr = nullptr;
      }

   // copy assignment operator
      sharedptr& operator =(const sharedptr& from){
         decrement();
         m_data = from.m_data;
         count_ptr = from.count_ptr;
         increment();
         return *this;
      }

   // move assignment operator
      sharedptr& operator =(sharedptr&& from){
         m_data = from.m_data;
         count_ptr = from.count_ptr;
         from.count_ptr = nullptr;
         from.m_data = nullptr;
         return *this;
      }

   // -> operator
      T* operator ->(){
         return m_data;
      }

   // operator *
      T& operator *(){
         return *m_data;
      }

   // reset
      void reset(T* ptr){
         decrement();
         m_data = ptr;
         count_ptr = new int(1);
      }

   // get
      T get(){
         return m_data;
      }
   // get_count
      int get_count(){
         if(count_ptr)
            return *count_ptr;
         return -1;
      }
      ~sharedptr(){
         decrement();
         cout<<"sharedptr destructed\n";
      }
};

class A{
	public:
		void printData(){
		cout<<"Data\n";
		}
		~A(){
		cout<<"A destructed\n";
	}
};

int main(){

   sharedptr<A> ptr1(new A());
   sharedptr<A> ptr2;
   ptr2 = ptr1;
   (*ptr1).printData();
   cout << ptr1.get_count()<<"\n";
   return 0;
}