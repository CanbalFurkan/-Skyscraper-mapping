#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include "Header.h"

using namespace std;
struct map{ 

int y;
string control;
map::map() {
	
	control="T";
	y=0;
	
	}


}; //mapping structure to construct map


struct xholder{

int xcoor;
int label;
xholder(int x,int y);



};

xholder::xholder(int x,int y){

	xcoor=x;
	label=y;

}


void insertionSort(vector<xholder*>& arr, int n) //insertion sort
{ 
   int i, key, j,id;
   for (i = 1; i < n; i++) 
   { 
	   key = arr[i]->xcoor; 
	   id =arr[i]->label;

       j = i-1; 
  
       /* Move elements of arr[0..i-1], that are 
          greater than key, to one position ahead 
          of their current position */
	   while (j >= 0 && arr[j]->xcoor > key) 
       { 
		   xholder* tmp=arr[j+1];
           arr[j+1] = arr[j]; 
		   arr[j]=tmp;
           j = j-1; 
       } 
   //   arr[j+1]->xcoor = key; 
	 //  arr[j+1]->label=id;
   } 
} 


int main() {


	ifstream inFile;

	inFile.open("docdb.txt");



	int leftx;
	int rightx;
	int height;
	int apartmentnumber;
	vector<xholder*> holder;
	
	
	int counter=0;
	inFile>>apartmentnumber;
	BinaryHeap a(apartmentnumber);
	while(!inFile.eof()){         //push all the x values and keys to the a vector +insert all the heights to the heap with a key value

		
		inFile>>leftx>>height>>rightx;

		a.insert(height,counter);
		holder.push_back(new xholder(leftx,counter));
		holder.push_back(new xholder(rightx,counter));
	

			counter++;
	}
	
	insertionSort(holder,holder.size()); //sort
	int limit=holder[holder.size()-1]->xcoor;
	vector<map*> mapping(limit);
	for(int num=0;num<limit;num++) { mapping[num]=new map();} //initiliaze with 0 starting position
	
	for(int num=0;num<apartmentnumber;num++) {  //this function take key of maximum heights and push it's x values to the map with height
		int height;
	 int k1=0;
	 int k2=holder.size()-1;
		int key=a.GetMax(height); //get max
		a.remove(key);//remove max
		
		for(int x=0; key!=holder[x]->label;x++) {k1++;}
		int x1=holder[k1]->xcoor;
		for(int b=holder.size()-1; key!=holder[b]->label;b--) {
			k2--;}
		int x2=holder[k2]->xcoor;


		for(; x1<x2;x1++){
			if(mapping[x1]->control=="T") {
			
				mapping[x1]->control="F";
				mapping[x1]->y=height;
			
			
			}	} 



	


	}

	int checkery=mapping[0]->y;
	int checkerx=0;
	
	for(int x=0;x<mapping.size();x++) { //mapping the skyline coordinates

		if(checkery!=mapping[x]->y) {
		
		cout<<checkerx<<" "<<checkery<<endl;
		checkery=mapping[x]->y;
			checkerx=x;
		}

	}

	cout<<checkerx<<" "<<checkery<<endl;
	cout<<0<<" "<<mapping.size()<<endl;

	system("pause");
return 0;
}