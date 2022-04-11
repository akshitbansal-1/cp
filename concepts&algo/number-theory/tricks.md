## Wilson theorem
---
If p is a prime number then
```
(p-1)! % p = p - 1
```

## Mod m
* Add -> (a + b) % m = ((a%m) + (b%m))%m or (a+b)%m
* Mul -> (a * b) % m = ((a%m) * (b%m))%m
* Sub -> (a - b) % m = ((a-b+m))%m
* Div -> (a / b) % m = **(a * b ^ (m - 2)) % m**, (b ^ (m - 2)) can be done in log with exp, if **m is prime**
* Pow -> a^b % m = if a is very large then mul for b times, if b is large then **a^(b%(m-1))%m**




