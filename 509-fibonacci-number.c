// python code to generate this array:
//  def fib(n):
//      if n == 0: return 0
//      if n == 1: return 1
//      return fib(n - 1) + fib(n - 2)
//  print(f"int mem[] = {{ {', '.join((str(fib(i)) for i in range(31)))}  }};")

int mem[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040 };

int fib(int n) {
    return mem[n];
}
