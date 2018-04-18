#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdarg.h>



class StackElement{
	public:
	double value;
	StackElement* next;

	StackElement(const double v);
	~StackElement();
	int IsValidElement();

};

StackElement :: ~StackElement(){}
StackElement :: StackElement(const double v){
		value = v;
 		next = NULL;
}

int StackElement :: IsValidElement(){
	
	return (this != NULL);
}

class Stack{
	StackElement* top;
	
	public:
		Stack();
		Stack(const Stack* s);
		Stack(double* array,int size);
		Stack(int n_args, ...);
		~Stack();
		int Push(double element);
		double Pop();
		int Add();
		int Sub();
		int Mul();
		int Div();
		int PushFromBottom(const double v);
		
		
	private:
		int IsValidStack();
};


Stack :: Stack(double* array,int size){
	for(int i = 0;i<size;i++){
		this->Push(array[i]);
	}
}

int Stack :: PushFromBottom(const double v){
	if(!(this->IsValidStack())){
		printf("Stack :: PushFromBottom FAILED\n");
		return 0;
	}
	if(this->top){
		StackElement* cur = top;
		while(cur->next != NULL){
			cur = cur->next;
		}
		StackElement* element = new StackElement(v);
		element->value = v;
		cur->next = element;
		return 1;
	}
	else{
		this->Push(v);
		return 1;
	}
	
	
}

Stack :: Stack(){
	top = NULL;
}

Stack :: ~Stack(){
	if(top){
		
		StackElement* cur = top->next;
			StackElement** del = &cur;
			
			for(;cur != NULL;){
				delete *del;
				del = &cur;
				cur=cur->next;
				if(cur->next != NULL)	
					cur = cur->next;
				else
					break;
			}
		delete top;
	}
}
Stack :: Stack(int n_args,...){
	va_list args;
    int i;

    va_start(args, n_args);
    for(i = 0; i < n_args; i++)
        this->Push(va_arg(args, double));
    va_end(args);

	
}

Stack :: Stack(const Stack* s){
	this->top = NULL;
	StackElement* cur = s->top;
	for (;cur != NULL; cur = cur->next){
		this->PushFromBottom(cur->value);
	}
}

int Stack :: IsValidStack(){
	assert(this != NULL);
	return 1;
}

double Stack :: Pop(){
	assert(this->top);
	
	double res = top->value;
	StackElement* elem_to_delete = top;
	top = top->next;
	delete elem_to_delete;
	return res;
}

int Stack :: Add(){
	this->IsValidStack();	
	
	double first = this->Pop();
	double second = this->Pop();
	
	this->Push(first + second);
	return 1;
	
	
	
}	
int Stack :: Sub(){
	this->IsValidStack();	
	
	double first = this->Pop();
	double second = this->Pop();
	
	this->Push(-first + second);
	return 1;
	
	
	
}

int Stack :: Mul(){
	this->IsValidStack();	
	
	double first = this->Pop();
	double second = this->Pop();
	
	this->Push(first * second);
	return 1;
	
	
	
}

int Stack :: Div(){
	if(top->next == NULL){
		printf("ERR div Failed nothing to divide on");
		return 0;
	}
		
	
	this->IsValidStack();	
	
	double first = this->Pop();
	double second = this->Pop();
	
	this->Push(first / second);
	return 1;
	
	
	
}

int Stack :: Push (double value) {
	StackElement* element = new StackElement(value);
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

	test_stack_ptr->Push(2);
	test_stack_ptr->Push(4);
	test_stack_ptr->PushFromBottom(3);
	test_stack_ptr->PushFromBottom(10);
	test_stack_ptr->Div();
	test_stack_ptr->Div();
	test_stack_ptr->Div();

	Stack* test_stack_ptr2 = new Stack(test_stack_ptr);
	Stack* test_stack_ptr3 = new Stack(3,1.0,2.0,3.0);
	
	double res = test_stack_ptr3->Pop();
	printf("res = %f\n",res);
	delete test_stack_ptr;
	delete test_stack_ptr2;
	return 0;
}
