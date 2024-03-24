#include <iostream>
#include <string>
#include <vector>

using namespace std;


typedef struct students{
    string student_id;
    string name;
    string cpf;
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


void register_period(period_class* cptr, subjects* sptr){
}


void selection_menu(){

}


int main(){

}

