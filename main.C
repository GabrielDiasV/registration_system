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
    subjects *prox_subject;
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

subjects *lista=NULL;

subjects *busca_subjects (string name, struct subjects *lista, struct subjects **ant)
{
    struct subjects *aux=lista; 
    *ant = NULL;          

    while ( (aux != NULL) && (aux->name != name))
    {
        *ant = aux;
        aux = aux->prox_subject;
    }
    return aux;
}

int inserir_subjects (string id, string name, string teacher, float credits, struct subjects **lista){
    struct subjects *aux=NULL;
    struct subjects *ant=NULL;
    
    aux = busca_subjects (name, *lista, &ant);
    
    if (aux != NULL)
        return 0;
    else
    {
        aux = new subjects;
        aux->subj_id = id;
        aux->name = name;
        aux->teacher = teacher;
        aux->credits = credits;
        aux->prox_subject = NULL;
        if (ant == NULL)
            *lista = aux;
        else
            ant->prox_subject = aux;
        return 1;
    }   
}

void print_subjects (subjects *lista)
{
    struct subjects *aux = lista;
    
    while (aux != NULL)
    {
        cout << aux -> subj_id << endl << aux->name << endl << aux->teacher << endl << aux->credits;
        aux = aux->prox_subject;
    }
    cout << "\n";
}




void register_period(period_class* cptr, subjects* sptr){
}


void selection_menu(){

}


int main(){
    inserir_subjects ("2401","Matematica discreta", "Veloso", 100, &lista);
    print_subjects(lista);
}