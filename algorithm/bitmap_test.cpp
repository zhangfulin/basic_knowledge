#include <iostream>

using namespace std;
// https://www.jianshu.com/p/6082a2f7df8e
class BitMap {
public:
  BitMap(int capacity) {
    capacity_ = capacity;
    int index = capacity >> 3;
    bits_ = NULL;
    bits_ = new char[index + 1];
  }

  void Add(int n) {
    // n/8得到 byte[]的index 
    int index = n >> 3;
    // n%8得到byte[index]的位置
    int position = n & 0x07;
    // 将1左移position位置后,那个位置自然
    // 就是1,然后和以前的数据做|, 这样,那个位置就替换成1了
    bits_[index] |= 1 << position; 
  }

  void Clear(int n) {
    // n/8得到 byte[]的index 
    int index = n >> 3;
    // n%8得到byte[index]的位置
    int position = n & 0x07;
    // 将1左移position位置后,那个位置自然
    // 就是1,然后对取反,再与当前值做&,即可清除当前的位置了
    bits_[index] &= ~(1 << position);
  }

  bool Contain(int n) {
    // n/8得到 byte[]的index 
    int index = n >> 3;
    // n%8得到byte[index]的位置
    int position = n & 0x07;
    // 将1左移position位置后,那个位置自然就是1,
    // 然后和以前的数据做&,判断是否为0即可.
    return (bits_[index] & (1 << position)) != 0;
  }
  ~BitMap() {
    if(bits_ != NULL) {
      delete []bits_;
      cout << "~BitMap()" << endl;
    }
  }
private:
  int capacity_;
  char *bits_;
};

int main(void) {
  BitMap bitmap(100);
  bitmap.Add(7);

  cout << "插入7成功!" << endl;
  cout << "7 是否存在:" << bitmap.Contain(7) << endl;

  bitmap.Clear(7);
  cout << "7 是否存在:" << bitmap.Contain(7) << endl;

  return 0;
}
