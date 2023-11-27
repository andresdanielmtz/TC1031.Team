#include <iostream>
#include <string>
#include <fstream>
#include "LinkedList.hpp"

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::LinkedList(Node* prev_node) {
    head = prev_node;
}

Node * LinkedList::get_head() {
    return head;
}

void LinkedList::create_beginning(const std::string& new_data) {
    Node* new_node = new Node(new_data);
    new_node->next = head;
    head = new_node;
}

void LinkedList::create_position(int position, const std::string& new_data) {
    Node* node = head;
    int counter = 0;
    Node* new_node = new Node(new_data);

    if (head == nullptr || position == 0) {
        std::cout << "The list is empty, adding an element at the beginning." << std::endl;
        create_beginning(new_data);
        return;
    }

    while (node != nullptr) {
        if (counter == position) {
            Node* tmp = node;
            node = new_node;
            new_node->next = tmp;
            return;
        }
        node = node->next;
        counter++;
    }

    // If no position, add to the end
    create_end(new_data);
    return;
}

void LinkedList::insert_after_value(const std::string& value, const std::string& new_data) {
    Node* node = head;
    Node* new_node = new Node(new_data);
    while (node != nullptr) {
        if (value == node->data) {
            Node* tmp = node->next;
            node->next = new_node;
            new_node->next = tmp;
            return;
        }
        node = node->next;
    }
    return;
}

void LinkedList::create_end(const std::string& new_data) {
    Node* node = head;
    Node* new_node = new Node(new_data);

    if(head == nullptr){
        head = new_node;
        return;
    }

    while (node->next != nullptr) {
        node = node->next;
    }
    node->next = new_node;
    return;
}

int LinkedList::search(const std::string& value) {
    Node* node = head;
    int counter = 0;
    while (node != nullptr) {
        if (value == node->data) {
            return counter;
        }
        node = node->next;
        counter++;
    }
    return -1;
}

void LinkedList::display_list() {
    Node* node = head;
    while (node != nullptr) {
        std::cout << node->data << std::endl;
        node = node->next;
    }
    std::cout << std::endl;
}

void LinkedList::update(int position, const std::string& new_data) {
    Node* node = head;
    int counter = 0;
    while (node != nullptr) {
        if (counter == position) {
            node->data = new_data;
            return;
        }
        node = node->next;
        counter++;
    }
    return;
}

void LinkedList::delete_head() {
    Node* node = head;
    if (node != nullptr) {
        Node* tmp = node->next;
        head = tmp;
        delete node;
        return;
    }
    std::cout << "Cannot delete the head. The list is empty." << std::endl;
    return;
}

void LinkedList::delete_value(const std::string& value) {
    Node* node = head;
    Node* prev_node = nullptr;
    while (node != nullptr) {
        if (node->data == value) {
            if (prev_node == nullptr) {
                head = node->next;
                delete node;
                return;
            }
            prev_node->next = node->next;
            delete node;
            return;
        }
        prev_node = node;
        node = node->next;
    }
    return;
}

void LinkedList::delete_last() {
    Node* node = head;
    while (node->next->next != nullptr) {
        node = node->next;
    }
    node->next = nullptr; // Delete last value
}

void LinkedList::print_file(std::string file_name) {
    std::ofstream file(file_name);
    Node* node = head;
    while (node != nullptr) {
        file << node->data << std::endl;
        node = node->next;
    }
    file.close();
}

/**
 * @brief Merge sorting algorithm.
 *
 * @param l1
 * @param l2
 * @return Node*
 */

Node* LinkedList::merge(Node* l1, Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    std::string temp = l1->data.substr(l1->data.length() - 6);
    std::string temp2 = l2->data.substr(l2->data.length() - 6);

    if(temp == temp2) {
        std::string fecha1 = l1->data.substr(6,4) + l1->data.substr(3,2) + l1->data.substr(0,2);
        std::string fecha2 = l2->data.substr(6,4) + l2->data.substr(3,2) + l2->data.substr(0,2);

        if(fecha1 <= fecha2) {
            l1->next = merge(l1->next, l2);
            return l1;
        } else {
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }
    else if (temp < temp2) {
        l1->next = merge(l1->next, l2);
        return l1;
    } else {
        l2->next = merge(l1, l2->next);
        return l2;
    }
}

Node* LinkedList::mergeSort(Node* head) {
    if (!head || !head->next) {
        return head;
    }

    Node* slow = head;
    Node* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* mid = slow->next; // get the middle part :)
    slow->next = nullptr;

    Node* left = mergeSort(head);
    Node* right = mergeSort(mid);

    return merge(left, right);
}

void LinkedList::merge_sort_id() {
    head = mergeSort(head); // make it self sorting, without a return value nor a parameter
}

int LinkedList::get_length() { 
    int length = 0; 
    while (head != NULL) { 
        length++; 
    }
    return length;
}

std::string get_id(std::string str) {
    return str.substr(str.length() - 6);
}

std::string get_sub_id(std::string str) {
    str = str.substr(str.length() - 6);
    str = str.substr(0, 3); // first three
    return str;
}

LinkedList LinkedList::linear_search_ids(std::string str) {
    LinkedList found;
    Node* temp = head;
    while (temp != NULL) {
        std::string Ubi = get_sub_id(temp->data); // 3 digits

        if (Ubi == str) {
            found.create_beginning(temp->data);
        }
        temp = temp->next;
    }
    return found;
}

LinkedList::~LinkedList() {}
