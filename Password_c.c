#include <stdio.h>
#include <string.h>

int count_upper(char password[], int len) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            count++;
        }
    }
    return count;
}

int count_lower(char password[], int len) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            count++;
        }
    }
    return count;
}

int count_digit(char password[], int len) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            count++;
        }
    }
    return count;
}

int count_special(char password[], int len) {
    char specials[] = "!@#$%^&*(),.?\":{}|<>";
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = 0; specials[j] != '\0'; j++) {
            if (password[i] == specials[j]) {
                count++;
            }
        }
    }
    return count;
}

void check_password_policy(char password[]) {
    int len = strlen(password);
    int upper = count_upper(password, len);
    int lower = count_lower(password, len);
    int digit = count_digit(password, len);
    int special = count_special(password, len);

    if (len >= 16 && upper >= 4 && lower >= 4 && digit >= 4 && special >= 4) {
        printf("Password is Too Strong.\n");
        return;
    }

    if (len < 9) {
        printf("Password must be at least 9 characters long.\n");
        return;
    }
    if (upper < 1) {
        printf("Password must contain at least one uppercase letter.\n");
        return;
    }
    if (lower < 1) {
        printf("Password must contain at least one lowercase letter.\n");
        return;
    }
    if (digit < 1) {
        printf("Password must contain at least one digit.\n");
        return;
    }
    if (special < 1) {
        printf("Password must contain at least one special character (!@#$%%^&*(),.?\":{}|<>).\n");
        return;
    }

    printf("Password is Strong.\n");
}

int main() {
    char password[256];

    printf("Welcome to the Password Validator!\n\n");
    printf("Please enter a password that meets the following requirements:\n");
    printf(" - At least 9 characters long\n");
    printf(" - At least one uppercase letter\n");
    printf(" - At least one lowercase letter\n");
    printf(" - At least one digit\n");
    printf(" - At least one special character (!@#$%%^&*(),.?\":{}|<>)\n");
    printf(" - For 'Too Strong': At least 16 characters with 4 uppercase, 4 lowercase, 4 digits, 4 special characters\n\n");

    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);

    // Remove newline character if it exists
    int len = strlen(password);
    if (password[len - 1] == '\n') {
        password[len - 1] = '\0';
    }

    check_password_policy(password);

    return 0;
}
