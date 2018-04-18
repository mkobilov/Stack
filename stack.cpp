#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>



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
		printf("%f\n",value);
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
		template<typename... Args>
		Stack( Args ... args);
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
	printf("v == %f\n",v);
	if(this->top){
		StackElement* cur = top;
		while(cur->next != NULL){
			cur = cur->next;
		}
		StackElement* element = new StackElement(v);
		element->value = v;
		cur->next = element;
		printf("top->value if = %f\n",top->value);
		return 1;
	}
	else{
		this->Push(v);
		printf("top->value else = %f\n",top->value);
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
				printf("cur->value del\n");
				delete *del;
				del = &cur;
				cur=cur->next;
				printf("cur->value del2\n");
				if(cur->next != NULL)	
					cur = cur->next;
				else
					break;
				printf("cur->value del2.5\n");
			}
			printf("cur->value del3\n");
		delete top;
	}
}
template<typename... Args>
Stack :: Stack( Args ... args){
	this->Push(ExtractValue(args...));
	
}

Stack :: Stack(const Stack* s){
	this->top = NULL;
	StackElement* cur = s->top;
	printf("lmao1\n");
	for (;cur != NULL; cur = cur->next){
		printf("lmao2 %f\n",cur->value);
		this->PushFromBottom(cur->value);
		printf("lmao3\n");
	}
	printf("lmao4\n");
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
	Stack* test_stack_ptr3 = new Stack(1.0,2.0,3.0);

	double res = test_stack_ptr2->Pop();
	printf("res =%f \n",res);
	delete test_stack_ptr;
	printf("mmmmm\n");
	delete test_stack_ptr2;
	return 0;
}
