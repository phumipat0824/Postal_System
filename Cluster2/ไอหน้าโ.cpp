#include<iostream>
using namespace std;

class QueueArray{

		private:
		
			int max;
			int *arr_queue;
			int count;
			int font;
			int rear;
			
		public:
			QueueArray(int size)
			{
				arr_queue=new int[size];
				max = size;
				font=0;
				count=0;
				rear=0;
			}
			
			void enqueue(int value)
			{	
			
				if(isFull()==true)
				{
				cout<<"Full data"<<endl;
				}
				else
					{
					cout<<"Added"<<endl;
					arr_queue[rear] =value;
 	  				rear=rear+1;
		   			count++; 
					}
			}
			
			int dequeue()
			{
				if(isEmpty()==true)
				{
				cout<<"Empty data"<<endl;
				}

					else
					{
					cout<<"Deleted"<<endl;
					arr_queue[font] = NULL;
 	  				font=font+1;
 	  				count--;
					}
			
			}
			
			void show()

			{		for(int i=font;i<rear;i++){
					cout<<arr_queue[i];
			}	
			cout<<endl;
			}	
			
			bool isFull()
			{
				if(count == max)
				{
				return true;}
				
				else{
					return false;
				}
			}
			
			bool isEmpty()
			{
				if(count == 0)
			{
				return true;}
				
				else{
					return false;
				}
			}
};


int main()
{
	int value;
	QueueArray qu(5);
	for(int i=1;i<=6;i++)
	{
	cout<<"::";
	cin>>value;
	qu.enqueue(value);
	}
	qu.show();
	
	qu.dequeue();
	qu.show();
	qu.dequeue();
	qu.show();
	qu.dequeue();
	qu.show();
	qu.dequeue();
	qu.show();
	qu.dequeue();
	qu.show();
	qu.dequeue();
	qu.show();
	
	
}
