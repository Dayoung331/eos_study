#include <iostream>

using namespace std;

void magicSquare(int** MagicSquare, int N){
  for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			MagicSquare[i][j] = (N*i+j+1);
		}
	}

  for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i >=0 && i< N/4 || i >= N/4*3 && i < N) {
			  if (j >= N/4 && j <N/4*3) {
					MagicSquare[i][j] = (N*N)-(i*N+j);
				}
			}
        else {
					if(j >=0 && j< N/4 || j >= N/4*3 && j < N) {
					MagicSquare[i][j] = (N*N)-(i*N+j);
				}
			}
		}
	}
}

int main(){
  int N;
  while(true){
    cin >> N;
    if(N % 4 != 0){
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
