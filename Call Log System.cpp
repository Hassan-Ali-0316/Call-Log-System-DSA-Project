#include<bits/stdc++.h>
#include<windows.h>  // for setting consol position
#include<stdlib.h>
#include<conio.h>
#include<fstream>
#include<sstream>  // for reading from file
#include<list>
#include<stack>
using namespace std;

void gotoxy(int x, int y) //cursor setting
{
     COORD coord;
     coord.X = x;
     coord.Y = y;
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void mainp()
{
	system("cls");
	time_t now = time(0);
    tm *ltm = localtime(&now);   //reading current time
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	gotoxy(28,3);
	SetConsoleTextAttribute(hConsole, 480);   
	cout<<"FAST SCHOOL OF COMPUTER SCIENCE";
	SetConsoleTextAttribute(hConsole, 47);     //Green & White Color Code=47
	gotoxy(24,4);
	cout<<"      P H O N E   L O G   S Y S T E M     "; 
	gotoxy(33,6);
	SetConsoleTextAttribute(hConsole, 27);             //Blue Color Code=27
	cout<<"  Semester Project  ";
	SetConsoleTextAttribute(hConsole, 47); 
	gotoxy(48,9);
	cout<<" Today's Date : \n";
	SetConsoleTextAttribute(hConsole, 15);
	gotoxy(55,11);
	cout << ltm->tm_mday <<" / "<<1 + ltm->tm_mon <<" / "<<1900 + ltm->tm_year<<endl;     //printing current date and time
	SetConsoleTextAttribute(hConsole, 8); 
	for (int i=8; i<14; i++) 
	{
	    gotoxy(43,i);
	    cout<<'\xB3';
	}
	SetConsoleTextAttribute(hConsole, 15); 
	gotoxy(2,8);
	cout<<"Group Members : \n";
	SetConsoleTextAttribute(hConsole, 15);
	gotoxy(4,10);
	cout<<"Hassan Ali (22K-4637)\n";
	gotoxy(4,11);
	cout<<"Abdul Sami (22k-4354)\n";
	gotoxy(4,12);
	cout<<"Hussain (22K-4244)\n";
	gotoxy(8,17);
	cout<<"Press Any Key To Continue....... ";
	getch();
	system("cls"); 
}

int Menu()
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	gotoxy(20,4);
	SetConsoleTextAttribute(hConsole, 15);
	cout<<"Enter Your Choice : \n";
	gotoxy(20,6);
	cout<<"1) Add a contact \n";
	gotoxy(20,7);
	cout<<"2) Update a contact \n";
	gotoxy(20,8);
	cout<<"3) Delete a contact \n";
	gotoxy(20,9);
	cout<<"4) Search a contact \n";
	gotoxy(20,10);
	cout<<"5) Display All contacts according to first added \n";
	gotoxy(20,11);
	cout<<"6) See All Call Logs (Latest to Earliest) \n";
	gotoxy(20,12);
	cout<<"7) See All Call Logs (Earliest to Latest) \n";
	gotoxy(20,13);
	cout<<"8) Enter a call Log \n";
	gotoxy(20,14);
	cout<<"9) Display all Contacts in Ascending Order \n";
	gotoxy(20,15);
	cout<<"10) Display all Contacts in Descending Order \n";
	gotoxy(20,16);
	cout<<"11) Display all Call Logs in Ascending Order \n";
	SetConsoleTextAttribute(hConsole, 8);             //Gray Color Code=8
	gotoxy(43,18);
	cout<<'\xDA'<<'\xC4';
	for (int i=0; i<29; i++)   		//printing design boxes
	{
		cout<<'\xC4';
		cout<<'\xBF';
		gotoxy(43,19);
		cout<<'\xB3';
		gotoxy(43,19);
		cout<<'\xC0'<<'\xC4';
	}
	for (int i=0; i<29; i++)
	{
		cout<<'\xC4';
		cout<<'\xD9';
	}
	SetConsoleTextAttribute(hConsole, 15);             //White Color Code=12
	gotoxy(45,20);
	cout<<"Note: ";
	SetConsoleTextAttribute(hConsole, 10);             //Green Color Code=10
	cout<<"To Quit , Press '0'";
	SetConsoleTextAttribute(hConsole, 8);             //Gray Color Code=8
	gotoxy(74,20);
	cout<<'\xB3';
	SetConsoleTextAttribute(hConsole, 15);  
	gotoxy(2,21);
	cout<<"Enter your Choice ....... ";
	int n;
	cin>>n;
	return(n);
}

class ContactNode   
{
	public:
		string name;
		string email;
		string gender;
		string address;
		bool favorite;
		string number;
		ContactNode* next;
		ContactNode* tail;
		ContactNode()
		{
			next = NULL;
			tail = NULL;
			name = "-";
			gender = "-";
			email = "-";
			address = "-";
			number = "-";
			favorite = 0;
		}	
		ContactNode(string n,string g,string e,string a,string num,bool f)
		{
			name = n;
			gender = g;
			email = e;
			address = a;
			number = num;
			favorite = f;
			next = NULL;
			tail = NULL;
		}
};

class BSTNode
{
	public:
		ContactNode c;
		BSTNode* left;
		BSTNode* right;
		BSTNode()
		{
			left = NULL;
			right = NULL;
		}
		BSTNode(string n,string g,string e,string a,string num,bool fav)
		{
			c.name = n;
			c.gender = g;
			c.address = a;
			c.email =  e;
			c.number = num;
			c.favorite = fav;
			left = NULL;
			right = NULL;
		}
};

class Node               // linked list node
{
	public:
		ContactNode c;
		Node* next;
		Node()
		{
			next = NULL;
		}
		Node(string n,string g,string e,string a,string num,bool fav)
		{
			c.name = n;
			c.gender = g;
			c.address = a;
			c.email =  e;
			c.number = num;
			c.favorite = fav;
			next = NULL;
		}
};

class Log
{
	public:
		string date;
		string time;
		string number;
		Log()
		{
			date = "-";
			time = "-";
			number = "-";
		}
		Log(string d,string t,string num)
		{
			this->date = d;
			this->time = t;
			this->number = num;
		}
};


class Contacts
{
	public:
		ContactNode** chained;       // for hashing
		BSTNode* root;               // for bst (sorting)
		Node* head;
		const int capacity = 100;
		int size;
		Contacts()
		{
			chained = new ContactNode*[capacity];
			root = NULL;
			for(int i=0 ; i<capacity ; i++)
			{
				chained[i] = nullptr;
			}
			size = 0;
			root = NULL;
			head = NULL;
		}	
		~Contacts()
		{
			for(int i=0 ; i<capacity ; i++)
			{
				delete chained[i];
				chained[i] = nullptr;
			}
		}
		void start()
		{
			while(1)
			{
				int op = Menu();
				if(op == 1)
				{
					system("cls");
					this->addContact();         // simply added in last of file
				}
				else if(op == 2)
				{
					system("cls");
					this->updateContact();      // used hashing for searching and then updated
				}
				else if(op == 3)
				{
					system("cls");
					this->deleteContact();          // delete hashing
				}
				else if(op == 4)
				{
					system("cls");
					this->searchContact();            // used hashing
				}
				else if(op == 5)
				{
					system("cls");
					this->displayallContacts();
				}
				else if(op == 6)
				{
					system("cls");
					this->seeCallLogsLtoE();
				}
				else if(op == 7)
				{
					system("cls");
					this->seeCallLogsEtoL();
				}
				else if(op == 8)
				{
					system("cls");
					this->EnterCallLog();
				}
				else if(op == 9)
				{
					system("cls");
					this->displayAscending();             // used inorder traversal of binary search tree
				}
				else if(op == 10)
				{
					system("cls");
					this->displayDescending();
				}
				else if(op == 11)
				{
					system("cls");
					this->readLogs();
				}
				else
				{
					break;
				}
			}
		}
		int hashFunc(string n)
		{
			int sum = 0;
			for(int i=0 ; i<n.length() ; i++)
			{
				char ch = n[i];
				sum += static_cast<int>(ch); 
			}
			return (sum%capacity);
		}
		bool isEmpty()
		{
			if(root == NULL)
			{
				return 1;
			}
			return 0;
		}
		void display(ContactNode* temp)
		{
  
			gotoxy(25,10);
			cout << "---------------------- C O N T A C T  D E T A I L S ---------------------\n";
			gotoxy(40,12);
			cout << "Name: " << temp->name << endl;
			gotoxy(40,13);
			cout << "Gender: " << temp->gender << endl;
			gotoxy(40,14);
			cout << "Email Address: " << temp->email << endl;
			gotoxy(40,15);
			cout << "Address: " << temp->address << endl;
			gotoxy(40,16);
			cout << "Phone: " << temp->number << endl;
			gotoxy(40,17);
			cout << "Favorite : " << temp->favorite << endl;
			gotoxy(25,18);
			cout << "---------------------- C O N T A C T  D E T A I L S ---------------------\n";
			cout << "Press any key to continue...\n";
			gotoxy(40,20);
			getch();
			system("cls");
		}
		void addContact()
		{
			system("cls");
			
			string num,a,e,n;
			string g;
			bool fav;
			gotoxy(4,6);
			cout << "Enter Contact Details : ";
			gotoxy(4,7);
			cout << "---------------------";
			gotoxy(4,9);
			cout << "Enter Full Name : ";
			gotoxy(24,9);
			fflush(stdin);
			cin >> n;
			gotoxy(4,10);
			srand(time(0));
			cout << "Enter Gender : ";
			gotoxy(24,10);
			cin >> g;
			gotoxy(4,11);
			cout << "Enter Address : ";
			gotoxy(26,11);
			fflush(stdin);
			cin >> a;
			gotoxy(4,12);
			cout << "Enter Email address : ";
			gotoxy(31,12);
			fflush(stdin);
			cin >> e;
			gotoxy(4,14);
			cout << "Enter Phone Number : ";
			gotoxy(30,14);
			cin >> num;
			gotoxy(4,15);
			cout << "Set to Favorite ? (1/0) : ";
			fflush(stdin);
			gotoxy(36,15);
			cin >> fav;
			system("cls");
			gotoxy(10,10);
			
			if(!validateNumber(num))
			{
				ofstream fout;
				fout.open("Contacts.csv",ios::out|ios::app);
				if(!fout.is_open())
				{
					cout << "Error opening file :// \n";
					return;
				}
				cout << "Contact Record Added! ";
				size++;
				fout << n << "," << g << "," << e  << "," << a << "," << num << "," << fav << endl;
				fout.close();
				gotoxy(60,19);
				cout << "PRESS ANY KEY TO CONTINUE...";
				getch();
				system("cls"); 
			}
			else
			{
				cout << "Numbers incompelete or contact with this number already exists\nPress any key to continue...\n";
				getch();
				system("cls");
				return;
			}
		}	
		void updateContact()
		{
			system("cls");
			ifstream fin("Contacts.csv");
			if(!fin.is_open())
			{
				cout << "Error opening file :// \n";
				return;	
			}		
			gotoxy(10,10);
			cout << "Enter name to search: ";
			string n;
			fflush(stdin);
			cin >> n;
			int id = hashFunc(n);              // hashfunction
			string line;
			int i = 0;
			list<ContactNode*> tempcon;
			string name,num,a,e,g,fav;
			while (getline(fin, line)) 
			{
    		    stringstream ss(line);
     		  	getline(ss, name, ',');
     		  	getline(ss, g, ',');
    		 	getline(ss, e, ',');
    	 		getline(ss, a, ',');
      			getline(ss, num, ',');	
   			    getline(ss, fav, ',');
      			bool favorite = (fav == "1"); 
      			
      			int idx = hashFunc(name);
	    		ContactNode* c1 = new ContactNode(name,g,e,a,num,favorite);
      			tempcon.push_back(c1);
   	 			if(chained[idx] == NULL)
    			{ 
    				chained[idx] = c1;
					chained[idx]->next = NULL;
					chained[idx]->tail = c1;
				}
				else
				{
					chained[idx]->tail->next = c1;
					chained[idx]->tail = c1;
					chained[idx]->tail->next = NULL;
				}
    		}
    		bool flag = false;
    		ContactNode* temp = chained[id];
    		while(temp != NULL)
    		{
    			if(temp->name == n)
    			{
    				flag = true;
    				cout << "\t\t\t\t\tContact found\n";
    				break;
				}
    			temp = temp->next;
			}
			if(!flag)
			{
				cout << "\t\t\t\t\tNo such contact found... Press any key to continue\n";
				getch();
				system("cls");
				return;
			}
			gotoxy(10,12);
    		cout << "Enter 1 to update Name\n";
    		gotoxy(10,13);
    		cout << "Enter 2 to update Gender\n";
    		gotoxy(10,14);
    		cout << "Enter 3 to update Address\n";
    		gotoxy(10,15);
    		cout << "Enter 4 to update Email Address\n";
    		gotoxy(10,16);
    		cout << "Enter 5 to update Number\n";
    		gotoxy(10,17);
    		cout << "Enter 6 to update favorite\n";
    		gotoxy(10,18);
    		int ch;
    		cin >> ch;
    		gotoxy(10,21);
    		if(ch == 1)
    		{
    			cout << "Enter new Name: ";
    			fflush(stdin);
    			cin >> temp->name;
			}
			else if(ch == 2)
			{
				cout << "Enter new Gender: ";
				fflush(stdin);
				cin >> temp->gender;
			}
			else if(ch == 3)
			{
				cout << "Enter new address: ";
				fflush(stdin);
				cin >> temp->address;
			}
			else if(ch == 4)
			{
				cout << "Enter new email: ";
				fflush(stdin);
				cin >> temp->email;
			}
			else if(ch == 5)
			{
				cout << "Enter new number: ";
				fflush(stdin);
				string num;
				fflush(stdin);
				cin >> num;
				if(validateNumber(num))
				{
					system("cls");
					cout << "Number can't be updated since this number is already associated with another contact\n";
					cout << "Press any key to continue\n";
					getch();
					system("cls");
					return;
				}
				temp->number = num;
			}
			else if(ch == 6)
			{
				cout << "Enter 1 to set contact to favorite else enter 0: ";
				int ch;
				cin >> ch;
				if(ch == 1)
				{
					temp->favorite = 1;
				}
				else
				{
					temp->favorite = 0;
				}
			}
			else
			{
				cout << "Invalid choice\n";
			}
			fin.close();
			ofstream fout;
			fout.open("contacts.csv");
			for(auto &el : tempcon)
			{
				if(el->number == temp->number)
				{
					el->name = temp->name;
					el->gender = temp->gender;
					el->address = temp->address;
					el->number = temp->number;
					el->email = temp->email;
					el->favorite = temp->favorite;
				}
				fout << el->name << "," << el->gender << "," << el->email  << "," << el->address << "," << el->number << "," << el->favorite << endl;
			}	
			cout << "Contact updated.... Press any key to continue  ";
			getch();
			system("cls");
			fout.close();
			return;
		}
		void deleteContact()
		{
			system("cls");
			ifstream fin("Contacts.csv");
			if(!fin.is_open())
			{
				cout << "Error opening file :// \n";
				return;	
			}		
			gotoxy(10,10);
			cout << "Enter name to of contact to delete: ";
			string n;
			fflush(stdin);
			cin >> n;
			string line;
			int i = 0;
			head = NULL;
			string name,num,a,e,g,fav;
			while (getline(fin, line)) 
			{
    		    stringstream ss(line);
     		  	getline(ss, name, ',');
     		  	getline(ss, g, ',');
    		 	getline(ss, e, ',');
    	 		getline(ss, a, ',');
      			getline(ss, num, ',');	
   			    getline(ss, fav, ',');
      			bool favorite = (fav == "1"); 
      			Node* c1 = new Node(name,g,e,a,num,favorite);
      			if(head == NULL)
      			{
      				head = c1;
      				head->next = NULL;
				}
				else
				{
					Node* temp = head;
					while(temp->next != NULL)
					{
						temp = temp->next;
					}
					temp->next = c1;
				}
    		}
    		bool flag = false;
    		Node* temp = head;
    		while(temp != NULL)
    		{
    			if(temp->c.name == n)
    			{
	    			flag = true;
	    			cout << "\t\t\t\t\tContact found\n";
	    			break;
				}
    			temp = temp->next;
			}
			if(!flag)
			{
				cout << "\t\t\t\t\tNo such contact found... Press any key to continue\n";
				getch();
				system("cls");
				return;
			}
			gotoxy(10,12);
			Node* curr = head;
			Node* prev = NULL;
			while (curr != NULL) 
			{
      			if(curr->c.name == n) 
				{
					flag = 1;
    	       	 	if (prev != NULL) 
					{
       	    		    prev->next = curr->next;
       	    		} 
					else 
					{
        		   	     head = curr->next;
       	        	}
           		 	delete curr;
           		 	cout << "\t\t\t\t\tContact deleted\n";
           		 	break;
        		}
        		prev = curr;
        		curr = curr->next;
    		}
    		ofstream fout;
    		fout.open("contacts.csv");
			if(!fout.is_open())
			{
				cout << "Error opening file :// \n";
				return;
			}
			size--;
			temp = head;
			while(temp != NULL)
			{
				fout << temp->c.name << "," << temp->c.gender << "," << temp->c.email  << "," << temp->c.address << "," << temp->c.number << "," 
				<< temp->c.favorite << endl;	
				temp = temp->next;
			}
			fout.close();
			gotoxy(60,19);
			cout << "PRESS ANY KEY TO CONTINUE...";
			getch();
			system("cls"); 
		}
		void searchContact()
		{
			// first we load contacts from file into hash table then we search it from hash table
			ifstream fin("Contacts.csv");
			if(!fin.is_open())
			{
				cout << "Error opening file :// \n";
				return;	
			}		
			string line;
			int i = 0;
			string name,num,a,e,g,fav;
			while (getline(fin, line)) 
			{
				if(i == 0)
				{
					i++;
					continue;
				}
    		    stringstream ss(line);
     		  	getline(ss, name, ',');
     		  	getline(ss, g, ',');
    		 	getline(ss, e, ',');
    	 		getline(ss, a, ',');
      			getline(ss, num, ',');	
   			    getline(ss, fav, ',');
      			bool favorite = (fav == "1"); 
      			
      			int idx = hashFunc(name);
	    		ContactNode* c1 = new ContactNode(name,g,e,a,num,favorite);
   	 			if(chained[idx] == NULL)
    			{ 
    				chained[idx] = c1;
					chained[idx]->next = NULL;
					chained[idx]->tail = c1;
				}
				else
				{
					chained[idx]->tail->next = c1;
					chained[idx]->tail = c1;
					chained[idx]->tail->next = NULL;
				}
    		}
			fin.close();
			
			gotoxy(10,10);
			cout << "Enter name to search: ";
			string n;
			fflush(stdin);
			cin >> n;
			int idx = hashFunc(n);
			ContactNode* temp = chained[idx];
			while(temp != NULL)
			{
				if(temp->name == n)
				{
					system("cls");
					display(temp);
					break;
				}
				temp = temp->next;
			}
		}
		
		void insertIntoBST(BSTNode*& root, ContactNode* newNode) 
		{
		    if (root == NULL) 
			{
		        root = new BSTNode(newNode->name,newNode->gender,newNode->email,newNode->address,newNode->number,newNode->favorite);
		        return;
		    }
		    if (newNode->name < root->c.name) 
			{
		        insertIntoBST(root->left, newNode);
		    } 
			else if (newNode->name > root->c.name) 
			{
		        insertIntoBST(root->right, newNode);
		    }
		}

		void displayAscending() 
		{
		    ifstream fin("Contacts.csv");
		    if (!fin.is_open()) 
			{
		        cout << "Error opening file :// \n";
		        return;
		    }
		
		    string line;
		    int i = 0;
		    string name, num, a, e, g, fav;
		
		    while (getline(fin, line)) 
			{
		        if (i == 0) 
				{
		            i++;
		            continue;
		        }
		        stringstream ss(line);
		        getline(ss, name, ',');
		        getline(ss, g, ',');
		        getline(ss, e, ',');
		        getline(ss, a, ',');
		        getline(ss, num, ',');
		        getline(ss, fav, ',');
		        bool favorite = (fav == "1");
		
		        ContactNode* c1 = new ContactNode(name, g, e, a, num, favorite);
		        insertIntoBST(root, c1);
		    }
		
		    fin.close();
		    gotoxy(1,0);
		    inOrderTraversal(root);
		    cout << "Press any key to continue...\n";
		    getch();
		    system("cls");
		}
		void inOrderTraversal(BSTNode* &temp)
    	{
    		cout << endl;
    		if(temp == NULL)
    		{
    			return;
			}
			inOrderTraversal(temp->left);
			cout << "Name: " << temp->c.name << endl;
			cout << "Gender: " << temp->c.gender << endl;
			cout << "Address: " << temp->c.address << endl;
			cout << "Email Address: " << temp->c.email << endl;
			cout << "Phone: " << temp->c.number << endl;
			cout << "Favorite : " << temp->c.favorite << endl << endl;
			inOrderTraversal(temp->right);
		}
		int getlines()
		{
			ifstream fin("Contacts.csv");
			string line;
		    if (!fin.is_open()) 
			{
		        cout << "Error opening file :// \n";
		        return -1;
		    }
		    int i = 0;
		    while (getline(fin, line)) 
			{
		        i++;
		    }
		    fin.close();
			return i;		
		}
		void displayDescending()
		{
			root = NULL;
			ifstream fin("Contacts.csv");
		    if (!fin.is_open()) 
			{
		        cout << "Error opening file :// \n";
		        return;
		    }
		    string line;
		    int i = 0;
		    string name, num, a, e, g, fav;
		
		    while (getline(fin, line)) 
			{
		        stringstream ss(line);
		        getline(ss, name, ',');
		        getline(ss, g, ',');
		        getline(ss, e, ',');
		        getline(ss, a, ',');
		        getline(ss, num, ',');
		        getline(ss, fav, ',');
		        bool favorite = (fav == "1");
		        
		        ContactNode *c1 = new ContactNode(name, g, e, a, num, favorite);
		        insertIntoBST(root,c1);
		    }
		
		    fin.close();
		    gotoxy(1,0);
		    inOrderTraversal2(root);        // basically it traverses right first then left so that they are in descending order
		    cout << "Press any key to continue...\n";
		    getch();
		    system("cls");
		}
		void inOrderTraversal2(BSTNode* &temp)
		{
			if(temp == NULL)
			{
				return;
			}
			inOrderTraversal2(temp->right);
			cout << "Name: " << temp->c.name << endl;
			cout << "Gender: " << temp->c.gender << endl;
			cout << "Address: " << temp->c.address << endl;
			cout << "Email Address: " << temp->c.email << endl;
			cout << "Phone: " << temp->c.number << endl;
			cout << "Favorite : " << temp->c.favorite << endl << endl;
			inOrderTraversal2(temp->left);	
		}
		void displayallContacts()
		{
			head = NULL;;
			ifstream fin("Contacts.csv");
		    if (!fin.is_open()) 
			{
		        cout << "Error opening file :// \n";
		        return;
		    }
		    string line;
		    int i = 0;
		    string name, num, a, e, g, fav;
		
		    while (getline(fin, line)) 
			{
		        stringstream ss(line);
		        getline(ss, name, ',');
		        getline(ss, g, ',');
		        getline(ss, e, ',');
		        getline(ss, a, ',');
		        getline(ss, num, ',');
		        getline(ss, fav, ',');
		        bool favorite = (fav == "1");
		        
		        Node *c1 = new Node(name, g, e, a, num, favorite);
		        if(head == NULL)
		        {
		        	head = c1;
		        	head->next = NULL;
				}
				else
				{
					Node* temp = head;
					while(temp->next != NULL)
					{
						temp = temp->next;
					}
					temp->next = c1;
					c1->next = NULL;
				}
		    }
		
		    fin.close();
		    gotoxy(1,0);
			Node* temp = head;
			while(temp != NULL)
			{
				cout << "Name: " << temp->c.name << endl;
				cout << "Gender: " << temp->c.gender << endl;
				cout << "Address: " << temp->c.address << endl;
				cout << "Email Address: " << temp->c.email << endl;
				cout << "Phone: " << temp->c.number << endl;
				cout << "Favorite : " << temp->c.favorite << endl << endl;
				temp = temp->next;
			}
		    cout << "Press any key to continue...\n";
		    getch();
		    system("cls");	
		}
		void EnterCallLog()
		{
			system("cls");
			ifstream fin;
			fin.open("callLogs.csv");
			if(!fin)
			{
				cout << "Error openeing file :// \n";
				return;
			}
			stack<Log> temp;
			string n;
			int day, month, year;
		    int hour, min, sec;
		    time_t now = time(0);
		    tm *ltm = localtime(&now);
		
		    day = ltm->tm_mday;
		    month = ltm->tm_mon;
		    year = ltm->tm_year + 1900;
		    hour = ltm->tm_hour;
		    min = ltm->tm_min;
		    sec = ltm->tm_sec;
		
		    string dayStr = to_string(day);
		    string monthStr = to_string(month);
		    string yearStr = to_string(year);
		    string hourStr = to_string(hour);
		    string minStr = to_string(min);
		    string secStr = to_string(sec);

			string find = dayStr + "/" + monthStr + "/" + yearStr;
			string fint = hourStr + ":" + minStr + ":" + secStr;
			
			cout << "Enter Number: ";
			cin >> n;
			
			Log l1(find,fint,n);
			string line;
		    string date,time,number;
			
		    while(getline(fin, line)) 
			{
		        stringstream ss(line);
		        getline(ss, date, ',');
		        getline(ss, time, ',');
		        getline(ss, number, ',');
		       	Log l(date,time,number);
		        temp.push(l);
		    }
		    
		    fin.close();
		    
		    temp.push(l1);                       // call log entered
		    
		    ofstream fout;
		    fout.open("callLogs.csv");
		    if(!fout)
		    {
		    	cout << "Error opening file :/ \n";
		    	return;
			}
		    
		    while(!temp.empty())
		    {
		    	Log t = temp.top();
		    	fout << t.date << "," << t.time << "," << t.number << endl;
		    	temp.pop();
			}
			fout.close();
			gotoxy(30,10);
			cout << "Call Log Entered!\n";
			gotoxy(30,11);
			cout << "Details: ";
			gotoxy(30,12);
			cout << "Date: " << find;
			gotoxy(30,13);
			cout << "Time: " << fint;
			gotoxy(30,14);
			cout << "Number: " << n;
			gotoxy(60,19);
			cout << "PRESS ANY KEY TO CONTINUE...";
			getch();
			system("cls"); 
		}
		void seeCallLogsLtoE()
		{
			system("cls");
			stack<Log> temp;
			ifstream fin;
			
			fin.open("callLogs.csv");
			if(!fin)
			{
				cout << "Error openeing file :/ \n";
				return;
			}
			string line;
		    string date,time,number;
			
		    while (getline(fin, line)) 
			{
		        stringstream ss(line);
		        getline(ss, date, ',');
		        getline(ss, time, ',');
		        getline(ss, number, ',');
		       	Log l(date,time,number);
		        temp.push(l);
		    }
			fin.close();

			while(!temp.empty())
			{
				Log t = temp.top();
				cout << "Date: " << t.date << endl << "Time: " << t.time << endl << "Number: " << t.number << endl << endl;
				temp.pop();
			}
			gotoxy(60,19);
			cout << "PRESS ANY KEY TO CONTINUE...";
			getch();
			system("cls"); 
		}
		void seeCallLogsEtoL()
		{
			system("cls");
			stack<Log> temp;
			ifstream fin;
			
			fin.open("callLogs.csv");
			if(!fin)
			{
				cout << "Error openeing file :/ \n";
				return;
			}
			string line;
		    string date,time,number;
			
		    while (getline(fin, line)) 
			{
		        stringstream ss(line);
		        getline(ss, date, ',');
		        getline(ss, time, ',');
		        getline(ss, number, ',');
		       	Log l(date,time,number);
		        temp.push(l);
		    }
			fin.close();
			recursionPrint(temp);                      // prints stack basically in First in First out manner
			gotoxy(60,19);
			cout << "PRESS ANY KEY TO CONTINUE...";
			getch();
			system("cls"); 
		}
		void recursionPrint(stack<Log> temp)
		{
			if(temp.empty())
			{
				return;
			}
			Log t = temp.top();
			temp.pop();
			recursionPrint(temp);
			cout << "Date: " << t.date << endl << "Time: " << t.time << endl << "Number: " << t.number << endl << endl;
		}
		
		tm StringToTm(const string& dateString) 
		{
		    tm time = {};
		    istringstream ss(dateString);
		    ss >> get_time(&time, "%d-%m-%Y"); // Assuming date format: YYYY-MM-DD
		    return time;
		}
		
		void merge(vector<Log> &l,int s,int mid,int e)
		{
			int n1 = mid - s + 1;
			int n2 = e-mid;
			
			Log a[n1];
			Log b[n2];
			
			int k = s;
			for(int i=0 ; i<n1 ; i++)
			{
				a[i] = l[k];
				k++;
			}
			k = mid+1;
			for(int i=0 ; i<n2 ; i++)
			{
				b[i] = l[k];
				k++;
			}
			int i=0,j=0;
			k=s;
			while(i<n1 && j<n2)
			{
				tm tm_date1 = StringToTm(a[i].date);
				tm tm_date2 = StringToTm(b[j].date);
				
				if(mktime(&tm_date1) < mktime(&tm_date2))
				{
					l[k] = a[i];
					i++;
					k++;
				}
				else
				{
					l[k] = b[j];
					j++;
					k++;
				}
			}
			while(i<n1)
			{
				l[k] = a[i];
				k++;
				i++;
			}
			while(j<n2)
			{
				l[k] = b[j];
				k++;
				j++;
			}
		}
		void mergeSort(vector<Log> &l,int s,int e)
		{
			if(s<e)
			{
				int mid = ((s+e)/2);
				mergeSort(l,s,mid);
				mergeSort(l,mid+1,e);
				
				merge(l,s,mid,e);
			}
		}
		void readLogs()
		{
			vector<Log> l;
			ifstream fout;
			fout.open("callLogs.csv");
			if(!fout)
			{
				cout << "Error opening file :/ \n";
				return;
			}
			string line;
		    string date,time,number;
			
		    while (getline(fout, line)) 
			{
		        stringstream ss(line);
		        getline(ss, date, ',');
		        getline(ss, time, ',');
		        getline(ss, number, ',');
		       	Log temp(date,time,number);
		        l.push_back(temp);
		    }
			fout.close();
			
			mergeSort(l,0,l.size());                     
			for(int i=0 ; i<l.size() ; i++)
			{
				cout << "Date: " << l[i].date << endl << "Time: " << l[i].time << endl << "Number: " << l[i].number << endl << endl;	
			}
			
			gotoxy(60,19);
			cout << "PRESS ANY KEY TO CONTINUE...";
			getch();
			system("cls"); 
		}
		bool validateNumber(string num)
		{
			if(num.length()>11)
			{
				return false;	
			}
			list<string> number;              // implementation of doubly linkedlist
			
			bool found = false;
			
			ifstream fin("Contacts.csv");
			if(!fin.is_open())
			{
				cout << "Error opening file :// \n";
				return false;	
			}		
			string line;
			int i = 0;
			string name,n,a,e,g,fav;
			while (getline(fin, line)) 
			{
				if(i == 0)
				{
					i++;
					continue;
				}
    		    stringstream ss(line);
     		  	getline(ss, name, ',');
     		  	getline(ss, g, ',');
    		 	getline(ss, e, ',');
    	 		getline(ss, a, ',');
      			getline(ss, n, ',');	
    	 		number.push_back(n);    // doubly linkedlist
   			    getline(ss, fav, ',');
      			bool favorite = (fav == "1"); 	
      		}
      		
      		// linear searching for contact number if it exists already return false
      		for(auto & el : number)
      		{
      			if(el == num)
				{
					return true;
				}	
			}
      		return false;
		}
};

int main()
{
	mainp();
	Contacts contactList;
	contactList.start();
}