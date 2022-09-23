#include <iostream>

using namespace std;

void magicSquare(int** MagicSquare, int N){
    int number=1, i=0, j=N/2;
    MagicSquare[i][j] = number;
    number+=1;

  while(number <= N*N){
    if((number-1) % N == 0){
      i++;
      MagicSquare[i][j] = number;
      number+=1;
    }
    else{
      if(i == 0){
        i=N-1;
        j++;
        MagicSquare[i][j] = number;
        number+=1;
      }
      else if(j == N-1){
        i--;
        j=0;
        MagicSquare[i][j]=number;
        number+=1;
      }
      else{
        i--;
        j++;
        MagicSquare[i][j]=number;
        number+=1;
      }
    }
  }
 
}

int main() {
  int N;
  while(true){
    cin >> N;
    if(N % 2 == 0 || N < 3){
      return 0;
    }
    else{
      break;
    }
  }
 
  int** MagicSquare = new int*[N];
  for(int i=0; i<N; i++){
 MagicSquare[i] = new int[N];
  }
 
  magicSquare(MagicSquare, N);

  for(int l=0; l<N; l++){
    for(int m=0; m<N; m++){
      cout << MagicSquare[l][m] << " ";
    }
    cout << endl;
  }
 
  for(int i=0; i<N; i++){
 delete[] MagicSquare[i];
  }
  delete[] MagicSquare;

  return 0;
}