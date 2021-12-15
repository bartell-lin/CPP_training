The maximun a b-bit integer can be is $2^b$. 
With this we have $F(n) < 2^b$

Using Binet's formula, we have $F(n) = (\phi^n - \psi^n)/(\phi - \psi)$ where $\phi = (1 + \sqrt{5})/2$ and $\psi = 1 - \phi = -1/\phi$

We can see that as n grows, the term $\psi^n$ converges to 0 so we can ignore it. 
So now we have:
$(\phi^n )/(\phi - \psi) < 2^b$
$(\phi^n )/(\phi - (1 - \phi)) < 2^b$
$(\phi^n )/(2\phi - 1) < 2^b$
$(\phi^n )/(2((1 + \sqrt{5})/2) - 1) < 2^b$
$(\phi^n )/(\sqrt{5}) < 2^b$
$\phi^n  < 2^b * \sqrt{5}$
$nlog(\phi) < b*log(2) + .5*log(5)$
$n < (b*log(2) + .5*log(5)) / log(\phi)$

From here, you just plug in b to get the value of n. In the case of int32, n < 46.32 so you could represent F(47) with that.
A long has 63 bits so n < 92.42. That mean F(93) would be the largest Fibonacci term in a long.