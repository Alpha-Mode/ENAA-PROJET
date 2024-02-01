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
void modifyTaskStatus() {
    int taskIndex;
    printf("Entrez le num�ro de la t�che � modifier le status: ");
    scanf("%d", &taskIndex);

    if (taskIndex > 0 && taskIndex <= taskCount) {
        printf("Entrez la nouvelle status : ");
        scanf("%d", &taskList[taskIndex - 1].status);

        printf("T�che modifi�e avec succ�s!\n");
    } else {
        printf("Num�ro de t�che invalide!\n");
    }
}

void deleteTask() {
    int taskIndex;
    printf("Entrez le num�ro de la t�che � supprimer : ");
    scanf("%d", &taskIndex);

    if (taskIndex > 0 && taskIndex <= taskCount) {
        for (int i = taskIndex - 1; i < taskCount - 1; i++) {
            taskList[i] = taskList[i + 1];
        }

        taskCount--;
        printf("T�che supprim�e avec succ�s!\n");
    } else {
        printf("Num�ro de t�che invalide!\n");
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

    printf("T�ches tri�es par date d'�ch�ance (ordre croissant)!\n");
}

void filterByPriority() {
    int priorityFilter;
    printf("Entrez la priorit� � filtrer (1-5) : ");
    scanf("%d", &priorityFilter);

    printf("\nT�ches avec priorit� %d :\n", priorityFilter);
    for (int i = 0; i < taskCount; i++) {
        if (taskList[i].priority == priorityFilter) {
            printf("Description : %s, Date d'�ch�ance : %s, Priorit� : %d, Statut : %s\n",
                   taskList[i].description, taskList[i].deadline, taskList[i].priority,
                   taskList[i].status ? "Compl�te" : "Incompl�te");
        }
    }
}

void filterByStatus() {
    int statusFilter;
    printf("Entrez le statut � filtrer (0 pour incompl�te, 1 pour compl�te) : ");
    scanf("%d", &statusFilter);

    printf("\nT�ches avec statut %s :\n", statusFilter ? "Compl�te" : "Incompl�te");
    for (int i = 0; i < taskCount; i++) {
        if (taskList[i].status == statusFilter) {
            printf("Description : %s, Date d'�ch�ance : %s, Priorit� : %d, Statut : %s\n",
                   taskList[i].description, taskList[i].deadline, taskList[i].priority,
                   taskList[i].status ? "Compl�te" : "Incompl�te");
        }
    }
}

int main() {
    int choice;

    do {
        printf("\n===== Application de Gestion de T�ches =============\n");
        printf("	1. Ajouter une T�che\n");
        printf("	2. Afficher la Liste des T�ches\n");
        printf("	3. Modifier une T�che\n");
        printf("	4. Modifier le status de la T�che\n");
        printf("	5. Ordonner les T�ches par Date d'�ch�ance\n");
        printf("	6. Filtrer les T�ches par Priorit�\n");
        printf("	7. Filtrer les T�ches par Statut\n");
        printf("	8. Supprimer une T�che\n");
        printf("	0. Quitter l'Application\n");
        printf("===================================================\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                displayTasks();
                break;
            case 3:
                modifyTask();
                break;
            case 4:
                modifyTaskStatus();
                break;
            case 5:
                sortByDeadline();
                break;
            case 6:
                filterByPriority();
                break;
            case 7:
                filterByStatus();
                break;
            case 8:
                deleteTask();
                break;
            case 0:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide. Veuillez r�essayer.\n");
        }
    } while (choice != 0);

    return 0;
}
