#include <iostream>

using namespace std;

//https://blog.csdn.net/feliciafay/article/details/6841115
//https://blog.csdn.net/geekmanong/article/details/51097196
struct ListNode {
  int value;
  ListNode *next;
};

int CreatList(ListNode * &head, int data) {
  
  ListNode *node = nullptr;
  node = new ListNode();
  
  if(node == nullptr) {
    return 1;
  }
  node->next = nullptr;

  node->value = data;
  if(head == nullptr) {
    head = node;
    return 0;
  }

  node->next = head;
  head = node;
  return 0;
}

void PrintList(ListNode *head) {
  if(head == nullptr)
    return;
  for(ListNode *p = head; p != nullptr; p = p->next) {
    cout << p->value << " ";
  }

  cout << endl;
}

//递归方式实现链表的反转
ListNode *ReverseList(ListNode *head) {
  //链表少于两个结点没必要翻转
  //递归终止条件,找到链表的最后一个节点
  if(head == nullptr || head->next == nullptr) {
    return head;
  } else {
    //先反转后面的链表,从最后面的两个结点开始反转,依次向前.
    ListNode *newhead = ReverseList(head->next);
   
    //拿链表的最后的两个结点解释一下head->next->next的意思
    //head->next 表示最后两个结点的前一个结点
    //head->next->next 表示最后一个结点
    //表示最后一个结点反向指向前一个结点
    head->next->next = head;

    //前一个结点的next指针置nullptr
    head->next = nullptr;

    //把原链表的最后一个结点当作新的head指针返回
    return newhead;
  }
}

int main(void) {

  ListNode * head = nullptr;
  for(int i = 0; i < 9; i++) {
    int ret = CreatList(head, i);
    if(ret == 1) {
      break;
    }
  }

  PrintList(head);
  
  ListNode *newhead = nullptr;
  newhead = ReverseList(head);

  cout << "---------------------------" << endl;

  PrintList(newhead);
  for(ListNode *p = newhead; p != nullptr; p=p->next) {
    delete p;
  }
  
  return 0;
}

