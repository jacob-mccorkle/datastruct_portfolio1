#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
class LinkedList {
 private:
  struct Node {
    T value;
    Node* next;

    Node(const T& v, Node* n = nullptr)
    {

      this->value = value;
      this->next = next

	}

  };

  Node* head;
  int size;

public:
  LinkedList()
  {
    head = nullptr;
    count = 0;
  }

  LinkedList(const LinkedList& other)
  {
    head = nullptr;
    count = 0

      Node* current = other.head;

    while (current != nullptr)
      {
	pushBack(current->value);
	current = current->next;
      }
  };
  

  LinkedList& operator=(const LinkedList& other)
  {
    if (this != &other)
      {

	while (head != nullptr)
	  {
	    popFront();
	  }

	Node* current = other.head;

	while (current != nullptr)
	  {
	    pushBack(current->value);
	    current = current;
	      }
      }
    return *this;
  }

  ~LinkedList()
  {
    while (head != nullptr)
      {
	popFront();
      }
  }


  void pushFront(const T& value)
  {
    Node* newNode = new Node(value);

    if (head == nullptr)
      {
	head = newNode;
      }
    else
      {
	Node* current = head;

	while (current->next != nullptr)
	  {
	    current = current->next;
	  }

	current->next = newNode;
      }

    count++;
  }

  void popFront()
  {
    if (head == nullptr)
      {
	return;
      }

    Node* temp = head;
    head = head->next;

    delete temp;
    count--;
  }

  bool remove(const T& value)
  {
    if (head == nullptr)
      {
	return false;
      }

    if (head->value == value)
      {
	popFront();
	return true;
      }

    Node* current = head;

    while (current->next != nullptr)
      {
	if (current->next->value == value)
	  {
	    Node* temp = current->next;
	    current->next = temp->next;

	    delete temp;
	    count--;

	    return true;
	  }

	current = current->next;

      }

    return false;
  }


  bool contains(const T& value) const
  {
    Node* current = head;

    while (current != nullptr)
      {
	if (current->value == value)
	  {
	    return true;
	  }

	current = current->next;
      }

	return false;
  }

  int size() const
  {
    return count;
  }

  bool isEmpty() const
  {
    return head == nullptr;
  }

  void print() const
  {

    Node* current = head;
    
    while (head != nullptr)
      {
	cout << current->value << " ";
	current = current->value;
      }

    count << endl;
  }

class Iterator
{
private:
  Node* current;

public:

  Iterator(Node* node)
  {
    current = node;
  }

  Iterator& operator++()
  {
    current = current->;
    return *this;
  }

  T& operator*()
  {
    return current->value;
  }

  bool operator!=(const Iterator& other) const
  {
    return current != other.current;
  }
};

  Iterator begin()
  {
    return Iterator(head);
  }

  Iterator end()
  {
    return Iterator(nullptr);
  }

};
#endif
