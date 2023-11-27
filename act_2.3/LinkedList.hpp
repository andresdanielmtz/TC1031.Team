#pragma once
#include <iostream>
#include <string> // Include the string header
#include "Node.hpp"

class LinkedList {
private:
    Node* head;

    Node * merge(Node *, Node *);
    Node * mergeSort(Node *);

public:
    LinkedList();
    LinkedList(Node* prev_node);
    Node * get_head();

    /* Base functions for linked list manipulation and usage. */
    void create_beginning(const std::string& new_data);
    void create_position(int position, const std::string& new_data);
    void insert_after_value(const std::string& value, const std::string& new_data);
    void create_end(const std::string& new_data);
    int search(const std::string& value);
    void display_list();
    void update(int position, const std::string& new_value);
    void delete_head();
    void delete_value(const std::string& value);
    void delete_last();

    void print_file(std::string);

    LinkedList linear_search_ids(std::string);
    void merge_sort_id();
    int get_length();

    ~LinkedList();
};
