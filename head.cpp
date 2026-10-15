/*

        PROJECT - STUDENT REPORT MANAGEMENT SYSTEM

 Build a complete Student Management System that sores student records,
 calculates grades and support data storage using files.

 Works to be done
 -- Add student records
 -- Display all students records
 -- SEARCH a student by NAME or ROLL-NO.
 -- DELETE or UPDATE students records
 -- FIND toppers
 -- SAVE AND LOAD
*/

#include<iostream>
#include<limits>
#include <fstream>
#include<unordered_map>
using namespace std;

class Student{
    private:
    string name;
    int rollno;
    unordered_map<string,double> marks;

    public:
    Student(){}
    Student(const string& name,int rollno,const unordered_map<string,double>& marks){
        this->name = name;
        this->rollno = rollno;
        this->marks = marks;
    }
    // GETTER

    // get roll no. of the student
    int getRollNo() const{
        return rollno;
    }

    // get name of the student
    string getName() const{
        return name;
    }

    // get marks of the student
    const unordered_map<string,double>& getMarks() const{
        return marks;
    }

    // SETTER

    // set roll no. of the student
    void setRollNo(int rollno){
        this->rollno = rollno;
    }

    // set name of the student
    void setName(const string& name){
        this->name = name;
    }

    // set marks of the student
    void setMarks(const string& sub,double updatedmark){
        marks[sub] = updatedmark;
    }

    //get total marks of the student
    double getGrandTotal() const;

    //get percentage
    double getPercentage() const;

    //get grade
    char getGrade() const;
    
};

double Student::getGrandTotal() const{
    double sum = 0;
    for(auto pair : marks){
        sum += pair.second;
    }
    return sum;
}

double Student::getPercentage() const{
    if(marks.size()){
        double percent = (getGrandTotal() / (marks.size() * 100)) * 100 ;
        return percent;
    }else{
        return 0;
    }
}

class Node{

    public:
    Student s;
    Node* prev;
    Node* next;
    

    Node(const Student& input){
        this->s = input;
        this->prev = NULL;
        this->next = NULL;
    }
};

// GLOBAL VARIABLES

Node* head = NULL;
Node* tail = NULL;

void AddStudentRecords(Node* &head,Node* &tail,const Student& s1,bool showMsg){
    Node* newNode = new Node(s1);

    // first node
    if(head == NULL){
        head = newNode;
        tail = newNode;
        if(showMsg)
            cout<<"Student record is added successfully ! " <<endl;
        return;
    }

    // insert at end using tail
    tail->next = newNode;
    newNode->prev = tail;

    // move tail forward
    tail = newNode;
    if(showMsg)
        cout<<"Student record is added successfully ! " <<endl;
}

char Student::getGrade() const{
    double p = getPercentage();

    if(p >= 90) return 'S';
    else if(p >= 80) return 'A';
    else if(p >= 70) return 'B';
    else if(p >= 60) return 'C';
    else if(p >= 50) return 'D';
    else if(p >= 40) return 'E';

    return 'F';
}

void searchByName(Node* &head,const string& name){
    if(!head){
        cout<<"\t ****** THERE IS NO RECORD PRESENT RIGHT NOW ******"<< endl;
        return;
    }
    Node* temp = head;
    while(temp){
        if((temp->s).getName() == name){
            break;
        }else{
            temp = temp->next;
        }
    }
    if(!temp){
        cout<<"\t ****** THERE IS NO RECORD BY NAME "<<name<<" ******"<< endl;
        return;
    }
    Student& dummyStudent = temp->s;
        cout<<"\t Student Name : "<<dummyStudent.getName()<<endl;
        cout<<"\t Roll-No. : "<<dummyStudent.getRollNo()<<endl;
        cout<<"\t Marks : ";

        for(auto pair : dummyStudent.getMarks()){
            cout<<"  "<<pair.first << " : "<<pair.second;
        }
        cout<<endl;
        cout<<"\t Total Marks : " << dummyStudent.getGrandTotal()<<endl;
        cout<<"\t Percentage : "<<dummyStudent.getPercentage()<<endl;

        cout<<"\t Grade : "<<dummyStudent.getGrade()<<endl;

}

void searchByRollno(Node* &head,int roll){
    if(!head){
        cout<<"\t ****** THERE IS NO RECORD PRESENT RIGHT NOW ******"<< endl;
        return;
    }
    Node* temp = head;
    while(temp){
        if((temp->s).getRollNo() == roll){
            break;
        }else{
            temp = temp->next;
        }
    }
    if(!temp){
        cout<<"\t ****** THERE IS NO RECORD BY ROLL-NO "<<roll<<" ******"<< endl;
        return;
    }
    Student& dummyStudent = temp->s;
        cout<<"\t Student Name : "<<dummyStudent.getName()<<endl;
        cout<<"\t Roll-No. : "<<dummyStudent.getRollNo()<<endl;
        cout<<"\t Marks : ";

        for(auto pair : dummyStudent.getMarks()){
            cout<<"  "<<pair.first << " : "<<pair.second;
        }
        cout<<endl;
        cout<<"\t Total Marks : " << dummyStudent.getGrandTotal()<<endl;
        cout<<"\t Percentage : "<<dummyStudent.getPercentage()<<endl;

        cout<<"\t Grade : "<<dummyStudent.getGrade()<<endl;
}

void Display(Node* &head,string name,int roll){

    if(!head){
        cout<<"\t ****** THERE IS NO RECORD PRESENT RIGHT NOW ******"<< endl;
        return;
    }
    Node* temp = head;
    while(temp){
        if((temp->s).getRollNo() == roll && (temp->s).getName() == name){
            break;
        }else{
            temp = temp->next;
        }
    }
    if(!temp){
        cout<<"\t ****** THERE IS NO RECORD BY NAME "<<name<<" ******"<< endl;
        return;
    }
    Student& dummyStudent = temp->s;
        cout<<"\t Student Name : "<<dummyStudent.getName()<<endl;
        cout<<"\t Roll-No. : "<<dummyStudent.getRollNo()<<endl;
        cout<<"\t Marks : ";

        for(auto pair : dummyStudent.getMarks()){
            cout<<"  "<<pair.first << " : "<<pair.second;
        }
        cout<<endl;
        cout<<"\t Total Marks : " << dummyStudent.getGrandTotal()<<endl;
        cout<<"\t Percentage : "<<dummyStudent.getPercentage()<<endl;

        cout<<"\t Grade : "<<dummyStudent.getGrade()<<endl;
    
}

void Display(Node* &head){

    if(!head){
        cout<<"\t ****** THERE IS NO RECORD PRESENT RIGHT NOW ******"<< endl;
        return;
    }

    Node* temp = head;

    while(temp){

        Student& dummyStudent = temp->s;
        cout<<"\t Student Name : "<<dummyStudent.getName();
        cout<<"\t Roll-No. : "<<dummyStudent.getRollNo();
        cout<<"\t Marks : ";

        for(auto pair : dummyStudent.getMarks()){
            cout<<"  "<<pair.first << " : "<<pair.second;
        }

        cout<<"\t Total Marks : " << dummyStudent.getGrandTotal();
        cout<<"\t Percentage : "<<dummyStudent.getPercentage();

        cout<<"\t Grade : "<<dummyStudent.getGrade()<<endl;

        temp = temp->next;
        cout<<endl;
    }
    cout<<endl;
}

void EraseStudentRecords(Node* &head,Node* &tail,const string& name,int roll){

    if(!head){
        cout<<"\t ****** THERE IS NO RECORD PRESENT RIGHT NOW ******"<< endl;
        return;
    }
    Node* temp = head;

    while(temp){
        if((temp->s).getRollNo() == roll && (temp->s).getName() == name){
            break;
        }else{
            temp = temp->next;
        }
    }
    if(!temp){
        cout<<"****** THERE IS NO RECORD BY NAME "<<name<<" AND ROLL-NO. "<<roll<<" ******";
        return;
    }
    if(head == tail){
        delete temp;
        head = tail = NULL;
    }
    else if(temp == head){
        Node* deleteNode = temp;
        head = head->next;
        head->prev = NULL;

        delete deleteNode;
    }else if(temp == tail){
        Node* deleteNode = temp;
        tail = tail->prev;
        tail->next = NULL;

        delete deleteNode;
    }else{
        Node* deleteNode = temp;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete deleteNode;
    }
    cout<<"Record deleted Successfully"<<endl;
}

// UPDATE FUNCTION FOR NAME
void updateName(Node* &head,const string& nameOfStudent,int rollnoOfStudent,const string& updatedname){
    if(!head){
        cout<<"\t ****** THERE IS NO RECORD PRESENT RIGHT NOW ******"<< endl;
        return;
    }

    Node* temp = head;

    while(temp){
        if((temp->s).getRollNo() == rollnoOfStudent && (temp->s).getName() == nameOfStudent){
            break;
        }else{
            temp = temp->next;
        }
    }
    if(!temp){
        cout<<"\t ****** THERE IS NO RECORD BY NAME "<<nameOfStudent<<"and ROLL-NO. "<< rollnoOfStudent<<" ******"<< endl;
        return;
    }
    (temp->s).setName(updatedname);
    cout<<" Name of the student has been successfully updated "<<endl;
}

// UPDATE FUNCTION FOR ROLL-NO
void updateRollNo(Node* &head,const string& nameOfStudent,int rollnoOfStudent,int updatedrollno){
    if(!head){
        cout<<"\t ****** THERE IS NO RECORD PRESENT RIGHT NOW ******"<< endl;
        return;
    }

    Node* temp = head;

    while(temp){
        if((temp->s).getRollNo() == rollnoOfStudent && (temp->s).getName() == nameOfStudent){
            break;
        }else{
            temp = temp->next;
        }
    }
    if(!temp){
        cout<<"\t ****** THERE IS NO RECORD BY NAME "<<nameOfStudent<<"and ROLL-NO. "<< rollnoOfStudent<<" ******"<< endl;
        return;
    }
    (temp->s).setRollNo(updatedrollno);
    cout<<" Roll number has been successfully updated "<<endl;
}

// UPDATE FUNCTION FOR MARKS
void updateMarks(Node* &head,const string& nameOfStudent,int rollnoOfStudent,const string& sub,double updatedmark){
    if(!head){
        cout<<"\t ****** THERE IS NO RECORD PRESENT RIGHT NOW ******"<< endl;
        return;
    }

    Node* temp = head;

    while(temp){
        if((temp->s).getRollNo() == rollnoOfStudent && (temp->s).getName() == nameOfStudent){
            break;
        }else{
            temp = temp->next;
        }
    }
    if(!temp){
        cout<<"\t ****** THERE IS NO RECORD BY NAME "<<nameOfStudent<<"and ROLL-NO. "<< rollnoOfStudent<<" ******"<< endl;
        return;
    }
    (temp->s).setMarks(sub,updatedmark);
    cout<<" Marks has been successfully updated "<<endl;
}
Node* getTopper(Node* head){
    if(!head){
        cout<<"\t ****** THERE IS NO RECORD PRESENT RIGHT NOW ******"<< endl;
        return NULL;
    }

    cout<<"\t ***** TOPPER STUDENT *****\n";
    Node* temp = head;
    Node* topper = temp;
    while(temp){
        if((temp->s).getPercentage() > (topper->s).getPercentage()){
            topper = temp;
        }
        temp = temp->next;
    }

    return topper;
}

// CLEAR ALL RECORDS
void clearRecords(Node* &head,Node* &tail){

    Node* temp = head;

    while(temp){

        Node* nextNode = temp->next;

        delete temp;

        temp = nextNode;
    }

    head = NULL;
    tail = NULL;
}

// SAVE THE RECORDS IN .txt
void saveRecords(Node* head){

    ofstream fout("students.txt");

    if(!fout){
        cout<<"Error opening file\n";
        return;
    }

    Node* temp = head;

    while(temp){

        Student s = temp->s;

        // save student name
        fout<<s.getName()<<endl;

        // save roll number
        fout<<s.getRollNo()<<endl;

        // save number of subjects
        fout<<s.getMarks().size()<<endl;

        // save subject + marks
        for(auto pair : s.getMarks()){
            fout << pair.first << " " << pair.second << endl;
        }
        temp = temp->next;
    }

    fout.close();

    cout<<"Records saved successfully\n";
}


void loadRecords(Node* &head,Node* &tail){

    // remove previous records first
    clearRecords(head,tail);

    ifstream fin("students.txt");

    if(!fin){
        cout<<"No saved file found\n";
        return;
    }

    string name;

    while(getline(fin,name)){

        int rollno;
        fin>>rollno;

        int totalSubjects;
        fin>>totalSubjects;

        unordered_map<string,double> marks;

        for(int i=0;i<totalSubjects;i++){

            string sub;
            double mark;

            fin>>sub>>mark;

            marks[sub] = mark;
        }

        fin.ignore(
            numeric_limits<streamsize>::max(),
            '\n'
        );

        Student s(name,rollno,marks);

        AddStudentRecords(head,tail,s,false);
    }

    fin.close();

    cout<<"Records loaded successfully\n";
}

int main(){

    int choice;
    do{
        cout<<"\t What are you looking for.... !\n";
        cout<<"\t 1) ADD new students to the organization.\n";
        cout<<"\t 2) DISPLAY all students records.\n";
        cout<<"\t 3) SEARCH a student by NAME or ROLL-NO. .\n";
        cout<<"\t 4) DELETE or UPDATE students records.\n";
        cout<<"\t 5) FIND toppers.\n";
        cout<<"\t 6) SAVE AND LOAD.\n";
        cout<<"\t 7) Exits.\n";

        cout<<"\t Enter your choice :";
        cin>>choice;

        switch(choice){

            case 1 : {
                // ADD new students to the organization

                //student name
                string nameOfStudent;
                cout<<"\t Enter student name : ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin,nameOfStudent);

                //student rollno
                int rollnoOfStudent;
                cout<<"\t Enter student's ROLL-NO. : ";
                cin>> rollnoOfStudent;

                int sizeOfMarksArray ;
                cout<<"\t Enter number of subjects you have : ";
                cin>> sizeOfMarksArray;

                //students marks
                unordered_map<string,double> marks;
                for(int i=0;i<sizeOfMarksArray;i++){
                
                    string newsubject;
                    cout<<"Enter subject : ";
                    cin>> newsubject;
                    double obtainedmark;
                    cout<<"Enter marks of "<<newsubject<<" : ";
                    cin>>obtainedmark;
                    marks[newsubject] = obtainedmark;
                }

                Student student(nameOfStudent,rollnoOfStudent,marks);

                AddStudentRecords(head,tail,student,true);
                break;
            }
            case 2 : {
                // DISPLAY all students records
                Display(head);
                break;
            }
            case 3 : {
                // SEARCH a student by NAME or ROLL-NO
                int x;
                cout<<"Want to search student by 1)-name or 2)-rollno. : ";
                cin>>x;
                if(x == 1){
                    //student name
                    string nameOfStudent;
                    cout<<"\t Enter student name : ";
                    cin.ignore();
                    getline(cin,nameOfStudent);
                    searchByName(head,nameOfStudent);
                }
                else{
                    //student rollno
                    int rollnoOfStudent;
                    cout<<"\t Enter student's ROLL-NO. : ";
                    cin>> rollnoOfStudent;
                    searchByRollno(head,rollnoOfStudent);
                }
                
                break;
            }
            case 4 : {
                // DELETE or UPDATE students records
                int operation;

                cout << "\t 1) DELETE student\n";
                cout << "\t 2) UPDATE student\n";
                cout << "\t Enter your choice : ";
                cin >> operation;

                if(operation == 1){

                    // DELETE LOGIC

                    //student name
                    string nameOfStudent;
                    cout<<"\t Enter student name : ";
                    cin.ignore();
                    getline(cin,nameOfStudent);
                    
                    //student rollno
                    int rollnoOfStudent;
                    cout<<"\t Enter student's ROLL-NO. : ";
                    cin>> rollnoOfStudent;

                    EraseStudentRecords(head,tail,nameOfStudent,rollnoOfStudent);

                }else if(operation == 2){

                    // UPDATE LOGIC

                    //student name
                    string nameOfStudent;
                    cout<<"\t Enter student name : ";
                    cin.ignore();
                    getline(cin,nameOfStudent);
                    
                    //student rollno
                    int rollnoOfStudent;
                    cout<<"\t Enter student's ROLL-NO. : ";
                    cin>> rollnoOfStudent;

                    int updateValue;
                    cout<<"what do you want to update : 0)-name, 1)-rollno., 2)-marks : ";
                    cin>>updateValue;
 
                    if(updateValue == 0){
                        // call function to update name

                        string updatedname;
                        cout<<"\t Enter student's new name : ";
                        cin.ignore();
                        getline(cin,updatedname);

                        updateName(head,nameOfStudent,rollnoOfStudent,updatedname);

                    }else if(updateValue == 1){
                        // call function to update rollno

                        //student rollno
                        int updatedrollno;
                        cout<<"\t Enter student's ROLL-NO. : ";
                        cin>> updatedrollno;

                        updateRollNo(head,nameOfStudent,rollnoOfStudent,updatedrollno);

                    }else if(updateValue == 2){
                        // call function to update marks

                        string sub;double updatedmarks;
                        cout<<"Enter subject : ";
                        cin>> sub;
                        cout<<"Enter marks of "<<sub<<" : ";
                        cin>>updatedmarks;

                        updateMarks(head,nameOfStudent,rollnoOfStudent,sub,updatedmarks);
                    }

                }else{
                    cout << "\t Invalid Choice\n";
                }
                break;
            }
            case 5 : {
                // FIND toppers
                Node* topper = getTopper(head);
                if(topper)
                    Display(head,(topper->s).getName(),(topper->s).getRollNo());
                break;
            }
            case 6 : {
                // SAVE AND LOAD
                int option;

                cout<<"1) SAVE\n";
                cout<<"2) LOAD\n";
                cin>>option;

                if(option==1){
                    saveRecords(head);
                }
                else if(option==2){
                    loadRecords(head,tail);
                }else{
                    cout<<"Invalid Inputs !"<<endl;
                }
                break;
            }
            case 7 : {
                cout<<"\t Exiting....\n";
            }
        }

    }while(choice != 7);

    clearRecords(head,tail);
    
    cout<<endl;
    return 0;
}