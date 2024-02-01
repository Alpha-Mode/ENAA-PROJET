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
    printf("Entrez la description de la tâche : ");
    scanf("%s", newTask.description);
    printf("Entrez la date d'échéance (AAAA/MM/JJ) : ");
    scanf("%s", newTask.deadline);
    printf("Entrez la priorité (1-5) : ");
    scanf("%d", &newTask.priority);
    newTask.status = 0; 

    taskList[taskCount++] = newTask;
    printf("Tâche ajoutée avec succès!\n");
}

    printf("\nListe des tâches :\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. Description : %s, Date d'échéance : %s, Priorité : %d, Statut : %s\n",
               i + 1, taskList[i].description, taskList[i].deadline, taskList[i].priority,
               taskList[i].status ? "Complète" : "Incomplète");
    }
}
