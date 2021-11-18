// python code to generate this array:
// from functools import cache
// @cache
// def fib(n):
//      if n == 0: return 0
//      if n == 1 or n == 2: return 1
//      return fib(n - 1) + fib(n - 2) + fib(n - 3)
// print(f"int mem[] = {{ {', '.join((str(fib(i)) for i in range(38)))}  }};")

int mem[] = { 0, 1, 1, 2, 4, 7, 13, 24, 44, 81, 149, 274, 504, 927, 1705, 3136, 5768, 10609, 19513, 35890, 66012, 121415, 223317, 410744, 755476, 1389537, 2555757, 4700770, 8646064, 15902591, 29249425, 53798080, 98950096, 181997601, 334745777, 615693474, 1132436852, 2082876103 };

int tribonacci(int n){
    return mem[n];
}
