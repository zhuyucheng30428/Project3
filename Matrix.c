#include <stdio.h>
struct Matrix{
    float * data;
    int row;
    int col;
};
//创建空矩阵
struct Matrix *createMatrix(int row,int col){
    float * data = (float *) malloc(row*col * sizeof(float));
    struct Matrix * result=(struct Matrix *)malloc (sizeof(struct Matrix));
    *result={data,row,col};
    return result;
}
struct Matrix *createMatrix(float* data,int row,int col){
    struct Matrix * result=(struct Matrix *)malloc (sizeof(struct Matrix));
    *result={data,row,col};
    return result;
};
//打印矩阵
void printMatrix(const struct Matrix * a){
    if(a!=nullptr){
        for(int i=0;i<a->row;i++){
        for(int j=0;j<a->col;j++){
            printf("%f ",a->data[i*a->col+j]);
        }
        printf("\n");
    }
    }
    else printf("Matrix doesn't exist!\n");
}
//输入矩阵
struct Matrix *inputMatrix(int row,int col){
    struct Matrix *result=createMatrix(row,col);
    printf("Please input a %d by %d matrix\n",row,col);
    for(int i=0;i<row*col;i++){
        scanf("%f",&result->data[i]);
    }
    printf("The input matrix is:\n");
    printMatrix(result);
    return result;
};
//删除矩阵
void deleteMatrix(struct Matrix ** p){
    if ((*p)->data!=nullptr) free((*p)->data); 
    if (*p!=nullptr) free(*p);
    *p=nullptr;
    printf("Matrix deleted\n");
};
//复制矩阵
struct Matrix *copyMatrix(const struct Matrix * a){
    if(a!=nullptr){
       struct Matrix *result=createMatrix(a->row,a->col);
        for (int i=0;i<(a->row*a->col);i++){
            result->data[i]=a->data[i];
        }
        return result; 
    }
    else{
        printf("Matrix doesn't exist!\n");
        return nullptr;
    }
}
//矩阵加矩阵
struct Matrix *addMatrix(const struct Matrix * a,const struct Matrix * b){
    if (a!=nullptr && b!=nullptr){
       struct Matrix *result=copyMatrix(a);
        if(a->col==b->col &&a->row==b->row){
            for(int i=0;i<(a->row*a->col);i++){
                result->data[i]+=b->data[i];
            }
        }
        return result; 
    }
    else{
        printf("Matrix doesn't exist!\n");
        return nullptr;
    }
};
//矩阵减矩阵
struct Matrix *subtractMatrix(const struct Matrix * a,const struct Matrix * b){
    if (a!=nullptr && b!=nullptr){
       struct Matrix *result=copyMatrix(a);
        if(a->col==b->col &&a->row==b->row){
            for(int i=0;i<(a->row*a->col);i++){
                result->data[i]-=b->data[i];
            }
        }
        return result; 
    }
    else{
        printf("Matrix doesn't exist!\n");
        return nullptr;
    }
};
//矩阵乘以一个数
struct Matrix *multiplyMatrix(const struct Matrix * a,float n){
    if(a!=nullptr){
       struct Matrix *result=copyMatrix(a);
        for(int i=0;i<(a->row*a->col);i++){
            result->data[i]*=n;
        }
        return result; 
    }
    else {
        printf("Matrix doesn't exist!\n");
        return nullptr;
    }
};
//矩阵加上一个数
struct Matrix *addMatrix(const struct Matrix * a,float n){
    if(a!=nullptr){
       struct Matrix *result=copyMatrix(a);
        for(int i=0;i<(a->row*a->col);i++){
            result->data[i]+=n;
        }
        return result; 
    }
    else {
        printf("Matrix doesn't exist!\n");
        return nullptr;
    }
};
//矩阵乘矩阵
struct Matrix *multiplyMatrix(const struct Matrix * a,const struct Matrix * b){
    if(a!=nullptr && b!=nullptr){
        int row=a->row;
        int col=a->col;
        struct Matrix *result=createMatrix(row,col);
        for(int m=0;m<row;m++){
            for(int n=0;n<row;n++){
                float cache=0;
                for (int i=0;i<col;i++){
                    cache+=a->data[m*col+i]*b->data[i*row+n];
                }
                result->data[m*row+n]=cache;
            }
        }
        return result;
    }
    else {
        printf("Matrix doesn't exist!\n");
        return nullptr;
    }
};
//找最小值
float minValue(float* data,int len){
    if (data!=nullptr){
        float m=data[0];
        for(int i=0;i<len;i++){
            if (data[i]<m){
                m=data[i];
            }
        }
        return m;
    }
    else {
        printf("Data source doesn't exist!\n");
        return 0;
    }
}
float findMatrixMin(const struct Matrix * a){
    if (a!=nullptr){
       return minValue(a->data,a->col*a->row); 
    }
    else {
        printf("Matrix doesn't exist!\n");
        return 0;
    }
}
//找最大值
float maxValue(float* data,int len){
    if (data!=nullptr){
        float m=data[0];
        for(int i=0;i<len;i++){
            if (data[i]>m){
                m=data[i];
            }
        }
        return m;
    }
    else {
        printf("Data source doesn't exist!\n");
        return 0;
    }
}
float findMatrixMax(const struct Matrix * a){
    if (a!=nullptr){
       return maxValue(a->data,a->col*a->row); 
    }
    else {
        printf("Matrix doesn't exist!\n");
        return 0;
    }
}


