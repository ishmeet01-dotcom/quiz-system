#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OPTIONS 4
#define MAX_LENGTH 256
#define TOTAL_QUESTIONS 15

typedef struct {
    char question[MAX_LENGTH];
    char options[MAX_OPTIONS][MAX_LENGTH];
    int correct_option; // 0-based index
} QuizQuestion;

void loadQuestions(QuizQuestion *questions) {
    // Example questions — you can expand or update with fresh data
    strcpy(questions[0].question, "Who won the men's singles gold medal in badminton at the Tokyo 2020 Olympics?");
    strcpy(questions[0].options[0], "Viktor Axelsen");
    strcpy(questions[0].options[1], "Chen Long");
    strcpy(questions[0].options[2], "Kento Momota");
    strcpy(questions[0].options[3], "Anthony Ginting");
    questions[0].correct_option = 0;

    strcpy(questions[1].question, "Which country won the most badminton medals at Tokyo 2020?");
    strcpy(questions[1].options[0], "India");
    strcpy(questions[1].options[1], "China");
    strcpy(questions[1].options[2], "Indonesia");
    strcpy(questions[1].options[3], "Japan");
    questions[1].correct_option = 1;

    strcpy(questions[2].question, "Who won the women's singles gold medal at the Rio 2016 Olympics?");
    strcpy(questions[2].options[0], "Carolina Marin");
    strcpy(questions[2].options[1], "PV Sindhu");
    strcpy(questions[2].options[2], "Tai Tzu-ying");
    strcpy(questions[2].options[3], "Nozomi Okuhara");
    questions[2].correct_option = 0;

    // Add 12 more questions similarly...
    for (int i = 3; i < TOTAL_QUESTIONS; i++) {
        sprintf(questions[i].question, "Sample Question %d: Who is a famous badminton player?", i + 1);
        strcpy(questions[i].options[0], "Lin Dan");
        strcpy(questions[i].options[1], "Lee Chong Wei");
        strcpy(questions[i].options[2], "Saina Nehwal");
        strcpy(questions[i].options[3], "All of the above");
        questions[i].correct_option = 3;
    }
}

void runQuiz(QuizQuestion *questions) {
    int score = 0;
    int answer;

    for (int i = 0; i < TOTAL_QUESTIONS; i++) {
        printf("\nQ%d: %s\n", i + 1, questions[i].question);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("  %d. %s\n", j + 1, questions[i].options[j]);
        }

        printf("Your answer (1-4): ");
        scanf("%d", &answer);

        if (answer - 1 == questions[i].correct_option) {
            printf("✅ Correct!\n");
            score++;
        } else {
            printf("❌ Incorrect. Correct answer: %s\n", questions[i].options[questions[i].correct_option]);
        }
    }

    printf("\n🎉 Quiz Completed! Your Score: %d/%d\n", score, TOTAL_QUESTIONS);
}

int main() {
    QuizQuestion *questions = (QuizQuestion *)malloc(TOTAL_QUESTIONS * sizeof(QuizQuestion));
    if (questions == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    loadQuestions(questions);
    runQuiz(questions);

    free(questions);
    return 0;
}