
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "mstack.h"

mstack <char> * obj_stack = new mstack<char>;

int main() {
	
	std::ifstream file_input("input.txt"); //исходный текст
	std::ofstream file_output("output.txt"); //зашифрованный текст
	char ri;
	if (file_input.is_open()) {
		while (file_input.get(ri)) {
			if (ri != '\n') {
				obj_stack->push(ri);
			}
			else {
				for (int i = 0; i < obj_stack->size; i++) {
					char ro = obj_stack->r_end();
					obj_stack->pop();
					i--;
					file_output << ro;
				}
				file_output << '\n';
			}
		}
		if (obj_stack->size != 0) {
			for (int i = 0; i < obj_stack->size; i++) {
				char ro = obj_stack->r_end();
				obj_stack->pop();
				i--;
				file_output << ro;
			}
			file_output << '\n';
		}
	}
	else return 1;

	file_input.close();
	file_output.close();
	return 0;

}