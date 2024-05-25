#include <iostream>

using namespace std;

struct Node {
   int val;
   Node *next;
   Node(int x) : val(x), next(nullptr) {}
};

class list {
public:
   void push_back(int val) {
       if (first == nullptr) {
           first = new Node(val);
           last = first;
       }
       else {
           Node *temp = new Node(val);
           last->next = temp;
           last = temp;
       }
   }
   void print_list() {
       if (first == nullptr)
           return;
       else {
           Node *temp = first;
           while (temp) {
               cout << temp->val << " -> ";
               temp = temp->next;
           }
       }
   }
   void delete_list() {
       if (first == nullptr)
           return;
       else {
           last = first;
           while (last) {
               last = first->next;
               delete first;
               first = last;
           }
       }
   }
   bool is_palindrom() {
       if (first == nullptr) {
           cerr << "\nno list" << endl;
           return false;
       }
       else {
           Node *temp1 = first, *temp2 = first, *temp1_last = nullptr;
           size_t n = 0;
           while (temp1) {
               n++;
               temp1 = temp1->next;
           }
           temp1 = first;
           for (int i = 1; i <= n / 2; i++) {
               if (i == n / 2)
                   temp1_last = temp2;
               temp2 = temp2->next;
           }
           if (n % 2 == 1)
               temp2 = temp2->next;
           while (temp2) {
               if (temp1_last->val == temp2->val) {
                   temp2 = temp2->next;
                   while (1) {
                       if (temp1->next == temp1_last || temp1 == temp1_last) {
                           temp1_last = temp1;
                           temp1 = first;
                           break;
                       }
                       temp1 = temp1->next;
                   }
               }
               else
                   return false;
           }
           return true;
       }
   }
private:
   Node *first = nullptr;
   Node *last = nullptr;
};

int main() {
   list a;

   a.push_back(1);
   a.push_back(2);
   a.push_back(3);
   a.push_back(4);
   a.push_back(4);
   a.push_back(3);
   a.push_back(2);
   a.push_back(1);

   a.print_list();

   cout << "\n\n" << a.is_palindrom() << endl;

   a.delete_list();

   a.print_list();

   return 0;
}
