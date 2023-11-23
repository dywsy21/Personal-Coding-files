int* get_one_dimensional_array(int n) {
  int* int_array = (int*) malloc(n * sizeof(int));
  return int_array;
}

int* get_two_dimensional_array(int rows, int cols){
//先malloc行再malloc列

int** matrix=(int**) malloc(rows*sizeof(int));
for(int i=0;i<cols;i++) matrix[i]=(int*) malloc(cols*sizeof(int));

return matrix;
}

void set_all_elements_to_0(int** matrix, int rows, int cols){
  for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
      matrix[i][j]=0;
    }
  }
}



int main() {
  int* p = get_one_dimensional_array(10);
  int** q=get_two_dimensional_array(10, 10)



  free(p);


//先free列再free行
  for (int i = 0; i < rows; i++)   free(q[i]);
  free(q);


  return 0;
}
