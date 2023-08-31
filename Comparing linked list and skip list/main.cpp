#include <iostream>
#include <chrono>

#include "LinkedList.h"
#include "SkipList.h"


int main() {

    srand(time(nullptr));

    LinkedList linked_list;
    SkipList skip_list;

    int numbers = 10000;
    int numbersChosen = 1000;

    bool used_numbers[numbers];
    for (int i=0; i<numbers; i++) {
        used_numbers[i] = false;
    }

    int v[numbers];

    for (int i=0; i<numbers; i++) {
        int random_value = rand() % numbers;
        while (used_numbers[random_value]) {
            random_value = rand() % numbers;
        }
        v[i] = random_value;
        used_numbers[random_value] = true;
    }

    /// count time for insertion in linked list

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < numbers; i++) {
        linked_list.insert(std::to_string(v[i]), v[i]);
    }

    auto finish = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed_insertion_linked = finish - start;

    std::cout << "Elapsed time for insertion in linked list: " << elapsed_insertion_linked.count() << " s\n";

    /// count time for insertion in skip list

    start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < numbers; i++) {
        skip_list.insert(std::to_string(v[i]), v[i]);
    }

    finish = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed_insertion_skip = finish - start;

    std::cout << "Elapsed time for insertion in skip list: " << elapsed_insertion_skip.count() << " s\n";


    /// printing the lists
    //linked_list.print();
    //skip_list.print();
    std::cout << "\n";


    /// sorting the lists by key
    /// skiplist is already sorted
    linked_list.sort();

    for (int i=0; i<numbers; i++) {
        used_numbers[i] = false;
    }

    int w[numbersChosen];

    for (int i=0; i<numbersChosen; i++) {
        int random_value = rand() % numbers;
        while (used_numbers[random_value]) {
            random_value = rand() % numbers;
        }
        w[i] = random_value;
        used_numbers[random_value] = true;
    }

    /// search in linked list

    start = std::chrono::high_resolution_clock::now();

    for (int i=0; i<numbersChosen; i++) {
        linked_list.search(std::to_string(w[i]));
    }

    finish = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed_search_linked = finish - start;

    std::cout << "Elapsed time for search in linked list: " << elapsed_search_linked.count() << " s\n";

    /// search in skip list

    start = std::chrono::high_resolution_clock::now();

    for (int i=0; i<numbersChosen; i++) {
        skip_list.search(std::to_string(w[i]));
    }

    finish = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed_search_skip = finish - start;

    std::cout << "Elapsed time for search in skip list: " << elapsed_search_skip.count() << " s\n";

    std::cout << "\n";

    /// remove from linked list

    start = std::chrono::high_resolution_clock::now();

    for (int i=0; i<numbersChosen; i++) {
        linked_list.remove(std::to_string(w[i]));
    }

    finish = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed_remove_linked = finish - start;

    std::cout << "Elapsed time for remove in linked list: " << elapsed_remove_linked.count() << " s\n";

    /// remove from skip list

    start = std::chrono::high_resolution_clock::now();

    for (int i=0; i<numbersChosen; i++) {
        skip_list.remove(std::to_string(w[i]));
    }

    finish = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed_remove_skip = finish - start;

    std::cout << "Elapsed time for remove in skip list: " << elapsed_remove_skip.count() << " s\n";


    /// printing the lists
    //linked_list.print();
    //skip_list.print();


    return 0;
}
