#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Task {
    char description[100];
    char deadline[20];
    int priority;
    int status; 
};

struct Task taskList[100];
int taskCount = 0;

void addTask() {
    struct Task newTask;
    printf("Entrez la description de la t�che : ");
    scanf("%s", newTask.description);
    printf("Entrez la date d'�ch�ance (AAAA/MM/JJ) : ");
    scanf("%s", newTask.deadline);
    printf("Entrez la priorit� (1-5) : ");
    scanf("%d", &newTask.priority);
    newTask.status = 0; 

    taskList[taskCount++] = newTask;
    printf("T�che ajout�e avec succ�s!\n");
}

void displayTasks() {
    printf("\nListe des t�ches :\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. Description : %s, Date d'�ch�ance : %s, Priorit� : %d, Statut : %s\n",
               i + 1, taskList[i].description, taskList[i].deadline, taskList[i].priority,
               taskList[i].status ? "Compl�te" : "Incompl�te");
    }
}

void modifyTask() {
    int taskIndex;
    printf("Entrez le num�ro de la t�che � modifier : ");
    scanf("%d", &taskIndex);

    if (taskIndex > 0 && taskIndex <= taskCount) {
        printf("Entrez la nouvelle description : ");
        scanf("%s", taskList[taskIndex - 1].description);
        printf("Entrez la nouvelle date d'�ch�ance (AAAA/MM/JJ) : ");
        scanf("%s", taskList[taskIndex - 1].deadline);
        printf("Entrez la nouvelle priorit� (1-5) : ");
        scanf("%d", &taskList[taskIndex - 1].priority);

        printf("T�che modifi�e avec succ�s!\n");
    } else {
        printf("Num�ro de t�che invalide!\n");
    }
}
