#include <iostream>
#include <cstdint>
#include <math.h>
#include <vector>
#include <functional>

#define PI 3.14285714286 

float Ci, Cj;

bool isImgValid(int row, int column, int size){
	if(row * column < size) {
		std::cout << "Image dimensions or size is invalid\n";
		return false;
	}
	return true;
}


std::vector<std::vector<float>> dct(int row, int column, int size, int img[8][8]){
	std::vector<std::vector<float>> comp_img;
	comp_img.resize(row * column);
	if(isImgValid(row, column, size)){
		
		for (int i = 0; i < row; ++i){
			for (int j = 0; j < column; ++j){
			
				if(i == 0)
					Ci = 1 / sqrt(row);
				else
					Ci = sqrt(2) / sqrt(row);
				if(j == 0)
					Cj = 1 / sqrt(column);
				else
					Cj = sqrt(2) / sqrt(column);
				float sum = 0;
				float d = 0;
				for (int k = 0; k < row; ++k) {
					for (int m = 0; m < column; ++m) {
						sum = img[k][m] * cos((2 * k + 1) * i * PI / (2 * row)) *
							cos((2 * m + 1) * j * PI / (2 * column));
						d += sum;
					}
				}
				comp_img[i].push_back(d * Ci * Cj);
				printf("%f\t", comp_img[i].at(j));
			}
		}
		return comp_img;
	}
	return NULL;
}


int main(){
	int m = 8;
	int n = 8;
	int size = 64;

	int matrix[8][8] = { { 255, 255, 255, 255, 255, 255, 255, 255 },
						 { 255, 255, 255, 255, 255, 255, 255, 255 },
						 { 255, 255, 255, 255, 255, 255, 255, 255 },
						 { 255, 255, 255, 255, 255, 255, 255, 255 },
                         { 255, 255, 255, 255, 255, 255, 255, 255 },
						 { 255, 255, 255, 255, 255, 255, 255, 255 },
					     { 255, 255, 255, 255, 255, 255, 255, 255 },
					     { 255, 255, 255, 255, 255, 255, 255, 255 } };
	
	std::vector<std::vector<float>> compressed_img = dct(m, n, size, matrix);

	return 0;
}
