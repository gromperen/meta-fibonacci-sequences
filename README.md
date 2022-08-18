# Plotting Hofstadter Sequences and Meta-Fibonacci Recurrences using ROOT

For general info refer to [Hofstadter Sequences Wikipedia](https://en.wikipedia.org/wiki/Hofstadter_sequence)
All graphs drawn with [ROOT](https://root.cern/)


## [Hofstadter Q-sequence](https://oeis.org/A005185)

```math
Q(1) = Q(2) = 1
Q(n) = Q(n-Q(n-1)) + Q(n-Q(n-2))
```

$ Plot of Q(n) for n <= 1e7 $
![plot](/images/Q1,png)

$ Plot of Q(n) - n/2 for n <= 1e7 $
![plot](images/Q2,png)

## Hofstadter-Conway C-sequence

```math
C(1) = C(2) = 1
C(n) = C(C(n-1)) + C(n-C(n-1))
```

$ Plot of C(n) for n <= 1e7 $
![plot](images/C1,png)

$ Plot of C(n) - n/2 for n <= 1e7 $
![plot](images/C2,png)

## Hofstadter Heart Sequence
```math
H(n) = C(n) - Q(n)
```


$ Plot of H(n) for n <= 1e7 $
![plot](images/H1,png)


## [A055748](http://oeis.org/A055748)

```math
B(1) = B(2) = 1
B(n) = B(B(n-1)) + B(n - B(n-2) - 1)
```

$ Plot of B(n) for n <= 1e7 $
![plot](images/B1,png)

TODO:
$ Plot of B(n)/n for n <= 1e7 $

## 3D Poincaré(-ish) Plot of H

Plotting points $ (x,H(x), H(x+1)) $ (just because it looks cool)

![plot](images/PCH,png)

To view in 3D edit geb.C to draw gr6 and run using root.

## 3D Poincaré(-ish) Plot of B

![plot](images/PCB,png)


Plotting points $ (B(x),B(x+1), B(x+2)) $ (just because it looks cool)

To view in 3D edit geb.C to draw gr7 and run using root.
