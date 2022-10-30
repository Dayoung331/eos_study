#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Shape {
  public:
  Shape();
  Shape(int _width, int _height) : width(_width), height(_height){ }
  double GetArea(){
    return width * height;
  }
  int GetPerimeter(){
    return 2 * (width + height);
  }
  void set_brush(string _brush){
    brush = _brush;
  }
  void set_top_left(int _top_left_x, int _top_left_y){
    top_left_x = _top_left_x;
    top_left_y = _top_left_y;
  }

  void Draw(int canvas_width, int canvas_height){
    vector<vector<string>> canvas(canvas_width+1, vector<string>(canvas_height+1));
    canvas[0][0] = " ";
   
    for(int i = 1; i < canvas_width+1; i++){
      canvas[0][i] = to_string(i-1);
    }
    for(int i = 1; i < canvas_height+1; i++){
      canvas[i][0] = to_string(i-1);
    }
   
    for(int i = 1; i < canvas_width+1; i++){
      for (int j = 1; j < canvas_height+1; j++){
        if(i > top_left_y && i < top_left_y + height + 1 && j > top_left_x && j < top_left_x + width + 1){
        canvas[i][j] = brush;
        }
        else{
          canvas[i][j] = ".";
        }
      }
    }
    for(int i = 0; i < canvas_width+1; i++){
      for(int j = 0; j < canvas_height+1; j++){
        cout << canvas[i][j];
      }
      cout << endl;
    }
  }

  protected:
  int width, height;
  string brush;
  int top_left_x, top_left_y;
};

class Square : public Shape{
  public:
  Square(int width) : Shape(width, width){}
};

class Rectangle : public Shape{
  public:
  Rectangle(int width, int height) : Shape(width, height){}
};

class Diamond : public Shape{
  public:
  Diamond(int width) : Shape(width, width){}
  double GetArea(){
    return (diagonal * diagonal)/2;
  }
  int GetPerimeter(){
    return 2 * (width+1);
  }

  void set_diagonal(double _diagonal){
    diagonal = _diagonal;
  }
  void Draw(int canvas_width, int canvas_height){
    vector<vector<string>> canvas(canvas_width+1, vector<string>(canvas_height+1));
    canvas[0][0] = " ";
    for(int i = 1; i < canvas_width+1; i++){
      canvas[0][i] = to_string(i-1);
    }
    for(int i = 1; i < canvas_height+1; i++){
      canvas[i][0] = to_string(i-1);
    }

    vector<vector<string>> diamond_canvas(width, vector<string>(width));
	  for (int i=0;i<width;i++){
      for (int j=0; j<width;j++){
        if (i<=width/2)// 위쪽 영역
        {
          if (i+j<=width/2-1)// 왼쪽 위 공백찍기
            diamond_canvas[i][j] =".";
          else if (j-i>=width/2+1) // 오른쪽 위 공백찍기
        	  diamond_canvas[i][j] = ".";
          else
            diamond_canvas[i][j] = brush;
        }
        else if (i>width/2) //아래쪽 영역
        {
          if (i-j>=width/2+1) //왼쪽 밑 공백
        	  diamond_canvas[i][j] = ".";
          else if (i+j>=width/2*3+1)//오른쪽 밑 공백
        	  diamond_canvas[i][j] = ".";
          else
        	  diamond_canvas[i][j] = brush; // 채우기
        }
      }
    } //다이아몬드 캔버스 세팅 완료!

  for(int i=top_left_y; i<top_left_y+width; i++){
    for(int j=top_left_x; j<top_left_x+width; j++){
      canvas[i][j] = diamond_canvas[i-top_left_y][j-top_left_x];
    }
  } //다이아몬드 캔버스를 원래 캔버스로

  for(int i = 1; i < canvas_width+1; i++){
    for (int j = 1; j < canvas_height+1; j++){
      if(canvas[i][j] != brush){
        canvas[i][j] = ".";
      } //캔버스 빈 공간 채우기

    }
  }
  for(int i = 0; i < canvas_width+1; i++){
    for(int j = 0; j < canvas_height+1; j++){
      cout << canvas[i][j];
    }
    cout << endl;
  } //캔버스 출력
  }

  protected:
  double diagonal;
};

int main(){
  string shape;
  int canvas_width, canvas_height;
  int width, height;
  int top_left_x, top_left_y;
  string brush;
  cin >> canvas_width >> canvas_height;
  while(true){
    cin >> shape;
    if(shape == "rect"){
      cin >> top_left_x >> top_left_y >> width >> height >> brush;
      Rectangle rect(width, height);
      rect.set_brush(brush);
      rect.set_top_left(top_left_x, top_left_y);
      cout << "Area: " << rect.GetArea() << endl;
      cout << "Perimeter: " << rect.GetPerimeter() << endl;
      rect.Draw(canvas_width, canvas_height);
    }
    else if(shape == "square"){
      cin >> top_left_x >> top_left_y >> width >> brush;
      Square square(width);
      square.set_brush(brush);
      square.set_top_left(top_left_x, top_left_y);
      cout << "Area: " << square.GetArea() << endl;
      cout << "Perimeter: " << square.GetPerimeter() << endl;
      square.Draw(canvas_width, canvas_height);
    }
    else if(shape == "diamond"){
      int distance;
      cin >> top_left_x >> top_left_y >> distance >> brush;
      int width = 2 * distance + 1;
      Diamond diamond(width);
      diamond.set_brush(brush);
      diamond.set_top_left(top_left_x-distance+1, top_left_y+1);
      diamond.set_diagonal(width);
      cout << "Area: " << diamond.GetArea() << endl;
      cout << "Perimeter: " << diamond.GetPerimeter() << endl;
      diamond.Draw(canvas_width, canvas_height);
    }
    else if(shape == "quit"){
      break;
    }
  }
  return 0;
}