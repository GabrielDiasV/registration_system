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
    periods *prox_period;
} period_schedule;


typedef struct student_subj{
    float period;
    string student_id;
    vector<int> subjs_id;
} period_class;



subjects *lista=NULL;

struct subjects *busca_subjects (string id, struct subjects *lista, struct subjects **ant)
{
    struct subjects *aux=lista; 
    *ant = NULL;          

    while ( (aux != NULL) && (aux->subj_id != id))
    {
        *ant = aux;
        aux = aux->prox_subject;
    }
    return aux;
}

int inserir_subjects (string id, string name, string teacher, float credits, struct subjects **lista){
    struct subjects *aux=NULL;
    struct subjects *ant=NULL;
    
    aux = busca_subjects (id, *lista, &ant);
    
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
        cout << aux -> subj_id << endl << aux->name << endl << aux->teacher << endl << aux->credits << endl;
        aux = aux->prox_subject;
    }
    cout << "\n";
}

int remove_subject (string id, struct subjects **lista)
{
    struct subjects *aux = NULL;
    struct subjects *ant = NULL;
    
    aux = busca_subjects (id, *lista, &ant);
    
    if (aux == NULL)
        return 0;
    else
    {
        if (ant == NULL)
        {
            *lista = aux->prox_subject;
            delete (aux);
            return 1;
        }
        else
        {
            ant->prox_subject = aux->prox_subject;
            delete (aux);
            return 1;
        }
    }
}







periods *listap=NULL;

struct periods *busca_periods (float period, struct periods *lista, struct periods **ant)
{
    struct periods *aux=lista; 
    *ant = NULL;          

    while ( (aux != NULL) && (aux->period != period))
    {
        *ant = aux;
        aux = aux->prox_period;
    }
    return aux;
}

int inserir_periods (float period, vector<int> ids , struct periods **lista){
    struct periods *aux=NULL;
    struct periods *ant=NULL;
    
    aux = busca_periods (period, *lista, &ant);
    
    if (aux != NULL)
        return 0;
    else
    {
        aux = new periods;
        aux->period = period;
        aux->subjs_id = ids;
        aux->prox_period = NULL;
        if (ant == NULL)
            *lista = aux;
        else
            ant->prox_period = aux;
        return 1;
    }   
}

void print_periods (periods *lista)
{
    struct periods *aux = lista;
    
    while (aux != NULL)
    {
        cout << aux->period << endl;
        for (int id : aux->subjs_id) {
            cout << id << " ";
        }
        cout << endl;
        aux = aux->prox_period;
    }
    cout << "\n";
}

int remove_period (float period, struct periods **listap)
{
    struct periods *aux = NULL;
    struct periods *ant = NULL;
    
    aux = busca_periods (period, *listap, &ant);
    
    if (aux == NULL)
        return 0;
    else
    {
        if (ant == NULL) 
        {
            *listap = aux->prox_period;
            delete (aux);
            return 1;
        }
        else
        {
            ant->prox_period = aux->prox_period;
            delete (aux);
            return 1;
        }
    }
}







void register_period(period_class* cptr, subjects* sptr){
}


void selection_menu(){

}


int main(){
    inserir_subjects ("2401","Matematica discreta", "Veloso", 100, &lista);
    inserir_subjects ("2402","Sitemas Digitais", "Rotava", 100, &lista);
    print_subjects(lista);
    inserir_periods (24.1,{2401,2402} ,&listap);
    inserir_periods (23.2,{2301,2302,2303} ,&listap);
    print_periods(listap);
    remove_subject("2401", &lista);
    remove_period(23.2, &listap);
    print_subjects(lista);
    print_periods(listap);
}