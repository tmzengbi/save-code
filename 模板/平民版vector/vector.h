#ifndef __VECTOR_H__
#define __VECTOR_H__
#include<iostream>
#include<memory>
#include"base.h"
template< typename T, typename Alloc = std::allocator<T> >
class myVector : public Base {
    public:
        // Constructor
        myVector(){
			_data=alloc.allocate(0);
			this->_capacity=this->_size=0;
		}
         myVector(const std::size_t & size, const T & val,
                 Alloc a = Alloc()){
					alloc=a;
                    _size=_capacity=size;
                    _data=alloc.allocate(_capacity);
                    for(size_t i=0;i<size;++i){
                        alloc.construct(_data+i,val);
                    }
				 }
        template<typename InputIterator>
            myVector(InputIterator begin, InputIterator end,
                     Alloc a = Alloc()){
						 alloc=a;
                         _size=_capacity=end-begin;
                         _data=alloc.allocate(_capacity);
                         for(int cnt=0;begin!=end;++begin,++cnt){
                             alloc.construct(_data+cnt,*begin);
                         }
					 }
        myVector(const myVector & other):myVector(other.begin(),other.end()){
			
		}
        ~myVector(){
   			Tidy();
		}
         // Copy Operator
        myVector & operator=(const myVector & other){
			if(this==&other) return *this;
			Tidy();
			_size=_capacity=other.end()-other.begin();
			_data=alloc.allocate(_size);
			for(size_t cnt=0;cnt<_size;++cnt){
				alloc.construct(_data+cnt,*(other._data+cnt));
			}
            return *this;
		}
         // Iterator
        typedef T *         iterator;
        typedef const T *   const_iterator;
        inline iterator begin(){
			return _data;
		}
        inline const_iterator begin() const{
			return _data;
		}
        inline iterator end(){
			return _data+_size;
		}
        inline const_iterator end() const{
			return _data+_size;
		}
         // Capacity
        inline std::size_t size(){
			return _size;
		}
		// todo
        void resize(const std::size_t & newSize){
			expand(newSize);
			if(_size>newSize){
				while(_size>newSize){
					alloc.destroy(_data+_size-1);
					--_size;
				}
			} else {
				_size=newSize;
			}
		}
        void resize(const std::size_t & newSize, const T & val){
			expand(newSize);
			if(_size>newSize){
				while(_size>newSize){
					alloc.destroy(_data+_size-1);
					--_size;
				}
			} else {
				while(_size<newSize){
					alloc.construct(_data+_size,val);
					_size++;
				}
			}
		}
		//
        inline std::size_t capacity() const{
			return _capacity;
		}
        inline bool empty() const{
			return !_size;
		}
		//todo
        void reserve(const std::size_t & newCapacity){
			if(_capacity>=newCapacity) return;
			T *new_data=alloc.allocate(newCapacity);
			size_t old_size=_size;
			for(size_t i=0;i<_size;++i){
				alloc.construct(new_data+i,*(_data+i));
                alloc.destroy(_data+i);
			}
			alloc.deallocate(_data,old_size);
			_data=new_data;
			_size=old_size;
			_capacity=newCapacity;

		}
		//
         // Element Access
        inline T & operator[](const std::size_t & index){
			return *(_data+index);
		}
        inline const T & operator[](const std::size_t & index) const{
			return *(_data+index);
		}
        inline T & front(){
			return *_data;
		}
        inline const T & front() const{
			return *_data;
		}
        inline T & back(){
			return *(_data+_size-1);
		}
        inline const T & back() const{
			return *(_data+_size-1);
		}
        inline T * data(){
			return _data;
		}
        inline const T * data() const{
			return _data;
		}
         // Modifiers
        template<typename InputIterator>
        void assign(InputIterator begin, InputIterator end){
			size_t newSize=end-begin;
            if(newSize>_capacity){
                Tidy();
				_capacity=newSize;
			    _data=alloc.allocate(_capacity);
            }
			_size=newSize;
			for(int cnt=0;begin!=end;++begin,++cnt){
				alloc.construct(_data+cnt,*begin);
			}
			
		}
        void assign(const std::size_t & newSize, const T & val){
    		if(newSize>_capacity){
                Tidy();
                _capacity=newSize;
                _data=alloc.allocate(_capacity);
            }
			_size=newSize;
			for(size_t i=0;i<newSize;++i){
				alloc.construct(_data+i,val);
			}
		}
        void push_back(const T & val){
			expand(_capacity+1);
			alloc.construct(_data+_size,val);
			_size++;
		}
        void pop_back(){
			if(empty()) return;
			alloc.destroy(_data+_size-1);
			_size--;
		}
        void clear(){
			for(T *it=_data;it!=_data+_size;++it)
				alloc.destroy(it);
			_size=0;
		}
     private:
	 	void expand(size_t __capacity){
			 if(__capacity<=_capacity) return;
			 size_t old_capacity=_capacity;
			 if(_capacity*2<=__capacity){
				 _capacity=__capacity;
			 } else { 
			 	_capacity *=2;
		 	 }
			 T *new_data=alloc.allocate(_capacity),*tmp=new_data;
			 for(T *it=_data;it!=_data+_size;++it){
			 	alloc.construct(tmp,*it);
				alloc.destroy(it);
				tmp++;
			 }
			 alloc.deallocate(_data,old_capacity);
			 _data=new_data;
		 }
		void Tidy(){
			for(T *it=_data;it!=_data+_size;++it)
				alloc.destroy(it);
			alloc.deallocate(_data,_capacity);
			_size=_capacity=0;
			_data=nullptr;
		}
        T * _data;
        std::size_t _size, _capacity;
		Alloc alloc;
};
#endif