#include <stdio.h>
int main()
{
	int ar1[4]={0},ar2[4]={0},ar3[4]={0};
	float ar4[4],apodotikotita,temp; 
	int i=0,n,k=-1,j;
	FILE *fp;
	
	if(fp=fopen("in.txt", "r")){
		fscanf(fp, "%d",&n);
		printf("Reading file for %d lines of data...\n",n);
		while(i<n){
			fscanf(fp, "%d",&ar1[i]);
			fscanf(fp, "%d",&ar2[i]);
			fscanf(fp, "%d",&ar3[i]);
			//Ypologismos
			apodotikotita=ar1[i]-ar1[i]*(ar2[i]/3000.0)-ar3[i]*ar1[i]/40.0;
			if (apodotikotita>0){
				k++;
				ar4[k]=apodotikotita;
			}
			i++;
		}
		printf("Printing Array with results...\n");
		for(i=0;i<n;i++){
			printf("i=%d=%d=%d=%d\n",i,ar1[i],ar2[i],ar3[i]);
		}
		for(i=0;i<=k;i++){
			printf("k=%d-apodotikotita=%f\n",i,ar4[i]);
		}
		//bubble sort
		for(i=1;i<=k;i++){
			for(j=k;j>=i;j--){
				if(ar4[j]>ar4[j-1]){
					temp=ar4[j];
					ar4[j]=ar4[j-1];
					ar4[j-1]=temp;
				} 
			}
		}
		printf("Meta to bubble sort\n");
		for(i=0;i<=k;i++){
			printf("k=%d-apodotikotita=%f\n",i,ar4[i]);
		}
		fp=fopen("out.txt", "w");//write to file
	}
	else{
		printf("...error while opening file...");
	}
	return 0;
}
