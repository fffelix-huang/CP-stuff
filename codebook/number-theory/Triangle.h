// https://atcoder.jp/contests/abc315/submissions/44720694
// Counts x, y >= 0 such that Ax + By <= C. Requires A, B > 0. Runs in log time.
// Also representable as sum_{0 <= x <= C / A} floor((C - Ax) / B + 1).
// See "A Simple Algorithm for Lattice Point Counting in Rational Polygons" by Hiroki Yanagisawa.
long long count_triangle(long long A, long long B, long long C) {
    if (C < 0) return 0;
    if (A < B) swap(A, B);
    long long m = C / A;
    long long h = (C - m * A) / B + 1;
    long long k = A / B;
    return m * (m + 1) / 2 * k + (m + 1) * h + count_triangle(B, A - k * B, C - B * (k * m + h));
}
 
// Counts 0 <= x < RA, 0 <= y < RB such that Ax + By <= C. Requires A, B > 0.
long long count_triangle_rectangle_intersection(long long A, long long B, long long C, long long RA, long long RB) {
    if (C < 0 || RA <= 0 || RB <= 0) return 0;
    if (C >= A * (RA - 1) + B * (RB - 1)) return RA * RB;
    return count_triangle(A, B, C) - count_triangle(A, B, C - A * RA) - count_triangle(A, B, C - B * RB);
}
