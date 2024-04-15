#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;


typedef struct students{
    string student_id;
    string name;
    string cpf;
    students *next;
} student_regist;

typedef struct subjects{
    string subj_id;
    string name;
    string teacher;
    float credits;
    subjects *next;
} subject_regist;

typedef struct periods{
    float period;
    vector<string> subjs_id;
    periods *next;
} period_schedule;

typedef struct student_subj{
    float period;
    string student_id;
    vector<int> subjs_id;
    student_subj *next;
} period_class;



subjects *lista=NULL;

struct subjects *busca_subjects (string id, struct subjects *lista, struct subjects **ant)
{
    struct subjects *aux=lista; 
    *ant = NULL;          

    while ( (aux != NULL) && (aux->subj_id != id))
    {
        *ant = aux;
        aux = aux->next;
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
        aux->next = NULL;
        if (ant == NULL)
            *lista = aux;
        else
            ant->next = aux;
        return 1;
    }   
}

void print_subjects (subjects *lista)
{
    struct subjects *aux = lista;
    
    while (aux != NULL)
    {
        cout << aux -> subj_id << endl << aux->name << endl << aux->teacher << endl << aux->credits << endl;
        aux = aux->next;
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
            *lista = aux->next;
            delete (aux);
            return 1;
        }
        else
        {
            ant->next = aux->next;
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
        aux = aux->next;
    }
    return aux;
}

int inserir_periods (float period, vector<string> ids , struct periods **listap, subjects *lista){

    for (string id : ids) {
            subjects *ant;
            subjects *subject_aux = busca_subjects(id, lista, &ant);
            if (subject_aux == NULL) {
                cout << "subject " << id << " not found. Please register it" << endl;
                return 0;
            }
    }
        
    
    struct periods *aux=NULL;
    struct periods *ant=NULL;
    
    aux = busca_periods (period, *listap, &ant);
    
    if (aux != NULL)
        return 0;
    else
    {
        aux = new periods;
        aux->period = period;
        aux->subjs_id = ids;
        aux->next = NULL;
        if (ant == NULL)
            *listap = aux;
        else
            ant->next = aux;
        return 1;
    }   
}

void print_periods (periods *lista)
{
    struct periods *aux = lista;
    
    while (aux != NULL)
    {
        cout << aux->period << endl;
        for (string id : aux->subjs_id) {
            cout << id << " ";
        }
        cout << endl;
        aux = aux->next;
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
            *listap = aux->next;
            delete (aux);
            return 1;
        }
        else
        {
            ant->next = aux->next;
            delete (aux);
            return 1;
        }
    }
}





void subjects_csv(subjects *lista) {
    ofstream arquivo("subjects.csv"); 
    
    if (arquivo.is_open()) { 
        subjects *aux = lista;
        while (aux != NULL) {
            arquivo << aux->subj_id << ",";
            arquivo << aux->name << ",";
            arquivo << aux->teacher << ",";
            arquivo << aux->credits << endl;
            aux = aux->next;
        }
        arquivo.close(); 
    } else {
        cout << "Erro ao abrir o arquivo 'assuntos.csv' para escrita." << endl;
    }
}

void periods_csv(periods *listap) {
    ofstream arquivo("periods.csv"); 
    
    if (arquivo.is_open()) { 
        periods *aux = listap;
        while (aux != NULL) {
            arquivo << aux->period << ",";
            for (size_t i = 0; i < aux->subjs_id.size(); ++i) {
                arquivo << aux->subjs_id[i];
                if (i != aux->subjs_id.size() - 1) {
                    arquivo << ",";
                }
            }
            arquivo << endl;
            aux = aux->next;
        }
        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo 'periodos.csv' para escrita." << endl;
    }
}















void register_period(period_class* cptr, subjects* sptr){
}


void selection_menu(){

}


int main(){
    inserir_subjects ("2411","Matematica discreta", "Veloso", 100, &lista);
    inserir_subjects ("2412","Sitemas Digitais", "Rotava", 100, &lista);
    inserir_subjects ("2321","Calculo 3", "Lima Vaz", 100, &lista);
    print_subjects(lista);
    inserir_periods (24.1,{"2411", "2412"} ,&listap, lista);
    inserir_periods (23.2,{"2321"} ,&listap, lista);
    print_periods(listap);
    /*remove_subject("2401", &lista);
    remove_period(23.2, &listap);
    print_subjects(lista);
    print_periods(listap);*/
    periods_csv(listap);
    subjects_csv(lista);
}