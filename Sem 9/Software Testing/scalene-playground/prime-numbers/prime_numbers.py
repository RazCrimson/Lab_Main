def is_prime_number(num: int) -> bool:
    if num <= 1:
        return False
    if num <= 3:
        return True
    if num % 2 == 0 or num % 3 == 0:
        return False
    i = 5
    while i * i <= num:
        if num % i == 0 or num % (i + 2) == 0:
            return False
        i += 6
    return True
   
 
def slightly_optimized_prime_in_first_n(n: int) -> list[int]:
    primes = [2, 3]
    for num in range(5, n + 1, 6):
        if is_prime_number(num):
            primes.append(num)
        if num + 2 <= n and is_prime_number(num + 2):
            primes.append(num + 2)
    return primes

# @profile
def sieve_of_eratosthenes(n: int) -> list[int]:
    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False

    p = 2
    while p * p <= n:
        if is_prime[p]:
            for i in range(p * p, n + 1, p):
                is_prime[i] = False
        p += 1

    primes = [i for i in range(2, n + 1) if is_prime[i]]
    return primes

if __name__ == '__main__':
   N = 1_000_000

   from scalene import scalene_profiler

   scalene_profiler.start()
   slightly_optimized_prime_in_first_n(N)
   scalene_profiler.stop()

   sieve_of_eratosthenes(N)