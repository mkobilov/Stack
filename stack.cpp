#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>



class StackElement{
	public:
	double value;
	StackElement* next;


	StackElement(const double v){
		value = v;
		printf("%f\n",value);
		next = NULL;
	}
	~StackElement(){
		printf("Element with value %d erased\n",value);
	}
	int IsValidElement();
};


int StackElement :: IsValidElement(){
	
	return 1;
}

class Stack{
	StackElement* top;
	
	public:
		Stack(){
			top = NULL;
		}
		~Stack(){
			printf("Stack Deleted\n");
		}
		int Push(StackElement* element);
		StackElement* Pop();
		int Add();
		int Sub();
		int Mul();
		int Div();
		
	private:
		int IsValidStack();
};

int Stack :: IsValidStack(){
	assert(this != NULL);
	return 1;
}

StackElement* Stack :: Pop(){
	assert(this->top);
	
	StackElement* res = top;
	top = top->next;
	return res;
}

int Stack :: Add(){
	this->IsValidStack();	
	
	StackElement* first = this->Pop();
	StackElement* second = this->Pop();
	
	StackElement* res = new StackElement(first->value + second->value); 
	this->Push(res);
	delete first;
	delete second;
	return 1;
	
	
	
}	
int Stack :: Sub(){
	this->IsValidStack();	
	
	StackElement* first = this->Pop();
	StackElement* second = this->Pop();
	
	StackElement* res = new StackElement(-(first->value) + second->value); 
	this->Push(res);
	delete first;
	delete second;
	return 1;
	
	
	
}

int Stack :: Mul(){
	this->IsValidStack();	
	
	StackElement* first = this->Pop();
	StackElement* second = this->Pop();
	
	StackElement* res = new StackElement(first->value * second->value); 
	this->Push(res);
	delete first;
	delete second;
	return 1;
	
	
	
}	

int Stack :: Div(){
	this->IsValidStack();	
	
	StackElement* first = this->Pop();
	StackElement* second = this->Pop();
	
	StackElement* res = new StackElement( second->value / first->value); 
	this->Push(res);
	delete first;
	delete second;
	return 1;
	
	
	
}

int Stack :: Push (double value) {
	StackElement* = new StackElement(value);
	if((*element).IsValidElement() && this->IsValidStack()){	
		element->next = top;
		top = element;
		return 1;
	}
	printf("Push failed\n");
	return 0;
}


int main(){
	Stack* test_stack_ptr = new Stack;
	StackElement* elem_ptr1 = new StackElement(2);
	StackElement* elem_ptr2 = new StackElement(3);
	test_stack_ptr->Push(elem_ptr1);
	test_stack_ptr->Push(elem_ptr2);
	test_stack_ptr->Div();
	StackElement* res = test_stack_ptr->Pop();
	printf("res =%f \n",res->value);
	
	return 0;
}
