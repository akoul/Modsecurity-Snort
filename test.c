#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

	FILE *fp = fopen("data.log", "r");
    const char s[2] = ", ";
    char *token;
    int i;
    if(fp != NULL)
    {
        char line[80];
        while(fgets(line, sizeof line, fp) != NULL)
        {
            token = strtok(line, s);
            for(int i=0; i<5; i++)
            {
            	if(i==4)
            	{
            	printf("%s\n",token);
            	token = strtok(NULL,s);
            	}
            	else{
            	printf("%s\t",token);
            	token = strtok(NULL,s);	
            	}
            }
            printf("\nTest\n");    
        }
        fclose(fp);
    } else {
        perror("data.log");
    }   
	return 0;
}
