#include <iostream>
#include <fstream>
#include "LinkedList.hpp"
#include <string>
#include <map>
#include <vector>

/**
 * 
 * Actividad 2.3
 * Estructura de Datos y Algoritmos 
 * Prof. Baldomero Olvera Villanueva
 * 
 * Código que lee un archivo, separa las entradas en 2 listas ligadas dependiendo del punto de entrada,
 * ordena los datos en base a su UBI y fecha, pide al usuario los primeros 3 caracteres del UBI 
 * e imprime cuantos barcos con coincidencia pasaron por los distintos puntos de entrada cada mes.
 * 
 * Andrés Daniel Martínez - A00227463
 * Fernanda Granados - A01252895
 * Santiago Poblete - A01254609
 * Martín Tanori - A01252900
 * 
 */

void read_and_get_bitacora_info(LinkedList& listaM, LinkedList& listaR, std::string file_name){
    std::ifstream bitacora_file(file_name);
    std::string line;
    while (std::getline(bitacora_file, line)) {
        if(line[17] == 'M')
            listaM.create_beginning(line);
        else
            listaR.create_beginning(line);
    }
}

std::vector<int> getTotals(std::string file_name) {
    std::ifstream file(file_name);
    std::string line;
    std::vector<int> total(12, 0);

    while (std::getline(file, line)) {
        if (line.size() >= 10) {
            int dateDigit1 = line[3] - '0';
            int dateDigit2 = line[4] - '0';

            if (dateDigit1 == 0) {
                if (dateDigit2 >= 1 && dateDigit2 <= 9) {
                    total[dateDigit2 - 1]++;
                }
            } else if (dateDigit1 == 1) {
                if (dateDigit2 >= 0 && dateDigit2 <= 2) {
                    total[9 + dateDigit2]++;
                }
            }
        }
    }
    return total;
}

std::string get_month(int number) { 
    std::map<int, std::string> months = {
        {0, "jan"},
        {1, "feb"},
        {2, "mar"},
        {3, "apr"},
        {4, "may"},
        {5, "jun"},
        {6, "jul"},
        {7, "aug"},
        {8, "sep"},
        {9, "oct"},
        {10, "nov"},
        {11, "dec"}
    };

    if (months.find(number) != months.end()) {
        return months[number]; 

    } else {
        return "";  
    }

}

void printTotals(std::vector<int> mVector,std::vector<int> rVector) {
    for (int i = 0; i < 12; i++)
    {
        std::cout << get_month(i) << " 23 " << mVector[i] << " " << rVector[i] << std::endl;
    }
}

int main() { 
    LinkedList listaM;
    LinkedList listaR;
    read_and_get_bitacora_info(listaM, listaR, "canal.txt");

    listaM.print_file("M.txt");
    listaR.print_file("R.txt");

    listaR.merge_sort_id();  
    listaR.print_file("R_sorted.txt");

    listaM.merge_sort_id(); 
    listaM.print_file("M_sorted.txt");

    std::string buscar;
    std::cout << "Escriba los primeros 3 caracteres del UBI a buscar: "<< std::endl;
    std::cin >> buscar;

    LinkedList foundM = listaM.linear_search_ids(buscar);
    foundM.print_file("Found_M.txt");
    LinkedList foundR = listaR.linear_search_ids(buscar);
    foundR.print_file("Found_R.txt");

    std::vector<int> totalsM = getTotals("Found_M.txt");
    std::vector<int> totalsR = getTotals("Found_R.txt");
    
    printTotals(totalsM,totalsR);

    return 0; 
}
