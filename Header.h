#include<iostream>
#include<vector>
#include<string>
#include <stdexcept>
#include<stack>

using namespace std;

struct info {

public:

	int height;
	int idnumber;
	info(int height,int id);

};

info::info(int height,int id) {

	this->height=height;
	this->idnumber=id;
}


class BinaryHeap{
public:
	BinaryHeap(int creater);

	bool isEmpty( ) const;
	int GetMax(int &boy);
	void insert( const int  y,const int id );
	void remove( int & id );
	void makeEmpty( );
	int            currentSize; // Number of elements in heap
	vector<info*> array;       // The heap array
	void percolateDown( int hole );
};



BinaryHeap::BinaryHeap(int creater) {
	
	for(int a=0;a<creater+1;a++) {array.push_back(new info(-1,-1));}
	currentSize=0;

}


void BinaryHeap::insert(const int y,const int id)
{


	// Percolate up
	// Note that instead of swapping we move the hole up
	int hole = ++currentSize;
	for( ; hole > 1 && y > array[ hole / 2 ]->height; hole /= 2 )
	{ array[ hole ] = array[ hole / 2 ];}



	info* tmp=new info(y,id);
	array[hole]=tmp;

}










void BinaryHeap::percolateDown( int hole )
{
	int child;
	info* tmp = array[ hole ]; // tmp is the item that will 
	// be percolated down

	for( ; hole * 2 <= currentSize; hole = child )
	{   
		child = hole * 2;
		if( child != currentSize && array[ child ]->height < array[ child + 1 ]->height )
			child++;
		if( array[ child ]->height > tmp->height)
			array[ hole ] = array[ child ];
		else
			break;
	}
	array[ hole ] = tmp;
}



bool  BinaryHeap:: isEmpty() const { //checking if the heap is empty


	if(currentSize==0){
		return true;}

	else {
		return false;}




}

int BinaryHeap::GetMax(int &boy  ) //function that takes the maximum value and return it's id number
{
	if( isEmpty( ) )
		throw UNDERFLOW;

	
	
	boy=array[1]->height;
	return array[1]->idnumber;
}

void BinaryHeap::remove(int & key) { //remove spesific function

	for(int x=1;x<currentSize;x++) {
	
		if(key==array[x]->idnumber) {
			
			array[x]=array[currentSize];
			percolateDown(x);
			currentSize--;	
			array.pop_back();
			break;}}





}