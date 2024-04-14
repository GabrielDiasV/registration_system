#include <iostream>
#include <string>
#include <vector>

using namespace std;


typedef struct students{
    string student_id;
    string name;
    string cpf;
    struct students *next; 
} student_regist;


typedef struct subjects{
    string subj_id;
    string name;
    string teacher;
    float credits;
} subject_regist;


typedef struct periods{
    float period;
    vector<int> subjs_id;
} period_schedule;


typedef struct student_subj{
    float period;
    string student_id;
    vector<int> subjs_id;
} period_class;


void register_student(student_regist** rptr){
    //append a new student in the end of the struct
     
    student_regist *new_regist;
    students *it_ptr;
    it_ptr = (**rptr).next;

    new_regist = new student_regist;
    cout << "Please insert students credentials \nID: ";
    cin >> (*new_regist).student_id;  
    cout << "\nName: ";
    cin >> (*new_regist).name;
    cout << "\nCPF: ";
    cin >> (*new_regist).cpf;

    if(*rptr == NULL){
        // Empty list
        *rptr = new_regist;
    }
    else{
        while((*it_ptr).next != NULL){
            it_ptr = (*it_ptr).next;
        }

        (*it_ptr).next = new_regist;
    }
}


void remove_student(student_regist** rptr){
    //remove student by its ID

    string removed_id;
    student_regist *it_ptr;
    student_regist *bin;
    it_ptr = (**rptr).next;
    int removed = 0;

    cout << "Please insert the ID you want to remove \nName: ";
    cin >> removed_id;

    if((**rptr).student_id == removed_id){
        *rptr = (**rptr).next;
    }
    else{
        while((*it_ptr).next != NULL){
            bin = (*it_ptr).next;

            if((*bin).student_id == removed_id){
                (*it_ptr).next = (*bin).next;
                delete bin;
                removed = 1;
            }
            it_ptr = (*it_ptr).next;
        }
    }
    if (removed == 1){
        cout << "Student removed";
    }
    else{
        cout << "Student not found";
    }
}


void selection_menu(){

}


int main(){

}

