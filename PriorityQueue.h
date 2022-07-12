#pragma once
#include <vector>
#include <utility>

using namespace std;

//DO NOT CHANGE THIS PART
typedef int TElem;
typedef int TPriority;
typedef std::pair<TElem, TPriority> Element;
typedef bool (*Relation)(TPriority p1, TPriority p2);
#define NULL_TELEM pair<TElem, TPriority> (-11111,-11111);

typedef struct DLL
{
	Element info;
	DLL* next;
	DLL* previous;
};

class PriorityQueue {
	friend class Iterator;
private:
	DLL* head;
	DLL* tail;
	Relation relation;
	DLL* current;
	//Element* lista;

public:
	//implicit constructor
	PriorityQueue(Relation r);

	//pushes an element with priority to the queue
	void push(TElem e, TPriority p);

	//returns the element with the highest priority with respect to the order relation
	//throws exception if the queue is empty
	Element top()  const;

	//removes and returns the element with the highest priority
	//throws exception if the queue is empty
	Element pop();

	//checks if the queue is empty
	bool isEmpty() const;

	//checks if elem in PQ or not
	bool search(TElem elem) const;


	//destructor
	~PriorityQueue();





	void test();

};
class Iterator {
	friend class PriorityQueue;
private:
	const PriorityQueue& pqueue;
	DLL* pointer;

public:
	Iterator(PriorityQueue& pq);
	//MatrixIterator(Matrix m, int line);
///MatrixIterator iterator(int line)const;
	void next();
	void first();
	Element getCurrent();
	void previous();
	bool valid();
	void last();

};