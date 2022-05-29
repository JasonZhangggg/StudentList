/*
Jason Zhang
10/30/2019
Student List
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <math.h>
using namespace std;
//student struct
struct student{
  char firstName[80];
  char lastName[80];
  int id;
  float gpa;
};
void add(vector<student*>*sVec);
void deleteStudent(vector<student*>*sVec);
void printVec(vector<student*>*sVec);
int main(){
  //make the vector
  vector<student*>*sVec = new vector<student*>;
  while(true){
    //take in the users input
    char input[80];
    cout<<"Input ADD to add a student, PRINT to print the students, DELETE to delete a student, and QUIT to exit the program."<<endl;
    cin.getline(input, sizeof(input));
    //set it to upper case
    for(int i = 0; i<sizeof(input); i++){
      input[i] = toupper(input[i]);
    }
    //if they inputed ADD
    if(strcmp(input, "ADD") == 0){
      //call add
      add(sVec);
      cin.ignore(1000, '\n');
    }
    //if they inputed PRINT
    else if(strcmp(input, "PRINT") == 0){
      //call print
      printVec(sVec);
    }
    //if they inputed DELETE
    else if(strcmp(input, "DELETE") == 0){
      //run delete
      deleteStudent(sVec);
      cin.ignore(1000, '\n');
    }
    //if they inputed QUIT
    else if(strcmp(input, "QUIT") == 0){
      //return 0, exiting the program
      return 0;
    }
    else{
      cout<<"That is invalid."<< endl;
    }
  }
}
void add(vector<student*>*sVec){
  //add a new student to the vector
  sVec->push_back(new student());
  //prompt for last and first name, id, and gpa and add it to the vector
  cout<<"What is the first name of the student?"<<endl;
  cin.getline(sVec->at(sVec->size()-1)->firstName, 80);
  cout<<"What is the last name of the student?"<<endl;
  cin.getline(sVec->at(sVec->size()-1)->lastName, 80);    
  cout<<"What is the student's id?"<<endl;
  cin>>sVec->at(sVec->size()-1)->id;
  vector<student*>::iterator i;
  for(i = sVec->begin(); i!= sVec->end()-1;i++){
    if(sVec->at(sVec->size()-1)->id == (*i)->id){
      cout<<"That id is already taken"<<endl;
      sVec->erase(sVec->end()-1);
      return;
    }
  }
  cout<<"What is the student's gpa?"<<endl;
  cin>>sVec->at(sVec->size()-1)->gpa;
}
void deleteStudent(vector<student*>*sVec){
  //ask for id
  int newId;
  cout<<"What is the studenst's Id?"<<endl;
  cin>>newId;
  //loop through vector
  vector<student*>::iterator i;
  for(i = sVec->begin(); i!=sVec->end();i++){
    //if the id is found
    if(newId == (*i)->id){
      //erease it
      sVec->erase(i);
      //return
      return;
    }
  }
  //if student is not found, tell the user
  cout<<"Student not found"<<endl;
}
  
void printVec(vector<student*>*sVec){
  vector<student*>::iterator i;
  //loop through vector
  for(i=sVec->begin();i!=sVec->end();i++){
    //print first name, last name, id, and the gpa
    cout<<(*i)->firstName<<" "<<(*i)->lastName<<", "<<(*i)->id<<", "<<((float)((int)(((*i)->gpa)*100)))/100<<endl;
  }
}
