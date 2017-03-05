
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <iomanip>
#include <string.h>
using namespace std;
struct node
{
	int info;
	node *next;
	node():info(0), next(NULL)
	{}
};
struct all
{
	int name[10];
	int total[10];
	all()
	{
	for(int i=0; i<10; i++)
	{
		name[i]=0;
		total[i]=0;
	}
	}
};
class linked_list
{
private:
	node *head;
public:
	linked_list():head(NULL)
	{}
	node* start()
	{
		return head;
	}
	linked_list (const linked_list &list):head(NULL)
	{
		node *cur=list.head;
		node *temp=NULL;
		while(cur!=NULL)
		{
			node *n=new node;
			n->info=cur->info;
			if (!head)
			{
				head = n;
				temp = head;
			}
			else
			{
				temp->next = n;
				temp = n;
			}
			cur=cur->next;
		}
	}
	void destroyList()
	{
		while(!isEmpty())
		{
			delete_beg();
		}
		//cout<<"\tThe list has been DESTROYED\n";
	}
	bool isEmpty()
	{
		if (head==NULL)
			return 1;
		else
			return 0;
	}
	void insert_beg (int val)
	{
		node *new_node;
		new_node=new node;
		new_node->info=val;
		new_node->next=head;
		head=new_node;
		//cout<<"\tInserted at Front: "<<val<<endl;
	}
	void delete_beg ()
	{
		node *d=head;
		if(isEmpty())
			return;
		head=head->next;
		delete d;
		d=NULL;
		//cout<<"\tDeleted From Front\n";
	}
	void insert_end(int val)
	{
		if (isEmpty())
		{
			insert_beg(val);
			return;
		}
		node *new_node;
		new_node= new node;
		new_node->info=val;
		node *cur;
		cur=head;
		while(cur!=NULL)
		{
			if(cur->next==NULL)
			{
				cur->next=new_node;
				break;
			}
			cur=cur->next;
		}
		//cout<<"Inserted at end: "<<val<<endl;
	}
	void delete_end()
	{
		if(isEmpty())
			return;
		if (head->next==NULL)
		{
			delete head;
			head=NULL;
			return;
		}
		node *cur=head;
		while(cur->next->next!=NULL)
		{
			cur=cur->next;
		}
		delete cur->next;
		cur->next=NULL;
	}
	void insert_order (int val)
	{
		if(isEmpty())
		{
			insert_beg(val);
			return;
		}
		node *new_node;
		new_node= new node;
		new_node->info=val;
		node *prev, *cur;
		prev=NULL;
		cur=head;
		if(val<head->info)
		{
			new_node->next=head;
			head=new_node;
			//cout<<"\tNumber Inserted: "<<val<<endl;
			return;
		}
		while(cur!=NULL && val>cur->info)
		{
			prev=cur;
			cur=cur->next;
		}
		new_node->next=cur;
		prev->next=new_node;
	}
	void delete_order(int val)
	{
		node *cur;
		cur=head;
		if(head->info==val)
		{
			head=head->next;
			delete cur;
			cur=NULL;
			return;
		}
		while(cur->next!=NULL)
		{
			if(cur->next->info==val)
			{
				node *d;
				d=cur->next;
				cur->next=cur->next->next;
				//cout<<"\tNumber Deleted: "<<val<<endl;
				delete d;
				return;
			}
			cur=cur->next;
		}
		//cout<<" Number not found in the LIST\n";
	}
	void display()
	{
		if(isEmpty())
		{
			cout<<"\tThe List is Empty\n";
			return;
		}
		node *cur=head;
		cout<<"\n Linked List :\t";
		while(cur!=NULL)
		{
			cout<<" "<<cur->info<<" , ";
			cur=cur->next;
		}
	}
	int count()
	{
		int count=0;
		node *cur;
		cur=head;
		while(cur!=NULL)
		{
			cur=cur->next;
			count++;
		}
		return count;
	}
	void reverse_list()
	{
		node *cur=head;
		node *prev=head;
		node *temp=NULL;
		while (cur!=NULL)
		{
			temp=cur->next;
			cur->next=prev;
			prev=cur;
			cur=temp;
		}
		head->next=NULL;
		head=prev;
	}
	~linked_list ()
	{
		while(!isEmpty())
		{
			delete_beg();
		}
	}
	void sort()
	{
		node *cur= head;
		int temp;
		int counter=count();
		for (int i=0; i<counter; i++)
		{
			cur = head;
			while (cur->next!=NULL)
			{
				if (cur->info > cur->next->info)
				{
					temp=cur->info;
					cur->info=cur->next->info;
					cur->next->info=temp;
					cur=cur->next;
				}
				else
					cur = cur->next;
			}
		}
	}
};
class Stack
{
private:
	node *top;
public:
	Stack():top(NULL){}
	Stack (const Stack &s)
	{
		node *cur;
		node *cur1;;
		cur=s.top;;
		top=new node;
		cur1=top;
		while(cur!=NULL)
		{
			cur1->info=cur->info;
			cur1->next=new node;
			cur1=cur1->next;
			cur=cur->next;
		}
	}
	void push(int value)
	{
		node *new_node;
		new_node= new node;
		new_node->info=value;
		new_node->next=top;
		top=new_node;
	}
	bool Empty() const
	{
		if(top==NULL)
			return 1;
		return 0;
	}
	int get_top()
	{
		if(Empty())
		{
			cout<<"\n\tStack is Empty";
			return 0;
		}
		cout<<"\nTop:\t"<<top->info;
		return top->info;
	}
	int pop()
	{
		if(Empty())
		{
			cout<<"\n\tStack is Empty";
			return 0;
		}
		else if(top->next==NULL)
		{
			int x;
			x=top->info;
			delete top;
			top=NULL;
			return x;
		}
		else
		{
			node *temp;
			temp=top;
			int x;
			x=temp->info;
			top=temp->next;
			delete temp;
			temp=NULL;
			cout<<"\nRemoved:\t"<<x;
			return x;
		}
	}
};
class country
{
public:
	string name;
	int budget;
	string hotel;
	country()
	{
		name="Pakistan";
		hotel="Any";
		budget=4500;
	}
	country(string cname, int b,  string hot)
	{
		name=cname;
		budget=b;
		hotel=hot;
	}
};
class Recommender
{
	private:
		country  hot[10];
		country cold[10];
		country mountains[10];
		country coastal[10];
		country metropolitan[10];
		country desert[10];
	public:
		Recommender()
		{
			hot[0]=country("Malyasia",5000,"prince hotel kuala lampur");
			hot[1]=country("Brazil",7000,"costa do sol botique hotel");
			hot[2]=country("Mexico",4000,"Rosewood MayaKoba playa del caMON mexico");
			hot[3]=country("Indonesia",2500,"the samaya balis emiyak indonesia");
			hot[4]=country("Singapore",4500,"shangrila hotel");
			hot[5]=country("Colombia",2000,"charleis palace ");
			hot[6]=country("Cuba",3500,"paradisus rio de oro resort and spa");
			hot[7]=country("Thailand",2900,"rabbit resort pataya thailand");
			hot[8]=country("Phillipines",2700,"aman pulo palawan mimaropa");
			hot[9]=country("Madagascar",1700,"hotel andilana beach");
			cold[0]=country("Sweden",9000,"renaisance malmo hotel");
			cold[1]=country("Austria",11000,"palais henson campensici vieana");
			cold[2]=country("Norway",8500,"dalen hotel");
			cold[3]=country("Canada",12000,"L'hermitage hotel vencuwar");
			cold[4]=country("Denmark",9100,"crown plazae copen hegen towers");
			cold[5]=country("France",12500,"cour do corbeau hotel");
			cold[6]=country("Germany",8000,"park hayat hamberg");
			cold[7]=country("United Kingdom",9500,"reding park hotel");
			cold[8]=country("Brazil",7000,"costa do sol botique hotel");
			cold[9]=country("Hungary",4600,"four seasons hotel grashham palace budapest");
			mountains[0]=country("Austria",11000,"palais henson campensici vieana");
			mountains[1]=country("Canada",12000,"L'hermitage hotel vencuwar");
			mountains[2]=country("United States of America",14000,"rty");
			mountains[3]=country("China",7200,"the upper houser hongkong");
			mountains[4]=country("Pakistan",3300,"pearl continental islamabad");
			mountains[5]=country("New Zealand",5800,"milbrook resort aero town");
			mountains[6]=country("Austrailia",9300,"pepers broad beach in broad beach");
			mountains[7]=country("Mexico",4000,"Rosewood MayaKoba playa del caMON mexico");
			mountains[8]=country("Nepal",4900,"khatmando hotel");
			mountains[9]=country("Brazil",7000,"costa do sol botique hotel");
			coastal[0]=country("Brazil",7000,"costa do sol botique hotel");
			coastal[1]=country("Mexico",4000,"Rosewood MayaKoba playa del caMON mexico");
			coastal[2]=country("Indonesia",2500,"the samaya balis emiyak indonesia");
			coastal[3]=country("United States Of America",14000,"ritz hotel ");
			coastal[4]=country("Russia",11100,"swissutil crasnye holeme moscow");
			coastal[5]=country("Greenland",3210,"sisimuit hotels");
			coastal[6]=country("Australia",9300,"pepers broad beach in broad beach");
			coastal[7]=country("United Kingdom",9500,"reding park hotel");
			coastal[8]=country("Nepal",4900,"khatmando hotel");
			coastal[9]=country("India",3420,"the oberoi udayvillas");
			metropolitan[0]=country("United arab emirates",14500,"burj ul arab");
			metropolitan[1]=country("United States of America",14000,"ritz hotel");
			metropolitan[2]=country("France",12500,"cour do corbeau hotel");
			metropolitan[3]=country("China",7200,"the upper houser hongkong");
			metropolitan[4]=country("United Kingdom",9500,"reding park hotel");
			metropolitan[5]=country("Italy",7910,"hotel belvidere");
			metropolitan[6]=country("Germany",8830,"park hayat hamberg");
			metropolitan[7]=country("Brazil",7000,"costa do sol botique hotel");
			metropolitan[8]=country("Turkey",6750,"four season hotel istanbul at sultana meth");
			metropolitan[9]=country("Malaysia",7940,"prince hotel kuala lampur");
			desert[0]=country("Egypt",5620,"the oberoi sahl hasheesh");
			desert[1]=country("United Arab Emirates",14500,"burj ul arab");
			desert[2]=country("Saudi Arabia",6390,"inter continental da al tawhid mecca");
			desert[3]=country("Morocco",3970,"palace namskaar");
			desert[4]=country("Sudan",4120,"al salaam rutana");
			desert[5]=country("Algeria",4680,"hilton algerie");
			desert[6]=country("Libya",5460,"al manara");
			desert[7]=country("Niger",2950,"niamey hotel");
			desert[8]=country("Tunisia",2720,"hasrubal dhalasa and spa dejarba");
			desert[9]=country("Oman",3220,"the chedi muscat");
		}
		Stack callstack1(country c1[10])
		{
			Stack s1;
			for(int i=9; i>=0; i--)
		  {
			  s1.push(c1[i].budget);
			  s1.get_top();
		  }
			return s1;
		}
		void choose(country &c1, country &c2, country &c3)
		{
		    int k;
		    cout<<"   The Country is selected"<<endl;
		    cout<<" entr 1 for country 1 ,  2 for country 2 , 3 for country 3        "<<endl;
		    cin>>k;
		    cout<<endl;
		    cout<<endl;
		    switch(k)
		    {
                case 1:
                {cout<<"   The Choose Country is ";
                    cout<<c1.name<<"  Budget is"<<c1.budget<<endl;
                    cout<<c1.hotel<<endl;
                    break;
                }
                case 3:
                {cout<<"   The Choose Country is ";
                    cout<<c3.name<<"  Budget is"<<c3.budget<<endl;
                    cout<<" Hotel is  "<<c3.hotel<<endl;
                    break;
                }
                case 2:
                {cout<<"   The Choose Country is ";
                    cout<<c2.name<<"  Budget is"<<c2.budget<<endl;
                    cout<<"   Hotel is"<<c2.hotel<<endl;
                    break;
                }
                default:
                cout<<" Invalid Input"<<endl;
		    }
		}
		void choice()
		{
			int  c;
			Stack s1,s2,s3,s4,s5,s6;
			int push=0;
			while(push<=2)
				{
					cout<<"  Enter your choice "<<endl;
					cin>>c;
					if(c==1 || c==2)
                        {
					if(c==1)
                        {
						cout<<" U choose Hot region"<<endl;
						s1=callstack1(hot);
						push++;
						cout<<"   PLz enter the 3  or 4 next consecutive region "<<endl;
                        }
                    else
                        {
					cout<<" U choose cold region"<<endl;
					cout<<"   PLz enter the 3  or 4 next consecutive region "<<endl;
					s1=callstack1(cold);
					push++;
                        }
                        }
			else if(c==3 || c==4)
			{
				if(c==3)
				{
					cout<<" U choose mountains region"<<endl;

					s2=callstack1(mountains);
					push++;
					cout<<"   PLz enter the 5  or 6 next consecutive region "<<endl;
				}
				else
				{
					cout<<" U choose coastal region"<<endl;

					s2=callstack1(coastal);
					push++;
					cout<<"   PLz enter the 5  or 6 next consecutive region "<<endl;
				}
			}
			else if(c==5 || c==6)
			{
				if(c==5)
				{

					cout<<" U choose metropolitan region"<<endl;
					s3=callstack1(metropolitan);
					push++;
				}
				else
				{
					cout<<" U choose desert region"<<endl;
					s3=callstack1(desert);
					push++;
				}
			}
			else
			{
				cout<<" Invalid choice "<<endl;
			}
		}
			int x,y,z;
			int i=0;
			bool hot1=true;
			bool mount=true;
			bool city=true;
			while(s1.Empty()!=true)
					{
						x=s1.get_top();
						if(x==(hot[i].budget))
							{
							    cout<<endl;
							    cout<<" Region is of hot"<<endl;
							    cout<<endl;
							}
						else
						{
							cout<<endl;
							cout<<" Region is cold"<<endl;
							hot1=false;
							cout<<endl;
						}
						y=s2.get_top();
						if(y==(mountains[i].budget))
						{
                            cout<<endl;
                            cout<<" The region is mountainopus"<<endl;
                            cout<<endl;
						}
						else
						{
							cout<<endl;
							cout<<" the region is costal"<<endl;
							mount=false;
							cout<<endl;
						}
						z=s3.get_top();
						if(z==(metropolitan[i].budget))
						{
						    cout<<endl;
						    cout<<"  the region is metropolian "<<endl;
						}
						else
						{
							cout<<endl;
							cout<<" The region is desert"<<endl;
							city=false;
							cout<<endl;
						}
					s1.pop();
					s2.pop();
					s3.pop();
                            if(hot1==true)
                            {   cout<<endl;
                                cout<<" Budget  is   $"<<hot[i].budget<<endl<<"   Hotel is "<<hot[i].hotel<<endl<<"   Country name is   "<<hot[i].name<<endl;
                            cout<<endl;
                            cout<<" Budget is   $"<<metropolitan[i].budget<<endl<<"   Hotel is "<<metropolitan[i].hotel<<endl<<"   Country name is   "<<metropolitan[i].name<<endl;
                            cout<<endl;
                            cout<<" Budget is  $"<<mountains[i].budget<<endl<<"   Hotel is "<<mountains[i].hotel<<endl<<"   Country name is   "<<mountains[i].name<<endl;}
                            else
                            {
                                cout<<endl;
                                cout<<"Budget is   $"<<cold[i].budget<<endl<<" Hotel is     "<<cold[i].hotel<<endl<<"        Country name is   "<<cold[i].name<<endl;
                                cout<<endl;
                                cout<<"Budget  is $"<<desert[i].budget<<endl<<" Hotel is "<<desert[i].hotel<<endl<<"          Country name is   "<<endl<<desert[i].name<<endl;
                                cout<<endl;
                                cout<<"Budget is  $"<<coastal[i].budget<<endl<<"  Hotel is "<<coastal[i].hotel<<endl<<endl<<"         Country name is   "<<coastal[i].name<<endl;
                            }
                        char chk='y';
                        cout<<"  Want to go there  enter (y) for yes"<<endl;
                        cin>>chk;
                        if(chk=='y')
                        {
                            if(hot1==true)
                            choose(hot[i],metropolitan[i],mountains[i]);
                            else
                            choose(cold[i],desert[i],coastal[i]);
                            break;
                        }
                        i++;
					}
		}
};
int main()
{
	Recommender  r1;  //  creating the object of the class
	cout<<"\nX=================X   Welcome, We are your Trip Advisors!   X=================X"<<endl;
	cout<<"\n\n\t\t      To chose your dream vacation spot,\n\t       we will first have to ask you a few questions."<<endl;
	cout<<"\n\nX=================X \t   What are you looking for:         X=================X\n\n\t\t\t1.Hot Climatic Zones,\n\t\t\t2.Cold Climatic Zones,\n\t\t\t3.Mountainous Areas,\n\t\t\t4.Coastal Areas,\n\t\t\t5.Metropolitan Zones,\n\t\t\t6.Deserts.\n\nPlease choose three options out of the six provided according to their number.\n"<<endl;
	r1.choice();
	return 0;
}
