/*
Implement atoi to convert a string to an integer.
*/
class Solution {
public:
    int atoi(const char *str) {
        if (!str) return 0;
        while (*str == ' ') str++;
        bool positive = true;
        if (*str == '+' || *str == '-') {
            positive = *str == '+';
            str++;
        }
        long long res = 0;
        while (isdigit(*str)) {
            res = res * 10 + (*str - '0');
            str++;
        }
        res = positive ? res : -res;
        if (res > INT_MAX) return INT_MAX;
        if (res < INT_MIN) return INT_MIN;
        return (int)res;
    }
};
class Solution1{
public:
    int atoi(const char *str) {
    int num = 0;
    int sign = 1;
    const int len = strlen(str);
    int i = 0;
    while (str[i] == ' ' && i < len) i++;
    if (str[i] == '+') i++;
    if (str[i] == '-') {
        sign = -1;
        i++;
    }
    for (; i < len; i++) {
        if (str[i] < '0' || str[i] > '9')
            break;
        if (num > INT_MAX / 10 ||
            (num == INT_MAX / 10 &&
            (str[i] - '0') > INT_MAX % 10)) {
            return sign == -1 ? INT_MIN : INT_MAX;
        }
        num = num * 10 + str[i] - '0';
    }
    return num * sign;
}
};