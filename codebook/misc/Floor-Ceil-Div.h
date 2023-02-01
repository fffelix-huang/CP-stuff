long long floor_div(long long a, long long b) {
    return a / b - ((a ^ b) < 0 && a % b != 0);
}

long long ceil_div(long long a, long long b) {
    return a / b + ((a ^ b) > 0 && a % b != 0);
}
