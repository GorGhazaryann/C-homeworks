#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[50];
    char surname[50];
    int id;
    float grade;
    struct Student* next;
} Student;

Student* head = NULL;

// Create a new student
Student* createStudent(char* name, char* surname, int id, float grade) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    strcpy(newStudent->name, name);
    strcpy(newStudent->surname, surname);
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = NULL;
    return newStudent;
}

// Add a new student
void addStudent(char* name, char* surname, int id, float grade) {
    Student* newStudent = createStudent(name, surname, id, grade);
    newStudent->next = head;
    head = newStudent;
    printf("Student added successfully.\n");
}

// Remove a student by ID
void removeStudent(int id) {
    Student *current = head, *previous = NULL;
    while (current != NULL) {
        if (current->id == id) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("Student with ID %d removed successfully.\n", id);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Student with ID %d not found.\n", id);
}

// Search for a student by ID
void searchStudent(int id) {
    Student* current = head;
    while (current != NULL) {
        if (current->id == id) {
            printf("Student Found:\nName: %s\nSurname: %s\nID: %d\nGrade: %.2f\n",
                   current->name, current->surname, current->id, current->grade);
            return;
        }
        current = current->next;
    }
    printf("Student with ID %d not found.\n", id);
}

// Display all students
void displayStudents() {
    Student* current = head;
    if (current == NULL) {
        printf("No students in the list.\n");
        return;
    }
    printf("Student Details:\n");
    while (current != NULL) {
        printf("Name: %s, Surname: %s, ID: %d, Grade: %.2f\n",
               current->name, current->surname, current->id, current->grade);
        current = current->next;
    }
}

// Calculate and display average grade
void displayAverageGrade() {
    Student* current = head;
    int count = 0;
    float sum = 0.0;
    if (current == NULL) {
        printf("No students to calculate average grade.\n");
        return;
    }
    while (current != NULL) {
        sum += current->grade;
        count++;
        current = current->next;
    }
    printf("Average Grade: %.2f\n", sum / count);
}

// Save student details to file
void saveToFile(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }
    Student* current = head;
    while (current != NULL) {
        fprintf(file, "%s,%s,%d,%.2f\n",
                current->name, current->surname, current->id, current->grade);
        current = current->next;
    }
    fclose(file);
    printf("Student details saved to %s.\n", filename);
}

// Read student details from file
void readFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file for reading.\n");
        return;
    }
    char name[50], surname[50];
    int id;
    float grade;
    while (fscanf(file, "%49[^,],%49[^,],%d,%f\n", name, surname, &id, &grade) == 4) {
        addStudent(name, surname, id, grade);
    }
    fclose(file);
    printf("Student details loaded from %s.\n", filename);
}

// Free all allocated memory
void freeMemory() {
    Student* current = head;
    while (current != NULL) {
        Student* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    int choice, id;
    char name[50], surname[50];
    float grade;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Student\n");
        printf("2. Remove Student\n");
        printf("3. Search Student\n");
        printf("4. Display All Students\n");
        printf("5. Display Average Grade\n");
        printf("6. Save to File\n");
        printf("7. Read from File\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter surname: ");
                scanf("%s", surname);
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter grade: ");
                scanf("%f", &grade);
                addStudent(name, surname, id, grade);
                break;
            case 2:
                printf("Enter ID to remove: ");
                scanf("%d", &id);
                removeStudent(id);
                break;
            case 3:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                searchStudent(id);
                break;
            case 4:
                displayStudents();
                break;
            case 5:
                displayAverageGrade();
                break;
            case 6:
                saveToFile("group_details.csv");
                break;
            case 7:
                readFromFile("group_details.csv");
                break;
            case 8:
                freeMemory();
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}