#include <iostream>
#include <string>
#include<iomanip>
using namespace std;

int studentId=0;
// ======================= STUDENT CLASS ===========================
class Student {
public:
    int id;
    int age;
    string name;
    string cnicNo;
    string phoneNo;
    string department;
    string email;
    string previousDegree;
    int previousPercentage;
    string degree;
    //string courses[5];
    float CGPA;

    Student() {
        id = 0;
        name = "";
        department = "";
        CGPA = 0.0;
        phoneNo = "";
        cnicNo = "";
    }
};

// ======================= LINKED LIST NODE FOR STUDENTS ===========================
struct Node {
    Student data;
    string designation;
    Node* next;

    Node(Student s, string d) {
        data = s;
        designation = d;
        next = NULL;
    }
};

Node* head = NULL;

// ======================= ADD STUDENT ===========================
void AddStudentLL() {
    int n;
    cout << "How many students you want to add: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Student s;
		studentId++;
		s.id=studentId;
        cout << "\n===== Enter Data of Student " << i + 1 << " =====\n";

        cout << "Enter Student ID: "<<s.id<<endl;

        cin.ignore();
        cout << "Enter Student Name: ";
        getline(cin, s.name);
        
        cout<<"Enter Age : ";
        cin>>s.age;

        cout << "Enter Phone Number: ";
        cin.ignore();
        getline(cin, s.phoneNo);

        cout << "Enter Cnic Number: ";
        getline(cin, s.cnicNo);

        cout<<"Enter Email : ";
        cin>>s.email;
        
        cout<<"Enter Previous Degree : ";
        cin>>s.previousDegree;
        
        cout<<"Ente Previous Percentage : ";
        cin>>s.previousPercentage;
        
        cout<<"Enter Current Degrre to Enroll : ";
        cin>>s.degree;
        
        
        

        Node* newNode = new Node(s, "");

        if (head == NULL)
            head = newNode;
        else {
            Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }

        cout << "Student " << i + 1 << " added successfully!\n";
        cin.ignore();
    }
}

// ======================= DISPLAY STUDENTS ===========================
void DisplayStudentsLL() {
    if (head == NULL) {
        cout << "No student records found.\n";
        return;
    }

    Node* temp = head;
    int index = 1;

    while (temp != NULL) {
        cout << "\n===== Student " << index++ << " =====\n";
        cout << "Student ID: " << temp->data.id << endl;
        cout << "Name: " << temp->data.name << endl;
        cout << "Phone Number: " << temp->data.phoneNo << endl;
        cout << "CNIC Number: " << temp->data.cnicNo << endl;
        cout << "Email : "<<temp->data.email<<endl;
        cout<< "Previous Degree : "<<temp->data.previousDegree<<endl;
        cout<<"Previous Percentage : "<<temp->data.previousPercentage<<"%"<<endl;
        cout<<"Current Degree Enroll : "<<temp->data.degree<<endl;
        temp = temp->next;
    }
}

// ======================= SEARCH STUDENT ===========================
void SearchStudentLL() {
    if (head == NULL) {
        cout << "No student records found.\n";
        return;
    }

    Student arr[100];
    int size = 0;

    Node* temp = head;
    while (temp != NULL) {
        arr[size++] = temp->data;
        temp = temp->next;
    }

    // sort
    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size; j++)
            if (arr[i].id > arr[j].id)
                swap(arr[i], arr[j]);

    int key;
    cout << "Enter ID to search: ";
    cin >> key;

    int start = 0, end = size - 1, mid;
    bool found = false;

    while (start <= end) {
        mid = (start + end) / 2;

        if (arr[mid].id == key) {
            found = true;
            break;
        } else if (key > arr[mid].id)
            start = mid + 1;
        else
            end = mid - 1;
    }

    if (found) {
        cout << "\nStudent Found!\n";
        cout << "ID: " << arr[mid].id << endl;
        cout << "Name: " << arr[mid].name << endl;
        cout << "Phone: " << arr[mid].phoneNo << endl;
        cout << "CNIC: " << arr[mid].cnicNo << endl;
        cout<<"Email : "<<arr[mid].email<<endl;
        cout<<"Previous Degree : "<<arr[mid].previousDegree<<endl;
        cout<<"Previous Percentage : "<<arr[mid].previousPercentage<<endl;
        cout<<"Current Enrolled Degree : "<<arr[mid].degree<<endl;
    } else {
        cout << "Student Not Found!\n";
    }
}

// ======================= UPDATE STUDENT ===========================
void UpdateStudentLL() {
    int id;
    cout << "Enter ID to update student: ";
    cin >> id;

    Node* temp = head;
    cin.ignore();

    while (temp != NULL) {
        if (temp->data.id == id) {

            cout << "Enter new name: ";
            getline(cin, temp->data.name);

            cout << "Enter new Phone Number: ";
            getline(cin, temp->data.phoneNo);

            cout << "Enter new Cnic Number: ";
            getline(cin, temp->data.cnicNo);

            cout<<"Enter New Email : ";
            cin>>temp->data.email;
            
            cout<<"Enter Current Enrolled Degree : ";
            cin>>temp->data.previousDegree;
            
            cout<<"Enter Previous Degree Percentage : ";
            cin>>temp->data.previousPercentage;
            
            cout<<"Enter Current Degree : ";
            cin>>temp->data.degree;

            cout << "\nStudent Updated Successfully!\n";
            return;
        }
        temp = temp->next;
    }

    cout << "Student not found!\n";
}

// ======================= FACULTY CLASS ===========================
class Faculty : public Student {
public:
    string designation;

    // separate linked list node for faculty
    Student fdata;
    Faculty() { designation = ""; }

    struct FNode {
        Student data;
        string designation;
        FNode* next;

        FNode(Student s, string d) {
            data = s;
            designation = d;
            next = NULL;
        }
    };

    FNode* facHead = NULL;

    // ADD FACULTY
    void AddFaculty() {
        int n;
        cout << "How many faculty you want to add: ";
        cin >> n;
        cin.ignore();

        for (int i = 0; i < n; i++) {
            Student f;
            cout << "\nEnter Faculty ID: ";
            cin >> f.id;
            cin.ignore();

            cout << "Enter Faculty Name: ";
            getline(cin, f.name);

            cout << "Enter Faculty Department: ";
            getline(cin, f.department);

            cout << "Enter Faculty Phone No: ";
            getline(cin, f.phoneNo);

            cout << "Enter Faculty CNIC No: ";
            getline(cin, f.cnicNo);

            cout << "Enter Designation: ";
            getline(cin, designation);

            FNode* newNode = new FNode(f, designation);

            if (facHead == NULL)
                facHead = newNode;
            else {
                FNode* t = facHead;
                while (t->next != NULL) t = t->next;
                t->next = newNode;
            }
            cout << "Faculty added successfully!\n";
        }
    }

    // DISPLAY FACULTY
    void dispFaculty() {
        if (facHead == NULL) {
            cout << "No faculty found.\n";
            return;
        }

        FNode* temp = facHead;
        int i = 1;
        while (temp != NULL) {
            cout << "\n--- Faculty " << i++ << " ---\n";
            cout << "ID: " << temp->data.id << endl;
            cout << "Name: " << temp->data.name << endl;
            cout << "Department: " << temp->data.department << endl;
            cout << "Phone: " << temp->data.phoneNo << endl;
            cout << "CNIC: " << temp->data.cnicNo << endl;
            cout << "Designation: " << temp->designation << endl;

            temp = temp->next;
        }
    }

    // SEARCH FACULTY
    void SearchFaculty() {
        if (facHead == NULL) {
            cout << "No faculty records.\n";
            return;
        }

        Student arr[100];
        string des[100];
        int size = 0;

        FNode* temp = facHead;
        while (temp != NULL) {
            arr[size] = temp->data;
            des[size] = temp->designation;
            size++;
            temp = temp->next;
        }

        // sorting
        for (int i = 0; i < size - 1; i++)
            for (int j = i + 1; j < size; j++)
                if (arr[i].id > arr[j].id) {
                    swap(arr[i], arr[j]);
                    swap(des[i], des[j]);
                }

        int key;
        cout << "Enter Faculty ID: ";
        cin >> key;

        int start = 0, end = size - 1, mid;
        bool found = false;

        while (start <= end) {
            mid = (start + end) / 2;

            if (arr[mid].id == key) {
                found = true;
                break;
            } else if (key > arr[mid].id)
                start = mid + 1;
            else
                end = mid - 1;
        }

        if (!found) {
            cout << "Faculty Not Found!\n";
            return;
        }

        cout << "\n--- Faculty Found ---\n";
        cout << "ID: " << arr[mid].id << endl;
        cout << "Name: " << arr[mid].name << endl;
        cout << "Department: " << arr[mid].department << endl;
        cout << "Phone: " << arr[mid].phoneNo << endl;
        cout << "CNIC: " << arr[mid].cnicNo << endl;
        cout << "Designation: " << des[mid] << endl;
    }
};
// ======================= COURSE CLASS =============================
class Course { 
private:
    Node* courHead = NULL;

    string courseTeacher;
    string courseCode;
    string courseName;
    int creditHours;

public:

    // ================= ADD COURSE ==================
    void addCourse() {
        int n;
        cout << "Enter how many number of courses you want to add: ";
        cin >> n;
        cin.ignore();

        for (int i = 0; i < n; i++) {
            cout << "\nEnter details of course " << i + 1 << endl;

            cout << "Enter course Teacher name: ";
            getline(cin, courseTeacher);

            cout << "Enter course code: ";
            getline(cin, courseCode);

            cout << "Enter course name: ";
            getline(cin, courseName);

            cout << "Enter course credit hours: ";
            cin >> creditHours;
            cin.ignore();

            Student s;
            s.name = courseName;            // Course name
            s.department = courseTeacher;   // Teacher
            s.phoneNo = courseCode;         // Course code
            s.CGPA = creditHours;           // Credit hours

            Node* newNode = new Node(s, "COURSE");

            if (courHead == NULL) {
                courHead = newNode;
            }
            else {
                Node* temp = courHead;
                while (temp->next != NULL)
                    temp = temp->next;

                temp->next = newNode;
            }

            cout << "Course " << i + 1 << " added Successfully\n";
        }
    }

    // ================= DISPLAY COURSES ==================
    void dispCourse() {
        if (courHead == NULL) {
            cout << "No course Records Found!\n";
            return;
        }

        Node* temp = courHead;
        int index = 1;

        while (temp != NULL) {

            cout << "\n--- Course " << index << " Details ---\n";
            cout << "Course Teacher Name: " << temp->data.department << endl;
            cout << "Course Name: " << temp->data.name << endl;
            cout << "Course Code: " << temp->data.phoneNo << endl;
            cout << "Course Credit Hours: " << temp->data.CGPA << endl;

            temp = temp->next;
            index++;
        }
    }

    // ================= ASSIGN FACULTY ==================
    void assignFaculty() {
        if (courHead == NULL) {
            cout << "No Courses Found!\n";
            return;
        }

        cin.ignore();
        string code;
        cout << "Enter Course Code to assign faculty: ";
        getline(cin, code);

        Node* temp = courHead;

        while (temp != NULL) {

            if (temp->data.phoneNo == code) { // FIXED
                cout << "Enter Faculty Name: ";
                getline(cin, temp->data.department);

                cout << "Faculty Assigned Successfully!\n";
                return;
            }

            temp = temp->next;
        }

        cout << "Course Not Found!\n";
    }

    // ================= REGISTER STUDENT ==================
    void regiStudent() {
        if (courHead == NULL) {
            cout << "No Courses Available!\n";
            return;
        }

        cin.ignore();
        string code;
        cout << "Enter Course Code to register student: ";
        getline(cin, code);

        Node* temp = courHead;

        while (temp != NULL) {

            if (temp->data.phoneNo == code) {  // FIXED (was temp->data.courseCode)
                cout << "Enter Student Name: ";
                getline(cin, temp->data.name);

                cout << "Student Registered Successfully!\n";
                return;
            }

            temp = temp->next;
        }

        cout << "Course Not Found!\n";
    }
};
// ======================= DEPARTMENT CLASS =============================
class Department {
private:
    struct DeptNode {
        int deptID;
        string deptName;

        int totalStudents;
        int totalFaculty;

        string listOfStudents[100];
        string listOfFaculty[100];

        DeptNode* next;

        DeptNode() {
            deptID = 0;
            deptName = "";
            totalStudents = 0;
            totalFaculty = 0;
            next = NULL;
        }
    };

    DeptNode* deptHead = NULL;

public:

    // ================= ADD DEPARTMENT ==================
    void addDept() {
        int n;
        cout << "How many departments you want to add: ";
        cin >> n;
        cin.ignore();

        for (int i = 0; i < n; i++) {

            DeptNode* newNode = new DeptNode();

            cout << "\n=== Enter Department " << i + 1 << " Details ===\n";

            cout << "Enter Department ID: ";
            cin >> newNode->deptID;
            cin.ignore();

            cout << "Enter Department Name: ";
            getline(cin, newNode->deptName);

            cout << "How many students in this department? ";
            cin >> newNode->totalStudents;
            cin.ignore();

            for (int s = 0; s < newNode->totalStudents; s++) {
                cout << "Enter Student Name " << s + 1 << ": ";
                getline(cin, newNode->listOfStudents[s]);
            }

            cout << "How many faculty in this department? ";
            cin >> newNode->totalFaculty;
            cin.ignore();

            for (int f = 0; f < newNode->totalFaculty; f++) {
                cout << "Enter Faculty Name " << f + 1 << ": ";
                getline(cin, newNode->listOfFaculty[f]);
            }

            // Insert into Linked List
            if (deptHead == NULL) {
                deptHead = newNode;
            }
            else {
                DeptNode* temp = deptHead;
                while (temp->next != NULL)
                    temp = temp->next;
                temp->next = newNode;
            }

            cout << "Department Added Successfully!\n";
        }
    }

    // ================= DISPLAY DEPARTMENTS ==================
    void displayDept() {
        if (deptHead == NULL) {
            cout << "No Department Records Found!\n";
            return;
        }

        DeptNode* temp = deptHead;
        int index = 1;

        while (temp != NULL) {
            cout << "\n--- Department " << index++ << " Details ---\n";

            cout << "Department ID: " << temp->deptID << endl;
            cout << "Department Name: " << temp->deptName << endl;

            cout << "Students (" << temp->totalStudents << "): ";
            for (int i = 0; i < temp->totalStudents; i++)
                cout << temp->listOfStudents[i] << ", ";
            cout << endl;

            cout << "Faculty (" << temp->totalFaculty << "): ";
            for (int i = 0; i < temp->totalFaculty; i++)
                cout << temp->listOfFaculty[i] << ", ";
            cout << endl;

            temp = temp->next;
        }
    }

    // ================= DEPARTMENT REPORT ==================
    void deptReport() {
        if (deptHead == NULL) {
            cout << "No Department Data Available!\n";
            return;
        }

        DeptNode* temp = deptHead;

        cout << "\n========== DEPARTMENT REPORT ==========\n";

        while (temp != NULL) {
            cout << "\nDepartment: " << temp->deptName << " (ID: " << temp->deptID << ")\n";

            cout << "Total Students: " << temp->totalStudents << endl;
            cout << "Total Faculty: " << temp->totalFaculty << endl;

            cout << "----------------------------------------\n";

            temp = temp->next;
        }
    }
};

// ======================= STUDENT MENU ===========================
void StudentManage() {
    int choice; 

    do {
        cout << " ========================================\n";
        cout << "||          STUDENT MANAGEMENT          ||\n";
        cout << " ========================================\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "5. Main Menu\n";

        cout << "Enter a number (1-5): ";
        cin >> choice;

        switch(choice) {
            case 1:
                AddStudentLL();
                break;
            case 2:
                DisplayStudentsLL();
                break;
            case 3:
                SearchStudentLL();
                break;
            case 4:
                UpdateStudentLL();
                break;
            case 5:
                cout << "Returning to Main Menu...\n";
                break;
            default:
                cout << "Invalid Choice! Try Again.\n";
        }

        cout << "\n=====================================================\n";

    } while (choice != 5);
}
// ======================= FACULTY CLASS & MANAGEMENT ===========================
void FacultyManage() {
    Faculty f1;
    int choice;
    do {
        cout << " ========================================\n";
        cout << "||          FACULTY MANAGEMENT          ||\n";
        cout << " ========================================\n";
        cout << "1. Add Faculty\n";
        cout << "2. Display Faculty\n";
        cout << "3. Search Faculty\n";
        cout << "4. Main Menu\n";

        cout << "Enter a number (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Add faculty...\n";
                f1.AddFaculty();
                break;

            case 2:
                cout << "Display faculty...\n";
                f1.dispFaculty();
                break;

            case 3:
                cout << "Searching faculty...\n";
                f1.SearchFaculty();
                break;

            case 4:
                cout << "Returning to Main Menu...\n";
                break;

            default:
                cout << "Invalid Choice! Try Again.\n";
        }

        cout << "\n=====================================================\n\n";

    } while (choice != 4);
}
void CourseManage() {
	Course c1;
    int choice;
    do {
        cout << " ========================================\n";
        cout << "||          COURSE MANAGEMENT           ||\n";
        cout << " ========================================\n";
        cout << "1. Add Course\n";
        cout << "2. Display Course\n";
        cout << "3. Assign Faculty\n";
        cout << "4. Register Student\n";
        cout << "5. Main Menu\n";

        cout << "Enter a number (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Add course...\n";
                 c1.addCourse();
                break;

            case 2:
                cout << "Display courses...\n";
                c1.dispCourse();
                break;

            case 3:
                cout << "Assigning faculty...\n";
                c1.assignFaculty();
                break;

            case 4:
                cout << "Registering student...\n";
                c1.regiStudent();
                break;

            case 5:
                cout << "Returning to Main Menu...\n";
                break;

            default:
                cout << "Invalid Choice! Try Again.\n";
        }

        cout << "\n=====================================================\n\n";

    } while (choice != 5);
}

// ======================= DEPARTMENT MANAGEMENT ===========================
void DepartManage() {
	Department d1;
    int choice;
    do {
        cout << " ========================================\n";
        cout << "||        DEPARTMENT MANAGEMENT         ||\n";
        cout << " ========================================\n";
        cout << "1. Add Department\n";
        cout << "2. Display Department\n";
        cout << "3. Department Report\n";
        cout << "4. Main Menu\n";

        cout << "Enter a number (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Add department...\n";
                d1.addDept();
                break;

            case 2:
                cout << "Display department...\n";
                d1.displayDept();
                break;

            case 3:
                cout << "Generating report...\n";
                d1.deptReport();
                break;

            case 4:
                cout << "Returning to Main Menu...\n";
                break;

            default:
                cout << "Invalid Choice! Try Again.\n";
        }

        cout << "\n=====================================================\n\n";

    } while (choice != 4);
}

int countStudentAdmission=0;
string u[40];
string p[40];

struct node {
	string name;
	string cnic;
	string phoneNumber;
	string email;
	int age;
	string previousDegree;
	int previousPercentage;
	string degree;
	string verificationStatus="Waiting";
	node *next;
};

class addmissionQueue {
		node* front;
		node* rear;
	public:
		addmissionQueue(){
			front=rear=NULL;
		}
		bool isEmpty(){
			return front==NULL;
		}
		void enqueue(string name,string phoneNumber,string CNIC,string email,int age,string previousDegree,int previousPercentage,string degree){
			node * current=new node;
			current->name=name;
			current->cnic=CNIC;
			current->phoneNumber=phoneNumber;
			current->email=email;
			current->age=age;
			current->previousDegree=previousDegree;
			current->previousPercentage=previousPercentage;
			current->degree=degree;
			current->next=NULL;
			if(isEmpty()){
				front=current;
				rear=current;
			}else{
				rear->next=current;
				rear=current;
			}
			cout<<"=== Data Enqueued ===\n";
		}
		
		void dequeue(){
			if(isEmpty()){
				cout<<"=== No Data to Deque ===\n";
				return;
			}
			if(front->next==NULL){
				front=rear=NULL;
			}else{
				front=front->next;
			}
		}
		void display(){
			if(isEmpty()){
				cout<<"Nothing to Display!\n";
				return;
			}
			node *current=front;
			cout<<"-------------------------------------------------------------------------\n";
			cout<<left<<setw(15)<<"Name"<<setw(12)<<"PhoneNumber"<<setw(15)
			<<"CNIC"<<setw(15)<<"Email"<<setw(5)<<"Age"<<setw(17)<<"Previous Degree"
			<<setw(24)<<"Previous Precentage"<<setw(18)<<"Preffered Degree"<<setw(10)<<"Status"<<endl;
			cout<<"-------------------------------------------------------------------------\n";
			while(current!=NULL){
				cout<<left<<setw(15)<<current->name<<setw(12)<<current->phoneNumber<<setw(15)
				<<current->cnic<<setw(15)
				<<current->email<<setw(5)<<current->age<<setw(17)<<current->previousDegree<<setw(24)
				<<current->previousPercentage<<setw(18)<<current->degree<<setw(10)<<current->verificationStatus<<endl;
				current=current->next;
			}
			cout<<"\n";
		}
		void verify(){
			cout<<"\n=== Student Verification ===\n";
			cout <<"Enter CNIC to verify (Without Spaces and Dashes) : ";
			string c;
			cin>>c;
			node *current=front;
			while(current!=NULL){
				if(current->cnic==c){
					cout<<"Enter Verification Status : ";
					cin>>current->verificationStatus;
					if(current->verificationStatus=="Approved"){
						Student s;
						s.cnicNo=current->cnic;
						s.name=current->name;
						s.age=current->age;
						s.email=current->email;
						s.previousDegree=current->previousDegree;
						s.previousPercentage=current->previousPercentage;
						s.degree=current->degree;
						studentId++;
						s.id=studentId;
						Node * temp = new Node(s,"");
						if(head==NULL){
							head=temp;
						}else{
							Node *t =head;
							while(t->next!=NULL){
								t=t->next;
							}
								t->next=temp;
						}
						
					}
					cout<<"=== Status Updated ===\n";
					break;
				}
				current=current->next;
			}
		}
		
		void checkStatus(){
			cout<<"=== Check Status ===\n";
			cout<<"Enter String : ";
			string s ;
			cin>>s;
			node*current=front;
			while(current!=NULL){
				if(current->cnic==s){
					cout<<"Status : "<<current->verificationStatus<<endl;
					cout<<"=-=-=-=-=--=-=-==-=-=-=-==-=--====-=-=-=-=\n";
					break;
				}
				current=current->next;
			}
		}
		void withdraw (){
			if(isEmpty()){
				cout<<"No Students Application TO Withdraw!\n";
				return;
			}
			cout<<"Enter CNIC : ";
			string s;
			cin>>s;
			node *current=front;
			if(front->cnic==s){
				front=front->next;//First Node
				cout<<"\n= = = Application Withdrawn = = = \n";
				return;
			}
			while(current!=NULL){
				if(current->next->cnic==s && current->next->next==NULL){
					current->next=current->next->next;
					//last node case
				}
				if(current->next->cnic==s){//Any middle node
					current->next=current->next->next;
					cout<<"\n= = =  Application Withdrawn = = =\n";
					return;
				}
				current=current->next;
			}
			cout<<"CNIC not Found\n";
		}
};

addmissionQueue spring26;

class StudentLog {
		string username;
		string password;
		int idx;
	public:
		StudentLog(){
			username="";
			password="";
			idx=0;
		}
		
		void signIn(string usernames[],string passwords[],int len,int scount){
			if(scount<1){
				cout<<"==== No Student Data ====\n";
				return;
			}
			bool chk=false;
			int length=len;
			int count;
			int idx;
			cout<<"====== Sign In ======\n";
			do{
				chk=false;
				cout<<"Enter Username : ";
				string enteredUsername;
				cin>>enteredUsername;
				for (int i=0;i<length;i++){
					if(enteredUsername==usernames[i]){
						chk=true;
						idx=i;
						break;
					}
				}
				if(chk!=true){
					cout<<"Username Not Found !\n";
				}
			}while(chk!=true);
			chk=true;
			do{
				chk=false;
				cout<<"Enter Password : ";
				string enteredPassword;
				cin>>enteredPassword;
				if(enteredPassword == passwords[idx] ){
						chk=true;
				}
				count++;
				if(!chk){
					cout<<"Incorrect Password Entered!\n";
				}
				if(count==4){
					cout<<"Too many inccorrect Attempts!\n";
					cout<<"->Redirecting To Home Page!\n";
					//goto mn;
				}
				
			}while(chk!=true);
			
			cout <<"SignIn Successfull!\n";
			cout<<"---------------------------------\n";
			
		}
		
		void signUp(){
			cout<<"======= Sign Up =======\n";
			cout<<"Enter Username : ";
			cin>>u[idx];
			bool chk;
			do{
				chk=false;
				cout<<"Enter Password : ";
				string pwd;
				cin>>pwd;
				bool a=isValidPwd(pwd);
				if(isValidPwd(pwd)){
					p[idx]=pwd;
					chk=true;
					idx++;
				}else{
					chk=false;
					cout<<"Password Should Contain :\n1. At Least 6 Characters\n2. At least 1 letter\n3. At Least 1 Number\n4.At Least 1 Special Character\n"; 
				}
			}while(!chk);
		}
		bool isValidPwd(string p){
			int ln=p.length();
			bool lnb=false;//length bool
			bool c=false;
			bool l=false;
			bool d=false; 
			if(ln>=6){
					lnb=true;
				}
			for (char ch:p){
				
				if(isalpha(ch)){
					l=true;
				}else if(isdigit(ch)){
					d=true;
				}else{
					c=true;
				}
			}
			
			return c && l && d && lnb;
		}
	
};
bool checkCNIC(string s){
	bool a=true;
	int l=s.length();
	bool lb=true;
	if(l!=13){
		lb=false;
	}
	for (char ch:s){
		if(!isdigit(ch)){
			a=false;
		}
	}
	return a&&lb;
}
bool checkPhoneNumber(string s){
	int l = s.length();
	bool lb=true;
	bool d=true;
	if(l!=11){
		lb=false;
	}
	for(char ch:s){
		if(!isdigit(ch)){
			d=false;
		}
	}
	return lb && d;
}
addmissionQueue applyAdmission(){
	cout<<"====== Apply Admission ======\n";
	//addmissionQueue spring26;
	cout<<"Enter Your Full Name : ";
	cin.ignore();
	string name;
	getline (cin,name);
	string CNIC,phoneNumber;
	bool chk;
	do{	
		chk=true;
		cout<<"Enter CNIC : (Without Spaces and Hyphen) : ";
		cin>>CNIC;
		if(!checkCNIC(CNIC)){
			cout<<"Enter 13 Digits Without Spaces and Hyphen(Only Numbers)\n";
			chk=false;
		}
	}while(!chk);
		
	do{
		chk=true;
		cout<<"Enter Phone Number (Without Spaces or Dashes): ";
		cin>>phoneNumber;
		if(!checkPhoneNumber(phoneNumber)){
			cout<<"Not A Valid Phone Number !(11 Digits without spaces)\n";
			chk=false;
		}
	}while(!chk);
	string email;
	cout<<"Enter Email : ";
	cin >>email;
	
		int age;
	do{
		chk=true;
		cout<<"Enter Age : ";
		cin>>age;
		if(age<=16){
			cout<<"Age Limit (16+) !\n";
			chk=false;
		}
		
	}while(!chk);
	string previousDegree;
	cout<<"Enter Previous Degree : ";
	cin>>previousDegree;
	
	int previousPercentage;
	cout<<"Enter Previous Degree Percentage : ";
	cin>>previousPercentage;
	
	string degree;
	cout<<"Enter Degree to Apply : ";
		cin>>degree;
	
	cout<<"==== Application Successfull ====\n";    
	
	
	spring26.enqueue(name,phoneNumber,CNIC,email,age,previousDegree,previousPercentage,degree);
	return spring26;
	
}

void admissionPortal(){
	
	char inp;
	int len= sizeof (u)/sizeof(u[0]);
	bool chk;
	StudentLog sl;
	do{
	chk=true;
	cout<<"========= Admission =========\n";
	cout<<"1.Sign In (Already have an account )\n";
	cout<<"2.Sign Up (Dont Have Account)\n";
	int choice1;
	cout<<"Enter Choice  : ";
	cin>>choice1;
	
	switch(choice1){
		
		case 1:{
			if(!countStudentAdmission<1){
				sl.signIn(u,p,len,countStudentAdmission);
			}
			break;
		}
		case 2:{
			countStudentAdmission++;
			sl.signUp();
			break;
		}
		default:{
			chk=false;
			cout<<"Incorrect Number Entered !\n";
			break;
		}
	}
	}while(!chk);
	do{
	if(countStudentAdmission>=1){
		cout<<"1. Apply For Admission\n";
		cout<<"2. View Application Status\n";
		cout<<"3. WithDraw Application\n";
		cout<<"4. Log Out\n";
		cout<<"Enter Choice : ";
		int choice2;
		cin>>choice2;
		switch(choice2){
			case 1:{
				applyAdmission();
				break;
			}
			case 2:{
				spring26.checkStatus();
				break;
			}
			case 3:{
				spring26.withdraw();
				break;
			}
			case 4:{
				cout<<"\n===Logging Out ===\n";
				return;
				break;
			}
			default:{
				cout<<"Incorrect Choice Entered!\n";
				break;
			}
		}
	}
		cout<<"Another Operation in Admission Portal (Y/N) : ";
		cin>>inp;
	}while(inp=='Y'||inp=='y');
}


void displayAdmissionQueue(){
	cout<<"\n=============== Displaying Admission Queue ==============\n";
	spring26.display();
}
////////////////////
void adminPortal(){
	cout<<"\n=================== Admin Portal =======================\n";
	string username="admin",password="admin_123",eusrnme,eusrpwd;
	bool chk=true;
	int count=0;
	cout<<"= = = = = = = = Sign In To Continue = = = = = = = = \n";
	do{
		chk=true;
		cout<<"Enter Username : ";
		cin>>eusrnme;
		if(eusrnme!=username){
			cout<<"Username is Incorrect!\n";
			chk=false;
		}
	}while(!chk);
	do{
		chk=true;
		cout<<"Enter Password : ";
		cin>>eusrpwd;
		if(eusrpwd!=password){
			cout<<"Incorrect Password!\n";
			chk=false;
		}
		count++;
		if(count==4){
			cout<<"Many Incorrect Inputs! Backing to Main Menu\n";
			return;
		}
	}while(!chk);
	char inp;
	do{
	cout<<"====  Sign In Successful ====\n";
	cout<<"1. View Application Queue\n";
	cout<<"2. Verify Students\n";
	cout<<"3. Student Management\n";
    cout<<"4. Faculty Management\n";
    cout<<"5. Course Management\n";
    cout<<"6. Department Management\n";
	cout<<"0.Log Out\n";
	cout<<"Enter Choice : ";
	int choice;
	cin>>choice;
	switch(choice){
		case 1:{
			displayAdmissionQueue();
			break;
			}
		case 2:{
			spring26.verify();
			break;
			}
		case 3:{
			StudentManage();
			break;
		}
		case 4:{
			FacultyManage();
			break;
		}
		case 5:{
			CourseManage();
			break;
		}
		case 6:{
			DepartManage();
			break;
		}
		case 0:{
			cout<<"=== Logging Out ===\n";
			return;
			break;
			}
		}
		cout<<"Another Operation From Admin (Y/N) : ";
		cin>>inp;
	}while(inp=='Y' || inp=='y');
}

void displayMainMenu(){
	cout<<"==============================\n";
	cout<<"            U M S \n";
	cout<<"==============================\n";
	cout<<"1. Admission Portal\n";
	cout<<"2. Admin Portal\n";
	cout<<"0. E X I T\n";
}

int main(){
	
	char mm;
	do{
	displayMainMenu();
	int choiceMain;
	cout<<"Enter Choice : ";
	cin>>choiceMain;
		switch(choiceMain){
			
			case 1:{
				admissionPortal();
				break;
			}
			case 2:{
				adminPortal();
				break;
			}
			case 0:{
				cout<<"=== E X I T I N G ===\n";
				return 0;
				break;
			}
			default:{
				cout<<"Incorrect Number Entered!\n";
				break;
			}
		}
		cout<<"Main Menu (Y/N) : ";
		cin>>mm;
	}while(mm=='Y'||mm=='y');	
	
}
