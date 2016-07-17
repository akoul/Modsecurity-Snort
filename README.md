#Introduction

This repo contains the Modsecurity-snort connector which will be used to process data extracted from Snort.

#Installation guide

1. First build libModSecurity in your system. [Compilation recipes]
(https://github.com/SpiderLabs/ModSecurity/wiki/Compilation-recipes)

2. Build snort++ in your system. [Compilation recipes]
(https://github.com/snortadmin/snort3#build-snort)

3. Try running snort in your system to see if it is correctly installed and working properly. [Testing]
(https://github.com/snortadmin/snort3#run-snort)

4. Build the examples using instructions from `snort3/extra/README`

5. To extract http data from a buffer, you will need a trace file having http data. An example [trace file] is also attached in the repo
(https://github.com/akoul/Modsecurity-Snort/blob/master/http.cap)

6. Run the following command in your terminal:

   `snort -c $my_path/etc/snort/snort.lua --plugin-path $my_path/lib/snort_extra -A alert_ex -r /path/to/my.pcap`

7. A data.log file must be created in your home directory. The file contains extracted data from the http trace file you used as input to the snort system. 
Note: It is important that the pcap file used contains http data, otherwise the data.log file will be blank.

8. Change to /opt directory and clone the ModSecurity-snort repo
   `cd /opt`
   `git clone https://github.com/akoul/Modsecurity-Snort`
   
9. Use the following commands for compilation and running the connector:
   
   `cd Modsecurity-Snort`
   
   `export LD_LIBRARY_PATH=/usr/local/modsecurity/lib`
   
   `sudo gcc modsecurity-snort.c  -I /opt/ModSecurity/headers -L /opt/ModSecurity/src/.libs/ -lmodsecurity -o modsecurity-snort`
   
   `./modsecurity-snort`   
	

#TO-DO

1. Extract remaining fields from the snort inspector.

2. Send the remaining fields to libmodsecurity for processing.

3. Check for bugs

#Disclaimer
This is an basic example of ModSecurity-snort connector. More functionalities to be added later.
