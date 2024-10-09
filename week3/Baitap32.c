#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
typedef struct circle{
      double r;
      double x;
      double y;
      int giao;
}circle;

void ctr(circle a[],int n){
    printf("Cac hinh tron vua nhap la:");
    for(int i=0;i<n;i++){
       printf("Hinh tron T%d:",i+1);
       printf("r=%lf x=%lf y=%lf",a[i].r,a[i].x,a[i].y);
       printf("\n");
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i].giao=-1;//ð? tr? ði trý?ng h?p i j trùng nhau
            double kc = sqrt((a[i].x - a[j].x)*(a[i].x - a[j].x) + (a[i].y - a[j].y)*(a[i].y - a[j].y));
            if(kc<=a[i].r+a[j].r) a[i].giao++;
        }
    }
    int max_giao = -1;
    int max_index = -1;
    for (int i = 0; i < n; i++) {
        if (a[i].giao > max_giao) {
            max_giao = a[i].giao;
            max_index = i;
        }
    }
    printf("Hinh tron r=%lf, (%lf,%lf) giao nhieu hinh tron nhat ( %d lan) ",a[max_index].r,a[max_index].x,a[max_index].y,a[max_index].giao);
    
}
int main(){
    int n; scanf("%d",&n);
    circle a =(circle)malloc(n*sizeof(circle));
    for(int i=0;i<n;i++){
        scanf("%lf%lf%lf",&a[i].r,&a[i].x,&a[i].y);
    }
    ctr(a,n);
    
    return 0;
}

