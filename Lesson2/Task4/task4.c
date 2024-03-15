#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_STUDENTS 3

typedef struct {
    char name[MAX_NAME_LENGTH];
    float finalGrade;
} Student;

void bubbleSort(Student *students, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (students[j].finalGrade < students[j + 1].finalGrade) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    Student students[MAX_STUDENTS] = {
        {"Paweł", 24.05f},
        {"Karol", 19.78f},
        {"Jan", 73.12f}
    };

    int numStudents = sizeof(students) / sizeof(students[0]);

    bubbleSort(students, numStudents);

    printf("Posortowana lista studentów:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Imię: %s, Ocena końcowa: %.2f\n", students[i].name, students[i].finalGrade);
    }

    return 0;
}