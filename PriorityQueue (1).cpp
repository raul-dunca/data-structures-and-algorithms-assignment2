
#include "PriorityQueue.h"
#include <exception>
using namespace std;


PriorityQueue::PriorityQueue(Relation r) {
	
	this->relation = r;
	this->head = NULL;
	this->tail = NULL;
	this->current = 0;
}
//O(1)

void PriorityQueue::push(TElem e, TPriority p) {
	//TODO - Implementation
	DLL* d = new DLL[1];
	int k = 0;
	d->info.first = e;
	d->info.second = p;
	if (this->head==NULL)
	{
		
		this->head = d;
		this->tail = d;
		this->head->next = NULL;
		this->head->previous = NULL;
	}
	else
	{
		if (this->relation(d->info.second, this->head->info.second) == false)//add to begining
		{	
			d->next = this->head;
			this->head->previous = d;
			this->head = d;
			this->head->previous = NULL;
		}
		else if (this->relation(d->info.second, this->tail->info.second) == true)//add to end
		{
			this->tail->next = d;
			d->previous = this->tail;
			this->tail = d;
			this->tail->next = NULL;
		}
		else
		{
			this->current = this->head;
			while (this->relation(d->info.second, this->current->info.second) == true)
			{
				this->current = this->current->next;

			}
			d->next = this->current;
			this->current->previous->next = d;
			d->previous = this->current->previous;
			this->current->previous = d;
			
		}

	
	}
}
//O(n) n-nr de noduri


//void PriorityQueue::test()
//{
//	this->current = this->head;
//	while (1)
//	{
//		this->current = this->current->next;
//
//	}
//}

//throws exception if the queue is empty
Element PriorityQueue::top() const {
	
	if (this->head == NULL)
		throw exception();
	return this->tail->info;
	
}
//Theta(1)
Element PriorityQueue::pop() {

	if (this->head == NULL)
		throw exception();
	if (this->head == this->tail)
	{
		this->current = this->tail;
		this->head = NULL;
		this->tail = NULL;
		
	}
	else
	{
		this->current = this->tail;
		this->tail = this->current->previous;
		this->tail->next = NULL;
		this->current->previous = NULL;
	}
	Element el;
	el = this->current->info;
	delete this->current;
	return el;
}
//Theta(1)

bool PriorityQueue::isEmpty() const {
	
	if (this->head == NULL)
		return true;
	return false;
}
//Theta(1)

PriorityQueue::~PriorityQueue() {

	this->current = this->head;
	if (this->head != NULL)
	{
		while (this->current->next != NULL)
		{
			this->current = this->current->next;
			delete this->current->previous;

		}
		delete this->current;
	}
	
};
//O(n)

bool PriorityQueue::search(TElem e) const
{
	DLL* p;
	p = this->head;
	while (p != NULL)
	{
		if (p->info.first == e)
			return true;
		p = p->next;
	}
	return false;

	//while()
}


Iterator::Iterator(PriorityQueue& pq) :pqueue{ pq }
{
	this->pointer = pq.head;

}
void Iterator::next()
{
	if (this->pointer == NULL)
		throw exception();
	this->pointer = this->pointer->next;
}
void Iterator::previous()
{
	if (this->pointer == NULL)
		throw exception();
	this->pointer = this->pointer->previous;
}
void Iterator::first()
{
	this->pointer = this->pqueue.head;
}
void Iterator::last()
{
	this->pointer = this->pqueue.tail;
}
bool Iterator::valid()
{
	if (this->pointer != NULL)
		return true;
	return false;

}
Element Iterator::getCurrent()
{
	return this->pointer->info;
}