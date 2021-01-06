#pragma once

template<typename type>
class SmartPtr {
	type* newPointer;
public: 
	SmartPtr( type* point ) {
		this->newPointer = point;
	}
	~SmartPtr() {
		delete newPointer;
	}

	type& operator*() {
		return *newPointer;
	}
};

