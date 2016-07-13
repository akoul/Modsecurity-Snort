#include <modsecurity/transaction.h>
#include "modsecurity/modsecurity.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

	//File reading declarations
	FILE *fp = fopen("data.log", "r");
    const char s[2] = ", ";
    char *token;
    int i;
    char *srcIP, *desIP;
    int srcPort, desPort;

    //Modsecurity load rules declarations
    int ret = 1;
    const char *error = NULL;
    ModSecurity *modsec = NULL;
    Transaction *transaction = NULL;
    Rules *rules = NULL;

    modsec = msc_init();

    msc_set_connector_info(modsec, "ModSecurity-test v0.0.1-alpha (Simple " \
        "example on how to use ModSecurity API");

    rules = msc_create_rules_set();

    ret = msc_rules_add_file(rules, main_rule_uri, &error);
    if (ret < 0) {
        fprintf(stderr, "Problems loading the rules --\n");
        fprintf(stderr, "%s\n", error);
        goto end;
    }
    msc_rules_dump(rules);

    ret = msc_rules_add_remote(rules, "test",
        "https://www.modsecurity.org/modsecurity-regression-test-secremoterules.txt",
        &error);
    if (ret < 0) {
        fprintf(stderr, "Problems loading the rules --\n");
        fprintf(stderr, "%s\n", error);
        goto end;
    }
    msc_rules_dump(rules);

    //Read from file and call process() function for every packet after rading data from file.
    if(fp != NULL)
    {
        char line[80];
        while(fgets(line, sizeof line, fp) != NULL)
        {
        	transaction = msc_new_transaction(modsec, rules, NULL);
            token = strtok(line, s);
            for(int i=0; i<5; i++)
            {
            	if (i == 0)
            		continue;
            	else if (i == 1)
            		srcIP = token;
            	else if (i == 2)
            		srcPort = atoi(token);
            	else if (i == 3)
            		desIP = token;
            	else if (i == 4)
            		desPort = atoi(token);
            	//Test printing the values
            	/*if(i==4)
            	{
            	printf("%s\n",token);
            	token = strtok(NULL,s);
            	}
            	else{
            	printf("%s\t",token);
            	token = strtok(NULL,s);	
            	}*/
            }
            msc_process_connection(transaction, srcIP, srcPort, desIP, desPort);
        }
        fclose(fp);
        msc_rules_cleanup(rules);
    	msc_cleanup(modsec);
    } else {
        perror("data.log");
    }   
	return 0;
}

