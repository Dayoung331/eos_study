#include <stdio.h>
long long c4(a,b){
   long long a3;
   long long a33;
   long long a4;
   long long a5;
   long long a6;
   if(a >= 5 && b>=5){//1
      if(a>b){
         a3 = a - b;
      }
      else{
         a3 = b - a;
      }
      if(a3 == 0){
         a33 = 0;
      }
      if(a3 == 1){
         a33 = 1;
      }
      if(a3 == 2){
         a33 = 22;
      }
      if(a3==3){
         a33 = 333;
      }
      if(a3 == 4){
         a33 = 4444;
      }
      return a33;
   }
   if(a < 5 && b >=5){//2
      if(a ==0){
         a4 = 0;
      }
      if(a == 1){
         a4 = b;
      }
      if(a == 2){
         a4 = 11*b;
      }
      if(a == 3){
         a4 = 111*b;
      }
      if(a == 4){
         a4 = 1111*b;
      }
      return a4;
   }
   if(a >= 5 && b < 5){//2
      if(b ==0){
         a4 = 0;
      }
      if(b == 1){
         a4 = a;
      }
      if(b == 2){
         a4 = 11*a;
      }
      if(b == 3){
         a4 = 111*a;
      }
      if(b == 4){
         a4 = 1111*a;
      }
      return a4;
   }
   if(a < 5 && b < 5){//3
      a5 = a + b;
      if(a5 == 0){
         a6 = 0;
      }
      if(a5 == 1){
         a6 = 1;
      }
      if(a5 == 2){
         a6 = 22;
      }
      if(a5 == 3){
         a6 = 333;
      }
      if(a5 == 4){
         a6 = 4444;
      }
      if(a5 == 5){
         a6 = 55555;
      }
      if(a5 == 6){
         a6 = 666666;
      }
      if(a5 == 7){
         a6 = 7777777;
      }
      if(a5 == 8){
         a6 = 88888888;
      }
      return a6;
   }
}

int main() {
   int commands;
   int num;
   scanf("%d", &commands);
   scanf("%d", &num);

int d1 = 1;
int h2;
int input;
while(commands>=d1){
   d1 = d1*10;
}
h2 = d1/10;


do{
   input = commands/h2;
   
   if(input == 1){
      int n = num%100;
      if(n != 0){
         int b = (num*10/n)%10;
         if(b>= 5){
            num = num/n+1;
            }
         else{
            num = num/n;
            }
         }
      else{
         num = num; // 아니면 걍 그대로 튀어나오도록 설정.
         }
      commands = commands - input*h2;
      h2 = h2/10;
      }

   if(input == 2){
      int a = num%10/1;
      int b = num%100/10;
      int c = num%1000/100;
      int d = num%10000/1000;
      int e = num%100000/10000;
      int f = num%1000000/100000;
      int g = num%10000000/1000000;
      int h = num%100000000/10000000;
      int i = num/100000000;
      int value1 = 10000*i+1000*g+100*e+10*c+a;
      int value2 = 1000*h+100*f+10*d+b;
      if(value1 > value2){
         num = value1 - value2;
         }
      else{
         num = value2 - value1;
         }
      commands = commands - input*h2;
      h2 = h2/10;
      }


   if(input == 3){
      int a;
      int n9 = num/100000000;
      int n8 = num%100000000/10000000;
      int n7 = num%10000000/1000000;
      int n6 = num%1000000/100000;
      int n5 = num%100000/10000;
      int n4 = num%10000/1000;
      int n3 = num%1000/100;
      int n2 = num%100/10;
      int n1 = num%10;
   
      if(num>=100000000){
         a = (n5)%10*10000+(n6+n4)%10*1000+(n7+n3)%10*100+(n8+n2)%10*10+(n9+n1)%10*10;
         }
      if(num<100000000 && num >=10000000){
         a = (n5 + n4)%10*1000+(n6+n3)%10*100+(n7+n2)%10*10+(n8+n1)%10*1;
         }
      if(num<10000000 && num >= 1000000){
         a = (n4)%10*1000+(n5+n3)%10*100+(n6+n2)%10*10+(n7+n1)%10*1;
         }
      if(num<1000000 && num >= 100000){
         a = (n4 + n3)%10*100+(n5+n2)%10*10+(n6+n1)%10*1;
         }
      if(num< 100000 && num >= 10000){
         a = (n3)%10*100+(n4+n2)%10*10+(n5+n1)%10*1;
         }
      if(num<10000 && num >= 1000){
         a = (n3 + n2)%10*10+(n4+n1)%10*1;
         }
      if(num<1000 && num >= 100){
         a = (n2)%10*10 + (n3 + n1)%10*1;
         }
      if(num<100 && num >= 10){
         a = (n2 + n1)%10*10;
         }
      if(num<10){
         a = n1;
         }
      num = a;
      commands = commands - input*h2;
      h2 = h2/10;
      }
   

   
   if(input == 4){
      
      long long c4n = 0;
      long long d1 = 1;
      long long d2 = 1;
      long long d3 = 1;
      long long d4 = 1;
      long long n9 = num%10/1;
      long long n8 = num%100/10;
      long long n7 = num%1000/100;
      long long n6 = num%10000/1000;
      long long n5 = num%100000/10000; //62 89
      long long n4 = num%1000000/100000; //31 67
      long long n3 = num%10000000/1000000; //87 45
      long long n2 = num%100000000/10000000; //93 23
      long long n1 = num/100000000; //7 1
      

   
      c4n = c4n + c4(n8,n9); // 123456789 입력일 시 , 1
      if(c4n > 999999999){
         c4n = c4n - c4(n8,n9);
         }
      if(n1 == 0 & n2 == 0 & n3 == 0 & n4 == 0 & n5 == 0 & n6 == 0 & n7 == 0 & n8 == 0 & n9 > 0 && n9 < 10){
         c4n = c4n +n9;
      }
      while(c4n>=d1){
         d1 = d1 *10; // ㅇ1 = 10
         }
   
      c4n = c4n + c4(n6,n7)*d1; // 11
      if(c4n > 999999999){
         c4n = c4n - c4(n6,n7)*d1;
         }
      if(n1 == 0 & n2 == 0 & n3 == 0 & n4 == 0 & n5 == 0 & n6 == 0 & n7  > 0 && n7 < 10){
         c4n = c4n +n7*d1;
      }
      while(c4n>=d2){
         d2 = d2 *10; // 100
         }
   
      c4n = c4n +c4(n4,n5)*d2;// 555511 8877776
      if(c4n > 999999999){
         c4n = c4n - c4(n4,n5)*d2;
         }
      if(n1 == 0 & n2 == 0 & n3 == 0 & n4 == 0 & n5  > 0 && n5 < 10){
         c4n = c4n +n5*d2;
         }
      while(c4n >= d3){
         d3 = d3*10; //d3 = 10000000
         }
      
      c4n = c4n +c4(n2,n3)*d3;
      if(c4n > 999999999){
         c4n = c4n -c4(n2,n3)*d3;
         }
      if(n1 == 0 & n2 == 0 & n3  > 0 && n3< 10){
         c4n = c4n +n3*d3;
         }
      while(c4n >= d4){
         d4 = d4*10;
         }
   
      c4n = c4n + n1*d4;
      if(c4n > 999999999){
         c4n = c4n - n1*d4;
         }
      num = (int)c4n;
      commands = commands - input*h2;
      h2 = h2/10;
   }
} while(h2>0);

   printf("Your final number: %d\n", num);
   return 0;
}