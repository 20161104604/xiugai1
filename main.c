
//  main.c
//  gpsz
//
//  Created by 20161104604 on 2018/7/6.
//  Copyright © 2018年 20161104604. All rights reserved.
//


#include <stdio.h>
int main()
{
    FILE *fr;
    FILE *fw;
    char a[70];
    char a1[70];
    char date[7];
    char time[8];
    char lat[9];
    char  longitude[10];
    char hight[5];
    int k,j,s,i,t1,t2,n;
    fr=fopen("//Users//a20161104604//Desktop//gpsz//GPSW.txt","r");
    fw=fopen("//Users//a20161104604//Desktop//gpsz//GPSOUT.csv","w");
    fprintf(fw,"日期,时间,纬度,经度,高度\n");
    while(!feof(fr))
    {
        fscanf(fr,"%s%s",a,a1);
        printf("结果:%s\n%s\n",a,a1);
        for(n=0;n<2;n++)
        {
            date[n]=a[n+55];
        }
        date[2]='\0';
        printf("日期:%s",date);
        fprintf(fw,"%s／",date);
        for(n=0;n<2;n++)
        {
            date[n]=a[n+51];
        }
        date[2]='\0';
        printf("%s",date);
        fprintf(fw,"%s／",date);
        for(n=0;n<2;n++)
        {
            date[n]=a[n+53];
        }
        date[2]='\0';
        printf("%s\n",date);
        fprintf(fw,"%s,",date);
        for(i=0;i<2;i++)
        {
            time[i]=a[i+7];
        }
        time[2]='\0';
        t1=(time[0]-'0')*10;
        t2=(time[1]-'0')*1+t1+8;
        printf("时间:%d",t2);
        fprintf(fw,"%d",t2);
        for(i=0;i<4;i++)
        {
            time[i]=a[i+9];
        }
        time[4]='\0';
        printf("%s\n",time);
        fprintf(fw,"%s,",time);
        for(k=0;k<2;k++)
        {
            lat[k]=a[k+16];
        }
        lat[2]='\0';
        printf("纬度:%s/",lat);
        fprintf(fw,"%s/",lat);
        for(k=0;k<6;k++)
        {
            lat[k]=a[k+18];
        }
        lat[6]='\0';
        printf("%s\n",lat);
        fprintf(fw,"%s,",lat);
        for(j=0;j<3;j++)
        {
            longitude[j]=a[j+27];
        }
        longitude[3]='\0';
        printf("经度:%s.",longitude);
        fprintf(fw,"%s.",longitude);
        for(j=0;j<6;j++)
        {
            longitude[j]=a[j+30];
        }
        longitude[6]='\0';
        printf("%s\n",longitude);
        fprintf(fw,"%s,",longitude);
        for(s=0;s<4;s++)
        {
            hight[s]=a1[s+43];
        }
        hight[4]='\0';
        printf("海拔:%sm\n",hight);
        fprintf(fw,"%sm\n",hight);
    }
    fclose(fr);
    fclose(fw);
    return 0;
}

