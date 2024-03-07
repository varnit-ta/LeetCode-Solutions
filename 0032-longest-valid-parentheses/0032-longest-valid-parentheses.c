int max(int a, int b) {
    return (a > b) ? a : b;
}

int longestValidParentheses(char* s) {
    int len = strlen(s);
    if (len == 0 || len == 1) {
        return 0;
    }

    int* stack = (int*)malloc(len * sizeof(int));
    int top = -1;

    for (int i = 0; i < len; i++) {
        char c = s[i];

        if (c == '(') {
            stack[++top] = 0;
        } else if (c == ')') {
            if (top >= 0 && stack[top] == 0) {
                // When the previous element is "(" i.e. making "( )" pattern
                top--;
                stack[++top] = 2;
            } else if (top >= 0 && stack[top] != 0 && stack[top] != 1) {
                // When the previous element is num not in [0, 1] i.e. pattern is continuing
                int num = stack[top--];
                if (top >= 0 && stack[top] == 0) {
                    num += 2;
                    top--;
                    stack[++top] = num;
                } else {
                    stack[++top] = num;
                    stack[++top] = 1;
                }
            } else {
                stack[++top] = 1;
            }

            if (top >= 0 && stack[top] != 0 && stack[top] != 1) {
                int sum = 0;
                while (top >= 0 && stack[top] != 0 && stack[top] != 1) {
                    sum += stack[top--];
                }
                stack[++top] = sum;
            }
        }
    }

    int maxLen = 0;
    for (int i = 0; i <= top; i++) {
        if (stack[i] != 0 && stack[i] != 1) {
            maxLen = max(maxLen, stack[i]);
        }
    }

    free(stack);
    return maxLen;
}