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

void displayTasks() {
    printf("\nListe des tâches :\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. Description : %s, Date d'échéance : %s, Priorité : %d, Statut : %s\n",
               i + 1, taskList[i].description, taskList[i].deadline, taskList[i].priority,
               taskList[i].status ? "Complète" : "Incomplète");
    }
}

void modifyTask() {
    int taskIndex;
    printf("Entrez le numéro de la tâche à modifier : ");
    scanf("%d", &taskIndex);

    if (taskIndex > 0 && taskIndex <= taskCount) {
        printf("Entrez la nouvelle description : ");
        scanf("%s", taskList[taskIndex - 1].description);
        printf("Entrez la nouvelle date d'échéance (AAAA/MM/JJ) : ");
        scanf("%s", taskList[taskIndex - 1].deadline);
        printf("Entrez la nouvelle priorité (1-5) : ");
        scanf("%d", &taskList[taskIndex - 1].priority);

        printf("Tâche modifiée avec succès!\n");
    } else {
        printf("Numéro de tâche invalide!\n");
    }
}
void modifyTaskStatus() {
    int taskIndex;
    printf("Entrez le numéro de la tâche à modifier le status: ");
    scanf("%d", &taskIndex);

    if (taskIndex > 0 && taskIndex <= taskCount) {
        printf("Entrez la nouvelle status : ");
        scanf("%d", &taskList[taskIndex - 1].status);

        printf("Tâche modifiée avec succès!\n");
    } else {
        printf("Numéro de tâche invalide!\n");
    }
}

void deleteTask() {
    int taskIndex;
    printf("Entrez le numéro de la tâche à supprimer : ");
    scanf("%d", &taskIndex);

    if (taskIndex > 0 && taskIndex <= taskCount) {
        for (int i = taskIndex - 1; i < taskCount - 1; i++) {
            taskList[i] = taskList[i + 1];
        }

        taskCount--;
        printf("Tâche supprimée avec succès!\n");
    } else {
        printf("Numéro de tâche invalide!\n");
    }
}

void sortByDeadline() {
    for (int i = 0; i < taskCount - 1; i++) {
        for (int j = 0; j < taskCount - i - 1; j++) {
            if (strcmp(taskList[j].deadline, taskList[j + 1].deadline) > 0) {
                struct Task temp = taskList[j];
                taskList[j] = taskList[j + 1];
                taskList[j + 1] = temp;
            }
        }
    }

    printf("Tâches triées par date d'échéance (ordre croissant)!\n");
}

void filterByPriority() {
    int priorityFilter;
    printf("Entrez la priorité à filtrer (1-5) : ");
    scanf("%d", &priorityFilter);

    printf("\nTâches avec priorité %d :\n", priorityFilter);
    for (int i = 0; i < taskCount; i++) {
        if (taskList[i].priority == priorityFilter) {
            printf("Description : %s, Date d'échéance : %s, Priorité : %d, Statut : %s\n",
                   taskList[i].description, taskList[i].deadline, taskList[i].priority,
                   taskList[i].status ? "Complète" : "Incomplète");
        }
    }
}

void filterByStatus() {
    int statusFilter;
    printf("Entrez le statut à filtrer (0 pour incomplète, 1 pour complète) : ");
    scanf("%d", &statusFilter);

    printf("\nTâches avec statut %s :\n", statusFilter ? "Complète" : "Incomplète");
    for (int i = 0; i < taskCount; i++) {
        if (taskList[i].status == statusFilter) {
            printf("Description : %s, Date d'échéance : %s, Priorité : %d, Statut : %s\n",
                   taskList[i].description, taskList[i].deadline, taskList[i].priority,
                   taskList[i].status ? "Complète" : "Incomplète");
        }
    }
}
