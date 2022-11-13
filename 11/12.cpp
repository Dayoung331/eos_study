#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Canvas {
public:
  Canvas(size_t _row, size_t _col){
    row = _row;
	  col = _col;
    pixel = new char *[col];
	  for(size_t i = 0; i < row; i++){
      pixel[i] = new char[col];
    }
    Clear();
  }
  ~Canvas(){
    for(int i = 0; i < row; i++) {
		  delete[] pixel[i];
	  }
	  delete[] pixel;
  }
  void Resize(size_t w, size_t h){
    col = w;
	  row = h;
  }
  bool DrawPixel(int x, int y, char brush){
    if((x >= 0 && x < col) && (y >= 0 && y < row)) {
		pixel[y][x] = brush;
		return true;
	  }
    else{
      return false;
    }
  }
  void Print(){
    for(size_t i = 0; i < col+1; i++) {
		if(i == 0){
      cout << " ";
    }
		else if(i != 0){
      cout << (i-1) % 10;
    }
	}
	cout << endl;
	for(size_t i = 0; i < row; i++){
		cout << i % 10;
		for(size_t j = 0; j < col; j++){
      cout << pixel[i][j];
    }
		cout << endl;
	}
}
  void Clear(){
    for(size_t i = 0; i < row; i++){
		  for(size_t j = 0; j < col; j++){
			  pixel[i][j]='.';
		  }
	  }
  }

  private:
  size_t row, col;
  char ** pixel;
};

class Shape {
  public:
  Shape(){ }
  virtual ~Shape(){ }
  virtual void Draw(Canvas* canvas){ }
  virtual void Dump(){ }

  protected:
  int x, y;
	int width, height;
  int distance;
	char brush;
};

class Rectangle : public Shape {
  public:
  Rectangle(int top_left_x, int top_left_y, int _width, int _height, char _brush){
    x = top_left_x;
    y = top_left_y;
    width = _width;
    height = _height;
    brush = _brush;
  }
  void Draw(Canvas* canvas) {
	  for(int i = y; i < y + height; i++) {
		  for(int j = x; j < x + width; j++) {
			  canvas->DrawPixel(j, i, brush);
		  }
	  }
  }
  void Dump(){
	cout << "rect " << x<< " " << y << " " << width << " " << height << " " << brush << endl;
  }
};

class UpTriangle : public Shape {
  public:
  UpTriangle(int top_center_x, int top_center_y, int _distance, char _brush) {
	  x = top_center_x;
	  y = top_center_y;
	  distance = _distance;
	  brush = _brush;
  }
  void Draw(Canvas* canvas) {
	for (int i = 0; i < distance; i++){
		for (int j = -i; j <= i; j++){
			canvas->DrawPixel(j + x, i + y, brush);
    }
  }
}
  void Dump(){
	  cout << "tri_up " << x << " " << y << " " << height << " " << brush << endl;
  }
};

class DownTriangle : public Shape {
  public:
  DownTriangle(int bottom_center_x, int bottom_center_y, int _distance, char _brush) {
	  x = bottom_center_x;
	  y = bottom_center_y;
	  distance = _distance;
	  brush = _brush;
  }
  void Draw(Canvas* canvas) {
	  for(int i = 0; i > -distance; i--){
		  for (int j = i; j <= -i; j++){
			  canvas->DrawPixel(j + x, i + y, brush);
      }
    }
  }
  void Dump(){
	  cout << "tri_down " << x << " " << y << " " << height << " " << brush << endl;
  }
};

class Diamond : public Shape {
  public:
  Diamond(int top_center_x, int top_center_y, int _distance, char _brush) {
	  x = top_center_x;
    y = top_center_y;
	  distance = _distance;
	  brush = _brush;
  }
  void Draw(Canvas* canvas){
	  for(int i = y; i < y + distance * 2 + 1; i++) {
		  if(i < y + distance +1) {
			  for(int j = x- i + y; j < x + i - y + 1; j++) {
				  canvas -> DrawPixel(j, i, brush);
			}
		} 
		  else{
			  for(int j = x - i + y + (i - y - distance) * 2; j < (x- i + y + (i - y - distance) * 2) + distance * 2 - (i - y - distance) * 2 + 1; j++) {
				canvas -> DrawPixel(j, i, brush);
			}
		}
	}
  }
  void Dump(){
	  cout << "diamond " << x << " " << y << " " << height << " " << brush << endl;
  }
};


int main() {
  vector<Shape*> shapes;

  size_t row, col;
  cin >> row >> col;
    
  Canvas canvas(row, col);
  canvas.Print();

  while(true) {
    string command;
    cin >> command;

    if(command == "add") {
      string shape;
      cin >> shape;

      if(shape == "rect") {
        int x, y, width, height;
        char brush;
        cin >> x >> y >> width >> height >> brush;
        shapes.push_back(new Rectangle(x, y, width, height, brush));
      }
      else if(shape == "tri_up") {
        int x, y, distance;
				char brush;
				cin >> x >> y >> distance >> brush;
				shapes.push_back(new UpTriangle(x, y, distance, brush));
      }
      else if(shape == "tri_down") {
        int x, y, distance;
				char brush;
				cin >> x >> y >> distance >> brush;
				shapes.push_back(new DownTriangle(x, y, distance, brush));
      }
      else if(shape == "diamond") {
        int x, y, distance;
        char brush;
        cin >> x >> y >> distance >> brush;
        shapes.push_back(new Diamond(x, y, distance, brush));
      }
    }

    if(command == "draw") {
      canvas.Clear();
      for(int i = 0; i < shapes.size(); i++){
        shapes[i]->Draw(&canvas);
      }
      canvas.Print();
    }

    if(command == "delete") {
      int index, count = 0;
      cin >> index;
      vector<Shape*>::iterator it;
      for(it = shapes.begin(); it != shapes.end(); it++) {
        if(count == index) {
          shapes.erase(it);
          break;
        }
      count++;
      }
    }

    if(command == "dump") {
      for(int i = 0; i < shapes.size(); i++) {
        cout << i << " ";
        shapes[i] -> Dump();
        }
      }

    if(command == "resize") {
      cin >> row >> col;
      canvas.Resize(row, col);
    }
    
    if(command == "quit"){
      break;
    }
  }

  for(int i = 0; i < shapes.size(); i++) delete shapes[i];
  shapes.clear();

  return 0;
}