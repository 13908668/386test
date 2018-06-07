#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define INTEG_FUNC(x)  fabs(sin(x))
double dclock(void);
int main(int argc, char * argv[])
{
  clock_t start, finish;
  double  duration;  
  long * pi, * t, m, n, r, s;
  int t0[][3] = {48, 32, 20, 24, 8, 4}, k0[][3] = {1, 1, 0, 1, 1, 1};
  int n0[][3] = {18, 57, 239, 8, 57, 239}, d, i, j, k, p, q;

  d = (argc > 1) ? (((i = atoi(argv[1])) < 0) ? 0 : i) : 9999;
  q = (argc > 2) ? 1 : 0;
  printf("%s\n\n", "pi calc..................................");
  printf("pi= %s%d * arctg(1/%d) %s %d * arctg(1/%d) %s %d * arctg(1/%d) [%s]\n",
    k0[q][0] ? "" : "-", t0[q][0], n0[q][0], k0[q][1] ? "+" : "-", t0[q][1],
    n0[q][1], k0[q][2] ? "+" : "-", t0[q][2], n0[q][2], q ? "Stomer" : "Gauss");
  if ((t = (long *)calloc((d += 5) + 1, sizeof(long))) == NULL) return 1;
  if ((pi = (long *)calloc(d + 1, sizeof(long))) == NULL) return 2;

  start = clock();

  for (i = d; i >= 0; i--) pi[i] = 0;
  for (p = 0; p < 3; p++) {
    for (k=k0[q][p], n=n0[q][p], t[i=j=d]=t0[q][p], i--; i >= 0; i--) t[i] = 0;
    for (r = 0, i = j; i >= 0; i--) {
      r = (m = 10 * r + t[i]) % n;
      t[i] = m / n;
      k ? (pi[i] += t[i]) : (pi[i] -= t[i]);
    }
    while (j > 0 && t[j] == 0) j--;
    for (k = !k, s = 3, n *= n; j > 0; k = !k, s += 2) {
      for (r = 0, i = j; i >= 0; i--) {
        r = (m = 10 * r + t[i]) % n;
        t[i] = m / n;
      }
      while (j > 0 && t[j] == 0) j--;
      for (r = 0, i = j; i >= 0; i--) {
        r = (m = 10 * r + t[i]) % s;
        m /= s;
        k ? (pi[i] += m) : (pi[i] -= m);
      }
    }
  }
  for (n = i = 0; i <= d; pi[i++] = r) {
    n = (m = pi[i] + n) / 10;
    if ((r = m % 10) < 0) r += 10, n--;
  }
 
  printf("pi= %ld.", pi[d]);
  for (i = d - 1; i >= 5; i--)
    printf("%ld%s", pi[i], ((m = d - i + 5) % 65) ? ((m % 5) ? "" : " ") : "\n");
  printf("%sDIGITS: %d\n", (m % 65) ? "\n" : "", d - 5);
 
 //_______________________________________
 // Loop counters and number of interior points
   unsigned int ia, ja, Na;
   // Stepsize, independent variable x, and accumulated sum
   double  duration2;
   double stepa, x_i, suma;
   // Timing variables for evaluation   
   double interval_begin = 0.0;
   // Complete integral at 
   double interval_end = 2.0 * 3.141592653589793238;
   // Start timing for the entire application
   printf("     \n");
   printf("    Number of    | Computed Integral | \n");
   printf(" Interior Points |                   | \n");
   for (ja=2;ja<27;ja++)
   {
    printf("------------------------------------- \n");
     // Compute the number of (internal rectangles + 1)
     Na =  1 << ja;
     // Compute stepsize for Na-1 internal rectangles 
     stepa = (interval_end - interval_begin) / Na;
     // Approx. 1/2 area in first rectangle: f(x0) * [stepa/2] 
     suma= INTEG_FUNC(interval_begin) * stepa / 2.0;
     // Apply midpoint rule:
     // Given length = f(x), compute the area of the
     // rectangle of width stepa
     // Suma areas of internal rectangle: f(xi + stepa) * stepa
     for (ia=1;ia<Na;ia++)
     {
        x_i = ia * stepa;
        suma += INTEG_FUNC(x_i) * stepa;
     }
     // Approx. 1/2 area in last rectangle: f(xN) * [stepa/2] 
     suma += INTEG_FUNC(interval_end) * stepa / 2.0;
     printf(" %10d      |  %14e   | \n", Na, suma);
   }
  
  
   printf("     \n");
  
  
    //_______________________________________
  double  duration1;  
  double  testa;
  double  testb;
    int  sum=0;
    int  num=1;
    int  sum2=0;
    int  num2=2;
	double   sqrt(double   x);
  
    while(num<=90000000){
        sum=sum+num;
        num=num+2;
        testa=sqrt(sum);
        testa=testa*num;
    }
    printf("Anti cheating verification code is=:%d\n",sum);
    printf("Floating-point precision %.38lf\n", testa);
    while(num2<=90000000){
        sum2=sum2+num2;
        num2=num2+2;
        testb=sqrt(sum2);
        testb=testb*num2;
    }
  printf("Anti cheating verification code is=：%d\n",sum2);
  printf("Floating-point precision %.38lf\n", testb);
  finish = clock();
  duration = (double)(finish - start) / CLOCKS_PER_SEC;  
  printf("Total time %f seconds \n", duration);
  printf("The less the time it is used, the more the performance becomes strongert!\n");
  printf("Press Enter to exit\n");
  sum = getchar( );
  return 0;

  
}
