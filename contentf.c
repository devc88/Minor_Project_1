//using basic file handling concepts read a txt file and categorizing it in different folder as per content.

#include <stdio.h>
#include<string.h>
#define MAXCHAR 1000

int largestNumber(float a,float b, float c)
{
	int largest=0;
	if(a>b && a>c)
		largest=1;
	else if(b>a && b>c)
		largest=2;
	else
		largest=3;
	return largest;
}

char *get_new_file(char arr[],char *copy){
//char arr[]="TextField(25)";

    int l=strlen(arr);


    for(int i=0;i<=l;i++){
        if(arr[i]!='(')
        {
            copy[i]=arr[i];
        }
        else{
            copy[i]='\0';
            break;
        }
    }

    //printf("\n%s\n",copy);
    return copy;
}



//this is the function to count the keyword
int count_of_keyword(char *x[])
{

        int i=1,count=0;
        while(i!=0)
        {
                if(strcmp("e1",x[count])==0)
                {
                        break;
                }
                count++;
        }
        return count;
}

int content_based_categorization(char filename[])
{
        FILE *fp;
        char read[100];
        int countkeyJava=0,countkeyC=0,countkeyhtml=0;
        int totalword=1;
    
        //all the keyword of JAVA
        char *JAVA[]={"abstract","assert","boolean","break","byte","case","catch","char","class","continue","default"
        ,"do","double","else","enum","extends","extends","final","finally","float","for","if","implements","import",
        "instance","of","int","interface","long","native","new","nullpackage","java.util.Scanner","reader.nextInt();","java.util.Scanner;",
       "public static","static class","public class","import java.io.*;","public class Main","Scanner reader","System.out.print","switch","case",
       "default:" ,"e1"};

        //all the keyword of C
        char *C[]={"auto","break","case","char","const","continue","default","do","double","else","enum"
        ,"extern","float","for","goto","if","int","long","register","return","short","signed","sizeof","static",
        "struct","switch","typedef","union","unsigned","void","volatile","while","#include","<stdio.h>","main()","e1"};
        
        //all the Keyword of HTML
        char *HTML[]={"<html>","<head>","<title>","<body>","<!DOCTYPE html>","<img src=","</html>",
        "</head>","</title>","<body>","</body>","<h1 ","</h1>","<style>","</style>","<p>","e1"};

        int countjava=0,countC=0,counthtml=0;

        fp = fopen(filename, "r");
        if (fp == NULL)
        {
                printf("Could not open file %s",filename);
        }

        countkeyJava=count_of_keyword(JAVA);
        countkeyC=count_of_keyword(C);
	countkeyhtml=count_of_keyword(HTML);
        while (!feof(fp)) 
        {

                fscanf(fp, "%s", read);

                for(int i=0;i<countkeyJava;i++)
                {
                        if(strcmpi(read,JAVA[i])==0){
                     
                        countjava++;
                }
        }

        for(int i=0;i<countkeyC;i++)
        {

              if(strcmpi(read,C[i])==0)
              {
                     
                       countC++;
              }
        }
		
	 for(int i=0;i<countkeyhtml;i++){

              if(strcmpi(read,HTML[i])==0){
          
              counthtml++;
         }
        }
	

        totalword++;

        }
        fclose(fp);
        float ratiojava=(countjava*100)/totalword;
        float ratioc=(countC*100)/totalword;
        float ratiohtml=(counthtml*100)/totalword;
/*
Different return value for each type
0=other
1=C
2=Java
3=HTML
*/
	if(ratioc<5.0 && ratiojava<5.0 && ratiohtml<5.0)
	{
	    printf("other");
	    return 0;
	}

	else
	{
	    return largestNumber(ratioc,ratiojava,ratiohtml);
	}
}
