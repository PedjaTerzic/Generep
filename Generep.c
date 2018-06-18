#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

mpz_t b,s,N,M;
unsigned long  i,a,p;
char sign = 'p';

void P(mpz_t p , unsigned long m , mpz_t x){
mpz_t p0,p1;
unsigned long l;

mpz_set_ui(p,4);
mpz_init_set_ui(p0,2);
mpz_init_set(p1,x);
l=2;

while(l<=m)
{
mpz_mul(p,x,p1);
mpz_sub(p,p,p0);
mpz_set(p0,p1);
mpz_set(p1,p);
l=l+1;
}

}

int main(void)
{

mpz_t r,r1,r2;

printf("Positive or negative base? (p/n) : ");
sign = getchar();

printf("Enter the base :");
scanf("%lu",&a);
printf("Enter the exponent :");
scanf("%lu",&p);

mpz_init(r);
mpz_init(r1);
mpz_init(r2);
mpz_init(b);

mpz_set_ui(b,4);
P(r1,a,b);
mpz_init_set(s,r1);

if(sign =='p' || sign =='P')

{

mpz_init(N);
mpz_ui_pow_ui(N,a,p);
mpz_sub_ui(N,N,1);
mpz_cdiv_q_ui(N,N,a-1);

for (i = 1; i <= p-1; i++)
{
P(r,a,s);
mpz_mod(s,r,N);
}

if((a%12==3 || a%12==11) 
|| ((a%12==5  || a%12==9) && p%4==1) 
|| (a%12==7 && (p%12==1 || p%12==7 )) 
|| (a%12==1 && (p%12==1 || p%12==11 )))
{
P(r1,a,b);
mpz_sub(r1,r1,s);
if(mpz_divisible_p(r1,N)!=0)
{
printf("(%lu^%lu-1)/(%lu-1) is probably prime\n" , a,p,a);
}
else
{
printf("(%lu^%lu-1)/(%lu-1) is composite\n" , a,p,a);
}
mpz_clear(N);
mpz_clear(s);
}
else
{
P(r2,a-2,b);
mpz_sub(r2,r2,s);
if(mpz_divisible_p(r2,N)!=0)
{
printf("(%lu^%lu-1)/(%lu-1) is probably prime\n" , a,p,a);
}
else
{
printf("(%lu^%lu-1)/(%lu-1) is composite\n" , a,p,a);
}
mpz_clear(N);
mpz_clear(s);
}
}

else if(sign =='n' || sign =='N')
{
mpz_init(M);
mpz_ui_pow_ui(M,a,p);
mpz_add_ui(M,M,1);
mpz_cdiv_q_ui(M,M,a+1);

for (i = 1; i <= p-1; i++)
{
P(r,a,s);
mpz_mod(s,r,M);
}

if(((a%12==1 || a%12==9) 
|| ((a%12==3 || a%12==7) && p%4==1) 
|| (a%12==5 && (p%12==1 || p%12==7 )) 
|| (a%12==11 && (p%12==1 || p%12==11 ))))
{
P(r1,a,b);
mpz_sub(r1,r1,s);
if(mpz_divisible_p(r1,M)!=0)
{
printf("(%lu^%lu+1)/(%lu+1) is probably prime\n" , a,p,a);
}
else
{
printf("(%lu^%lu+1)/(%lu+1) is composite\n" , a,p,a);
}
mpz_clear(M);
mpz_clear(s);
}
else
{
P(r2,a+2,b);
mpz_sub(r2,r2,s);
if(mpz_divisible_p(r2,M)!=0)
{
printf("(%lu^%lu+1)/(%lu+1) is probably prime\n" , a,p,a);
}
else
{
printf("(%lu^%lu+1)/(%lu+1) is composite\n" , a,p,a);
}
mpz_clear(M);
mpz_clear(s);
}
}


return 0;
}

