#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

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
    struct subjects *next;
} subject_regist;


typedef struct periods{
    float period;
    vector<int> subjs_id;
    struct periods *next;
} period_schedule;


typedef struct student_subj{
    float period;
    string student_id;
    vector<string> subjs_id;
    struct student_subj *next;
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


void search_std_subj(student_subj** rptr, subjects **sptr){
    // search student's subject by its ID and its period

    string search_std_id;
    float search_period;
    student_subj *it_ptr = *rptr;
    subjects *sec_it_ptr = *sptr;
    int is_found = 0;

    cout << "Please insert the ID of the student";
    cin >>  search_std_id;
    cout << "Please insert the period you wan't to search for";
    cin >> search_period;

    if (rptr == NULL){
        // empty struct
        cout << "Empty database";
        return;
    }
    else{
        while(it_ptr != NULL){
            if (((*it_ptr).period == search_period) && ((*it_ptr).student_id == search_std_id)){
                is_found = 1;
                for(unsigned int i=0; i < (*it_ptr).subjs_id.size(); i++){
                    while(sec_it_ptr != NULL){
                        if ((*sec_it_ptr).subj_id == (*it_ptr).subjs_id[i]){
                            cout << (*sec_it_ptr).name << " -> " << (*sec_it_ptr).teacher << " -> " << (*sec_it_ptr).credits << "\n";
                        }
                        sec_it_ptr = (*sec_it_ptr).next;
                    }
                    sec_it_ptr = *sptr;
                }
            }
            it_ptr = (*it_ptr).next;
        }
        if (is_found == 0){
            cout << "Pair ID/period not found";
        }
    }
}


void search_subj_std(student_subj** rptr, students** sptr){

    float search_period;
    string search_subj_id;
    vector<string> student_list;
    student_subj* it_ptr = *rptr;
    students* sec_it_ptr = *sptr;
    int is_found = 0;

    cout << "Please insert the ID of the subject";
    cin >>  search_subj_id;
    cout << "Please insert the period you wan't to search for";
    cin >> search_period;

    if (rptr == NULL){
        // empty struct
        cout << "Empty database";
        return;
    }
    else{
        while(it_ptr != NULL){
            if (((*it_ptr).period == search_period) && (count((*it_ptr).subjs_id.begin(), (*it_ptr).subjs_id.end(), search_subj_id) >= 1)){
                student_list.push_back((*it_ptr).student_id);
                is_found = 1;
            }
            it_ptr = (*it_ptr).next;
        }
        for(unsigned int i=0; i < student_list.size(); i++){
            while(sec_it_ptr != NULL){
                if((*sec_it_ptr).student_id == student_list[i]){
                    cout << (*sec_it_ptr).name << " -> " << (*sec_it_ptr).cpf << "\n";
                }
                sec_it_ptr = (*sec_it_ptr).next;
            }
            sec_it_ptr = *sptr;
        }
        if (is_found == 0){
            cout << "There's no student registered for this subject";
        }
    }
}


void selection_menu(){

}


int main(){

}

